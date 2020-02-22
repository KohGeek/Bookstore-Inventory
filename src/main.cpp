#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "GUI.hpp"

using namespace std;

struct BOOK
{
    string isbn;
    string author;
    string title;
    string publisher;
    int year_published;
    int quantity;
    int rack;
    int level;
    double price;
    char genre;
};

int main()
{
    GUI();

    cout << "Hello Easy C++ project!" << endl;

    cout << "Press any key to continue...";
    getch();
    return 0;
}