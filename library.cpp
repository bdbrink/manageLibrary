#include <iostream>
#include <fstream>
#include <vector>

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

    // Save the library to a file
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& book : books) {
                file << book.getTitle() << ',' << book.getAuthor() << ',' << book.getYear() << '\n';
            }
            std::cout << "Library saved to file: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file for writing: " << filename << std::endl;
        }
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    // Display all books in the library
    std::cout << "Books in the library:\n";
    library.displayBooks();

    // Save the library to a file
    library.saveToFile("library.txt");

    return 0;
}
