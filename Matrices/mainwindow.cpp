#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Matrix.h"
#include <iostream>
#include <stdarg.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->mainTabWidget->setCurrentIndex(0);
    webDisplay = new QWebEngineView;
    webDisplay->setUrl(QUrl("qrc:///html/m1.htm"));
    webDisplay->setMaximumHeight(540);
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


    QString msg = "Resultado:";
    if(ui->tableWidget->rowCount() == ui->tableWidget_2->rowCount() && ui->tableWidget->columnCount() == ui->tableWidget_2->columnCount()){
        Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
        Matrix b = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
               a.set(i, j, ql->text().toDouble());
            }
        for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
               b.set(i, j, ql->text().toDouble());
            }
        Matrix res = a + b;
        msg += "(\n";
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
                msg+=QString::number(res.at(i, j))+", ";
            }
            msg+="\n";
        }
        msg+=")";
    }
    else{
        msg = "error en la configuracion matricial";
    }


    QMessageBox msgBox;

    msgBox.setText(msg);
    msgBox.setWindowTitle("Resultado:");
    msgBox.setWindowModality(Qt::WindowModal);
    msgBox.exec();
    this->renderResult();

}

void MainWindow::on_pushButton_4_clicked()
{
    QString msg = "Resultado:";
    if(ui->tableWidget->rowCount() == ui->tableWidget_2->rowCount() && ui->tableWidget->columnCount() == ui->tableWidget_2->columnCount()){
        Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
        Matrix b = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
               a.set(i, j, ql->text().toDouble());
            }
        for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
               b.set(i, j, ql->text().toDouble());
            }
        Matrix res = a - b;
        msg += "(\n";
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
                msg+=QString::number(res.at(i, j))+", ";
            }
            msg+="\n";
        }
        msg+=")";
    }
    else{
        msg = "error en la configuracion matricial";
    }


    QMessageBox msgBox;

    msgBox.setText(msg);
    msgBox.setWindowTitle("Resultado:");
    msgBox.setWindowModality(Qt::WindowModal);
    msgBox.exec();
    this->renderResult();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString msg = "Resultado:";
    if(ui->tableWidget->columnCount() == ui->tableWidget_2->rowCount()){
        Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
        Matrix b = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
               a.set(i, j, ql->text().toDouble());
            }
        for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
               b.set(i, j, ql->text().toDouble());
            }
        Matrix res = a * b;
        msg += "(\n";
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
                msg+=QString::number(res.at(i, j))+", ";
            }
            msg+="\n";
        }
        msg+=")";
    }
    else{
        msg = "error en la configuracion matricial";
    }


    QMessageBox msgBox;

    msgBox.setText(msg);
    msgBox.setWindowTitle("Resultado:");
    msgBox.setWindowModality(Qt::WindowModal);
    msgBox.exec();
    this->renderResult();

}

void MainWindow::renderResult(){
    QString js = "document.removeChild(document.documentElement);";
    webDisplay->page()->runJavaScript(js);

}

void MainWindow::on_actionResultado_triggered()
{
    if(webDisplay->isHidden()){
        webDisplay->show();
    }
    else{
        webDisplay->hide();
    }
}

void MainWindow::on_actionSalir_triggered()
{
    QApplication::quit();
}
