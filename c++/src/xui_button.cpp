#include "xui_button.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace XUI
{

    XUIButton::XUIButton(int x, int y, int width, int height, const std::string &label,
                         rgba_color_t color)
        : label(label), color(color)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void XUIButton::draw(Display *dpy, Window win, GC gc)
    {
        // Simulate blur by drawing multiple offset shadows
        for (int i = 1; i <= blurIntensity; ++i)
        {
            XSetForeground(dpy, gc, shadowColor);
            XFillRectangle(dpy, win, gc, x + i, y + i, width, height);
        }

        // Main background
        XSetForeground(dpy, gc, bgColor);
        XFillRectangle(dpy, win, gc, x, y, width, height);

        // Border
        XSetLineAttributes(dpy, gc, borderWidth, LineSolid, CapButt, JoinMiter);
        XSetForeground(dpy, gc, borderColor);
        XDrawRectangle(dpy, win, gc, x, y, width, height);

        // Label
        XSetForeground(dpy, gc, textColor);
        XDrawString(dpy, win, gc, x + padding, y + height / 2 + 5, label.c_str(), label.size());
    }

    void XUIButton::onClick(int px, int py)
    {
        if (px >= x && px <= x + width && py >= y && py <= y + height)
        {
            if (onClickCallback)
                onClickCallback();
        }
    }

    void XUIButton::setOnClick(std::function<void()> cb)
    {
        onClickCallback = cb;
    }
}