#ifndef FILEIO_HPP
#define FILEIO_HPP

#include "csv/reader.hpp"
#include "csv/writer.hpp"
#include "nana/gui.hpp"
#include "nana/gui/filebox.hpp"
#include "nana/gui/widgets/label.hpp"
#include "nana/gui/widgets/textbox.hpp"
#include "nana/gui/widgets/button.hpp"

struct BOOK
{
    std::string isbn;
    std::string author;
    std::string title;
    std::string publisher;
    int year_published;
    int quantity;
    int rack;
    int level;
    double price;
    std::string genre;
};

extern BOOK inventory[1000];

int reader(void);
int writer(void);

#endif