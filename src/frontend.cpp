#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace tabulate;

void promptsave(std::vector<BOOK> &inventory)
{
    Table savetable;
    bool loop = true;
    char option;

    savetable.add_row({"Save?"});
    savetable.add_row({"1) Yes"});
    savetable.add_row({"2) No"});

    do
    {
        std::cout << "\n\n"
                  << savetable << "\n\nPlease key in a value: ";
        std::cin >> option;

        switch (option)
        {
        case '1':
            writer(inventory);
            std::cout << "Save attempted.\n";
            loop = false;
            break;
        case '2':
            std::cout << "Okay.\n";
            loop = false;
            break;
        default:
            std::cout << "Invalid option! Please try again. \n\n";
        }
    } while (loop == true);
}

int addrecord(std::vector<BOOK> &inventory)
{
    Table addedentries;
    Table menutable;
    char option;
    BOOK newentry;
    std::string input;

    addedentries.add_row({"ISBN", "Author", "Title", "Publisher", "Year", "Price", "Quantity", "Rack", "Level", "Genre"});
    menutable.add_row({"Add Entry"});
    menutable.add_row({"1) Add more entries"});
    menutable.add_row({"2) Exit to menu"});

    do
    {
        std::cout << menutable
                  << "\n\nPlease type your option here: ";
        std::cin >> option;

        if (flush() == 1)
        {
            option = 'a';
        }

        switch (option)
        {
        case '1':
            std::cout << "\nISBN Code: ";
            std::cin >> input;
            validator(input, 1, 1);
            newentry.isbn = input;

            std::cout << "Author: ";
            std::cin >> input;
            newentry.author = input;

            std::cout << "Title: ";
            std::cin >> input;
            newentry.title = input;

            std::cout << "Publisher: ";
            std::cin >> input;
            newentry.publisher = input;

            std::cout << "Year Published: ";
            std::cin >> input;
            validator(input, 4, 1);
            newentry.year_published = std::stoi(input);

            std::cout << "Quantity: ";
            std::cin >> input;
            validator(input, 2, 1);
            newentry.quantity = std::stoi(input);

            std::cout << "Rack: ";
            std::cin >> input;
            validator(input, 2, 1);
            newentry.rack = std::stoi(input);

            std::cout << "Level: ";
            std::cin >> input;
            validator(input, 2, 1);
            newentry.level = std::stoi(input);

            std::cout << "Price: ";
            std::cin >> input;
            validator(input, 3, 1);
            newentry.price = std::stod(input);

            std::cout << "Genre: ";
            std::cin >> input;
            newentry.genre = input;

            std::cout << "\n";

            inventory.push_back(newentry);
            addedentries.add_row({newentry.isbn,
                                  newentry.author,
                                  newentry.title,
                                  newentry.publisher,
                                  std::to_string(newentry.year_published),
                                  std::to_string(newentry.price),
                                  std::to_string(newentry.quantity),
                                  std::to_string(newentry.rack),
                                  std::to_string(newentry.level),
                                  newentry.genre});

            break;

        case '2':
            std::cout << "\nExiting to main menu...";
            break;

        default:
            std::cout << "\nPlease key in either 1 or 2. \n\n";
        }

    } while (option != '2');

    std::cout << "Added entries as below: \n"
              << addedentries;

    return 0;
}

int removerecord(std::vector<BOOK> &inventory)
{
    Table removedentries;
    Table menutable;
    std::vector<BOOK>::iterator i = inventory.begin();
    char option;
    int entrynumber;

    removedentries.add_row({"ISBN", "Author", "Title", "Publisher", "Year", "Price", "Quantity", "Rack", "Level", "Genre"});
    menutable.add_row({"Remove Entry"});
    menutable.add_row({"1) Remove more entries"});
    menutable.add_row({"2) Exit to menu"});

    do
    {
        std::cout << menutable
                  << "\n\nPlease type your option here: ";
        std::cin >> option;

        if (flush() == 1)
        {
            option = 'a';
        }

        switch (option)
        {
        case '1':
            entrynumber = query(inventory, false);

            if (entrynumber == -1)
            {
                std::cout << "Search canceled.\n\n";
                break;
            }

            removedentries.add_row({inventory[entrynumber].isbn,
                                    inventory[entrynumber].author,
                                    inventory[entrynumber].title,
                                    inventory[entrynumber].publisher,
                                    std::to_string(inventory[entrynumber].year_published),
                                    std::to_string(inventory[entrynumber].price),
                                    std::to_string(inventory[entrynumber].quantity),
                                    std::to_string(inventory[entrynumber].rack),
                                    std::to_string(inventory[entrynumber].level),
                                    inventory[entrynumber].genre});
            advance(i, entrynumber);
            inventory.erase(i);

            break;

        case '2':
            std::cout << "\nExiting to main menu...\n";
            break;

        default:
            std::cout << "\nPlease key in either 1 or 2. \n\n";
        }

    } while (option != '2');

    std::cout << "Removed entries as below: \n"
              << removedentries;

    return 0;
}

int editrecord(std::vector<BOOK> &inventory)
{
    Table editedentries;
    Table menutable;
    char option;
    int entrynumber;
    BOOK editedentry;
    std::string input;

    editedentries.add_row({"ISBN", "Author", "Title", "Publisher", "Year", "Price", "Quantity", "Rack", "Level", "Genre"});
    menutable.add_row({"Edit Entry"});
    menutable.add_row({"1) Edit more entries"});
    menutable.add_row({"2) Exit to menu"});

    do
    {
        std::cout << menutable
                  << "\n\nPlease type your option here: ";
        std::cin >> option;

        if (flush() == 1)
        {
            option = 'a';
        }

        switch (option)
        {
        case '1':
            entrynumber = query(inventory, false);

            if (entrynumber == -1)
            {
                std::cout << "Search canceled.\n";
                break;
            }

            std::cout << "\nISBN Code: ";
            std::cin >> input;
            validator(input, 1, 1);
            editedentry.isbn = input;

            std::cout << "Author: ";
            std::cin >> input;
            editedentry.author = input;

            std::cout << "Title: ";
            std::cin >> input;
            editedentry.title = input;

            std::cout << "Publisher: ";
            std::cin >> input;
            editedentry.publisher = input;

            std::cout << "Year Published: ";
            std::cin >> input;
            validator(input, 4, 1);
            editedentry.year_published = std::stoi(input);

            std::cout << "Quantity: ";
            std::cin >> input;
            validator(input, 2, 1);
            editedentry.quantity = std::stoi(input);

            std::cout << "Rack: ";
            std::cin >> input;
            validator(input, 2, 1);
            editedentry.rack = std::stoi(input);

            std::cout << "Level: ";
            std::cin >> input;
            validator(input, 2, 1);
            editedentry.level = std::stoi(input);

            std::cout << "Price: ";
            std::cin >> input;
            validator(input, 3, 1);
            editedentry.price = std::stod(input);

            std::cout << "Genre: ";
            std::cin >> input;
            editedentry.genre = input;

            inventory[entrynumber] = editedentry;
            editedentries.add_row({editedentry.isbn,
                                   editedentry.author,
                                   editedentry.title,
                                   editedentry.publisher,
                                   std::to_string(editedentry.year_published),
                                   std::to_string(editedentry.price),
                                   std::to_string(editedentry.quantity),
                                   std::to_string(editedentry.rack),
                                   std::to_string(editedentry.level),
                                   editedentry.genre});

            std::cout << "\n";

            break;

        case '2':
            std::cout << "\nExiting to main menu...\n";
            break;

        default:
            std::cout << "\nPlease key in either 1 or 2. \n\n";
        }

    } while (option != '2');

    std::cout << "Edited entries as below: \n"
              << editedentries;

    return 0;
}

int listrecords(std::vector<BOOK> &inventory, bool showall, std::vector<int> &matched)
{
    int numberofmatch = matched.size();
    Table queriedresults;
    queriedresults.add_row({"ISBN", "Author", "Title", "Publisher", "Year", "Price", "Quantity", "Rack", "Level", "Genre"});

    if (showall)
    {
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            queriedresults.add_row({(*i).isbn,
                                    (*i).author,
                                    (*i).title,
                                    (*i).publisher,
                                    std::to_string((*i).year_published),
                                    std::to_string((*i).price),
                                    std::to_string((*i).quantity),
                                    std::to_string((*i).rack),
                                    std::to_string((*i).level),
                                    (*i).genre});
        }
    }
    else
    {
        for (int i = 0; i < numberofmatch; i++)
        {
            queriedresults.add_row({inventory[matched[i]].isbn,
                                    inventory[matched[i]].author,
                                    inventory[matched[i]].title,
                                    inventory[matched[i]].publisher,
                                    std::to_string(inventory[matched[i]].year_published),
                                    std::to_string(inventory[matched[i]].price),
                                    std::to_string(inventory[matched[i]].quantity),
                                    std::to_string(inventory[matched[i]].rack),
                                    std::to_string(inventory[matched[i]].level),
                                    inventory[matched[i]].genre});
        }
    }

    std::cout << queriedresults << std::endl;
    return 0;
}

int query(std::vector<BOOK> &inventory, bool allowmultiple)
{

    int numberofmatches;
    char repeat_search = NULL;
    std::vector<int> matched = std::vector<int>();
    bool loop;

    do
    {
        loop = true;
        if (repeat_search == '1')
        {
            matched = std::vector<int>();
        }

        numberofmatches = searchfunc(inventory, matched);
        system("CLS");

        if (numberofmatches == 0)
        {
            std::cout << "No results available, please try again." << std::endl;
        }
        else
        {
            listrecords(inventory, 0, matched);
        }

        do
        {
            if (numberofmatches < 2)
            {
                std::cout << "Options - 1) Do another search\n"
                          << "        - 3) Exit\n"
                          << "Your choice: ";
            }
            else
            {
                std::cout << "Options - 1) Do another search\n"
                          << "        - 2) Narrow down the search\n"
                          << "        - 3) Exit\n"
                          << "Your choice: ";
            }

            std::cin >> repeat_search;

            if (flush() == 1)
            {
                repeat_search = '4';
            }

            switch (repeat_search)
            {
            case '1':
            case '3':
                loop = false;
                break;
            case '2':
                if (numberofmatches > 2)
                {
                    loop = false;
                    break;
                }
            default:
                std::cout << "Invalid option. Please try again.";
            }
        } while (loop == true);

        if (allowmultiple = false)
        {
            std::cout << "Do proceed to narrow down the result to one entry only.";
            repeat_search = '2';
        }

    } while (repeat_search != '3');

    return matched.size() ? matched[0] : -1;
}