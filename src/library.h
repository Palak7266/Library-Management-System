#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
using namespace std;
void issueBook(int id);
void returnBook(int id);

class Book {
public:
    int id;
    string name;
    string author;
    bool issued;

    void input();
    void display();
};

class Library {
public:
    void addBook();
    void showBooks();
    void searchBook(int id);
    void issueBook(int id);
    void returnBook(int id);
    void deleteBook(int id);
};

#endif