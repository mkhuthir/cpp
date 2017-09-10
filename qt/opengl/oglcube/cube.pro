QT += core gui opengl

TARGET = cube

TEMPLATE = app

SOURCES += main.cpp\
           glwidget.cpp

HEADERS += glwidget.h

OTHER_FILES += fragmentShader.fsh\
               vertexShader.vsh

RESOURCES += resources.qrc
