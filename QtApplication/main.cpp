#include <QtCore>
#include <QtGui>

#include "rasterwindow.h"

#define EXPORT __attribute__((visibility("default")))

Q_FORWARD_DECLARE_OBJC_CLASS(NSView);

extern "C" {
    EXPORT NSView *createQtApplicationView();
    EXPORT void destroyQtApplicationView(NSView *);
}

int argc = 0;
char *argv = 0;
QGuiApplication *app = 0;
NSView *nativeView = 0; // we support one view
QWindow *window = 0; // and one window

EXPORT NSView *createQtApplicationView()
{
    app = new QGuiApplication(argc, &argv);

    window = new RasterWindow();
    nativeView = reinterpret_cast<NSView *>(window->winId());
   
    // TODO: the QWindow may need a show() call (especially QWidgetWidnows)
   
    // TODO: memory management
    //  1) transfer ownership of QWindow:
    //      NSView *nativeView = static_cast<NSView *>(window->takeNativeView());
    //  2) rely on NSView refcounting - delete QWindow on [QNSView dealloc]
   
    return nativeView;
}

EXPORT void destroyQtApplicationView(NSView *view)
{
    Q_UNUSED(view)
    delete app;
    delete window;
}
