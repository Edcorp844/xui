let winTitle = "Swift Linux UI"
let win = xui_create_window(winTitle, 400, 300)

let buttonLabel = "Press Me"
let btn = xui_create_button(100, 100, 120, 50, buttonLabel)

xui_button_set_on_click(btn) {
    print("Button clicked from Swift!")
}

xui_window_add_widget(win, btn)
xui_window_show(win)
