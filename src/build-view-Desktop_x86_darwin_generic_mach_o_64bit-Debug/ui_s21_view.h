/********************************************************************************
** Form generated from reading UI file 's21_view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_VIEW_H
#define UI_S21_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_s21_view
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *s21_view)
    {
        if (s21_view->objectName().isEmpty())
            s21_view->setObjectName(QString::fromUtf8("s21_view"));
        s21_view->resize(800, 600);
        centralwidget = new QWidget(s21_view);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s21_view->setCentralWidget(centralwidget);
        menubar = new QMenuBar(s21_view);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        s21_view->setMenuBar(menubar);
        statusbar = new QStatusBar(s21_view);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        s21_view->setStatusBar(statusbar);

        retranslateUi(s21_view);

        QMetaObject::connectSlotsByName(s21_view);
    } // setupUi

    void retranslateUi(QMainWindow *s21_view)
    {
        s21_view->setWindowTitle(QCoreApplication::translate("s21_view", "s21_view", nullptr));
    } // retranslateUi

};

namespace Ui {
    class s21_view: public Ui_s21_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_VIEW_H
