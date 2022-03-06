/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *actionall;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget_2;
    QPushButton *dp;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *tp;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *bc;
    QPushButton *hy;
    QPushButton *del;
    QPushButton *add;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QStringLiteral("MainWindow2"));
        MainWindow2->resize(524, 536);
        action1 = new QAction(MainWindow2);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(MainWindow2);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(MainWindow2);
        action3->setObjectName(QStringLiteral("action3"));
        actionall = new QAction(MainWindow2);
        actionall->setObjectName(QStringLiteral("actionall"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_2);

        tableWidget_2 = new QTableWidget(tab_2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_2->addWidget(tableWidget_2);

        dp = new QPushButton(tab_2);
        dp->setObjectName(QStringLiteral("dp"));

        verticalLayout_2->addWidget(dp);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setLineWidth(1);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);

        verticalLayout_3->addWidget(label_2);

        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_3->addWidget(widget_3);

        tableWidget_3 = new QTableWidget(tab_3);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));

        verticalLayout_3->addWidget(tableWidget_3);

        widget_5 = new QWidget(tab_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_3);

        spinBox = new QSpinBox(widget_6);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(9);

        horizontalLayout_6->addWidget(spinBox);


        horizontalLayout_5->addWidget(widget_6);

        tp = new QPushButton(widget_5);
        tp->setObjectName(QStringLiteral("tp"));

        horizontalLayout_5->addWidget(tp);


        verticalLayout_3->addWidget(widget_5);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget_4 = new QTableWidget(tab_4);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));

        gridLayout_2->addWidget(tableWidget_4, 0, 2, 1, 1);

        widget_4 = new QWidget(tab_4);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bc = new QPushButton(widget_4);
        bc->setObjectName(QStringLiteral("bc"));

        horizontalLayout->addWidget(bc);

        hy = new QPushButton(widget_4);
        hy->setObjectName(QStringLiteral("hy"));

        horizontalLayout->addWidget(hy);

        del = new QPushButton(widget_4);
        del->setObjectName(QStringLiteral("del"));

        horizontalLayout->addWidget(del);

        add = new QPushButton(widget_4);
        add->setObjectName(QStringLiteral("add"));

        horizontalLayout->addWidget(add);


        gridLayout_2->addWidget(widget_4, 1, 2, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 524, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow2->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(actionall);

        retranslateUi(MainWindow2);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QApplication::translate("MainWindow2", "MainWindow", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindow2", "\350\210\252\347\217\255\344\277\241\346\201\257", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow2", "\350\256\242\347\245\250\344\272\272\345\221\230", Q_NULLPTR));
        action3->setText(QApplication::translate("MainWindow2", "\345\200\231\350\241\245\344\272\272\345\221\230", Q_NULLPTR));
        actionall->setText(QApplication::translate("MainWindow2", "\346\211\200\346\234\211\344\277\241\346\201\257", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow2", "\346\237\245\350\257\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow2", "\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow2", "\350\257\267\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow2", "\346\237\245\350\257\242", Q_NULLPTR));
        dp->setText(QApplication::translate("MainWindow2", "\350\256\242\347\245\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow2", "\350\256\242\347\245\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow2", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow2", "\346\237\245\350\257\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow2", "\351\200\200\347\245\250\346\225\260\351\242\235:", Q_NULLPTR));
        tp->setText(QApplication::translate("MainWindow2", "\351\200\200\347\245\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow2", "\351\200\200\347\245\250", Q_NULLPTR));
        bc->setText(QApplication::translate("MainWindow2", "\344\277\235\345\255\230", Q_NULLPTR));
        hy->setText(QApplication::translate("MainWindow2", "\350\277\230\345\216\237", Q_NULLPTR));
        del->setText(QApplication::translate("MainWindow2", "\345\210\240\351\231\244", Q_NULLPTR));
        add->setText(QApplication::translate("MainWindow2", "\345\242\236\345\212\240", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow2", "\344\277\256\346\224\271", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow2", "\345\257\274\345\207\272\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
