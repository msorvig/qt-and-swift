//
//  QtAndSwift-Bridging-Header.h
//  QtAndSwift
//
//  Created by Morten Johan Sørvig on 07/01/16.
//  Copyright © 2016 Qt Project. All rights reserved.
//

#ifndef QtAndSwift_Bridging_Header_h
#define QtAndSwift_Bridging_Header_h

#import <AppKit/AppKit.h>

NSView *createQtApplicationView();
void destroyQtApplicationView(NSView *);

#endif /* QtAndSwift_Bridging_Header_h */
