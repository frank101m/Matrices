#include "mainwindow.h"
#include "ui_mainwindow.h"

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




