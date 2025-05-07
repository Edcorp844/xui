#pragma once
#include <X11/Xlib.h>
#include <vector>

class XUIWidget;

class XUIWindow {
public:
    XUIWindow(const char* title, int width, int height);
    ~XUIWindow();

    void show();
    void addWidget(XUIWidget* widget);

private:
    Display* display;
    int screen;
    Window window;
    GC gc;
    std::vector<XUIWidget*> widgets;

    void mainLoop();
};
