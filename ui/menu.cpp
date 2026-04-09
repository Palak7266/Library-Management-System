#include "../src/library.h"

void menu() {
    Library lib;
    int choice, id;

    while (true) {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.showBooks();
                break;

            case 3:
                cout << "Enter Book ID: ";
                cin >> id;
                lib.searchBook(id);
                break;

            case 4:
                cout << "Enter Book ID to Issue: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 5:
                cout << "Enter Book ID to Return: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                cout << "Enter Book ID to Delete: ";
                cin >> id;
                lib.deleteBook(id);
                break;

            case 7:
                cout << "Exiting...\n";
                exit(0);

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}