import Foundation

@_silgen_name("xui_create_window")
func xui_create_window(_ title: UnsafePointer<CChar>, _ width: Int32, _ height: Int32) -> UnsafeMutableRawPointer

@_silgen_name("xui_window_show")
func xui_window_show(_ win: UnsafeMutableRawPointer)

@_silgen_name("xui_create_button")
func xui_create_button(_ x: Int32, _ y: Int32, _ w: Int32, _ h: Int32, _ label: UnsafePointer<CChar>) -> UnsafeMutableRawPointer

@_silgen_name("xui_button_set_on_click")
func xui_button_set_on_click(_ btn: UnsafeMutableRawPointer, _ callback: @convention(c) () -> Void)

@_silgen_name("xui_window_add_widget")
func xui_window_add_widget(_ win: UnsafeMutableRawPointer, _ widget: UnsafeMutableRawPointer)

@_silgen_name("xui_create_row")
func xui_create_row(_ x: Int32, _ y: Int32, _ w: Int32, _ h: Int32) -> UnsafeMutableRawPointer

@_silgen_name("xui_row_add_child")
func xui_row_add_child(_ row: UnsafeMutableRawPointer, _ widget: UnsafeMutableRawPointer)

