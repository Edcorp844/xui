// xui.h
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void* xui_create_window(const char* title, int width, int height);
void  xui_window_show(void* win);

void* xui_create_button(int x, int y, int width, int height, const char* label);
void  xui_button_set_on_click(void* btn, void (*callback)());

void  xui_window_add_widget(void* win, void* widget);

#ifdef __cplusplus
}
#endif
