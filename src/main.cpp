#include <iostream>
#include <vector>
#include <locale>
#include <windows.h>
#include <conio.h>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace std;

// marking as complete. Awaiting testing.
int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    locale::global(locale("en_US.UTF-8"));
    vector<BOOK> inventory;
    char option = '\0';

    displaymenu();
    cout << "Choose your options : " << endl;

    while (option != 'e' && option != 'E')
    {
        cin >> option;

        if (flush() == 1)
        {
            option = '7';
        }

        switch (option)
        {
        case '1':
            system("CLS");
            addrecord(inventory);
            promptsave(inventory);
            break;
        case '2':
            system("CLS");
            editrecord(inventory);
            promptsave(inventory);
            break;
        case '3':
            system("CLS");
            removerecord(inventory);
            promptsave(inventory);
            break;
        case '4':
            system("CLS");
            listrecords(inventory, 1, vector<int>());
            break;
        case '5':
            system("CLS");
            query(inventory, true);
            break;
        case 's':
        case 'S':
            writer(inventory);
            break;
        case 'l':
        case 'L':
            reader(inventory);
            break;
        case 'e':
        case 'E':
            break;
        default:
            system("CLS");
            displaymenu();
            cout << "Error, please input the listed values." << endl;
        }

        cout << "Press any key to continue...";
        getch();
        system("CLS");
        displaymenu();
        cout << "Choose your options : " << endl;
    }

    promptsave(inventory);

    return 0;
}

//Complete
void displaymenu()
{
    //header
    tabulate::Table header;
    header.add_row({"Book Inventory System"});

    header.format()
        .font_style({tabulate::FontStyle::bold})
        .border_top(" ")
        .border_bottom(" ")
        .border_left(" ")
        .border_right(" ")
        .corner(" ")
        .padding_top(1)
        .padding_bottom(1)
        .font_background_color(tabulate::Color::cyan);

    cout << header << endl;

    //selection
    tabulate::Table select;

    select.add_row({"1) Add"});
    select.add_row({"2) Edit"});
    select.add_row({"3) Delete"});
    select.add_row({"4) List"});
    select.add_row({"5) Search"});
    select.add_row({""});
    select.add_row({"S) Save"});
    select.add_row({"L) Load"});
    select.add_row({""});
    select.add_row({"E) Exit"});

    cout << select << endl;
}