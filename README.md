# Library Management System

## Overview

This C++ script implements a basic Library Management System. It allows you to add books, display them, save the library to an SQLite database, load books from the database, search for books, and provides a quick intro or summary of the library.

## Features

1. **Add Books**: Add books to the library with information such as title, author, and publication year.

2. **Display Books**: View a list of all books in the library.

3. **Save to Database**: Save the library to an SQLite database for persistent storage.

4. **Load from Database**: Load books from an SQLite database into the library.

5. **Search Books**: Search for books based on titles, authors, or publication years.

6. **Library Summary**: Get a quick intro or summary of the library, including the number of books.

## Usage

1. **Compilation**:
   - Compile the script using a C++ compiler.

2. **Run the Program**:
   - Execute the compiled program.

3. **Interact with the Library**:
   - Follow the prompts to add books, display the library, save/load from the database, search for books, and get a library summary.

## Dependencies

- [sqlite_modern_cpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp): A C++14 wrapper around SQLite.

## Example

```cpp
// Add some books to the library
library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));

// Display library info
library.displayLibraryInfo();

// Display all books
library.displayBooks();

// Search for books
library.searchBooks("Harper");
