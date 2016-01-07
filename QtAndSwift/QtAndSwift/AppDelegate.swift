//
//  AppDelegate.swift
//  QtAndSwift
//
//  Created by Morten Johan Sørvig on 07/01/16.
//  Copyright © 2016 Qt Project. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!
    var qtView: NSView?

    func applicationDidFinishLaunching(aNotification: NSNotification) {
        qtView = createQtApplicationView()
        window.contentView = qtView
    }

    func applicationWillTerminate(aNotification: NSNotification) {
        destroyQtApplicationView(qtView!)
    }
}

