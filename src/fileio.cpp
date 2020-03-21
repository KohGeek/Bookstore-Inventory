#include <iostream>
#include <vector>
#include <windows.h>

#include "csv/reader.hpp"
#include "csv/writer.hpp"
#include "fileio.hpp"

int reader(void)
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

    for (int i = 0; csvparse.busy();)
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
            i++;
        }
    }

    return 0;
}

int writer(void)
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