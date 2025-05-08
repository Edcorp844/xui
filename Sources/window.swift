
 struct Window: View {
    let window: UnsafeMutableRawPointer
    var width: Int32 = 1000
    var height: Int32 = 800
    var title: String
   
    init(_ title: String, @ViewBuilder _ content: () -> [any View]) {
        self.title = title
        let views = content()
        self.window = xui_create_window(self.title, self.width, self.height)
       
        for view in views {
            xui_window_add_widget(self.window, view.draw())
        }
    }

    func addChild(child:View){

    }

    func draw()-> UnsafeMutableRawPointer{
        xui_window_show(self.window)
        return self.window
    }
}