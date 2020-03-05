/**
 *  \file calculator.cpp
 *  \brief Nana Calculator
 *	Nana 1.3 and C++11 is required.
 *	This is a demo for Nana C++ Library.
 *	It creates an intermediate level graphical calculator with few code.
 */

#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <forward_list>
#include <map>
#include <cassert>

//#include <nana/paint/graphics.hpp"

#include <iostream>
#include <chrono>

#include <thread>

using namespace nana;




int main()
{
       
    
    form fm;
    fm.caption(("Test"));
    textbox t1 {fm},
            t2 {fm};
    button bt1(fm,"Hello");
      button bt2(fm,"Hello");

      t1.tip_string("Username:").multi_lines(false);
      t2.tip_string("Password:").multi_lines(false).mask('*');
      
    place plc(fm);
    plc.div("   <> <weight=80% vertical<><weight=70% vertical <vertical gap =10 textboxes arrange = [25,25] ><weight=25% gap = 5 buttons>        ><>     > <>");
    plc.field("textboxes") << t1 << t2;
    plc.field("buttons") << bt1 << bt2;

    plc.collocate();
    
    fm.show();
    exec();
    

}
