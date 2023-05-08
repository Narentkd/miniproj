#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Struct for book data
struct Book {
    string title;
    string author;
    string isbn;
    double price;
};

// Function to add a book to the inventory file
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    cout << "Enter book price: ";
    cin >> newBook.price;
    cin.ignore(); // Ignore the newline character
    books.push_back(newBook);
    ofstream outFile("inventory.txt", ios::app);
    outFile << newBook.title << "|" << newBook.author << "|" << newBook.isbn << "|" << newBook.price << endl;
    outFile.close();
    cout << "Book added to inventory." << endl;
}

// Function to search for a book by title
void searchBook(vector<Book>& books) {
    string title;
    cout << "Enter book title to search: ";
    getline(cin, title);
    bool found = false;
    for (Book book : books) {
        if (book.title == title) {
            found = true;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "Price: " << book.price << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Function to display all books in inventory
void displayInventory(vector<Book>& books) {
    cout << "Inventory:" << endl;
    for (Book book : books) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.isbn << endl;
        cout << "Price: " << book.price << endl;
        cout << endl;
    }
}

// Main function
int main() {
    vector<Book> books;

    // Read existing inventory from file
    ifstream inFile("inventory.txt");
    if (inFile) {
        string line;
        while (getline(inFile, line)) {
            Book book;
            size_t pos1 = line.find("|");
            size_t pos2 = line.find("|", pos1+1);
            size_t pos3 = line.find("|", pos2+1);
            book.title = line.substr(0, pos1);
            book.author = line.substr(pos1+1, pos2-pos1-1);
            book.isbn = line.substr(pos2+1, pos3-pos2-1);
            book.price = stod(line.substr(pos3+1));
            books.push_back(book);
        }
        inFile.close();
    }

    // Main loop
    while (true) {
        int choice;
        cout << "Select an option:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Search for book" << endl;
        cout << "3. Display inventory" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character
        cout << endl;
        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                searchBook

