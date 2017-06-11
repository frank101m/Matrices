#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>
#include <QTabWidget>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *basicOperationsModule = new QWidget;
    QWidget *modulo2 = new QWidget;
    QWidget *modulo3 = new QWidget;
    QWebEngineView *display = new QWebEngineView;

    tabWidget->addTab(basicOperationsModule, "Operaciones básicas con matrices");
    tabWidget->addTab(modulo2, "Modulo 2");
    tabWidget->addTab(modulo3, "Modulo 3");
    layout->addWidget(tabWidget);
    display->setUrl(QUrl(QStringLiteral("https://cdn.rawgit.com/mathjax/MathJax/2.7.1/test/sample.html")));
    layout->addWidget(display);

    window->setLayout(layout);
    window->resize(1024, 750);
    window->show();

    //QWebEngineView view;
    //view.setUrl(QUrl(QStringLiteral("https://cdn.rawgit.com/mathjax/MathJax/2.7.1/test/sample.html")));
    //view.resize(1024, 750);
    //view.show();

	return app.exec();
}
