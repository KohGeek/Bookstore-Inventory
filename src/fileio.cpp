#include <iostream>
#include <vector>

#include "fileio.hpp"

int reader(void){

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

    if(path.empty()){
        return 1;
    }else{
        std::string p = path[0].string();
        csvparse.read(p);
    }

    for(int i = 0; csvparse.busy();){
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

    return 0;
}

int writer(void){
    
    /** to be further developed
    nana::form NamePrompt;
    nana::folderbox SaveFile{nullptr,};
    int i = 0;
    std::string p;

    SaveFile.allow_multi_select(false);
    nana::label namelb{NamePrompt, nana::rectangle {20,10,300,30}};
    nana::textbox nametxt{NamePrompt, nana::rectangle {20,50,300,30}, true};
    nana::button namebut{NamePrompt, nana::rectangle {135,90,60,20}};

    namelb.caption("Please key in the file name you want to save:");
    namebut.caption("Confirm");

    auto path = SaveFile.show();

    if(path.empty()){
        return 0;
    }else{
        p = path[0].string();
        NamePrompt.show();
        nana::exec();
    }
    **/

    csv::Writer csvWriter("inventory.csv");

    csvWriter.configure_dialect()
        .delimiter(",")
        .column_names("ISBN","Author","Title","Publisher","YearPublished","Price","Quantity","Rack","Level","Genre");
    
    for(int i = 0; inventory[i].isbn != ""; i++){
        csvWriter.write_row(
            inventory[i].isbn,
            inventory[i].author,
            inventory[i].title,
            inventory[i].publisher,
            std::to_string(inventory[i].year_published),
            std::to_string(inventory[i].price),
            std::to_string(inventory[i].quantity),
            std::to_string(inventory[i].rack),
            std::to_string(inventory[i].level),
            inventory[i].genre
        );
    }

    csvWriter.close();

    return 0;
}