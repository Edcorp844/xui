// xui_layout.h

#pragma once
#include "xui_widget.hpp"
#include <vector>
#include "xui_alignment.hpp"



class XUILayout : public XUIWidget {
protected:
    std::vector<XUIWidget*> children;
    XAlignment horizontalAlign = XAlignment::Start;
    XAlignment verticalAlign = XAlignment::Start;

public:
    void addChild(XUIWidget* child);
    void setHorizontalAlignment(XAlignment align);
    void setVerticalAlignment(XAlignment align);
};
