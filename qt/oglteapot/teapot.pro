
QT += core gui opengl widgets

TARGET = oglteapot

TEMPLATE = app

SOURCES += \
      main.cpp \
      window.cpp \
      oglteapot.cpp

HEADERS  += \
      window.h \
      oglwidget.h \
      teapot.h

FORMS += window.ui
