protocol View {
    func addChild(child: View)
    func draw()-> UnsafeMutableRawPointer
}

@resultBuilder
struct ViewBuilder {
    static func buildBlock() -> [any View] {
        []
    }

    static func buildBlock(_ components: any View...) -> [any View] {
        components
    }
}
