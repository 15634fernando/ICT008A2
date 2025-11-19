// 15634Fernando.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;
    string dateAdded;

public:
    Book(string t, string a, string i, bool av, string date) :
        title(t), author(a), ISBN(i), available(av), dateAdded(date) {
    }

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdded << endl;
    }

    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "You have borrowed \"" << title << "\"." << endl;
        }
        else {
            cout << "Sorry, \"" << title << "\" is not available right now." << endl;
        }
    }

    const string& getISBN() const {
        return ISBN;
    }
};

int findBookByISBN(const vector<Book>& books, const string& isbn) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Book> books = {
        Book("Chainsaw Man Vol. 01", "Tatsuki Fujimoto", "9781974709939", true, "2025-11-01"),
        Book("The Maze Runner", "James Dashner", "9780385737951", true, "2025-11-01"),
        Book("Percy Jackson and the Sea of Monsters", "Rick Riordan", "9780141381497", true, "2025-11-01"),
        Book("Attack on Titan Vol. 01", "Hajime Isayama", "9781612626154", true, "2025-11-01"),
        Book("Jujutsu Kaisen Vol. 01", "Gege Akutami", "9781974720149", true, "2025-11-01")
    };

    string isbnInput;
    cout << "Welcome to the Book Management System\n";

    while (true) {
        cout << "\nEnter ISBN of book to borrow (0 to exit): ";
        getline(cin, isbnInput);

        if (isbnInput == "0") {
            cout << "Exiting the system. Goodbye!\n";
            break;
        }

        int index = findBookByISBN(books, isbnInput);

        if (index == -1) {
            cout << "Book with ISBN " << isbnInput << " not found.\n";
        }
        else {
            books[index].borrowBook();
        }
    }

    return 0;
}
