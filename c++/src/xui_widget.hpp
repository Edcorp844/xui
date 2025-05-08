#pragma once
#include <X11/Xlib.h>
#include <vector>

namespace XUI
{

    class XUIWidget
    {
    public:
        int x, y;
        int width, height;
        virtual void draw(Display *, Window, GC) = 0;
        virtual void onClick(int x, int y) {}
        virtual ~XUIWidget() {}
    };
}