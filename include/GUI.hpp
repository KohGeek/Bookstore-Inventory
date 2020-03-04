#ifndef GUI_HPP
#define GUI_HPP

#include <string>

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
    char genre;
};

void GUI(void);

#endif