#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <regex>
#include <conio.h>

#include "csv/reader.hpp"
#include "csv/writer.hpp"
#include "tabulate/table.hpp"
#include "core.hpp"

/** flush()
 *
 * flush() is used to clear input buffer in a safe and clean manner
 * by looping through the input buffer. Additional value can be returned
 * to help validate input.
 *
**/
int flush()
{
    int hasextra = 0;
    char s;
    while ((s = fgetc(stdin)) != '\n' && s != EOF)
        hasextra = 1;
    return hasextra;
}

int searchfunc(std::vector<BOOK> &inventory, std::vector<int> &matched)
{
    std::string userquery;
    std::vector<int> matches;
    std::regex matchpattern;
    bool loopcheck = true;
    char search_no = NULL;
    int counter = 0;

    //Search Table
    tabulate::Table searchinfo;
    searchinfo.add_row({"Search"});
    searchinfo.add_row({"1) ISBN"});
    searchinfo.add_row({"2) Author"});
    searchinfo.add_row({"3) Title"});
    searchinfo.add_row({"4) Genre"});
    searchinfo.add_row({"5) Rack"});
    searchinfo.add_row({"6) Level"});

    //styling
    searchinfo[0].format().font_background_color(tabulate::Color::magenta).font_style({tabulate::FontStyle::bold}).border_top(" ").border_bottom(" ").border_left(" ").border_right(" ").corner(" ").padding_top(1).padding_bottom(1);

    //asking
    std::cout << searchinfo << std::endl;
    std::cout << "How you want to search?" << std::endl;
    std::cout << "(Type in the relative number?)" << std::endl;

    do
    {
        std::cin >> search_no;

        if (flush() == 1)
        {
            search_no = '5';
        }

        switch (search_no)
        {
        case '1':
            std::cout << "Please enter ISBN code (full or partial):";
            loopcheck = false;
            break;
        case '2':
            std::cout << "Please enter author name (full or partial):";
            loopcheck = false;
            break;
        case '3':
            std::cout << "Please enter book title (full or partial):";
            loopcheck = false;
            break;
        case '4':
            std::cout << "Please enter genre name (full or partial):";
            loopcheck = false;
            break;
        case '5':
            std::cout << "Please enter the rack number (full or partial):";
            loopcheck = false;
            break;
        case '6':
            std::cout << "Please enter the level number (full or partial):";
            loopcheck = false;
            break;
        default:
            std::cout << searchinfo << std::endl;
            std::cout << "Please key in a number between 1 to 4:" << std::endl;
        }

        std::cin >> userquery;

    } while (loopcheck);

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
    case '5':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search(std::to_string((*i).rack), matchpattern))
                matches.push_back(counter);

            counter++;
        }
        break;
    case '6':
        for (auto i = inventory.cbegin(); i != inventory.cend(); i++)
        {
            if (std::regex_search(std::to_string((*i).level), matchpattern))
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

// if return true then contains non-numerics
bool intchecker(std::string checked)
{
    return checked.find_first_not_of("0123456789") != std::string::npos;
}

/** what to validate?
  * ISBN - 1
  * quantity/level/rack - 2
  * price - 3
  * year - 4
  * others - 5
  * Error state meanings:
  *    0 - all clear
  *    1 - length not accepted
  *    2 - non-numeric
  *    3 - empty
  *    4 - out of range
**/
int validator(std::string &validated, int type, bool user)
{
    int error_state;
    bool hasdecimal;

    do
    {
        error_state = 0;

        if (validated.empty() == true)
        {
            error_state = 3;
        }
        else
        {
            hasdecimal = FALSE;

            switch (type)
            {
            case 1:
                if (validated.length() != 10 && validated.length() != 13)
                {
                    error_state = 1;
                }
                else if (intchecker(validated))
                {
                    error_state = 2;
                }
                break;
            case 2:
                if (intchecker(validated))
                {
                    error_state = 2;
                }
                break;
            case 3:
                for (int i = 0; i < validated.length(); i++)
                {
                    if (isdigit(validated[i]) == 0)
                    {
                        if (i != 0 && validated[i] == '.' && hasdecimal == 0)
                        {
                            hasdecimal = 1;
                            continue;
                        }
                        error_state = 2;
                    }
                }
                break;
            case 4:
                if (stoi(validated) < 0 || stoi(validated) > 3000)
                {
                    error_state = 4;
                }
                else if (intchecker(validated))
                {
                    error_state = 2;
                }
            }
        }

        if (user == 1)
        {
            switch (error_state)
            {
            case 1:
                std::cout << "Incorrect length! ISBN must be 10 or 13 digits. Please try again: ";
                break;
            case 2:
                std::cout << "Number keyed in is not accepted/is not a number! Please try again: ";
                break;
            case 3:
                std::cout << "You didn't type anything? Please try again: ";
                break;
            case 4:
                std::cout << "Not a valid year! Please try again: ";
                break;
            }

            if (error_state != 0)
            {
                std::cin >> validated;
            }
        }

    } while (user == 1 && error_state != 0);

    return error_state;
}

int reader(std::vector<BOOK> &inventory)
{

    char filename[MAX_PATH];
    int counter = 1;
    std::vector<int> skipped;
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

            if (validator(row["ISBN"], 1, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.isbn = row["ISBN"];
            }
            temp.author = row["Author"];

            temp.title = row["Title"];
            temp.publisher = row["Publisher"];

            if (validator(row["YearPublished"], 4, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.year_published = std::stoi(row["YearPublished"]);
            }

            if (validator(row["Price"], 3, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.price = std::stod(row["Price"]);
            }

            if (validator(row["Quantity"], 2, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.quantity = std::stoi(row["Quantity"]);
            }

            if (validator(row["Rack"], 2, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.rack = std::stoi(row["Rack"]);
            }

            if (validator(row["Level"], 2, 0))
            {
                skipped.push_back(counter);
                continue;
            }
            else
            {
                temp.level = std::stoi(row["Level"]);
            }

            temp.genre = row["Genre"];
            inventory.push_back(temp);
        }
        counter++;
    }

    if (!skipped.empty())
    {
        std::cout << "The following entries, \n";
        for (auto i = skipped.cbegin(); i != skipped.cend(); i++)
        {
            std::cout << *i << std::endl;
        }
        std::cout << "have been omitted due to data error. Please verify them.";
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