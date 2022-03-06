#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include"qfile.h"
#include"qtextstream.h"
#include"qtablewidget.h"
#include<qtextcodec.h>
#include<qdialog.h>
#include<qmessagebox.h>
#include<dialog.h>
#include<ui_dialog.h>
#include<qevent.h>
#include <QFileDialog>
#include<qtextcodec.h>
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    piao=new Dialog;
    resize(800,600);
    setWindowTitle("功能界面");
    setWindowIcon(QIcon(":/票务系统.png"));
    //修改编码格式
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //导入文件txt
    QFile fp("./text.txt");

    static int row=0;
    if(fp.open(fp.ReadOnly))
    {
        QTextStream ts(&fp);

        for (int idx1 = 0; !ts.atEnd(); idx1++)
        {

            array.append(QVector<QString>());
            row++;
            for (int idx2 = 0; idx2 < 7; idx2++)
            {
                static QString buf;
                ts>>buf;
                array[idx1].append(buf);
            }
        }

        fp.close();
    }



    //1
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->comboBox->addItems(QStringList()<<"北京"<<"长沙"<<"成都"<<"贵阳"<<"广州"<<"合肥"<<"杭州"<<"南昌"<<"合肥"<<"哈尔滨"<<"呼和浩特"<<"昆明"<<"南宁"<<"南京"<<"沈阳"<<"上海"<<"太原"<<"武汉"<<"西安"<<"云南"<<"郑州");
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"航班号"<<"飞机号"<<"目的地"<<"出发时间"<<"最近出发时间"<<"成员定额"<<"余票量");
    ui->tableWidget->horizontalHeader()->setVisible(false);
    connect(ui->pushButton,&QPushButton::clicked,[=]{
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->horizontalHeader()->setVisible(true);
        int cou=0;
        for(int i=0;i<row;i++)
        {
            if(array[i][2]==ui->comboBox->currentText())
            {
                cou++;
                ui->tableWidget->setRowCount(cou);
                for(int j=0;j<7;j++)
                {
                    ui->tableWidget->setItem(cou-1,j,new QTableWidgetItem(array[i][j]));
                }
            }
        }
    });
    //2
    //建立订票人员数组
    //按钮绑定字母区enter
    ui->pushButton->setShortcut(Qt::Key_Return);
    ui->pushButton_2->setShortcut(Qt::Key_Return);
    ui->pushButton_3->setShortcut(Qt::Key_Return);


    QFile fp2("./text2.txt");
    static int row2=0;
    if(fp2.open(fp2.ReadOnly))
    {
        QTextStream ts2(&fp2);

        for (int idx1 = 0; !ts2.atEnd(); idx1++)
        {

            array2.append(QVector<QString>());
            row2++;
            for (int idx2 = 0; idx2 < 4; idx2++)
            {
                static QString buf;
                ts2>>buf;
                array2[idx1].append(buf);
            }
        }

        fp2.close();
    }
    //建立候补人员
    QFile fp3("./text3.txt");

    static int row3=0;
    if(fp3.open(fp3.ReadOnly))
    {
        QTextStream ts3(&fp3);

        for (int idx1 = 0; !ts3.atEnd(); idx1++)
        {

            array3.append(QVector<QString>());
            row3++;
            for (int idx2 = 0; idx2 < 4; idx2++)
            {
                static QString buf;
                ts3>>buf;
                array3[idx1].append(buf);
            }
        }

        fp3.close();
    }

    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"航班号"<<"飞机号"<<"目的地"<<"出发时间"<<"最近出发时间"<<"成员定额"<<"余票量");
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    //订票功能实现
    static QString hb;
    static QString yp;
    connect(ui->pushButton_2,&QPushButton::clicked,[=]{
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"警告","你未输入航班号","好的");
        }
        else
        {
            ui->tableWidget_2->clearContents();
            ui->tableWidget_2->setRowCount(0);
            ui->tableWidget_2->horizontalHeader()->setVisible(true);
            int cou=0;
            for(int i=0;i<row;i++)
            {
                if(array[i][0]==ui->lineEdit->text())
                {
                    cou++;
                    ui->tableWidget_2->setRowCount(cou);
                    for(int j=0;j<7;j++)
                    {
                        ui->tableWidget_2->setItem(cou-1,j,new QTableWidgetItem(array[i][j]));
                    }
                }
            }
        }
    });

    piao->ui->comboBox->addItems(QStringList()<<"1"<<"2"<<"3");
    connect(ui->dp,&QPushButton::clicked,[=]{
        QList<QTableWidgetItem*> items = ui->tableWidget_2->selectedItems();
        if(!items.empty())
        {

            hb=ui->tableWidget_2->selectedItems().at(0)->text();
            yp=ui->tableWidget_2->selectedItems().at(6)->text();

            piao->show();
            piao->ui->comboBox->setCurrentText("1");
            piao->ui->spinBox->setValue(1);
            piao->ui->lineEdit->clear();
        }
        else
            QMessageBox::warning(this,"警告","请先选择一行再进行操作");
    });
    //订票信息及保存

    connect(piao->ui->buttonBox,&QDialogButtonBox::accepted,[=]{
        if(!piao->ui->lineEdit->text().isEmpty())
        {
            if(yp.toInt()>=piao->ui->spinBox->value())
            {
                array2.append(QVector<QString>());
                array2[array2.length()-1].append(piao->ui->lineEdit->text());
                array2[array2.length()-1].append(hb);

                array2[array2.length()-1].append(piao->ui->comboBox->currentText());
                array2[array2.length()-1].append(QString::number( piao->ui->spinBox->value()));
                for(int i=0;i<row;i++)
                {
                    if(array[i][0]==hb)
                    {
                        int a=array[i][6].toInt()-piao->ui->spinBox->value();
                        array[i][6]=QString::number(a);
                    }
                }

                piao->close();
                ui->pushButton_2->click();
                QMessageBox::information(this,"订票成功","望旅途愉快!");
            }
            else
            {
                //余票不足候补
                if(QMessageBox::Ok == QMessageBox::question(piao,"问题","抱歉，余票不足，是否需要候补？",QMessageBox::Ok,QMessageBox::Cancel))
                {

                    if(yp.toInt()>0)
                    {
                        array2.append(QVector<QString>());
                        array2[array2.length()-1].append(piao->ui->lineEdit->text());
                        array2[array2.length()-1].append(hb);

                        array2[array2.length()-1].append(piao->ui->comboBox->currentText());
                        array2[array2.length()-1].append(yp);
                    }
                    array3.append(QVector<QString>());
                    array3[array3.length()-1].append(piao->ui->lineEdit->text());
                    array3[array3.length()-1].append(hb);

                    array3[array3.length()-1].append(piao->ui->comboBox->currentText());
                    array3[array3.length()-1].append(QString::number( piao->ui->spinBox->value()-yp.toInt()));

                    for(int i=0;i<row;i++)
                    {
                        if(array[i][0]==hb)
                        {

                            array[i][6]="0";
                        }
                    }
                    QMessageBox::information(piao,"提示","候补成功");
                    piao->close();
                    ui->pushButton_2->click();
                }
                else
                {

                    QMessageBox::information(piao,"提示","请选择适合的航班");
                }
            }
        }
        else
            QMessageBox::warning(piao,"警告","姓名不能为空");

    });
    connect(piao->ui->buttonBox,&QDialogButtonBox::rejected,[=]{
        piao->close();

        QMessageBox::information(this,"提示","已取消订票");
    });
    //3
    ui->tableWidget_3->setColumnCount(4);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"航班号"<<"座位等级"<<"订票数额");
    ui->tableWidget_3->horizontalHeader()->setVisible(false);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    static QString xm;
    static QString hb2;
    static  QString sl;
    connect(ui->pushButton_3,&QPushButton::clicked,[=]{
        if(ui->lineEdit_2->text().isEmpty())
        {
            QMessageBox::warning(this,"警告","你未输入姓名","好的");
        }
        else
        {
            ui->tableWidget_3->clearContents();
            ui->tableWidget_3->setRowCount(0);
            ui->tableWidget_3->horizontalHeader()->setVisible(true);
            int cou=0;
            for(int i=0;i<array2.length();i++)
            {
                if(array2[i][0]==ui->lineEdit_2->text())
                {
                    cou++;
                    ui->tableWidget_3->setRowCount(cou);
                    for(int j=0;j<4;j++)
                    {
                        ui->tableWidget_3->setItem(cou-1,j,new QTableWidgetItem(array2[i][j]));
                    }
                }
            }
        }
    });
    connect(ui->tp,&QPushButton::clicked,[=]{
        QList<QTableWidgetItem*> items = ui->tableWidget_3->selectedItems();
        if(!items.empty())
        {

            xm=ui->tableWidget_3->selectedItems().at(0)->text();
            hb2=ui->tableWidget_3->selectedItems().at(1)->text();
            sl=ui->tableWidget_3->selectedItems().at(3)->text();

            //退票
            if(QMessageBox::Ok==QMessageBox::warning(this,"警告","是否确定退票？",QMessageBox::Ok,QMessageBox::Cancel))
            {
                //修改订票信息
                if(ui->spinBox->value()>sl.toInt())
                {
                    QMessageBox::warning(this,"警告","请输入合法的订票数额");
                }
                else if(ui->spinBox->value()<=sl.toInt())
                {
                    static int r1;//找选中信息行数
                    for(int i=0;i<array2.length();i++)
                    {
                        if(array2[i][0]==xm && array2[i][1]==hb2)
                        {
                            r1=i;
                            break;
                        }
                    }
                    if(ui->spinBox->value()==sl.toInt())
                    {
                        array2.remove(r1);
                    }
                    if(ui->spinBox->value()<sl.toInt())
                    {
                        array2[r1][3]=QString::number(sl.toInt()-ui->spinBox->value());
                    }
                    QMessageBox::information(this,"提示","退票成功");
                    static int a=ui->spinBox->value();//退票数额
                    if(QMessageBox::Ok== QMessageBox::question(this,"问题","是否询问候补人？",QMessageBox::Ok,QMessageBox::Cancel))
                    {
                        //询问候选人
                        for(int i=0;i<array3.length()&&a>0;i++)
                        {
                            if(array3[i][1]==hb2)
                            {
                                if(array3[i][3].toInt()<=a)
                                {

                                    a=a-array3[i][3].toInt();
                                    array2.append(QVector<QString>());
                                    array2[array2.length()-1].append(array3[i][0]);
                                    array2[array2.length()-1].append(hb2);

                                    array2[array2.length()-1].append(array3[i][2]);
                                    array2[array2.length()-1].append(array3[i][3]);
                                    array3.remove(i);

                                    i--;
                                }
                                else
                                {
                                    array3[i][3]=QString::number(array3[i][3].toInt()-a);
                                    array2.append(QVector<QString>());
                                    array2[array2.length()-1].append(array3[i][0]);
                                    array2[array2.length()-1].append(hb2);

                                    array2[array2.length()-1].append(array3[i][2]);
                                    array2[array2.length()-1].append(QString::number(a));
                                    a=0;
                                }
                            }
                            ui->pushButton_3->click();
                        }
                        //多余的票退回
                        if(a==ui->spinBox->value())
                        {
                            for(int i=0;i<row;i++)
                            {
                                if(array[i][0]==hb2)
                                {
                                    int b=array[i][6].toInt()+a;
                                    array[i][6]=QString::number(b);
                                }
                            }
                            QMessageBox::information(this,"提示","未找到相关候补人，全部票已退回！");
                        }
                        if(a>0)
                        {
                            for(int i=0;i<row;i++)
                            {
                                if(array[i][0]==hb2)
                                {
                                    int b=array[i][6].toInt()+a;
                                    array[i][6]=QString::number(b);
                                }
                            }

                            QMessageBox::information(this,"提示","部分票已候补，部分票已退回！");
                        }
                        if(a<=0)
                        {
                            QMessageBox::information(this,"提示","全部票均被候选人获得！");
                        }
                    }
                    else
                    {
                        for(int i=0;i<row;i++)
                        {
                            if(array[i][0]==hb2)
                            {
                                int a=array[i][6].toInt()+ui->spinBox->value();
                                array[i][6]=QString::number(a);
                            }
                        }
                        QMessageBox::information(this,"提示","全部票已退回！");
                    }
                }


            }
            else
            {
                QMessageBox::information(this,"提示","已取消退票");
            }
        }
        else
            QMessageBox::warning(this,"警告","请先选择一行再进行操作");
    });
    //4
    //建立第四个表
    ui->tableWidget_4->setColumnCount(7);
    ui->tableWidget_4->setHorizontalHeaderLabels(QStringList()<<"航班号"<<"飞机号"<<"目的地"<<"出发时间"<<"最近出发时间"<<"成员定额"<<"余票量");
    ui->tableWidget_4->setRowCount(row);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<7;j++)
        {
            ui->tableWidget_4->setItem(i,j,new QTableWidgetItem(array[i][j]));
        }
    }
    //增行
    connect(ui->add,&QPushButton::clicked,[=]{

        int curc =ui->tableWidget_4->currentRow();
        ui->tableWidget_4->insertRow(curc+1);
    });
    //减行
    connect(ui->del,&QPushButton::clicked,[=]{
        int curc =ui->tableWidget_4->currentRow();
        ui->tableWidget_4->removeRow(curc);
    });
    //还原
    connect(ui->hy,&QPushButton::clicked,[=]{
        ui->tableWidget_4->clearContents();//只清除表中数据，不清除表头内容

        ui->tableWidget_4->setRowCount(0);
        ui->tableWidget_4->setRowCount(row);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<7;j++)
            {
                ui->tableWidget_4->setItem(i,j,new QTableWidgetItem(array[i][j]));
            }
        }//连行也清除掉
    });
    //保存
    connect(ui->bc,&QPushButton::clicked,[&]{
        int a=0;
        for (int idx1 = 0;idx1< ui->tableWidget_4->rowCount(); idx1++)
        {
            for (int idx2 = 0; idx2 < 7; idx2++)
            {
                if(ui->tableWidget_4->item(idx1,idx2)==NULL||ui->tableWidget_4->item(idx1,idx2)->text().isEmpty())
                    a=1;
            }
        }
        if(a==0)
        {
            array.clear();
            row=0;
            for (int idx1 = 0;idx1< ui->tableWidget_4->rowCount(); idx1++)
            {

                array.append(QVector<QString>());
                row++;
                for (int idx2 = 0; idx2 < 7; idx2++)
                {
                    QString str = ui->tableWidget_4->item(idx1,idx2)->text();//取出字符串


                    array[idx1].append(str);
                }
            }
            QMessageBox::information(this,"提示","保存成功");
        }
        else
            QMessageBox::warning(this,"警告","表中存在空格");
    });
    //菜单 数据导出
    connect(ui->action1,&QAction::triggered,[=]{

        QString path= QFileDialog::getExistingDirectory(this, "选择目录", "./", QFileDialog::ShowDirsOnly);

        if(path!=NULL)
        {
            QFile s;
            s.setFileName(path+"/航班信息.csv");
            s.open(QIODevice::WriteOnly |QIODevice::Text);
            QTextStream sl(&s);
            sl.setCodec("GBK");
            QString c="航班号,飞机号,目的地,出发时间,最近出发时间,成员定额,余票量";
            sl<<c<<endl;
            for(int i=0;i<array.length();i++)
            {
                if(i==array.length()-1)
                {
                    sl<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<','<<array[i][3]<<','<<array[i][4]<<','<<array[i][5]<<','<<array[i][6];
                }
                else
                    sl<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<','<<array[i][3]<<','<<array[i][4]<<','<<array[i][5]<<','<<array[i][6]<<endl;
            }
            s.close();
        }
    });
    connect(ui->action2,&QAction::triggered,[=]{

        QString path= QFileDialog::getExistingDirectory(this, "选择目录", "./", QFileDialog::ShowDirsOnly);
        QFile s;
        s.setFileName(path+"/订票人员.csv");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream sl(&s);
        sl.setCodec("GBK");
        QString b="姓名,航班,座位等级,订票数";
        sl<<b<<endl;
        for(int i=0;i<array2.length();i++)
        {
            if(i==array2.length()-1)
            {
                sl<<array2[i][0]<<','<<array2[i][1]<<','<<array2[i][2]<<','<<array2[i][3];
            }
            else
                sl<<array2[i][0]<<','<<array2[i][1]<<','<<array2[i][2]<<','<<array2[i][3]<<endl;
        }
        s.close();
    });
    connect(ui->action3,&QAction::triggered,[=]{

        QString path= QFileDialog::getExistingDirectory(this, "选择目录", "./", QFileDialog::ShowDirsOnly);
        QFile s;
        s.setFileName(path+"/候补人员.csv");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QString a="姓名,航班,座位等级,候补票数";

        QTextStream sl(&s);
        sl.setCodec("GBK");
        sl<<a<<endl;
        for(int i=0;i<array3.length();i++)
        {
            if(i==array3.length()-1)
            {
                sl<<array3[i][0]<<','<<array3[i][1]<<','<<array3[i][2]<<','<<array3[i][3];
            }
            else
                sl<<array3[i][0]<<','<<array3[i][1]<<','<<array3[i][2]<<','<<array3[i][3]<<endl;
        }
        s.close();
    });
    connect(ui->actionall,&QAction::triggered,[=]{
        QString path= QFileDialog::getExistingDirectory(this, "选择目录", "./", QFileDialog::ShowDirsOnly);
        QFile s;
        s.setFileName(path+"/航班信息.csv");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream sl(&s);
        sl.setCodec("GBK");
        QString c="航班号,飞机号,目的地,出发时间,最近出发时间,成员定额,余票量";
        sl<<c<<endl;
        for(int i=0;i<array.length();i++)
        {
            if(i==array.length()-1)
            {
                sl<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<','<<array[i][3]<<','<<array[i][4]<<','<<array[i][5]<<','<<array[i][6];
            }
            else
                sl<<array[i][0]<<','<<array[i][1]<<','<<array[i][2]<<','<<array[i][3]<<','<<array[i][4]<<','<<array[i][5]<<','<<array[i][6]<<endl;
        }
        s.close();
        s.setFileName(path+"/订票人员.csv");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QString b="姓名,航班,座位等级,订票数";
        sl<<b<<endl;
        for(int i=0;i<array2.length();i++)
        {
            if(i==array2.length()-1)
            {
                sl<<array2[i][0]<<','<<array2[i][1]<<','<<array2[i][2]<<','<<array2[i][3];
            }
            else
                sl<<array2[i][0]<<','<<array2[i][1]<<','<<array2[i][2]<<','<<array2[i][3]<<endl;
        }
        s.close();
        s.setFileName(path+"/候补人员.csv");
        s.open(QIODevice::WriteOnly |QIODevice::Text);
        QString a="姓名,航班,座位等级,候补票数";
        sl<<a<<endl;
        for(int i=0;i<array3.length();i++)
        {
            if(i==array3.length()-1)
            {
                sl<<array3[i][0]<<','<<array3[i][1]<<','<<array3[i][2]<<','<<array3[i][3];
            }
            else
                sl<<array3[i][0]<<','<<array3[i][1]<<','<<array3[i][2]<<','<<array3[i][3]<<endl;
        }

        s.close();
    });

}

MainWindow2::~MainWindow2()
{
    delete ui;
}

