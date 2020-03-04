#include "GUI.hpp"

#include "nana/gui.hpp"
#include "nana/gui/widgets/label.hpp"
#include "nana/gui/filebox.hpp"
#include "nana/gui/widgets/button.hpp"
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/place.hpp>



void GUI(void){
     using namespace nana;

    form fm;

    fm.events().click([]{
        //It will get called, but it is not the first event handler to be called.
    });

    fm.events().click([](const arg_mouse& arg){
        arg.stop_propagation();
    });

    fm.events().click([]{
        //It will not get called.
    });

    fm.events().click.connect_unignorable([]{
        //It will get called because it is unignorable.
    });

    fm.events().click.connect_front([]{
        //It will get called firstly, because it is the beginning of the chain.
    });

    fm.show();
    exec();

        fm.show();
        exec();
}