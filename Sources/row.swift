

 struct Row: View {
    let widget: UnsafeMutableRawPointer
    var x: Int32 = 0
    var y: Int32 = 0
    //var width: Int32= 10
    //var height: Int32=10
    var views: [any View]
  
   
    init(@ViewBuilder _ content: () -> [any View]) {   
        self.views = content()
        self.widget = xui_create_row(self.x,self.y, 100,100)

    }

    func addChild(child: View){
        xui_row_add_child(self.widget, child.draw())
    }

    func draw()-> UnsafeMutableRawPointer{
         for view in self.views {
           self.addChild(child: view)
        }
       
        return self.widget
    }
}