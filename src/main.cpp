#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <vector>

#include <string.h>
#include <stdio.h>

#include "tabulate/table.hpp"
#include "fileio.hpp"

std::vector<BOOK> inventory;

using namespace tabulate;

int main()
{

    int option, search_no;

    while (true)
    {

        //header
        Table header;
        header.add_row({"Book Inventory System"});

        header.format()
            .font_style({FontStyle::bold})
            .border_top(" ")
            .border_bottom(" ")
            .border_left(" ")
            .border_right(" ")
            .corner(" ")
            .padding_top(1)
            .padding_bottom(1)
            .font_background_color(Color::cyan);

        std::cout << header << std::endl;
        //header

        //selection
        Table select;

        select.add_row({"1) Add"});
        select.add_row({"2) Edit"});
        select.add_row({"3) Delete"});
        select.add_row({"4) Search"});

        std::cout << select << std::endl;
        std::cout << "Choose your options : " << std::endl;
        std::cin >> option;

        reader();

        //Add data
        if (option == 1)
        {
            system("CLS");
            std::cout << "Press any key to continue...";
            getch();
            system("CLS");
        }

        //Delete Data
        else if (option == 2)
        {
            system("CLS");
            std::cout << "Press any key to continue...";
            getch();
            system("CLS");
        }

        //Edit Data
        else if (option == 3)
        {
            system("CLS");
            std::cout << "Press any key to continue...";
            getch();
            system("CLS");
        }

        //Search Data
        else if (option == 4)
        {
            system("CLS");

            //Search Table
            Table search;
            search.add_row({"Advanced Search"});
            search.add_row({"1) ISBN"});
            search.add_row({"2) Author"});
            search.add_row({"3) Title"});
            search.add_row({"4) Publisher"});
            search.add_row({"5) Year Publish"});
            search.add_row({"6) Quantity"});
            search.add_row({"7) Price"});
            search.add_row({"8) Location"});

            search[0].format().font_background_color(Color::magenta).font_style({FontStyle::bold}).border_top(" ").border_bottom(" ").border_left(" ").border_right(" ").corner(" ").padding_top(1).padding_bottom(1);

            std::cout << search << std::endl;
            std::cout << "How you want to search?" << std::endl;
            std::cout << "(Type in the relative number?)" << std::endl;
            std::cin >> search_no;
            //search table

            getch();
            system("CLS");
        }

        //error checking (menu)
        else
        {
            system("CLS");
            std::cout << "Error pls input value between 1 to 4";
            getch();
            system("CLS");
        }
    }

    std::cout << "Click Pause";
}