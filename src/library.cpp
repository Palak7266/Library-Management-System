#include "library.h"
#include <cstdio>
void Book::input() {
    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Author: ";
    getline(cin, author);
    issued = false;
}

void Book::display() {
    cout << "\nID: " << id
         << "\nName: " << name
         << "\nAuthor: " << author
         << "\nIssued: " << (issued ? "Yes" : "No") << endl;
}

void Library::addBook() {
    Book b;
    ofstream file("data/books.txt", ios::app);

    b.input();

    file << b.id << "|" << b.name << "|" << b.author << "|" << b.issued << endl;
    file.close();

    cout << "Book Added Successfully!\n";
}

void Library::showBooks() {
    ifstream file("data/books.txt");
    Book b;

    while (file >> b.id) {
        file.ignore();
        getline(file, b.name, '|');
        getline(file, b.author, '|');
        file >> b.issued;

        b.display();
    }

    file.close();
}

void Library::searchBook(int id) {
    ifstream file("data/books.txt");
    Book b;
    bool found = false;

    while (file >> b.id) {
        file.ignore();
        getline(file, b.name, '|');
        getline(file, b.author, '|');
        file >> b.issued;

        if (b.id == id) {
            b.display();
            found = true;
        }
    }

    if (!found) cout << "Book not found!\n";

    file.close();
}

void Library::issueBook(int id) {
    ifstream file("data/books.txt");
    ofstream temp("data/temp.txt");

    Book b;
    bool found = false;

    while (file >> b.id) {
        file.ignore();
        getline(file, b.name, '|');
        getline(file, b.author, '|');
        file >> b.issued;

        // 👇 agar book mil gayi aur already issue nahi hai
        if (b.id == id && b.issued == false) {
            b.issued = true;
            found = true;
            cout << "Book Issued Successfully!\n";
        }

        temp << b.id << "|" << b.name << "|" << b.author << "|" << b.issued << endl;
    }

    file.close();
    temp.close();

    remove("data/books.txt");
    rename("data/temp.txt", "data/books.txt");

    if (!found) cout << "Book not available or already issued!\n";
}

void Library::returnBook(int id) {
    ifstream file("data/books.txt");
    ofstream temp("data/temp.txt");

    Book b;
    bool found = false;

    while (file >> b.id) {
        file.ignore();
        getline(file, b.name, '|');
        getline(file, b.author, '|');
        file >> b.issued;

        // 👇 agar book issued hai to return karo
        if (b.id == id && b.issued == true) {
            b.issued = false;
            found = true;
            cout << "Book Returned Successfully!\n";
        }

        temp << b.id << "|" << b.name << "|" << b.author << "|" << b.issued << endl;
    }

    file.close();
    temp.close();

    remove("data/books.txt");
    rename("data/temp.txt", "data/books.txt");

    if (!found) cout << "Book not issued or not found!\n";
}

void Library::deleteBook(int id) {
    ifstream file("data/books.txt");
    ofstream temp("data/temp.txt");

    Book b;
    bool found = false;

    while (file >> b.id) {
        file.ignore();
        getline(file, b.name, '|');
        getline(file, b.author, '|');
        file >> b.issued;

        // 👇 agar same ID mile to skip karo
        if (b.id == id) {
            found = true;
            cout << "Book Deleted Successfully!\n";
            continue;
        }

        temp << b.id << "|" << b.name << "|" << b.author << "|" << b.issued << endl;
    }

    file.close();
    temp.close();

    remove("data/books.txt");
    rename("data/temp.txt", "data/books.txt");

    if (!found) cout << "Book not found!\n";
}