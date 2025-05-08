// c++/include/xui.h
#ifndef XUI_H
#define XUI_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* XUIWindow;
typedef void* XUIButton;
typedef void* XUIRow;

// Window API
XUIWindow xui_create_window(const char* title, int width, int height);
void xui_window_show(XUIWindow window);
void xui_window_add_widget(XUIWindow window, void* widget);
void xui_destroy_window(XUIWindow window);

// Button API
XUIButton xui_create_button(int x, int y, int width, int height, const char* label);
void xui_button_set_on_click(XUIButton button, void (*callback)());
void xui_destroy_button(XUIButton button);

// Row API
XUIRow xui_create_row(int x, int y, int width, int height);
void xui_row_add_child(XUIRow row, void* widget);

#ifdef __cplusplus
}
#endif

#endif // XUI_H