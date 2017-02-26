#include <QApplication>
#include <QPushButton>
 
int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 
 QPushButton button;
 button.setText("Press Me!");
 button.setToolTip("A Tip!");
 button.show();
 
 return app.exec();
}
