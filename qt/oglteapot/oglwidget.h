
#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();


public slots:
    /*
     * Slots for: x, y, z coordinates
     */
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);


signals:
    /*
     * Rotation - x, y, z coordinates
     */
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);


protected:
    /*
     * These methods for rendering in OpenGL
     */
    void initializeGL(void);
    void paintGL(void);
    void resizeGL(int width, int height);

    QSize sizeHint(void) const;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private:
    int _x;
    int _y;
    int _z;

    QPoint _lastPosition;

    void draw(void);
};

#endif
