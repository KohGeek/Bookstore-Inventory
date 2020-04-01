#include <iostream>
#include <vector>
#include <locale>
#include <windows.h>
#include <conio.h>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace std;

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    locale::global(locale("en_US.UTF-8"));
    vector<BOOK> inventory;
    char option = '\0';

    // check if user wants to load anything
    reader(inventory);

    displaymenu();
    cout << "Choose your options : " << endl;

    while (option != '5')
    {
        cin >> option;

        switch (option)
        {
        case '1':
            system("CLS");
            addrecord(inventory);
            break;
        case '2':
            system("CLS");
            removerecord(inventory);
            break;
        case '3':
            system("CLS");
            editrecord(inventory);
            break;
        case '4':
            system("CLS");
            listrecords(inventory, 1, vector<int>());
            break;
        case '5':
            system("CLS");
            query(inventory, true);
            break;
        case '6':
            //prompt to save here
            break;
        default:
            system("CLS");
            displaymenu();
            cout << "Error, please input value between 1 to 6." << endl;
        }

        cout << "Press any key to continue...";
        getch();
        system("CLS");
        displaymenu();
        cout << "Choose your options : " << endl;
    }

    return 0;
}

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
    select.add_row({"6) Exit"});

    cout << select << endl;
}