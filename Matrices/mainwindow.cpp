#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Matrix.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->mainTabWidget->setCurrentIndex(0);
    webDisplay = new QWebEngineView;
    webDisplay->setUrl(QUrl("qrc:///html/katex.htm"));
    ui->basicMatrixOperations->layout()->addWidget(webDisplay);
    setTableValidatorA();
    setTableValidatorB();


}

MainWindow::~MainWindow()
{
    delete webDisplay;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    ui->tableWidget->setRowCount(ui->spinBox->value());
    ui->tableWidget->setColumnCount(ui->spinBox_2->value());
    setTableValidatorA();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget_2->setRowCount(ui->spinBox_3->value());
    ui->tableWidget_2->setColumnCount(ui->spinBox_4->value());
    setTableValidatorB();
}

void MainWindow::setTableValidatorA(){
    for(int row = 0; row < ui->tableWidget->rowCount(); row++){
        for(int column = 0; column < ui->tableWidget->columnCount(); column++){
            QLineEdit *ql = new QLineEdit;
            ql->setValidator(new QDoubleValidator(ql));
            ui->tableWidget->setCellWidget(row, column, ql);
        }
    }
}


void MainWindow::setTableValidatorB(){
    for(int row = 0; row < ui->tableWidget_2->rowCount(); row++){
        for(int column = 0; column < ui->tableWidget_2->columnCount(); column++){
            QLineEdit *ql = new QLineEdit;
            ql->setValidator(new QDoubleValidator(ql));
            ui->tableWidget_2->setCellWidget(row, column, ql);
        }
    }
}





void MainWindow::on_pushButton_3_clicked()
{
    int aCol = ui->tableWidget->columnCount();
    int aRow = ui->tableWidget->rowCount();
    int bCol = ui->tableWidget_2->columnCount();
    int bRow = ui->tableWidget_2->rowCount();
    QString msg = "";
    double **res;
    res = new double *[aRow];
    for(int i = 0; i < aRow; i++)
        res[i] = new double[aCol];

    //res = new double[aRow][bCol];
    if(aCol == bCol && aRow == bRow){
        for(int i = 0; i < aRow; i++){
            for(int j = 0; j< aCol; j++){
                QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
                double a = ql->text().toDouble();
                QLineEdit *ql2 = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
                double b = ql2->text().toDouble();
                res[i][j] = a+b;
                msg += QString::number(res[i][j])+", ";
            }
            msg+="\n";
        }
    }
    else
        msg+= "No se pudo realizar la suma. Revise la configuración matricial!";

    QMessageBox msgBox;    

    msgBox.setText(msg);
    msgBox.setWindowTitle("Resultado:");
    msgBox.setWindowModality(Qt::WindowModal);
    msgBox.exec();

    for(int i = 0; i < aCol; i++)
        delete[] res[i];
    delete[] res;
}
