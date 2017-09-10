/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "oglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout;
    OpenGLWidget *openGLWidget;
    QLabel *labelCoordinates;
    QHBoxLayout *horizontalLayout_for_X;
    QLabel *labelX;
    QSlider *xSlider;
    QHBoxLayout *horizontalLayout_for_Y;
    QLabel *labelY;
    QSlider *ySlider;
    QHBoxLayout *horizontalLayout_for_Z;
    QLabel *labelZ;
    QSlider *zSlider;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(379, 401);
        verticalLayout = new QVBoxLayout(Window);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openGLWidget = new OpenGLWidget(Window);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(openGLWidget);

        labelCoordinates = new QLabel(Window);
        labelCoordinates->setObjectName(QStringLiteral("labelCoordinates"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCoordinates->sizePolicy().hasHeightForWidth());
        labelCoordinates->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(labelCoordinates);

        horizontalLayout_for_X = new QHBoxLayout();
        horizontalLayout_for_X->setSpacing(6);
        horizontalLayout_for_X->setObjectName(QStringLiteral("horizontalLayout_for_X"));
        labelX = new QLabel(Window);
        labelX->setObjectName(QStringLiteral("labelX"));

        horizontalLayout_for_X->addWidget(labelX);

        xSlider = new QSlider(Window);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        xSlider->setMaximum(5760);
        xSlider->setSingleStep(16);
        xSlider->setPageStep(15);
        xSlider->setOrientation(Qt::Horizontal);
        xSlider->setTickPosition(QSlider::TicksAbove);
        xSlider->setTickInterval(240);

        horizontalLayout_for_X->addWidget(xSlider);


        verticalLayout->addLayout(horizontalLayout_for_X);

        horizontalLayout_for_Y = new QHBoxLayout();
        horizontalLayout_for_Y->setSpacing(6);
        horizontalLayout_for_Y->setObjectName(QStringLiteral("horizontalLayout_for_Y"));
        labelY = new QLabel(Window);
        labelY->setObjectName(QStringLiteral("labelY"));

        horizontalLayout_for_Y->addWidget(labelY);

        ySlider = new QSlider(Window);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setMaximum(5760);
        ySlider->setSingleStep(16);
        ySlider->setPageStep(15);
        ySlider->setOrientation(Qt::Horizontal);
        ySlider->setTickPosition(QSlider::TicksAbove);
        ySlider->setTickInterval(240);

        horizontalLayout_for_Y->addWidget(ySlider);


        verticalLayout->addLayout(horizontalLayout_for_Y);

        horizontalLayout_for_Z = new QHBoxLayout();
        horizontalLayout_for_Z->setSpacing(6);
        horizontalLayout_for_Z->setObjectName(QStringLiteral("horizontalLayout_for_Z"));
        labelZ = new QLabel(Window);
        labelZ->setObjectName(QStringLiteral("labelZ"));

        horizontalLayout_for_Z->addWidget(labelZ);

        zSlider = new QSlider(Window);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setMaximum(5760);
        zSlider->setSingleStep(16);
        zSlider->setPageStep(15);
        zSlider->setOrientation(Qt::Horizontal);
        zSlider->setTickPosition(QSlider::TicksAbove);
        zSlider->setTickInterval(240);

        horizontalLayout_for_Z->addWidget(zSlider);


        verticalLayout->addLayout(horizontalLayout_for_Z);


        retranslateUi(Window);
        QObject::connect(xSlider, SIGNAL(valueChanged(int)), openGLWidget, SLOT(setXRotation(int)));
        QObject::connect(ySlider, SIGNAL(valueChanged(int)), openGLWidget, SLOT(setYRotation(int)));
        QObject::connect(zSlider, SIGNAL(valueChanged(int)), openGLWidget, SLOT(setZRotation(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        labelCoordinates->setText(QApplication::translate("Window", "Rotation:", 0));
        labelX->setText(QApplication::translate("Window", "X", 0));
        labelY->setText(QApplication::translate("Window", "Y", 0));
        labelZ->setText(QApplication::translate("Window", "Z", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
