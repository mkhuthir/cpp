
#include <QtWidgets>
#include "window.h"
#include "ui_window.h"
#include "oglwidget.h"

Window::Window(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Window)
{
    ui->setupUi(this);
    /*
     * Connectors for: x, y, z slots and signals
     */
    connect(ui->openGLWidget, SIGNAL(xRotationChanged(int)), ui->xSlider, SLOT(setValue(int)));
    connect(ui->openGLWidget, SIGNAL(yRotationChanged(int)), ui->ySlider, SLOT(setValue(int)));
    connect(ui->openGLWidget, SIGNAL(zRotationChanged(int)), ui->zSlider, SLOT(setValue(int)));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}
