// xui_row.hpp
#pragma once

#include <vector>
#include <X11/Xlib.h>
#include "xui_widget.hpp"
#include "xui_alignment.hpp" // if you store XAlignment separately

namespace XUI{
class XUIRow : public XUIWidget {
public:
    std::vector<XUIWidget*> children;
    XAlignment verticalAlign = XAlignment::Start;

    XUIRow(int x, int y, int w, int h);
    void draw(Display* dpy, Window win, GC gc) override;
    void addChild(XUIWidget* child);
};}
