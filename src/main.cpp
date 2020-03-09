

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





#include <forward_list>
#include <map>
#include <cassert>

//#include <nana/paint/graphics.hpp"

#include <iostream>
#include <chrono>

#include <thread>

using namespace nana;




/*int main()
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
    auto s = screen();
    auto pa = s.get_primary().workarea();
    form fm;

    fm.move(pa.x,pa.y);
    fm.outline_size({pa.width /2 , pa.height / 2});
    fm.caption("Book Inventory");

    fm.show();
    exec();
  


}