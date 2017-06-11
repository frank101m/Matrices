#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>
#include <QTabWidget>
#include <QVBoxLayout>
#include <qfile.h>
#include <iostream>


int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(Resource);

    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *basicOperationsModule = new QWidget;
    QWebEngineView *display = new QWebEngineView;
    //Cambiar estos modulos a los que cada quien va a utilizar:
    QWidget *modulo2 = new QWidget;
    QWidget *modulo3 = new QWidget;

    //Cuando este más trabajado debemos organizar esto en metodos
    tabWidget->addTab(basicOperationsModule, "Operaciones básicas con matrices");
    //Embedir modulos
    tabWidget->addTab(modulo2, "Modulo 2");
    tabWidget->addTab(modulo3, "Modulo 3");

    layout->addWidget(tabWidget);
    layout->addWidget(display);

	display->setUrl(QUrl("qrc:///html/katex.htm"));

	//Leer archivo HTML de recursor

    //Config de la pantalla principal
    window->setLayout(layout);
    window->resize(1024, 750);
    window->show();

    //QWebEngineView view;
    //view.setUrl(QUrl(QStringLiteral("https://cdn.rawgit.com/mathjax/MathJax/2.7.1/test/sample.html")));
    //view.resize(1024, 750);
    //view.show();

	return app.exec();
}
