#pragma once
#include <X11/Xlib.h>
#include <vector>
#include "xui_widget.hpp"

namespace XUI
{

    class XUIWindow
    {
    public:
        XUIWindow(const char *title, int width, int height);
        ~XUIWindow();

        void show();
        void addWidget(XUI::XUIWidget *widget);

    private:
        Display *display;
        int screen;
        Window window;
        GC gc;
        std::vector<XUI::XUIWidget *> widgets;

        void mainLoop();
    };
}