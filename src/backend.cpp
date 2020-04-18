#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <regex>

#include "csv/reader.hpp"
#include "csv/writer.hpp"
#include "tabulate/table.hpp"
#include "core.hpp"

int searchfunc(std::vector<BOOK> &inventory, std::vector<int> &matched)
{
    std::string userquery;
    std::vector<int> matches;
    std::regex matchpattern;
    bool hackloop = true;
    char search_no = NULL;
    int counter = 0;

    //Search Table
    tabulate::Table searchinfo;
    searchinfo.add_row({"Search"});
    searchinfo.add_row({"1) ISBN"});
    searchinfo.add_row({"2) Author"});
    searchinfo.add_row({"3) Title"});
    searchinfo.add_row({"4) Genre"});

    //styling
    searchinfo[0].format().font_background_color(tabulate::Color::magenta).font_style({tabulate::FontStyle::bold}).border_top(" ").border_bottom(" ").border_left(" ").border_right(" ").corner(" ").padding_top(1).padding_bottom(1);

    //asking
    std::cout << searchinfo << std::endl;
    std::cout << "How you want to search?" << std::endl;
    std::cout << "(Type in the relative number?)" << std::endl;

    do
    {
        std::cin >> search_no;

        switch (search_no)
        {
        case '1':
            std::cout << "Please enter ISBN code (full or partial):";
            hackloop = false;
            break;
        case '2':
            std::cout << "Please enter author name (full or partial):";
            hackloop = false;
            break;
        case '3':
            std::cout << "Please enter book title(full or partial):";
            hackloop = false;
            break;
        case '4':
            std::cout << "Please enter genre name(full or partial):";
            hackloop = false;
            break;
        default:
            std::cout << searchinfo << std::endl;
            std::cout << "Please key in a number between 1 to 4:" << std::endl;
        }

        std::cin >> userquery;

    } while (hackloop);

    matchpattern = std::regex(userquery, std::regex_constants::extended | std::regex_constants::icase);

    switch (search_no)
    {
    case '1':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search((*i).isbn, matchpattern))
                matches.push_back(counter);

            counter++;
        }
        break;
    case '2':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search((*i).author, matchpattern))
                matches.push_back(counter);

            counter++;
        }
        break;
    case '3':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search((*i).title, matchpattern))
                matches.push_back(counter);

            counter++;
        }
        break;
    case '4':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search((*i).genre, matchpattern))
                matches.push_back(counter);

            counter++;
        }
        break;
    }

    if (matched.size() > 0)
    {
        for (auto i : matches)
        {
            auto matching = std::find(matched.begin(), matched.end(), i);
            if (matching == matched.end())
            {
                matches.erase(matching);
            }
        }
    }

    matched = matches;

    return matched.size();
}

/** what to validate?
  * ISBN - 1
  * quantity - 2
  * level/rack - 3
  * price - 4
**/
int validator(std::string validated, int type)
{
    int error_state = 0;
    switch (type)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

int reader(std::vector<BOOK> &inventory)
{

    char filename[MAX_PATH];
    BOOK temp;

    csv::Reader csvparse;

    csvparse.configure_dialect("assignment")
        .header(false)
        .skip_empty_rows(true)
        .column_names("ISBN", "Author", "Title", "Publisher", "YearPublished", "Price", "Quantity", "Rack", "Level", "Genre");

    OPENFILENAME ofndialog;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofndialog, sizeof(ofndialog));
    ofndialog.lStructSize = sizeof(ofndialog);
    ofndialog.hwndOwner = NULL;
    ofndialog.lpstrFilter = "Text Files (*.txt;*.csv)\0*.txt;*.csv\0Any File (*.*)\0*.*\0\0";
    ofndialog.lpstrFile = filename;
    ofndialog.lpstrFileTitle = "inventory.csv";
    ofndialog.lpstrInitialDir = NULL;
    ofndialog.nMaxFile = MAX_PATH;
    ofndialog.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (!GetOpenFileNameA(&ofndialog))
    {
        switch (CommDlgExtendedError())
        {
        case CDERR_DIALOGFAILURE:
            std::cout << "CDERR_DIALOGFAILURE\n";
            break;
        case CDERR_INITIALIZATION:
            std::cout << "CDERR_INITIALIZATION\n";
            break;
        case FNERR_INVALIDFILENAME:
            std::cout << "FNERR_INVALIDFILENAME\n";
            break;
        default:
            std::cout << "You cancelled.\n";
        }

        return 1;
    }

    csvparse.read(filename);

    while (csvparse.busy())
    {
        if (csvparse.ready())
        {
            auto row = csvparse.next_row();
            temp.isbn = row["ISBN"];
            temp.author = row["Author"];
            temp.title = row["Title"];
            temp.publisher = row["Publisher"];
            temp.year_published = std::stoi(row["YearPublished"]);
            temp.price = std::stod(row["Price"]);
            temp.quantity = std::stoi(row["Quantity"]);
            temp.rack = std::stoi(row["Rack"]);
            temp.level = std::stoi(row["Level"]);
            temp.genre = row["Genre"];
            inventory.push_back(temp);
        }
    }

    return 0;
}

int writer(std::vector<BOOK> &inventory)
{

    char filename[MAX_PATH];

    csv::Writer csvWriter(filename);

    csvWriter.configure_dialect()
        .delimiter(",")
        .column_names("ISBN", "Author", "Title", "Publisher", "YearPublished", "Price", "Quantity", "Rack", "Level", "Genre");

    OPENFILENAME ofndialog;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofndialog, sizeof(ofndialog));
    ofndialog.lStructSize = sizeof(ofndialog);
    ofndialog.hwndOwner = NULL;
    ofndialog.lpstrFilter = "Text Files (*.txt;*.csv)\0*.txt;*.csv\0Any File (*.*)\0*.*\0\0";
    ofndialog.lpstrFile = filename;
    ofndialog.lpstrTitle = "Save As";
    ofndialog.lpstrFileTitle = "inventory.csv";
    ofndialog.lpstrInitialDir = NULL;
    ofndialog.nMaxFile = MAX_PATH;
    ofndialog.Flags = OFN_DONTADDTORECENT | OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT;

    if (!GetOpenFileNameA(&ofndialog))
    {
        switch (CommDlgExtendedError())
        {
        case CDERR_DIALOGFAILURE:
            std::cout << "CDERR_DIALOGFAILURE\n";
            break;
        case CDERR_INITIALIZATION:
            std::cout << "CDERR_INITIALIZATION\n";
            break;
        case FNERR_INVALIDFILENAME:
            std::cout << "FNERR_INVALIDFILENAME\n";
            break;
        default:
            std::cout << "You cancelled.\n";
        }
        return 1;
    }

    for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
    {
        csvWriter.write_row(
            (*i).isbn,
            (*i).author,
            (*i).title,
            (*i).publisher,
            std::to_string((*i).year_published),
            std::to_string((*i).price),
            std::to_string((*i).quantity),
            std::to_string((*i).rack),
            std::to_string((*i).level),
            (*i).genre);
    }

    csvWriter.close();

    return 0;
}