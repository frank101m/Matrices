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

}

MainWindow::~MainWindow()
{
    delete ui;
    free (webDisplay);
}

void MainWindow::on_pushButton_clicked()
{


    ui->tableWidget->setRowCount(ui->spinBox->value());
    ui->tableWidget->setColumnCount(ui->spinBox_2->value());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget_2->setRowCount(ui->spinBox_3->value());
    ui->tableWidget_2->setColumnCount(ui->spinBox_4->value());
}
