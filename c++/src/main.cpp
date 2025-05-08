

#include "xui_window.hpp"
#include "xui_button.hpp"
#include "xui_row.hpp"
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

void clicked()
{
    std::cout << "Cliked" << std::endl;
}

int main(int argc, char **argv)
{
    XUI::XUIWindow window = XUI::XUIWindow("My App", 800, 500);
    XUI::XUIRow row = XUI::XUIRow(5, 5, 400, 600);
    XUI::XUIButton button = XUI::XUIButton(100, 100, 120, 50, "Button", XUI::rgba_color_t{0, 29, 27, 56});
    // button.setOnClick(*void)clicked);
    XUI::XUIButton button1 = XUI::XUIButton(100, 100, 120, 50, "Button1", XUI::rgba_color_t{0, 29, 27, 56});
    XUI::XUIButton button2 = XUI::XUIButton(100, 100, 120, 50, "Button2", XUI::rgba_color_t{0, 29, 27, 56});
    row.addChild(&button);
    row.addChild(&button1);
    row.addChild(&button2);
    window.addWidget(&row);
    window.show();

    return 0;
}
