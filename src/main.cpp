/** This is a joint collaboration effort by Koh Jun Dong, Tan Kai Fung and Johnny Chuan.
 *  
 *  The following code is licensed under the GNU GPL license. All derivatives must be open sourced.
 * 
 *  The code is written with a few things in mind. 
 *  1) It is written with MSVC at its core.
 *  2) It is written with mainly C++11 features, but the libraries are C++17 mandatory.
 *  3) It is not written with the VS IDE, instead, a separate editor is used.
 * 
 *  The following source code will be open sourced on Github shortly after the completion of the assignment.
 *  Find it at https://github.com/KohGeek/Bookstore-Inventory
 * 
 *  The following header-only libaries are employed:
 *  - csv by p-ranav (https://github.com/p-ranav/csv)
 *  - tabulate by p-ranav (https://github.com/p-ranav/tabulate)
 * 
**/

#include <iostream>
#include <vector>
#include <locale>
#include <windows.h>
#include <conio.h>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace std;

/** main()
 * 
 *  This is where all the code starts and ends. Life is a circle.
 * 
**/
int main()
{
    // Maximises the windows, and sets the language to UTF-8 (experimental)
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    locale::global(locale("en_US.UTF-8"));
    vector<BOOK> inventory;
    char option = '\0';

    displaymenu();
    cout << "\nPlease proceed to load a file with L) before continuing.\n\n";
    cout << "Choose your options : " << endl;

    while (option != 'e' && option != 'E')
    {
        cin >> option;

        // This will occur for every character based menu selection
        // Without this, the program will bug if the user decides to type more than one character.
        if (flush() == 1)
        {
            option = '7';
        }

        // 1 - Add record
        // 2 - Edit record
        // 3 - Remove record
        // 4 - List all records
        // 5 - Query/Search
        // S - Save file
        // L - Load file
        // E - Exit
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

    // don't worry, we will notify you to save before you leave
    promptsave(inventory);

    return 0;
}

/** displaymenu()
 * 
 *  Sole purpose is to display the main menu. That's it really.
 * 
**/
void displaymenu()
{
    // Declarations
    tabulate::Table header;
    tabulate::Table select;

    // Add rows and format
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

    // Display
    cout << header << select << endl;
}