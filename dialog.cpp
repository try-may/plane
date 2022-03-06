#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("订票界面");
    // QspinBox移动Qslider跟着移动
    void(QSpinBox:: * span)(int)=&QSpinBox::valueChanged;
    connect (ui->spinBox ,span, ui->horizontalSlider , &QSlider::setValue);

    // Qslider跟着移动QspinBox移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

Dialog::~Dialog()
{
    delete ui;
}
