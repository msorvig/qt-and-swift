TEMPLATE = lib
CONFIG += lib_bundle
QT += widgets
TARGET=QtApplication

OBJECTS_DIR = .obj
MOC_DIR = .moc

HEADERS += \
    rasterwindow.h \
    
SOURCES += \
    rasterwindow.cpp \
    main.cpp
    
RESOURCES = qt.qrc
