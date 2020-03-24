#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <vector>

#include <algorithm>

#include <string>
#include <string.h>
#include <stdio.h>

#include "tabulate/table.hpp"
#include "fileio.hpp"

std::vector<BOOK> inventory;

using namespace tabulate;

//func prototype
void option_1();
void option_2();
void option_3();
void option_4();

int main()
{

    int option;

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
            option_1();
        }

        //Delete Data
        else if (option == 2)
        {
            option_2();
        }

        //Edit Data
        else if (option == 3)
        {
            option_3();
        }

        //Search Data
        else if (option == 4)
        {
            option_4();
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

void option_1()
{
    system("CLS");
    std::cout << "Press any key to continue...";
    getch();
    system("CLS");
}

void option_2()
{
    system("CLS");
    std::cout << "Press any key to continue...";
    getch();
    system("CLS");
}

void option_3()
{
    system("CLS");
    std::cout << "Press any key to continue...";
    getch();
    system("CLS");
}

void option_4()
{
    bool check_search(true);
    while (check_search)
    {
        //declaring variables
        int search_no;

        //clear screen
        system("CLS");

        //Search Table

        Table search;
        search.add_row({"Advanced Search"});
        search.add_row({"1) ISBN"});
        search.add_row({"2) Author"});
        search.add_row({"3) Title"});

        //styling
        search[0].format().font_background_color(Color::magenta).font_style({FontStyle::bold}).border_top(" ").border_bottom(" ").border_left(" ").border_right(" ").corner(" ").padding_top(1).padding_bottom(1);
        std::cout << search << std::endl;

        //asking
        std::cout << "How you want to search?" << std::endl;
        std::cout << "(Type in the relative number?)" << std::endl;
        std::cin >> search_no;

        //user_input
        std::string isbn_input;
        std::string author_input;
        std::string title_input;

        //change in value
        std::string isbn_change;
        std::string author_change;
        std::string title_change;
        std::string publisher_change;
        std::string year_change;
        std::string price_change;
        std::string quantity_change;
        std::string rack_change;
        std::string level_change;
        std::string genre_change;

        //formula
        if (search_no == 1)
        {
            bool check1(true);
            while (check1)
            {

                std::cout << "Pls enter relevant isbn code: ";
                std::cin >> isbn_input;

                for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
                {

                    isbn_change = (*i).isbn;
                    author_change = (*i).author;
                    title_change = (*i).title;
                    publisher_change = (*i).publisher;
                    year_change = std::to_string((*i).year_published);
                    price_change = std::to_string((*i).price);
                    quantity_change = std::to_string((*i).quantity);
                    rack_change = std::to_string((*i).rack);
                    level_change = std::to_string((*i).level);
                    genre_change = (*i).genre;

                    if (strstr(isbn_change.c_str(), isbn_input.c_str()))
                    {
                        std::cout << "ISBN : " << isbn_change << std::endl;
                        std::cout << "Author : " << author_change << std::endl;
                        std::cout << "Title : " << title_change << std::endl;
                        std::cout << "Publisher : " << publisher_change << std::endl;
                        std::cout << "Year Published : " << year_change << std::endl;
                        std::cout << "Price : " << price_change << std::endl;
                        std::cout << "Quantity : " << quantity_change << std::endl;
                        std::cout << "Rack : " << rack_change << std::endl;
                        std::cout << "Level : " << level_change << std::endl;
                        std::cout << "Genre : " << genre_change << std::endl;
                        check1 = false;

                        //ask if still want advanced search
                        int choose_as;
                        std::cout << "Do you want to continue advanced search? (0 if no / 1 if yes)";
                        std::cin >> choose_as;
                        if (choose_as == 1)
                        {
                            check_search = true;
                            break;
                        }

                        else
                        {
                            check_search = false;
                            system("CLS");
                            break;
                        }
                    }

                    else
                    {
                        std::cout << "Pls enter smtg else !!" << std::endl;
                        break;
                    }
                }
            }
        }

        if (search_no == 2)
        {
            bool check2(true);
            while (check2)
            {
                std::cout << "Pls enter relevant author: ";
                std::cin.ignore();

                //
                std::getline(std::cin, author_input);
                for_each(author_input.begin(), author_input.end(), [](char &a) {
                    a = ::toupper(a);
                }); // done

                for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
                {

                    isbn_change = (*i).isbn;
                    author_change = (*i).author;
                    title_change = (*i).title;
                    publisher_change = (*i).publisher;
                    year_change = std::to_string((*i).year_published);
                    price_change = std::to_string((*i).price);
                    quantity_change = std::to_string((*i).quantity);
                    rack_change = std::to_string((*i).rack);
                    level_change = std::to_string((*i).level);
                    genre_change = (*i).genre;

                    //change to lowercase
                    for_each(author_change.begin(), author_change.end(), [](char &b) {
                        b = ::toupper(b);
                    }); //done

                    if (strstr(author_change.c_str(), author_input.c_str()))
                    {
                        std::cout << "ISBN : " << isbn_change << std::endl;
                        std::cout << "Author : " << author_change << std::endl;
                        std::cout << "Title : " << title_change << std::endl;
                        std::cout << "Publisher : " << publisher_change << std::endl;
                        std::cout << "Year Published : " << year_change << std::endl;
                        std::cout << "Price : " << price_change << std::endl;
                        std::cout << "Quantity : " << quantity_change << std::endl;
                        std::cout << "Rack : " << rack_change << std::endl;
                        std::cout << "Level : " << level_change << std::endl;
                        std::cout << "Genre : " << genre_change << std::endl;
                        check2 = false;

                        //ask if still want advanced search
                        int choose_as;
                        std::cout << "Do you want to continue advanced search? (0 if no / 1 if yes)";
                        std::cin >> choose_as;
                        if (choose_as == 1)
                        {
                            check_search = true;
                            break;
                        }

                        else
                        {
                            check_search = false;
                            system("CLS");
                            break;
                        }
                    }

                    else
                    {
                        std::cout << "Pls enter smtg else !!" << std::endl;
                        break;
                    }
                }
            }
        }

        if (search_no == 3)
        {
            bool check3(true);
            while (check3)
            {
                std::cout << "Pls enter relevant book title: ";
                std::cin.ignore();

                //
                std::getline(std::cin, title_input);
                for_each(title_input.begin(), title_input.end(), [](char &c) {
                    c = ::toupper(c);
                }); // done

                for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
                {

                    isbn_change = (*i).isbn;
                    author_change = (*i).author;
                    title_change = (*i).title;
                    publisher_change = (*i).publisher;
                    year_change = std::to_string((*i).year_published);
                    price_change = std::to_string((*i).price);
                    quantity_change = std::to_string((*i).quantity);
                    rack_change = std::to_string((*i).rack);
                    level_change = std::to_string((*i).level);
                    genre_change = (*i).genre;

                    //change to lowercase
                    for_each(title_change.begin(), title_change.end(), [](char &d) {
                        d = ::toupper(d);
                    }); // done

                    if (strstr(title_change.c_str(), title_input.c_str()))
                    {
                        std::cout << "ISBN : " << isbn_change << std::endl;
                        std::cout << "Author : " << author_change << std::endl;
                        std::cout << "Title : " << title_change << std::endl;
                        std::cout << "Publisher : " << publisher_change << std::endl;
                        std::cout << "Year Published : " << year_change << std::endl;
                        std::cout << "Price : " << price_change << std::endl;
                        std::cout << "Quantity : " << quantity_change << std::endl;
                        std::cout << "Rack : " << rack_change << std::endl;
                        std::cout << "Level : " << level_change << std::endl;
                        std::cout << "Genre : " << genre_change << std::endl;
                        check3 = false;

                        //ask if still want advanced search
                        int choose_as;
                        std::cout << "Do you want to continue advanced search? (0 if no / 1 if yes) : ";
                        std::cin >> choose_as;
                        if (choose_as == 1)
                        {
                            check_search = true;
                            break;
                        }

                        else
                        {
                            check_search = false;
                            system("CLS");
                            break;
                        }
                    }

                    else
                    {
                        std::cout << "Pls enter smtg else !!" << std::endl;
                        break;
                    }
                }
            }
        }
    }
}