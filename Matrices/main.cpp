#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>
#include <QTabWidget>
#include <QVBoxLayout>
#include <qfile.h>
#include <iostream>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

void loadModuleOne(QTabWidget*);

int main(int argc, char *argv[])
{
    //declaraciones generales:
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(Resource);
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QTabWidget *tabWidget = new QTabWidget;

    //Cambiar estos modulos a los que cada quien va a utilizar, solo son de prueba:
    QWidget *modulo2 = new QWidget;
    QWidget *modulo3 = new QWidget;

    //Cuando este más trabajado debemos organizar esto en metodos
    //Mi método para cargar cosas :3
    loadModuleOne(tabWidget);

    //Embedir sus modulos en metodos:
    tabWidget->addTab(modulo2, "Modulo 2");
    tabWidget->addTab(modulo3, "Modulo 3");


    //seteando layouts y widgets
    layout->addWidget(tabWidget);


    /*
     * Las siguientes lineas son para poner el widget de web, como acordamos cada modulo tendra uno propkio:
     * Leer archivo HTML de recursor :
     *     QWebEngineView *display = new QWebEngineView;
     *     display->setUrl(QUrl("qrc:///html/katex.htm"));
     *     layout->addWidget(display);
     */



    //Config de la pantalla principal
    window->setLayout(layout);
    window->resize(1024, 750);
    window->show();


	return app.exec();
}

void loadModuleOne(QTabWidget *parent)
{
    QWidget *basicOperationsModule = new QWidget;
    QWebEngineView *displayBasicOperations = new QWebEngineView;
    QVBoxLayout *basicOperationsLayout = new QVBoxLayout;
    QGridLayout *moduleControls = new QGridLayout;
    QLabel *lblMatrixAx = new QLabel;
    QLabel *lblMatrixBx = new QLabel;
    QLabel *lblMatrixAy = new QLabel;
    QLabel *lblMatrixBy = new QLabel;
    QSpinBox *aDimenX = new QSpinBox;
    QSpinBox *bDimenX = new QSpinBox;
    QSpinBox *aDimenY = new QSpinBox;
    QSpinBox *bDimenY = new QSpinBox;
    QPushButton *generateMatrixA = new QPushButton;
    QPushButton *generateMatrixB = new QPushButton;

    generateMatrixA->setText("Generar matriz A");
    generateMatrixB->setText("Generar matriz B");
    aDimenX->setMinimum(2);
    bDimenX->setMinimum(2);
    aDimenY->setMinimum(2);
    bDimenY->setMinimum(2);
    aDimenX->setMaximum(15);
    bDimenX->setMaximum(15);
    aDimenY->setMaximum(15);
    bDimenY->setMaximum(15);
    lblMatrixAx->setText("Matriz A x");
    lblMatrixAx->setAlignment(Qt::AlignCenter);
    lblMatrixBx->setText("Matriz B x");
    lblMatrixBx->setAlignment(Qt::AlignCenter);
    lblMatrixAy->setText("Matriz A y");
    lblMatrixAy->setAlignment(Qt::AlignCenter);
    lblMatrixBy->setText("Matriz B y");
    lblMatrixBy->setAlignment(Qt::AlignCenter);
    moduleControls->addWidget(lblMatrixAx, 0, 0);
    moduleControls->addWidget(lblMatrixAy, 0, 1);
    moduleControls->addWidget(lblMatrixBx, 0, 2);
    moduleControls->addWidget(lblMatrixBy, 0, 3);
    moduleControls->addWidget(aDimenX, 1, 0);
    moduleControls->addWidget(aDimenY, 1, 1);
    moduleControls->addWidget(bDimenX, 1, 2);
    moduleControls->addWidget(bDimenY, 1, 3);
    moduleControls->addWidget(generateMatrixA, 2, 0);
    moduleControls->addWidget(generateMatrixB, 2, 2);
    basicOperationsModule->setLayout(basicOperationsLayout);
    basicOperationsLayout->addLayout(moduleControls);
    parent->addTab(basicOperationsModule, "Operaciones básicas con matrices");
    displayBasicOperations->setUrl(QUrl(QStringLiteral("https://cdn.rawgit.com/mathjax/MathJax/2.7.1/test/sample.html")));
    basicOperationsLayout->addWidget(displayBasicOperations);


}
