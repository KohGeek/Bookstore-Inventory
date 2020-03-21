#ifndef FILEIO_HPP
#define FILEIO_HPP

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

extern std::vector<BOOK> inventory;

int reader(void);
int writer(void);

#endif