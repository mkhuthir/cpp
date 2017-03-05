
TEMPLATE = app

TARGET = camera

QT +=   multimedia \
        multimediawidgets \
        widgets

HEADERS = \
    camera.h \
    imagesettings.h \
    videosettings.h

SOURCES = \
    main.cpp \
    camera.cpp \
    imagesettings.cpp \
    videosettings.cpp

FORMS += \
    camera.ui \
    videosettings.ui \
    imagesettings.ui

target.path = $$PWD

INSTALLS += target
