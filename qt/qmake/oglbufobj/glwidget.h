#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLBuffer>

class GlWidget : public QGLWidget
{
    Q_OBJECT

public:
    GlWidget(QWidget *parent = 0);
    ~GlWidget();
    QSize sizeHint() const;

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram lightingShaderProgram;
    int numCubeVertices;
    QGLBuffer cubeBuffer;
    GLuint cubeTexture;
    QGLShaderProgram coloringShaderProgram;
    int numSpotlightVertices;
    QGLBuffer spotlightBuffer;
    double lightAngle;
    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

private Q_SLOTS:
    void timeout();
};

#endif
