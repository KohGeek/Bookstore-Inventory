

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

//#include <nana/paint/graphics.hpp"

#include <iostream>
#include <chrono>

#include <thread>

using namespace nana;


/*

int main()
{
       
    
    nana::appearance fmapper;
    fmapper.maximize = true;
    form fm(rectangle(0,0,1920,1080), fmapper);
    
   

   
    fm.caption("Nana.exe");
    button bt0{fm,"Add"};
    button bt1{fm,"Delete"};
    button bt2{fm, "Edit"};
    textbox search{fm};
    label lb {fm};
    lb.format(true);

    lb.caption("<bold size = 30 font=\"Consolas\" >Book Managment</>");
    lb.bgcolor(colors::azure);
    lb.text_align(align::center, align_v::center);
    
    
    fm.show();
    place plc(fm);
   
    //plc.div("vertical <weight = 20% < vertical  <weight = 20% < buttons arrange = [100,100,100,100]>  <search_box margin = [0,0,0,300]>  > <> > <> > <> <>   ");
    //plc.field("buttons") << bt0 << bt1 << bt2;
    //plc.field("search_box") << search;
    
    plc.div("vertical<weight = 10%  vertical<text>   ><>");
    plc.field("text") << lb;
    
    
    plc.collocate();
    fm.show();
    exec();
   




}
*/


int main(){
    
    nana::appearance fmapper;
    fmapper.maximize = false;
    fmapper.sizable = false;
    form fm(rectangle(100,100,800,600), fmapper);
 
    fm.caption("Book Inventory");
    button add_but{fm,"Add"};
    button delete_but{fm,"Delete"};
    button edit_but{fm, "Edit"};
    button search_but{fm, "Search"};
    button adv_search_but{fm, "Advanced"};
    textbox search_box{fm};
    label lb {fm};
    lb.format(true);
    listbox table_box{fm, true};
    table_box.append_header("ISBN Code", 80);
    table_box.append_header("Author", 80);
    table_box.append_header("Title", 80);
    table_box.append_header("Publisher", 80);
    table_box.append_header("Year Publish", 80);
    table_box.append_header("Quantity", 80);
    table_box.append_header("Price", 80);
    table_box.append_header("Location", 80);    

    lb.caption("<bold size = 30 font=\"Consolas\" >Book Managment</>");
    lb.bgcolor(colors::azure);
    lb.text_align(align::center, align_v::center);
    place plc(fm);
    plc.div("vertical<weight = 10%  vertical<header> >  <weight = 20% <weight = 70%> <vertical <<weight = 70% <search_input  margin = [10,10,10,10] >  > <    <btn_search margin = [10,10,10,10]>  > >     < <weight = 60%> <    < btn_adv margin = [10,10,10,10]  >     > > >  >        < <weight =20%      vertical<weight = 70%     vertical<add margin = [20,20,20,20]><delete margin = [20,20,20,20]><edit margin = [20,20,20,20]>      > <weight = 30%>   >    <weight = 80% table_item> >");
    plc.field("header") << lb;
    plc.field("search_input") << search_box;
    plc.field("btn_search") << search_but;
    plc.field("btn_adv") << adv_search_but;
    plc.field("add") << add_but;
     plc.field("delete") << delete_but;
      plc.field("edit") << edit_but;
      plc.field("table_item") << table_box;
    
    
    plc.collocate();
    

    fm.show();
    exec();

    return 0;

}
