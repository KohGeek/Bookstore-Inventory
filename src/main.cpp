

#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/tabbar.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/widgets/menu.hpp>
#include <nana/gui/widgets/widget.hpp>

#include <forward_list>
#include <map>
#include <cassert>

//#include <nana/paint/graphics.hpp"

#include <iostream>
#include <chrono>

#include <thread>

using namespace nana;


void on_menu_item(menu::item_proxy& ip)
{
    std::size_t index = ip.index();
    std::cout << "Menu item index:" << index <<
    std::endl;
}

int main()
{
       
    
   form fm;

   
   fm.caption("Nana.exe");
   button bt0{fm,"Add"};
    button bt1{fm,"Delete"};
     button bt2{fm, "Edit"};
     textbox search{fm};
    
    

    

    

			
      
    fm.show();
    place plc(fm);
    plc.div("vertical <weight = 20% < vertical  <weight = 20% < buttons arrange = [100,100,100,100]>  <search_box margin = [0,0,0,300]>  > <> > <> > <> <>   ");
   
    plc.field("buttons") << bt0 << bt1 << bt2;
    plc.field("search_box") << search;
    
   
    plc.collocate();
    fm.show();
    exec();
   
    

}
