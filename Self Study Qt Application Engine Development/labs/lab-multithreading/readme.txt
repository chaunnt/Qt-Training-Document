==================
Multithreading Lab
==================

PiCalculator is a worker object, which uses an infinite loop to calculate digits of pi.

Run the worker in its own thread. There is no need to sub-class QThread.

Step 1:
=======

MainWindow has a slot on_pushButton_released().
- Create PiCalculator and QThread objects. Decide what happens, if the user clicks on the button, when the worker is running or finished. The calculator reuires two widget arguments: an observer and a label. The former is a progress bar and the latter a label, created in the UI.
- Create signal/slot connections to
    * start the calculator: slot run()
    * cleanup the thread and calculator
    * optionally to connect to the cleanupThread() slot, which could change the button text, for example.
- The worker should run in the new thread.
- Remember to start the thread.

Step 2:
=======

Quit nicely the worker. There is already a condition, if k exceeds the maximum double value.
- Check, if the thread interruption request has occurred. If yes, take care of quitting the thread.
- The thread interruption is requested, if a timer expires. Add a timer to the worker. Thread may be interrupted by the user by pressing the push button. Add the functionality in MainWindow slot.
- How to handle the timer event in the infinite loop? Take care of processing events every now and then.
- Notify the observer and label widgets about the progress and pi value. Create connections or use QMetaObject::invokeMethod() functions.

Test your solution in all cases. User presses the button several times, the timer expires or the window is closed. In all cases the program should exit gracefully.
