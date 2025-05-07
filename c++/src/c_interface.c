// xui.cpp
#include "xui_window.hpp"
#include "xui_button.hpp"
#include "xui_color.hpp"
#include "xui.h"

extern "C"
{

    // Create a new XUI window
    void *xui_create_window(const char *title, int width, int height)
    {
        return static_cast<void *>(new XUIWindow(title, width, height));
    }

    // Show the window and start the event loop
    void xui_window_show(void *win)
    {
        if (win)
        {
            static_cast<XUIWindow *>(win)->show();
        }
    }

    // Create a new XUI button
    void *xui_create_button(int x, int y, int width, int height, const char *label)
    {
        rgba_color_t color = {0.2f, 0.4f, 0.8f, 1.0f}; // default blue
        return static_cast<void *>(new XUIButton(x, y, width, height, label, color));
    }

    // Set the button's onClick callback
    void xui_button_set_on_click(void *btn, void (*callback)())
    {
        if (btn)
        {
            static_cast<XUIButton *>(btn)->setOnClick(callback);
        }
    }

    // Add a widget (button, row, etc.) to a window
    void xui_window_add_widget(void *win, void *widget)
    {
        if (win && widget)
        {
            static_cast<XUIWindow *>(win)->addWidget(static_cast<XUIWidget *>(widget));
        }
    }
}
