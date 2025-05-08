

// xui_button.h
#pragma once
#include <X11/Xlib.h>
#include <string>
#include "xui_widget.hpp"
#include "xui_color.hpp"
#include <functional>

namespace XUI
{

    class XUIButton : public XUIWidget
    {
    public:
        XUIButton(int x, int y, int width, int height, const std::string &label,
                  rgba_color_t color);

        void draw(Display *dpy, Window win, GC gc) override;
        // void onClick(int px, int py);
        // void setOnClick(void (*callback)());
        void onClick(int x, int y) override;
        void setOnClick(std::function<void()> callback);

    private:
        std::string label;
        rgba_color_t color;

        std::function<void()> onClickCallback;

        unsigned long bgColor;
        unsigned long borderColor;
        unsigned long shadowColor;
        unsigned long textColor = 0xFFFFFF;

        int padding = 8;
        int borderWidth = 2;
        int cornerRadius = 8;
        int blurIntensity = 0; // 0 = none, higher = more blurred shadow (fake)
                               // void (*onClick)() = nullptr;
    };

/*

#pragma once
#include <X11/Xlib.h>
#include <functional>
#include "xui_widget.hpp"
#include <string>

class XUIButton : public XUIWidget {
public:
    XUIButton(int x, int y, int w, int h, const char* label);
    void draw(Display*, Window, GC) override;
    void onClick(int x, int y) override;
    void setOnClick(std::function<void()> callback);

private:
    int x, y, w, h;
    std::string label;
    std::function<void()> onClickCallback;
};
*/}