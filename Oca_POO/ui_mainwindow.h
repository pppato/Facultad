/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Oca
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *tableroLayout;
    QPushButton *dado;
    QTextEdit *informacion;
    QSpinBox *spinBox;
    QPushButton *botonIniciar;
    QLabel *label;

    void setupUi(QMainWindow *Oca)
    {
        if (Oca->objectName().isEmpty())
            Oca->setObjectName("Oca");
        Oca->resize(800, 600);
        centralwidget = new QWidget(Oca);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 110, 631, 331));
        tableroLayout = new QGridLayout(gridLayoutWidget);
        tableroLayout->setObjectName("tableroLayout");
        tableroLayout->setContentsMargins(0, 0, 0, 0);
        dado = new QPushButton(centralwidget);
        dado->setObjectName("dado");
        dado->setGeometry(QRect(670, 120, 111, 91));
        informacion = new QTextEdit(centralwidget);
        informacion->setObjectName("informacion");
        informacion->setGeometry(QRect(280, 10, 371, 81));
        informacion->setReadOnly(true);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(670, 20, 91, 51));
        spinBox->setMinimum(2);
        spinBox->setMaximum(4);
        botonIniciar = new QPushButton(centralwidget);
        botonIniciar->setObjectName("botonIniciar");
        botonIniciar->setGeometry(QRect(670, 80, 101, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 510, 800, 600));
        Oca->setCentralWidget(centralwidget);

        retranslateUi(Oca);

        QMetaObject::connectSlotsByName(Oca);
    } // setupUi

    void retranslateUi(QMainWindow *Oca)
    {
        Oca->setWindowTitle(QCoreApplication::translate("Oca", "MainWindow", nullptr));
        dado->setText(QCoreApplication::translate("Oca", "Lanzar", nullptr));
        botonIniciar->setText(QCoreApplication::translate("Oca", "Iniciar juego", nullptr));
        label->setText(QCoreApplication::translate("Oca", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Oca: public Ui_Oca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
