Qt and Swift
============================

This project contains testing code for ongoing R&D on using Qt
in swift-based projects.

C++ and Swift
----------------------------
C++ and Swift interop is possible, but not at the level of Objective C++,
where for example Objective C objects can be used from C++ code.

What we can do instead is export a C function from our C++ implementation,
and then call it from Swift:

    #define EXPORT __attribute__((visibility("default")))
    extern "C" EXPORT NSView *createQtApplicationView();

    let qtView = createQtApplicationView()
    contentView.addSubview(qtView)

The function we are exporting creates an application view implemented using
Qt. On the Qt side this a QWindow with for example Qt Widgets or Qt Quick 
content.

qmake and Xcode
----------------------------
Qt has special build and deployment requirements (moc, rcc, plugin deployment).
Swift also has a bit of build logic. We'll let Qt build and deploy the
part of the application that uses Qt, and then integrate that into a Swift-
based Xcode project. 

The common interface will be a framework: Qt produces one in compliance with
the expected framework layout. Xcode can then build, deploy, and code sign it.

Building this sample code
----------------------------

1) Build and deploy QtApplication.framework

    /path/to/qtbase/bin/qmake && make && /path/to/qtbase/bin/macdeployqt QtApplication.framework -deploy-framework -qt-from-macdeployqt

[deploy-framework and qt-from-macdeployqt are undocumented research options
available on newer versions of macdeployqt]

2) Jump through a hoop and set the correct LC_RPATH on the cocoa platform plugin

    install_name_tool -add_rpath @loader_path/../../Frameworks/ QtApplication.framework/Contents/PlugIns/platforms/libqcocoa.dylib

[this step will eventually go away]

3) Open and Build the QtAndSwift project

    open QtAndSwift.xcodeproj
    

Implementing createQtApplicationView()
----------------------------
See sample code. Note qt.conf which sets up plugin and import paths.


Setting Up the Xcode Project
----------------------------

If you want to recreate the Xcode project, or modify your own, here's how:

1) Create a standard Cocoa/Swift project

2) Add QtApplication.framework

    Build Phases -> Link Binary With Libraries: Add QtApplication.framework
    Build Phases -> "+" -> New Copy Files Phase: Add QtApplication.framework
    Build Settings -> Search Paths -> Framework Search Paths: Add ../QtApplication

3) Create the Swift -> C bridging header

Create and add QtAndSwift-Bridging-Header.h to your project. Sample contents:

    #import <AppKit/AppKit.h>
    NSView *createQtApplicationView();
    void destroyQtApplicationView(NSView *);

And add to build:

    Build Setting -> Swift Compiler - Code Generation -> Objective C Bridging Header: QtAndSwift/QtAndSwift-Bridging-Header.h
    



