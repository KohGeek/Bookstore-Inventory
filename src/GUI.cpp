#include "GUI.hpp"

#include "nana/gui.hpp"
#include "nana/gui/widgets/label.hpp"
#include "nana/gui/filebox.hpp"
#include "nana/gui/widgets/button.hpp"
#include "nana/gui/widgets/textbox.hpp"
#include "nana/gui/place.hpp"
#include "nana/gui/compact.hpp"
#include "nana/gui/widgets/button.hpp"

void GUI()
{
	using namespace nana;

	form menu;
	
    button butt1(menu, rectangle(10, 10, 10 , 10), true);

    menu.show();
    exec();
}
