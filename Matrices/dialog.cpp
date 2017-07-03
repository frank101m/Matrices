#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, int *m, double *t):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->max = m;
    this->tol = t;
    ui->lineEdit->setValidator(new QDoubleValidator(ui->lineEdit));
    ui->lineEdit_2->setValidator(new QIntValidator(ui->lineEdit_2));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

    *max = ui->lineEdit_2->text().toInt();
    *tol = ui->lineEdit->text().toDouble();
}

void Dialog::on_buttonBox_rejected()
{
    *max = 15;
    *tol = 0.000001;
}
