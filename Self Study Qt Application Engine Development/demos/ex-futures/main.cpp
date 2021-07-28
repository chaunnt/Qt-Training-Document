/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtConcurrent>
#include <cmath> // for std::sin/cos/exp

static const int ITERATIONS = 5;    // adjust to your computer's speed and RAM
static const bool OPTIONALS = true;   // to to true to enable the optional part

#define Container QVector // no template typedefs :(
// #define Container QList

// test-data generators, defined towards the end (but not interesting):
static Container<double>    makeDoubles();
static Container<QString>   makeStrings(const Container<double> &);
static Container<QRect>     makeRectangles(const Container<double> &);

//
// Task 1: filtering/grepping strings
//

static bool isFirstLetterLowerCase(const QString &s) {
    return !s.isEmpty() && s[0].isLower();
}

static QFuture<QString> grepFirstLetterLowerCase(const Container<QString> &c) {
    return QtConcurrent::filtered(c, isFirstLetterLowerCase);
}

static QFuture<void> grepFirstLetterLowerCaseInline(Container<QString> &c) {
    return QtConcurrent::filter(c, isFirstLetterLowerCase);
}

//
// Task 2: Calculating some complex formula
//

static double formula(double x) {
    return std::exp(-std::abs(x)) + std::sin(x) + std::cos(x);
}

static QFuture<double> calculateFormula(const Container<double> &c) {
    return QtConcurrent::mapped(c, formula);
}

static void formulaInline(double &x) {
    x = formula(x);
}

static QFuture<void> calculateFormulaInline(Container<double> &c) {
    return QtConcurrent::map(c, formulaInline);
}

//
// Task 3: forming a covering QRegion from a set of rectangles, and a
//         reference window
//

struct Intersecter {
    const QRect m_rect;
    explicit Intersecter(const QRect &rect) : m_rect(rect) {}

    typedef QRect result_type;

    QRect operator()(const QRect &rect) const {
        return m_rect.intersected(rect);
    }
};

static void build_region(QRegion &region, const QRect &rect) {
    if (!rect.isEmpty())
        region = region.united(rect);
}

static QFuture<QRegion> coverage(const Container<QRect> &c, const QRect &window) {
    return QtConcurrent::mappedReduced(c, Intersecter(window), build_region);
}

//
// Timing Harness
//

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug("QThreadPool::maxThreadCount: %d", QThreadPool::globalInstance()->maxThreadCount());

    qsrand(0U); // seed, but deterministically

    // timing: exercise each task ITERATIONS times, and output the
    // time it took (in wallclock seconds)
    QTime timer;

    const Container<double> doubles = makeDoubles();

    {
        const Container<QString> strings = makeStrings(doubles);
        QVector< Container<QString> > stringLists;
        for (int i = 0 ; i < ITERATIONS ; ++i) {
            stringLists.push_back( strings );
            stringLists.back().detach();
        }

        timer.start();
        {
            QFutureSynchronizer<void> sync;
            for (int i = 0 ; i < ITERATIONS ; ++i)
                sync.addFuture(grepFirstLetterLowerCase(stringLists[i]));
        }
        qDebug("strings timing (copying): %.3f secs",
                timer.elapsed() / 1000. / ITERATIONS);

        if (OPTIONALS) {
            timer.start();
            {
                QFutureSynchronizer<void> sync;
                for (int i = 0 ; i < ITERATIONS ; ++i)
                    sync.addFuture(grepFirstLetterLowerCaseInline( stringLists[i]));
            }
            qDebug("strings timing (inline): %.3f secs",
                    timer.elapsed() / 1000. / ITERATIONS);
        }
    }

    {
        QVector<Container<double>> doubleLists;
        for (int i = 0 ; i < ITERATIONS ; ++i) {
            doubleLists.push_back(doubles);
            doubleLists.back().detach();
        }

        timer.start();
        {
            QFutureSynchronizer<void> sync;
            for (int i = 0 ; i < ITERATIONS ; ++i)
                sync.addFuture(calculateFormula(doubleLists[i]));
        }
        qDebug("doubles timing (copying): %.3f secs",
                timer.elapsed() / 1000. / ITERATIONS);

        if (OPTIONALS) {
            timer.start();
            {
                QFutureSynchronizer<void> sync;
                for (int i = 0 ; i < ITERATIONS ; ++i)
                    sync.addFuture(calculateFormulaInline( doubleLists[i]));
            }
            qDebug("doubles timing (inline): %.3f secs",
                    timer.elapsed() / 1000. / ITERATIONS);
        }
    }

    {
        const Container<QRect> rectangles = makeRectangles(doubles);
        const QRect reference(QPoint(-500, -500), QPoint(500, 500));
        timer.start();
        {
            QFutureSynchronizer<void> sync;
            for (int i = 0 ; i < ITERATIONS ; ++i)
                sync.addFuture(coverage(rectangles, reference));
        }
        qDebug("rectangles timing: %.3f secs",
                timer.elapsed() / 1000. / ITERATIONS);
    }
    return 0;
}

//
// Just test data generation below, not really interesting
//

static const int NUM_RANDOM_DOUBLES = 4*1024*1024;

static Container<double> makeDoubles() {
    Container<double> result;
    for (int i = 0 ; i < NUM_RANDOM_DOUBLES ; ++i)
        result.push_back(std::fmod(qrand(), 2000.) + 1000.);
    return result;
}

static Container<QString> makeStrings(const Container<double> &doubles) {
    Container<QString> result;
    // base64 encode the doubles:
    for (double d : doubles) {
        const void * dp = &d;
        const QByteArray data(static_cast<const char*>(dp), sizeof(double));
        result.push_back(QString::fromLatin1(data.toBase64()));
    }
    return result;
}

static Container<QRect> makeRectangles(const Container<double> &doubles) {
    // make rectangles with the random doubles as coordinates:
    Container<QRect> result;
    for (int i = 0 ; i < doubles.size() ; i += 4)
        result.push_back( QRectF( QPointF(doubles[i+0], doubles[i+1]),
                                  QPointF(doubles[i+2], doubles[i+3])).normalized().toRect());
    return result;
}

