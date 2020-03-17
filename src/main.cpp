#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <tabulate/table.hpp>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;


using namespace tabulate;

int main() {

//declaring variables
int option, search_no;

//declaring strings
	string isbn_code;
	string author_name;
	string book_title;
	string publisher_name;
	string year_of_publish;
	string price_of_book;
	string quantity_of_books;
	string location_of_books1;
	string location_of_books2;


	//decalring arrays	
	string isbn[20];
	string author[20];
	string title[20];
	string publisher[20];
	int year_publish[20];
	double price[20];
	int quantity[20];
	string location1[20];
	string location2[20];
	
	
	int i = 0;
	
	
	ifstream input("inventory.txt");
	
	while (!input.eof()) {
		getline(input, isbn_code, ',');
		isbn[i] = isbn_code;

		getline(input, author_name, ',');
		author[i] = author_name;

		getline(input, book_title, ',');
		title[i] = book_title;

		getline(input, publisher_name, ',');
		publisher[i] = publisher_name;

		getline(input, year_of_publish, ',');
		year_publish[i] = stoi(year_of_publish);

		getline(input, price_of_book, ',');
		price[i] = stod(price_of_book);

		getline(input, quantity_of_books, ',');
		quantity[i] = stoi(quantity_of_books);

		getline(input, location_of_books1, ',');
		location1[i] = location_of_books1;

		getline(input, location_of_books2, '\n');
		location2[i] = location_of_books2;

		i += 1;
	}
	
	cout << i << endl;
	for (int j = 0; j < (i-1); j++)
	{
		cout << isbn[j] << '\t'<< author[j] << '\t' << title[j] << '\t'<<  publisher[j] << '\t' << year_publish[j] << '\t' << price[j] << '\t' << quantity[j] << '\t' << location1[j] << '\t' << location2[j] << endl;
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

 cout << header <<endl;
 //header

 
 //selection
 Table select;

 select.add_row({"1) Add"});
 select.add_row({"2) Edit"});
 select.add_row({"3) Delete"});
 select.add_row({"4) Search"});

cout << select <<endl;
cout << "Choose your options : " << endl;
cin >> option;


 //Add data
    if (option == 1)
    {
         system("CLS");
         cout << "Press any key to continue...";
         getch();
         system("CLS");
    }

    
   
    //Delete Data
    else if (option == 2)
    {
         system("CLS");
         cout << "Press any key to continue...";
         getch();
         system("CLS");
    }

    
    //Edit Data
    else if (option == 3)
    {
         system("CLS");
         cout << "Press any key to continue...";
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


          search[0].format()
          .font_background_color(Color::magenta)
          .font_style({FontStyle::bold})
          .border_top(" ")
          .border_bottom(" ")
          .border_left(" ")
          .border_right(" ")
          .corner(" ")
          .padding_top(1)
          .padding_bottom(1);
          

          cout << search <<endl;
          cout << "How you want to search?" << endl;
          cout << "(Type in the relative number?)" << endl;
          cin >> search_no;
          //search table

          ifstream in_file("inventory.txt", ios::out);
          in_file.close();
          






         
         getch();
         system("CLS");
         
    }
    
    //error checking (menu)
    else
    {
         system("CLS");
         cout << "Error pls input value between 1 to 4";
         getch();
         system("CLS");
    }




     
     
     
     

    
}

 cout << "Click Pause";
     getch();
}




   
   
   
   
   
  
    
