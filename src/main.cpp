#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include <sstream>
#include <string.h>
#include <stdio.h>

#include "tabulate/table.hpp"

using namespace tabulate;

int main()
{

     //declaring variables
     int option, search_no;

     //declaring strings
     std::string isbn_code;
     std::string author_name;
     std::string book_title;
     std::string publisher_name;
     std::string year_of_publish;
     std::string price_of_book;
     std::string quantity_of_books;
     std::string location_of_books1;
     std::string location_of_books2;

     //decalring arrays
     std::string isbn[20];
     std::string author[20];
     std::string title[20];
     std::string publisher[20];
     int year_publish[20];
     double price[20];
     int quantity[20];
     std::string location1[20];
     std::string location2[20];

     int i = 0;

     std::ifstream inputfile("doc\\inventory.txt");

     while (!inputfile){
          std::cout << "fucking file not exist" << std::endl;
     }

     while (!inputfile.eof())
     {
          getline(inputfile, isbn_code, ',');
          isbn[i] = isbn_code;

          getline(inputfile, author_name, ',');
          author[i] = author_name;

          getline(inputfile, book_title, ',');
          title[i] = book_title;

          getline(inputfile, publisher_name, ',');
          publisher[i] = publisher_name;

          getline(inputfile, year_of_publish, ',');
          year_publish[i] = std::stoi(year_of_publish);

          getline(inputfile, price_of_book, ',');
          price[i] = std::stod(price_of_book);

          getline(inputfile, quantity_of_books, ',');
          quantity[i] = std::stoi(quantity_of_books);

          getline(inputfile, location_of_books1, ',');
          location1[i] = location_of_books1;

          getline(inputfile, location_of_books2, '\n');
          location2[i] = location_of_books2;

          i += 1;
     }

     std::cout << i << std::endl;
     for (int j = 0; j < (i - 1); j++)
     {
          std::cout << isbn[j] << '\t' << author[j] << '\t' << title[j] << '\t' << publisher[j] << '\t' << year_publish[j] << '\t' << price[j] << '\t' << quantity[j] << '\t' << location1[j] << '\t' << location2[j] << std::endl;
     }

     while (true)
     {

          //header
          Table header;
          header.add_row({"Book Inventory System"});

          header.format()
              .font_style({FontStyle::bold})
              .border_top(" ")
              .border_bottom(" ")
              .border_left(" ")
              .border_right(" ")
              .corner(" ")
              .padding_top(1)
              .padding_bottom(1)
              .font_background_color(Color::cyan);

          std::cout << header << std::endl;
          //header

          //selection
          Table select;

          select.add_row({"1) Add"});
          select.add_row({"2) Edit"});
          select.add_row({"3) Delete"});
          select.add_row({"4) Search"});

          std::cout << select << std::endl;
          std::cout << "Choose your options : " << std::endl;
          std::cin >> option;

          //Add data
          if (option == 1)
          {
               system("CLS");
               std::cout << "Press any key to continue...";
               getch();
               system("CLS");
          }

          //Delete Data
          else if (option == 2)
          {
               system("CLS");
               std::cout << "Press any key to continue...";
               getch();
               system("CLS");
          }

          //Edit Data
          else if (option == 3)
          {
               system("CLS");
               std::cout << "Press any key to continue...";
               getch();
               system("CLS");
          }

          //Search Data
          else if (option == 4)
          {
               system("CLS");

               //Search Table
               Table search;
               search.add_row({"Advanced Search"});
               search.add_row({"1) ISBN"});
               search.add_row({"2) Author"});
               search.add_row({"3) Title"});
               search.add_row({"4) Publisher"});
               search.add_row({"5) Year Publish"});
               search.add_row({"6) Quantity"});
               search.add_row({"7) Price"});
               search.add_row({"8) Location"});

               search[0].format().font_background_color(Color::magenta).font_style({FontStyle::bold}).border_top(" ").border_bottom(" ").border_left(" ").border_right(" ").corner(" ").padding_top(1).padding_bottom(1);

               std::cout << search << std::endl;
               std::cout << "How you want to search?" << std::endl;
               std::cout << "(Type in the relative number?)" << std::endl;
               std::cin >> search_no;
               //search table

               std::ifstream in_file("inventory.txt", std::ios::out);
               in_file.close();

               getch();
               system("CLS");
          }

          //error checking (menu)
          else
          {
               system("CLS");
               std::cout << "Error pls input value between 1 to 4";
               getch();
               system("CLS");
          }
     }

     std::cout << "Click Pause";

}