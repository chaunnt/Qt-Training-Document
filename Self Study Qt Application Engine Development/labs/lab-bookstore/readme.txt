=============
Bookstore Lab
=============

The application has two list views. The upper one shows data from the author table using QSqlTableModel, while
the lower one shows all books, written by one author. The book data is fetched from the database using QSqlQueryModel sub-class.

Both models wrapped into TableToListModel proxy, whose only purpose is to map database columns to roles, which are accessible in QML list view.

Your task is to complete the functionality or author and book models.

Note that the application crashes, if you try to run it before Steps 1 and 2 have been implemented.

Step 1:
=======

Set the author table for author model.

Step 2:
=======

Map table columns to named properties, you are later going to use in QML list views.

Author table has three fields of type text:
- authorid
- firstname
- surname

The book model column names depend on the query, you are requested to implement in Step 3. The book table contains the following columns:
- id
- authorid
- title
- price
- notes
The view expects to have access to last three columns, so map at least those.

Step 3:
=======

Now you may run the application. It shows dummy data, because the property names, you defined in Step 2 are not used yet in QML views.

Select all the books, written by authorid, from the Table book.

Step 4:
=======

Change all the text property values in Editor objects in AuthorView and BookView QML files to the actual property names.

Step 5:
=======

Allow author editing by adding flags() and setData() functions to the BookModel class.

In setData():
- The column index defines, which field to change
- The field value can be changed with the SQL query: "update book set FIELDNAME = :value where id = :id"
- id is the authorid, i.e. the first column in the changed row.
- After changing the data, call refresh() to update author's books

Step 6:
=======

Add functionality in Editor objects in AuthorView and BookView QML files to store the changed data into the database.

All done.

Optional step:
==============

Comment in the QML code, which defines a footer for author and books list views. The footers contain two button to add and remove authors and books, respectively.

Comment in the four functions to add and remove authors and books in BookStore.

The actual implementation is required in TableToListModel. Implement removeItem() and insertItem(). Note that when removing an item from QSqlTableModel, you need to call select() to make changes to the model. Remember to notify the view as well.

