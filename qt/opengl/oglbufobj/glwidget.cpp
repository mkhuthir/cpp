
#include "glwidget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QWheelEvent>

#ifdef WIN32
    #include <GL/glext.h>
    PFNGLACTIVETEXTUREPROC pGlActiveTexture = NULL;
    #define glActiveTexture pGlActiveTexture
#endif //WIN32

GlWidget::GlWidget(QWidget *parent)
    : QGLWidget(QGLFormat(/* Additional format options */), parent)
{
    alpha = 25;
    beta = -25;
    distance = 2.5;

    lightAngle = 0;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(20);
}

GlWidget::~GlWidget()
{
}

QSize GlWidget::sizeHint() const
{
    return QSize(640, 480);
}

void GlWidget::initializeGL()
{
    #ifdef WIN32
        glActiveTexture = (PFNGLACTIVETEXTUREPROC) wglGetProcAddress((LPCSTR) "glActiveTexture");
    #endif

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    qglClearColor(QColor(Qt::black));

    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/lightingVertexShader.vsh");
    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingFragmentShader.fsh");
    lightingShaderProgram.link();

    QVector<QVector3D> cubeVertices;
    QVector<QVector3D> cubeNormals;
    QVector<QVector2D> cubeTextureCoordinates;

    cubeVertices << QVector3D(-0.5, -0.5,  0.5) << QVector3D( 0.5, -0.5,  0.5) << QVector3D( 0.5,  0.5,  0.5) // Front
                 << QVector3D( 0.5,  0.5,  0.5) << QVector3D(-0.5,  0.5,  0.5) << QVector3D(-0.5, -0.5,  0.5)
                 << QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) // Back
                 << QVector3D(-0.5,  0.5, -0.5) << QVector3D( 0.5,  0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5)
                 << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5,  0.5) << QVector3D(-0.5,  0.5,  0.5) // Left
                 << QVector3D(-0.5,  0.5,  0.5) << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5)
                 << QVector3D( 0.5, -0.5,  0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5,  0.5, -0.5) // Right
                 << QVector3D( 0.5,  0.5, -0.5) << QVector3D( 0.5,  0.5,  0.5) << QVector3D( 0.5, -0.5,  0.5)
                 << QVector3D(-0.5,  0.5,  0.5) << QVector3D( 0.5,  0.5,  0.5) << QVector3D( 0.5,  0.5, -0.5) // Top
                 << QVector3D( 0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5,  0.5)
                 << QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5,  0.5) // Bottom
                 << QVector3D( 0.5, -0.5,  0.5) << QVector3D(-0.5, -0.5,  0.5) << QVector3D(-0.5, -0.5, -0.5);
    cubeNormals << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) // Front
                << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1)
                << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) // Back
                << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1)
                << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) // Left
                << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0)
                << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) // Right
                << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0)
                << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) // Top
                << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0)
                << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) // Bottom
                << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0);
    cubeTextureCoordinates << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);

    numCubeVertices = 36;

    cubeBuffer.create();
    cubeBuffer.bind();
    cubeBuffer.allocate(numCubeVertices * (3 + 3 + 2) * sizeof(GLfloat));

    int offset = 0;
    cubeBuffer.write(offset, cubeVertices.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeNormals.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeTextureCoordinates.constData(), numCubeVertices * 2 * sizeof(GLfloat));

    cubeBuffer.release();

    cubeTexture = bindTexture(QPixmap(":/cubeTexture.png"));

    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/coloringVertexShader.vsh");
    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/coloringFragmentShader.fsh");
    coloringShaderProgram.link();

    QVector<QVector3D> spotlightVertices;
    QVector<QVector3D> spotlightColors;

    spotlightVertices << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0,  0.5) << QVector3D( 0.5,    0,  0.5) // Front
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0, -0.5) << QVector3D(-0.5,    0, -0.5) // Back
                      << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0, -0.5) << QVector3D(-0.5,    0,  0.5) // Left
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0,  0.5) << QVector3D( 0.5,    0, -0.5) // Right
                      << QVector3D(-0.5,    0, -0.5) << QVector3D( 0.5,    0, -0.5) << QVector3D( 0.5,    0,  0.5) // Bottom
                      << QVector3D( 0.5,    0,  0.5) << QVector3D(-0.5,    0,  0.5) << QVector3D(-0.5,    0, -0.5);
    spotlightColors << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Front
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Back
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Left
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Right
                    << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) // Bottom
                    << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1);

    numSpotlightVertices = 18;

    spotlightBuffer.create();
    spotlightBuffer.bind();
    spotlightBuffer.allocate(numSpotlightVertices * (3 + 3) * sizeof(GLfloat));

    offset = 0;
    cubeBuffer.write(offset, spotlightVertices.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, spotlightColors.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));

    spotlightBuffer.release();
}

void GlWidget::resizeGL(int width, int height)
{
    if (height == 0) {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

void GlWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    mMatrix.setToIdentity();

    QMatrix4x4 mvMatrix;
    mvMatrix = vMatrix * mMatrix;

    QMatrix3x3 normalMatrix;
    normalMatrix = mvMatrix.normalMatrix();

    QMatrix4x4 lightTransformation;
    lightTransformation.rotate(lightAngle, 0, 1, 0);

    QVector3D lightPosition = lightTransformation * QVector3D(0, 1, 1);

    lightingShaderProgram.bind();

    lightingShaderProgram.setUniformValue("mvpMatrix", pMatrix * mvMatrix);
    lightingShaderProgram.setUniformValue("mvMatrix", mvMatrix);
    lightingShaderProgram.setUniformValue("normalMatrix", normalMatrix);
    lightingShaderProgram.setUniformValue("lightPosition", vMatrix * lightPosition);

    lightingShaderProgram.setUniformValue("ambientColor", QColor(32, 32, 32));
    lightingShaderProgram.setUniformValue("diffuseColor", QColor(128, 128, 128));
    lightingShaderProgram.setUniformValue("specularColor", QColor(255, 255, 255));
    lightingShaderProgram.setUniformValue("ambientReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("diffuseReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("specularReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("shininess", (GLfloat) 100.0);
    lightingShaderProgram.setUniformValue("texture", 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, cubeTexture);
    glActiveTexture(0);

    cubeBuffer.bind();
    int offset = 0;
    lightingShaderProgram.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("vertex");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    lightingShaderProgram.setAttributeBuffer("normal", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("normal");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    lightingShaderProgram.setAttributeBuffer("textureCoordinate", GL_FLOAT, offset, 2, 0);
    lightingShaderProgram.enableAttributeArray("textureCoordinate");
    cubeBuffer.release();

    glDrawArrays(GL_TRIANGLES, 0, numCubeVertices);

    lightingShaderProgram.disableAttributeArray("vertex");
    lightingShaderProgram.disableAttributeArray("normal");
    lightingShaderProgram.disableAttributeArray("textureCoordinate");

    lightingShaderProgram.release();

    mMatrix.setToIdentity();
    mMatrix.translate(lightPosition);
    mMatrix.rotate(lightAngle, 0, 1, 0);
    mMatrix.rotate(45, 1, 0, 0);
    mMatrix.scale(0.1);

    coloringShaderProgram.bind();

    coloringShaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);

    spotlightBuffer.bind();
    offset = 0;
    coloringShaderProgram.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    coloringShaderProgram.enableAttributeArray("vertex");
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    coloringShaderProgram.setAttributeBuffer("color", GL_FLOAT, offset, 3, 0);
    coloringShaderProgram.enableAttributeArray("color");
    spotlightBuffer.release();

    glDrawArrays(GL_TRIANGLES, 0, numSpotlightVertices);

    coloringShaderProgram.disableAttributeArray("vertex");
    coloringShaderProgram.disableAttributeArray("color");

    coloringShaderProgram.release();
}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        alpha -= deltaX;
        while (alpha < 0) {
            alpha += 360;
        }
        while (alpha >= 360) {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90) {
            beta = -90;
        }
        if (beta > 90) {
            beta = 90;
        }
    }

    lastMousePosition = event->pos();

    event->accept();
}

void GlWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            distance *= 1.1;
        } else if (delta > 0) {
            distance *= 0.9;
        }
    }

    event->accept();
}

void GlWidget::timeout()
{
    lightAngle += 1;
    while (lightAngle >= 360) {
        lightAngle -= 360;
    }

    updateGL();
}
