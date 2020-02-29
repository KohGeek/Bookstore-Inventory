#include <iostream>
#include <vector>

#include "fileio.hpp"

void reader(void){

    nana::filebox OpenFile{nullptr,true};
    csv::Reader csvparse;

    OpenFile.allow_multi_select(false);
    OpenFile.add_filter("CSV Files (*.csv; *.txt)","*.csv;*.txt");
    OpenFile.add_filter("All Files (*.*)","*.*");

    csvparse.configure_dialect("assignment")
        .header(false)
        .skip_empty_rows(true)
        .column_names("ISBN","Author","Title","Publisher","YearPublished","Price","Quantity","Rack","Level","Genre");

    auto path = OpenFile.show();
    std::stringstream ss;

    if(path.empty()){
        std::cout << "Cancelled" << std::endl;
    }else{
        std::string p = path[0].string();
        csvparse.read(p);
    }

    int i = 0;

    while(csvparse.busy()){
        if(csvparse.ready()){
            auto row = csvparse.next_row();
            inventory[i].isbn = row["ISBN"];
            inventory[i].author = row["Author"];
            inventory[i].title = row["Title"];
            inventory[i].publisher = row["Publisher"];
            inventory[i].year_published = std::stoi(row["YearPublished"]);
            inventory[i].price = std::stod(row["Price"]);
            inventory[i].quantity = std::stoi(row["Quantity"]);
            inventory[i].rack = std::stoi(row["Rack"]);
            inventory[i].level = std::stoi(row["Level"]);
            inventory[i].genre = row["Genre"];
            i++;
        }
    }
}