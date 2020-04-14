#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>

void AddBooks();
void DeleteBooks();
void EditBooks();
using namespace std;

struct BOOK
{
    string isbn[100];
    string author[100];
    string title[100];
    string publisher[100];
    int year_published;
    int quantity;
    int rack;
    int level;
    double price;
    char genre;
};

int main()
{
    AddBooks();
    DeleteBooks();
    //EditBooks();
    return 0;
}

/*void menu()
{
    cout << "1. Add books" << endl;
    cout << "2. Delete books" << endl;
}*/

void AddBooks()
{
    struct BOOK book;
    char choice;
    ofstream outfile("Library.txt", ios::out | ios::app);
    cout << "Would you like to add a book record (Y/N) : ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        if (!outfile)
            cout << "Error opening Library.txt\n";
        else
        {
            do
            {
                cout << "ISBN Code: ";
                cin.get(book.isbn, 100);
                cin.ignore();
                cout << "Author: ";
                cin.get(book.author, 100);
                cin.ignore();
                cout << "Title: ";
                cin.get(book.title, 100);
                cin.ignore();
                cout << "Publisher: ";
                cin.get(book.publisher, 100);
                cin.ignore();
                cout << "Year Published: ";
                cin >> book.year_published;
                cout << "Quantity: ";
                cin >> book.quantity;
                cout << "Rack: ";
                cin >> book.rack;
                cout << "Level: ";
                cin >> book.level;
                cout << "Price: ";
                cin >> book.price;
                cout << "Genre: ";
                cin >> book.genre;
                outfile << book.isbn << ", " << book.author << ", " << book.title << ", " << book.publisher << ", " << book.year_published << ", " << book.quantity << ", " << book.rack << ", " << book.level << ", " << book.price << ", " << book.genre << endl;
                outfile.close();
                cout << "Would you like to add a book record (Y/N) : ";
                cin >> choice;
            } while (choice == 'Y' || choice == 'y');
        }
    }
}

void DeleteBooks()
{
    char choice;
    cout << "Would you like to remove a book record (Y/N) : ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        ifstream infile("Library.txt", ios::in);
        ofstream temp("Temp.txt", ios::out);
        cout << "Enter the ISBN code of the book to remove : ";
        string isbn;
        cin >> isbn;
        cin.ignore();
        while (!infile.eof())
        {
            struct BOOK book;
            infile.getline(book.isbn, 100);
            if (strcmp(book.isbn, isbn) == 0)
            {
                continue;
            }
            temp << book.isbn << endl;
        }
        infile.close();
        temp.close();
        cout << "The book record with the isbn code " << isbn << " has been deleted if it exsisted" << endl;
        remove("Library.txt");
        rename("Temp.txt", "Library.txt");
    }
}

void EditBooks()
{
    ifstream infile;
    ofstream outfile;

    infile.open("Library.txt", ios::in);
    outfile.open("Temp.txt");

    string old;
    string New;
    string current;
    cout << "Enter the isbn code of the book to edit : ";
    cin >> old;

    cout << "Enter the new information of the book : ";
    cin >> New;

    while (!infile.eof())
    {
        infile >> current;

        if (current == old)
        {
            outfile << New << endl;
        }
        else
        {
            outfile << current << endl;
        }
    }

    infile.close();
    outfile.close();

    remove("Library.txt");
    rename("Temp.txt", "Library.txt");
}
