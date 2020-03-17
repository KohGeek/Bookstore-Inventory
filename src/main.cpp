#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <tabulate/table.hpp>

using namespace std;


using namespace tabulate;

int main() {

//declaring variables
int option, search_no;

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
.corner(" ");

header.format()
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
         cout << "What you want to search" << endl;

          //Search Table
          Table search;
          search.add_row({"1) ISBN"});
          search.add_row({"2) Author"});
          search.add_row({"3) Title"});
          search.add_row({"4) Publisher"});
          search.add_row({"5) Year Publish"});
          search.add_row({"6) Quantity"});
          search.add_row({"7) Price"});
          search.add_row({"8) Location"});

          cout << search <<endl;
          cout << "How you want to search?" << endl;
          cout << "(Type in the relative number?)" << endl;
          cin >> search_no;
          























         
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




   
   
   
   
   
  
    
