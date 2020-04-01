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

int reader(std::vector<BOOK> &inventory);
int writer(std::vector<BOOK> &inventory);

int validator(std::string validated, int type);

void displaymenu();
int searchfunc(std::vector<BOOK> &inventory, std::vector<int> &matched);

int addrecord(std::vector<BOOK> &inventory);
int removerecord(std::vector<BOOK> &inventory);
int editrecord(std::vector<BOOK> &inventory);
int listrecords(std::vector<BOOK> &inventory, bool showall, std::vector<int> &matched);
int query(std::vector<BOOK> &inventory, bool allowmultiple);

#endif