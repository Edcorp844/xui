//let buttonLabel = "Press Me"
//let btn = xui_create_button(100, 100, 120, 50, buttonLabel)

//xui_button_set_on_click(btn) {
 //   print("Button clicked from Swift!")
//}
/*
struct XButton: FlameUIView {
    let handle: UnsafeMutableRawPointer

    init(_ title: String, x: Int32, y: Int32, w: Int32, h: Int32,
         color: (r: UInt8, g: UInt8, b: UInt8, a: UInt8),
         onClick: @escaping () -> Void) {
        let cTitle = strdup(title)
        handle = xui_create_button(x, y, w, h, cTitle, color.r, color.g, color.b, color.a)
        xui_button_set_on_click(handle, onClick)
    }
}
 */
 
 struct Button: View {
    var width: Int32 = 120
    var height: Int32 = 50
    var label: String
   
    init(_ Label: String) {
       self.label = Label
       
    }

    func addChild(child:View){

    }

    func draw()-> UnsafeMutableRawPointer{
        xui_create_button(100, 100, self.width, self.height, self.label)
    }
}