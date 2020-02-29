#include <iostream>
#include <iomanip>
#include <conio.h>

#include "fileio.hpp"

using namespace std;

BOOK inventory[1000];

int main()
{
    reader();

    cout << "Hello Easy C++ project!" << endl;

    cout << "Press any key to continue...";
    getch();
    return 0;
}