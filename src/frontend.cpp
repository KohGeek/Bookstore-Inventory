#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

#include "tabulate/table.hpp"
#include "core.hpp"

using namespace tabulate;

int addrecord(std::vector<BOOK> &inventory)
{
    return 0;
}

int removerecord(std::vector<BOOK> &inventory)
{
    return 0;
}

int editrecord(std::vector<BOOK> &inventory)
{
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

    while (repeat_search != '3')
    {
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

        if (numberofmatches < 2)
        {
            std::cout << "Options - 1) Do another search\n"
                      << "        - 3) Exit\n"
                      << "Your choice: ";
            std::cin >> repeat_search;
        }
        else
        {
            std::cout << "Options - 1) Do another search\n"
                      << "        - 2) Narrow down the search\n"
                      << "        - 3) Exit\n"
                      << "Your choice: ";
            std::cin >> repeat_search;
        }
    }

    return matched.size() ? matched[0] : 0;
}