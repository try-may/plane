#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    MainWindow *qmain;
private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
