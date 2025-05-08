// c++/src/xui.cpp
#include "xui_window.hpp"
#include "xui_button.hpp"
#include "xui_row.hpp"
#include "xui.h"
#include <functional>
#include <unordered_map>

// Map to store Swift callbacks
static std::unordered_map<XUIButton, std::function<void()>> button_callbacks;

extern "C" {

// === Window Functions ===
XUIWindow xui_create_window(const char* title, int width, int height) {
    try {
        return reinterpret_cast<XUIWindow>(new XUI::XUIWindow(title, width, height));
    } catch (...) {
        return nullptr;
    }
}

void xui_window_show(XUIWindow window) {
    if (window) {
        reinterpret_cast<XUI::XUIWindow*>(window)->show();
    }
}

void xui_window_add_widget(XUIWindow window, void* widget) {
    if (window && widget) {
        reinterpret_cast<XUI::XUIWindow*>(window)->addWidget(
            reinterpret_cast<XUI::XUIWidget*>(widget));
    }
}

// === Button Functions ===
XUIButton xui_create_button(int x, int y, int width, int height, const char* label) {
    try {
        // Create default color
        XUI::rgba_color_t color = {0.2f, 0.4f, 0.8f, 1.0f}; // Default blue color
        return reinterpret_cast<XUIButton>(new XUI::XUIButton(
            x, y, width, height, std::string(label), color));
    } catch (...) {
        return nullptr;
    }
}

void xui_button_set_on_click(XUIButton button, void (*callback)()) {
    if (button) {
        auto btn = reinterpret_cast<XUI::XUIButton*>(button);
        
        // Store the C callback
        button_callbacks[button] = [callback]() {
            if (callback) callback();
        };
        
        // Set the simplified callback
        btn->setOnClick([button]() {
            auto it = button_callbacks.find(button);
            if (it != button_callbacks.end()) {
                it->second();
            }
        });
    }
}

XUIRow xui_create_row(int x, int y, int width, int height){
    try {
        // Create default color
        XUI::rgba_color_t color = {0.2f, 0.4f, 0.8f, 1.0f}; // Default blue color
        return reinterpret_cast<XUIRow>(new XUI::XUIRow(
            x, y, width, height));
    } catch (...) {
        return nullptr;
    }
}

void xui_row_add_child(XUIRow row, void* widget){
    if (row && widget) {
        reinterpret_cast<XUI::XUIRow*>(row)->addChild(
            reinterpret_cast<XUI::XUIWidget*>(widget));
    }
}



// === Cleanup Functions ===
void xui_destroy_window(XUIWindow window) {
    if (window) {
        delete reinterpret_cast<XUI::XUIWindow*>(window);
    }
}

void xui_destroy_button(XUIButton button) {
    if (button) {
        button_callbacks.erase(button);
        delete reinterpret_cast<XUI::XUIButton*>(button);
    }
}

} // extern "C"