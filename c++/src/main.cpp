

#include "xui_window.hpp"
#include "xui_button.hpp"
#include "xui_row.hpp"
#include <unistd.h>
#include <iostream>

void clicked()
{
    std::cout << "Cliked" << std::endl;
}

int main(int argc, char **argv)
{
    /*Display *d = XOpenDisplay(NULL);
    if (d == NULL)
        return 1;

    int s = DefaultScreen(d);
    Window w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 400, 300, 1,
                                   BlackPixel(d, s), WhitePixel(d, s));


    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);

    XEvent e;
    while (1)
    {
        XNextEvent(d, &e);
        if (e.type == KeyPress)
        {
            std::cout << "pressed" << e.xkey.x << std::endl;
        }
    }

    XCloseDisplay(d);*/

    XUIWindow window = XUIWindow("My App", 800, 500);
    XUIRow row = XUIRow(5, 5, 400, 600);
    XUIButton button = XUIButton(100, 100, 120, 50, "Button", rgba_color_t{0, 29, 27, 56});
    // button.setOnClick(*void)clicked);
    XUIButton button1 = XUIButton(100, 100, 120, 50, "Button1", rgba_color_t{0, 29, 27, 56});
    XUIButton button2 = XUIButton(100, 100, 120, 50, "Button2", rgba_color_t{0, 29, 27, 56});
    row.addChild(&button);
    row.addChild(&button1);
    row.addChild(&button2);
    window.addWidget(&row);
    window.show();

    return 0;
}
// gcc app.c -o app -lX11
