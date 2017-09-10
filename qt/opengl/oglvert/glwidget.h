
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>

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

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;
};

#endif 