#include <iostream>
#include <vector>
#include <sqlite_modern_cpp.h>

class Book {
public:
    // Constructors
    Book() = default;
    Book(std::string title, std::string author, int year) : title(std::move(title)), author(std::move(author)), year(year) {}

    // Display book information
    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year << "\n\n";
    }

    // Getters
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    int getYear() const { return year; }

private:
    std::string title;
    std::string author;
    int year;
};

class Library {
public:
    // Add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Display all books in the library
    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }

    // Save the library to an SQLite database
    void saveToDatabase(const std::string& dbname) const {
        sqlite::database db(dbname);

        db << "CREATE TABLE IF NOT EXISTS books (id INTEGER PRIMARY KEY, title TEXT, author TEXT, year INTEGER);";

        for (const auto& book : books) {
            db << "INSERT INTO books (title, author, year) VALUES (?, ?, ?);"
               << book.getTitle() << book.getAuthor() << book.getYear();
        }

        std::cout << "Library saved to SQLite database: " << dbname << std::endl;
    }

    // Load books from the SQLite database
    void loadFromDatabase(const std::string& dbname) {
        sqlite::database db(dbname);

        books.clear();

        db << "SELECT * FROM books;" >> [&](int id, std::string title, std::string author, int year) {
            addBook(Book(std::move(title), std::move(author), year));
        };

        std::cout << "Library loaded from SQLite database: " << dbname << std::endl;
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    library.addBo
