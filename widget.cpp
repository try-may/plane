#include "widget.h"
#include "ui_widget.h"
#include"qmainwindow.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("登陆界面");
    setWindowIcon(QIcon(":/飞机.png"));
    setFixedSize(300,200);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::close);
    qmain=new MainWindow;
    connect(ui->pushButton,&QPushButton::clicked,[=]
    {
        qmain->show();
        close();
    });

}

Widget::~Widget()
{
    delete ui;
}

