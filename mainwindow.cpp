#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qpushbutton.h>
#include"ui_mainwindow2.h"
#include"qfile.h"
#include"qtextstream.h"
#include"qdatetime.h"
#include"QDate"
#include<qtimer.h>
#include<qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("功能界面");
    setWindowIcon(QIcon(":/功能.png"));
    //建立mainwindow2
    func=new MainWindow2;
    //tab四个界面
    connect(ui->cx,&QPushButton::clicked,[=]()
    {
        func->show();
        func->ui->tabWidget->setCurrentIndex(0);
    });
    connect(ui->dp,&QPushButton::clicked,[=]()
    {
        func->show();
        func->ui->tabWidget->setCurrentIndex(1);
    });
    connect(ui->tp,&QPushButton::clicked,[=]()
    {
        func->show();
        func->ui->tabWidget->setCurrentIndex(2);
    });
    connect(ui->xg,&QPushButton::clicked,[=]()
    {
        func->show();
        func->ui->tabWidget->setCurrentIndex(3);
    });
    QTimer * timer= new QTimer(this);
    timer->start(25);
    QDateTime now=QDateTime::currentDateTime();
    QString now1=now.toString("yyyy年MM月dd日 dddd hh:mm:ss");

    QString n="现在是"+now1;
    ui->label->setText(n);
    static int pos=11;
    connect(timer,&QTimer::timeout,[=]()
    {
        pos+=1;
        if(ui->label->x()==this->width())
        {
            pos=11;
            ui->label->move(pos,11);
            QDateTime now=QDateTime::currentDateTime();
            QString now1=now.toString("yyyy年MM月dd日 dddd hh:mm:ss");
            QString n="现在是"+now1;
            ui->label->setText(n);
        }
        ui->label->move(pos,11);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{

    if(QMessageBox::Ok == QMessageBox::question(this,"问题","请问需要保存数据吗？",QMessageBox::Ok,QMessageBox::Cancel))
    {
        QFile s;
        s.setFileName("./text.txt");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream sl(&s);
        for(int i=0;i<func->array.length();i++)
        {
            if(i==func->array.length()-1)
            {
                sl<<func->array[i][0]<<' '<<func->array[i][1]<<' '<<func->array[i][2]<<' '<<func->array[i][3]<<' '<<func->array[i][4]<<' '<<func->array[i][5]<<' '<<func->array[i][6];
            }
            else
                sl<<func->array[i][0]<<' '<<func->array[i][1]<<' '<<func->array[i][2]<<' '<<func->array[i][3]<<' '<<func->array[i][4]<<' '<<func->array[i][5]<<' '<<func->array[i][6]<<endl;
        }
        s.close();
        s.setFileName("./text2.txt");
        s.open(QIODevice::WriteOnly |QIODevice::Text);

        for(int i=0;i<func->array2.length();i++)
        {
            if(i==func->array2.length()-1)
            {
                sl<<func->array2[i][0]<<' '<<func->array2[i][1]<<' '<<func->array2[i][2]<<' '<<func->array2[i][3];
            }
            else
                sl<<func->array2[i][0]<<' '<<func->array2[i][1]<<' '<<func->array2[i][2]<<' '<<func->array2[i][3]<<endl;
        }
        s.close();
        s.setFileName("./text3.txt");
        s.open(QIODevice::WriteOnly |QIODevice::Text);

        for(int i=0;i<func->array3.length();i++)
        {
            if(i==func->array3.length()-1)
            {
                sl<<func->array3[i][0]<<' '<<func->array3[i][1]<<' '<<func->array3[i][2]<<' '<<func->array3[i][3];
            }
            else
                sl<<func->array3[i][0]<<' '<<func->array3[i][1]<<' '<<func->array3[i][2]<<' '<<func->array3[i][3]<<endl;
        }
        s.close();
    }
    if(func->isVisible())
    {
        func->close();
    }
}
