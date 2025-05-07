// xui_row.cpp

#include "xui_row.hpp"

XUIRow::XUIRow(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}

void XUIRow::draw(Display* dpy, Window win, GC gc) {
    int currentX = x;
    for (auto* child : children) {
        child->x = currentX;
        child->y = y;

        // Adjust Y alignment
        if (verticalAlign == XAlignment::Center)
            child->y += (height - child->height) / 2;
        else if (verticalAlign == XAlignment::End)
            child->y += (height - child->height);

        child->draw(dpy, win, gc);
        currentX += child->width;
    }
}

void XUIRow::addChild(XUIWidget* child) {
    children.push_back(child); // changed from insert() to push_back()
}
