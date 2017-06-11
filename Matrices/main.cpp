#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	//Testeando git
    MainWindow w;
    w.show();

    return a.exec();
}
