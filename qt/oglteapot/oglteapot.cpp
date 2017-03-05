
#include <QtWidgets>
#include <QtOpenGL>

#include "oglwidget.h"

#include "GL/gl.h"
#include "GL/glu.h"
#include "teapot.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    _x = 0;
    _y = 0;
    _z = 0;
}

OpenGLWidget::~OpenGLWidget()
{
}

static void qtNormalizeAngle(int &angle)
{
    while(angle < 0)
    {
        angle += 360 * 16;
    }
    while(angle > 360)
    {
        angle -= 360 * 16;
    }
}

void OpenGLWidget::setXRotation(int angle)
{
    qtNormalizeAngle(angle);
    if(angle != _x)
    {
        _x = angle;
        updateGL();
    }
}

void OpenGLWidget::setYRotation(int angle)
{
    qtNormalizeAngle(angle);
    if(angle != _y)
    {
        _y = angle;
        updateGL();
    }
}

void OpenGLWidget::setZRotation(int angle)
{
    qtNormalizeAngle(angle);
    if(angle != _z)
    {
        _z = angle;
        updateGL();
    }
}

void OpenGLWidget::initializeGL(void)
{
    /*
     * Initialize background
     */
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void OpenGLWidget::paintGL(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(_x / 16.0, 1.0, 0.0, 0.0);
    glRotatef(_y / 16.0, 0.0, 1.0, 0.0);
    glRotatef(_z / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void OpenGLWidget::resizeGL(int width, int height)
{
    int side;
    /*
     * Initialize function resize figure
     */
    side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /*
     * Position figure
     */
    glOrtho(-5, +5, -2, +5, 1.0, 25.0);

    glMatrixMode(GL_MODELVIEW);
}

QSize OpenGLWidget::sizeHint(void) const
{
    return QSize(800, 600);
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    _lastPosition = event->pos();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx,
        dy;

    dx = event->x() - _lastPosition.x();
    dy = event->y() - _lastPosition.y();

    if (event->buttons() && Qt::LeftButton)
    {
        setXRotation(_x + 8 * dy);
        setYRotation(_y + 8 * dx);
    }
    else if (event->buttons() && Qt::RightButton)
    {
        setXRotation(_x + 8 * dy);
        setZRotation(_z + 8 * dx);
    }

    _lastPosition = event->pos();
}

void OpenGLWidget::draw(void)
{
    drawingTeapot();
}
