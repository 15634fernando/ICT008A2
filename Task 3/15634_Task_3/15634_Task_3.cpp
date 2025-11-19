#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
protected:
    string title;
    string author;
    string ISBN;
    bool available;
    string dateAdded;

public:
    Book(string t, string a, string i, bool av, string date) :
        title(t), author(a), ISBN(i), available(av), dateAdded(date) {
    }

    virtual void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdded << endl;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "You borrowed \"" << title << "\".\n";
        }
        else {
            cout << "\"" << title << "\" is not available.\n";
        }
    }
};

class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    HardcopyBook(string t, string a, string i, bool av, string date, string shelf) :
        Book(t, a, i, av, date), shelfNumber(shelf) {
    }

    void displayDetails() const override {
        Book::displayDetails();
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

class EBook : public Book {
private:
    string licenseEndDate;

public:
    EBook(string t, string a, string i, bool av, string date, string licenseDate) :
        Book(t, a, i, av, date), licenseEndDate(licenseDate) {
    }

    void displayDetails() const override {
        Book::displayDetails();
        cout << "License End Date: " << licenseEndDate << endl;
    }
};

int main() {
    vector<HardcopyBook> hardbooks = {
        HardcopyBook("Chainsaw Man Vol. 01", "Tatsuki Fujimoto", "9781974709939", true, "2025-11-01", "A12"),
        HardcopyBook("The Maze Runner", "James Dashner", "9780385737951", true, "2025-11-01", "B7")
    };

    vector<EBook> ebooks = {
        EBook("Percy Jackson and the Sea of Monsters", "Rick Riordan", "9780141381497", true, "2025-11-01", "2026-12-31"),
        EBook("Attack on Titan Vol. 01", "Hajime Isayama", "9781612626154", true, "2025-11-01", "2025-11-30"),
        EBook("Jujutsu Kaisen Vol. 01", "Gege Akutami", "9781974720149", true, "2025-11-01", "2025-12-31")
    };

    cout << "Hardcopy Books:\n";
    for (const auto& book : hardbooks) {
        book.displayDetails();
        cout << endl;
    }

    cout << "E-Books:\n";
    for (const auto& book : ebooks) {
        book.displayDetails();
        cout << endl;
    }

    // Example borrowing books
    hardbooks[0].borrowBook();
    ebooks[0].borrowBook();

    return 0;
}
