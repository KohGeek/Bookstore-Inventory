#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ios>
#include <limits>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace tabulate;

/** promptsave(BOOK)
 * 
 *  The following function is used to pester the user everytime any change is made so that no changes are lost.
 * 
**/
void promptsave(std::vector<BOOK> &inventory)
{
    Table savetable;
    bool loop = true;
    char option;

    savetable.add_row({"Save?"});
    savetable.add_row({"1) Yes"});
    savetable.add_row({"2) No"});

    // the following loop is for input validation purpose solely
    do
    {
        std::cout << "\n\n"
                  << savetable << "\n\nPlease key in a value: ";
        std::cin >> option;

        if (flush() == 1)
        {
            option = '3';
        }

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

/** addrecord(BOOK)
 * 
 *  Allows user to add record, and displays to the user what record is added in the end.
 * 
**/
int addrecord(std::vector<BOOK> &inventory)
{
    Table menutable;
    char option;
    BOOK newentry;
    std::vector<BOOK> newentries;
    std::string input;

    menutable.add_row({"Add Entry"});
    menutable.add_row({"1) Add more entries"});
    menutable.add_row({"2) Exit to menu"});

    // Similarly, such a loop is used for input validation
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
            std::getline(std::cin, input);
            validator(input, 1, 1);
            newentry.isbn = input;

            std::cout << "Author: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            newentry.author = input;

            std::cout << "Title: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            newentry.title = input;

            std::cout << "Publisher: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            newentry.publisher = input;

            std::cout << "Year Published: ";
            std::getline(std::cin, input);
            validator(input, 4, 1);
            newentry.year_published = std::stoi(input);

            std::cout << "Quantity: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            newentry.quantity = std::stoi(input);

            std::cout << "Rack: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            newentry.rack = std::stoi(input);

            std::cout << "Level: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            newentry.level = std::stoi(input);

            std::cout << "Price: ";
            std::getline(std::cin, input);
            validator(input, 3, 1);
            newentry.price = std::stod(input);

            std::cout << "Genre: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            newentry.genre = input;

            std::cout << "\n";

            newentries.push_back(newentry);
            inventory.push_back(newentry);
            break;

        case '2':
            std::cout << "\nExiting to main menu...";
            break;

        default:
            std::cout << "\nPlease key in either 1 or 2. \n\n";
        }

    } while (option != '2');

    std::cout << "\nAdded entries as below: \n";
    listrecords(newentries, true, std::vector<int>());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

/** removerecord(BOOK)
 * 
 *  Allows user to remove record, and displays to the user what record is removed in the end.
 * 
**/
int removerecord(std::vector<BOOK> &inventory)
{
    Table menutable;
    std::vector<BOOK>::iterator i = inventory.begin();
    std::vector<BOOK> removedentries;
    char option;
    int entrynumber;

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

            removedentries.push_back(inventory[entrynumber]);
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

    std::cout << "\nRemoved entries as below: \n";
    listrecords(removedentries, true, std::vector<int>());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

/** editrecord(BOOK)
 * 
 *  Allows user to edit record, and displays to the user what record is edited in the end.
 * 
**/
int editrecord(std::vector<BOOK> &inventory)
{
    std::vector<BOOK> editedentries;
    Table menutable;
    char option;
    int entrynumber;
    BOOK editedentry;
    std::string input;

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
            std::getline(std::cin, input);
            validator(input, 1, 1);
            editedentry.isbn = input;

            std::cout << "Author: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            editedentry.author = input;

            std::cout << "Title: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            editedentry.title = input;

            std::cout << "Publisher: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            editedentry.publisher = input;

            std::cout << "Year Published: ";
            std::getline(std::cin, input);
            validator(input, 4, 1);
            editedentry.year_published = std::stoi(input);

            std::cout << "Quantity: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            editedentry.quantity = std::stoi(input);

            std::cout << "Rack: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            editedentry.rack = std::stoi(input);

            std::cout << "Level: ";
            std::getline(std::cin, input);
            validator(input, 2, 1);
            editedentry.level = std::stoi(input);

            std::cout << "Price: ";
            std::getline(std::cin, input);
            validator(input, 3, 1);
            editedentry.price = std::stod(input);

            std::cout << "Genre: ";
            std::getline(std::cin, input);
            validator(input, 5, 1);
            editedentry.genre = input;

            // Editing is replacing
            inventory[entrynumber] = editedentry;
            editedentries.push_back(editedentry);
            break;

        case '2':
            std::cout << "\nExiting to main menu...\n";
            break;

        default:
            std::cout << "\nPlease key in either 1 or 2. \n\n";
        }

    } while (option != '2');

    std::cout << "\nEdited entries as below: \n";
    listrecords(editedentries, true, std::vector<int>());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

/** listrecords(BOOK, bool showall, vector<int> matched)
 * 
 *  Allows user to list all records that is loaded into memory.
 *  Serves dual functions. Cam show all records, or list a selected list of records (presented through int vector) 
 *  Showall facilitates this
 * 
**/
int listrecords(std::vector<BOOK> &inventory, bool showall, std::vector<int> &matched)
{
    int numberofmatch = matched.size();
    Table queriedresults;
    queriedresults.add_row({"ISBN", "Author", "Title", "Publisher", "Year", "Price", "Quantity", "Rack", "Level", "Genre"});
    std::stringstream stream;
    std::string price;

    if (showall)
    {
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            stream.str(std::string());
            stream << std::fixed << std::setprecision(2) << (*i).price;
            price = stream.str();
            queriedresults.add_row({(*i).isbn,
                                    (*i).author,
                                    (*i).title,
                                    (*i).publisher,
                                    std::to_string((*i).year_published),
                                    price,
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
            stream.str(std::string());
            stream << std::fixed << std::setprecision(2) << inventory[matched[i]].price;
            price = stream.str();
            queriedresults.add_row({inventory[matched[i]].isbn,
                                    inventory[matched[i]].author,
                                    inventory[matched[i]].title,
                                    inventory[matched[i]].publisher,
                                    std::to_string(inventory[matched[i]].year_published),
                                    price,
                                    std::to_string(inventory[matched[i]].quantity),
                                    std::to_string(inventory[matched[i]].rack),
                                    std::to_string(inventory[matched[i]].level),
                                    inventory[matched[i]].genre});
        }
    }

    std::cout << queriedresults << std::endl;
    return 0;
}

/** query(BOOK, bool allowmultiple)
 * 
 *  Front end to search function.
 *  Helps to show, restart or narrow down searches.
 * 
**/
int query(std::vector<BOOK> &inventory, bool allowmultiple)
{

    int numberofmatches;
    char repeat_search = NULL;
    std::vector<int> matched = std::vector<int>();
    bool loop;

    // Unless all other do loops, this loop *is* intended tp repeat the query.
    do
    {
        // Resets the internal validator
        loop = true;

        // If user resets the search, then the search array/vector is reset.
        if (repeat_search == '1')
        {
            matched = std::vector<int>();
        }

        // Performs said searches
        numberofmatches = searchfunc(inventory, matched);
        system("CLS");

        // Tell the user if there's any result.
        if (numberofmatches == 0)
        {
            std::cout << "No results available, please try again." << std::endl;
        }
        else
        {
            listrecords(inventory, 0, matched);
        }

        //Check if user want to repeat or narrow the search
        do
        {
            if (numberofmatches < 2)
            {
                std::cout << "Options - 1) Do another search\n"
                          << "        - \n"
                          << "        - 3) Exit/Confirm\n"
                          << "Your choice: ";
            }
            else
            {
                std::cout << "Options - 1) Do another search\n"
                          << "        - 2) Narrow down the search\n"
                          << "        - 3) Exit/Confirm\n"
                          << "Your choice: ";
            }

            std::cin >> repeat_search;

            if (flush() == 1)
            {
                repeat_search = '4';
            }

            // 1 and 3 basically go back to the main loop, 2 depends.
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

        if (allowmultiple = false && repeat_search == '3' && matched.size() > 1)
        {
            std::cout << "Do proceed to narrow down the result to one entry only.";
            repeat_search = '2';
        }

    } while (repeat_search != '3');

    // Is there any matches? If yes, return the first match. If not, say no.
    return matched.size() ? matched[0] : -1;
}