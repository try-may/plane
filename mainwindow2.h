#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include<dialog.h>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
    Ui::MainWindow2 *ui;
    Dialog * piao;
    QVector<QVector<QString>> array;
    QVector<QVector<QString>> array2;
    QVector<QVector<QString>> array3;
private:

};

#endif // MAINWINDOW2_H
