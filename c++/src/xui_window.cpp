#include "xui_window.hpp"
#include "xui_button.hpp"
#include <X11/Xutil.h>
#include <iostream>

namespace XUI
{
    XUIWindow::XUIWindow(const char *title, int width, int height)
    {
        display = XOpenDisplay(nullptr);
        screen = DefaultScreen(display);
        window = XCreateSimpleWindow(display, RootWindow(display, screen),
                                     100, 100, width, height, 1,
                                     BlackPixel(display, screen),
                                     WhitePixel(display, screen));

        XStoreName(display, window, title);
        XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);
        gc = XCreateGC(display, window, 0, 0);
    }

    XUIWindow::~XUIWindow()
    {
        XDestroyWindow(display, window);
        XCloseDisplay(display);
    }

    void XUIWindow::addWidget(XUIWidget *widget)
    {
        widgets.push_back(widget);
    }

    void XUIWindow::show()
    {
        XMapWindow(display, window);
        mainLoop();
    }

    void XUIWindow::mainLoop()
    {
        XEvent e;
        while (1)
        {
            XNextEvent(display, &e);
            if (e.type == Expose)
            {
                for (auto w : widgets)
                    w->draw(display, window, gc);
            }
            if (e.type == ButtonPress)
            {
                for (auto w : widgets)
                    w->onClick(e.xbutton.x, e.xbutton.y);
            }
        }
    }
}