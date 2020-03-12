

#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/tabbar.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/widgets/menu.hpp>
#include <nana/gui/widgets/widget.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/menubar.hpp>
#include <nana/gui/layout_utility.hpp>
#include <nana/gui/widgets/listbox.hpp>





#include <cmath>
#include <bitset>
#include <forward_list>
#include <map>
#include <cassert>
#include <iostream>
#include <chrono>
#include <thread>
#include <ostream>

using namespace nana;


//func prototype
void exit_func(const arg_click& ei )
{
    msgbox m(ei.window_handle, "msg.exe", msgbox::yes_no);
    m.icon(m.icon_question);
    m << "Want to Exit onii-chan?!!";  
    m(); 
    
}





int main(){
    
    //size of screen
    nana::appearance fmapper;
    fmapper.maximize = false;
    fmapper.sizable = false;
    form fm(rectangle(100,100,800,600), fmapper);
     fm.caption("Book Inventory");
    //fixed (not responsive)
 
   
   
   
 

   

   //button declare
    button add_but{fm,"Add"};
    button delete_but{fm,"Delete"};
    button edit_but{fm, "Edit"};
    button search_but{fm, "Search"};
    button adv_search_but{fm, "Advanced"};
    button exit_but{fm, "Quit"};
    //event handling (quit)
    exit_but.events().click(exit_func);

    //end button



    //declare txtbox
    textbox search_box{fm};
    //end txtbox
  
    //Make a table box
    listbox table_box{fm, true};
    table_box.append_header("ISBN Code", 80);
    
    table_box.append_header("Author", 80);
   
    table_box.append_header("Title", 80);
    table_box.append_header("Publisher", 80);
    table_box.append_header("Year Publish", 80);
    table_box.append_header("Quantity", 80);
    table_box.append_header("Price", 80);
    table_box.append_header("Location", 80);    
    //end of tablebox

    //header name
    label lb {fm};
    lb.format(true);
    lb.caption("<bold size = 30 font=\"Consolas\" >Book Managment</>");
    lb.bgcolor(colors::azure);
    lb.text_align(align::center, align_v::center);
    //end header

    //define place class
    place plc(fm);
    //end class

    //start placing items or widgets
    plc.div("vertical<weight = 10%  vertical<header> >  <weight = 20% <weight = 70%> <vertical <<weight = 70% <search_input  margin = [10,10,10,10] >  > <    <btn_search margin = [10,10,10,10]>  > >     < <weight = 60%> <    < btn_adv margin = [10,10,10,10]  >     > > >  >        < <weight =20%      vertical<weight = 70%     vertical<add margin = [20,20,20,20]><delete margin = [20,20,20,20]><edit margin = [20,20,20,20]>      > <weight = 30% <exit margin = [20,20,20,20]>>   >    <weight = 80% table_item> >");
    plc.field("header") << lb;
    plc.field("search_input") << search_box;
    plc.field("btn_search") << search_but;
    plc.field("btn_adv") << adv_search_but;
    plc.field("add") << add_but;
    plc.field("delete") << delete_but;
    plc.field("edit") << edit_but;
    plc.field("exit") << exit_but;
    plc.field("table_item") << table_box;
    //end
    
    
    plc.collocate();
    

    fm.show();
    exec();
    

    return 0;

}

