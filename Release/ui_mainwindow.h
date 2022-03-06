/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *cx;
    QToolButton *dp;
    QToolButton *tp;
    QToolButton *xg;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(497, 339);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cx = new QToolButton(widget);
        cx->setObjectName(QStringLiteral("cx"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        cx->setIcon(icon);
        cx->setIconSize(QSize(40, 40));
        cx->setCheckable(false);
        cx->setAutoRepeat(false);
        cx->setAutoExclusive(false);
        cx->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(cx);

        dp = new QToolButton(widget);
        dp->setObjectName(QStringLiteral("dp"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\350\256\242\347\245\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        dp->setIcon(icon1);
        dp->setIconSize(QSize(40, 40));
        dp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(dp);

        tp = new QToolButton(widget);
        tp->setObjectName(QStringLiteral("tp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\351\200\200\347\245\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        tp->setIcon(icon2);
        tp->setIconSize(QSize(40, 40));
        tp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(tp);

        xg = new QToolButton(widget);
        xg->setObjectName(QStringLiteral("xg"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\344\277\256\346\224\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        xg->setIcon(icon3);
        xg->setIconSize(QSize(40, 40));
        xg->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(xg);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        cx->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        dp->setText(QApplication::translate("MainWindow", "\350\256\242\347\245\250", Q_NULLPTR));
        tp->setText(QApplication::translate("MainWindow", "\351\200\200\347\245\250", Q_NULLPTR));
        xg->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
