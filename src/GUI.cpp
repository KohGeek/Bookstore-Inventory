#include "GUI.hpp"

#include "nana/gui.hpp"
#include "nana/gui/widgets/label.hpp"

void GUI(void){
    using namespace nana;

    form fm;

    label lb {fm, rectangle {10, 10, 100, 100}};
    lb.caption("Hello, world!");

    fm.show();

    exec();
}
