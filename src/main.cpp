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
#include <nana/gui/widgets/tabbar.hpp>
#include <nana/gui/widgets/group.hpp>

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
   fm.caption("Nana.exe");
   place plc(fm);
   bool really_quick{false};
   label hello{fm, "Hello World"};
   button btn {fm, "Quit"};
   btn.tooltip("I will ask first");
   group act(fm,"Actions");

   act.add_option("Quick quickly")
   .events().click([&] () {
       really_quick = true;
       });

        act.add_option("Ask first")
   .events().click([&] () {
       really_quick = false;
        });

        btn.events().click([&]() {
            if (!really_quick)
            {
                msgbox m(fm, "Our demo", msgbox::yes_no);
                m.icon(m.icon_question);
                m <<"Are you sure you want to quit";
                auto response = m();
                if (response != m.pick_yes)return;

                
            
        }
        API::exit();
        });
   
    
   
   
    plc.div("vertical <label margin=10>|70% <actions>");
    plc["label"] << hello << btn;
    plc["actions"] << act;
    plc.collocate();
    fm.show();
    exec();
   
    

}
