#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct BOOK
{
    string isbn;
    string author;
    string title;
    string publisher;
    int year_published;
    int quantity;
    int location;
    double price;
    char genre;
};

int main()
{

    cout << "Hello Easy C++ project!" << endl;

    cout << "Press any key to continue...";
    getch();
    return 0;
}