
QT += \
    core \
    gui \
    widgets

TARGET = dice

TEMPLATE = app


SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp \
    main.cpp

HEADERS += \
    mainwidget.h \
    geometryengine.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

target.path = $$PWD/bin
INSTALLS += target
