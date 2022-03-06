#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<qvector.h>
#include <QMainWindow>
#include<mainwindow2.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MainWindow2 * func;
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
