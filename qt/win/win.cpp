#include <QApplication>
#include <QPushButton>
 
int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 
 QWidget window;

 window.setFixedSize(400, 300);
 window.show();

 return app.exec();
}
