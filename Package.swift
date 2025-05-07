// swift-tools-version: 5.10

import PackageDescription

let package = Package(
    name: "xui",
    products: [
        .executable(name: "xui", targets: ["xui"])
    ],
    targets: [
        .executableTarget(
            name: "xui",
            dependencies: [],
            publicHeadersPath: "c++/include",  // Path to your C++ headers
            linkerSettings: [
                 .linkedLibrary("xui", .when(platforms: [.linux])), // Linking to the static library (libxui.a)
                .linkedLibrary("X11", .when(platforms: [.linux])),
                .unsafeFlags([
                    "-L./c++/lib", // Directory containing libxui.a
                    "-lxui"        // The static library file (libxui.a)
                ], .when(platforms: [.linux]))
            ]
        )
    ]
)
