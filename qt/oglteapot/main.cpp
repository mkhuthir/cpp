
#include <QApplication>
#include <QDesktopWidget>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Window window;

    window.setWindowTitle("OpenGl Teapot");
    window.resize(window.sizeHint());
    window.show();

    return application.exec();
}
