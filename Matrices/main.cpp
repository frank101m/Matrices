#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    //declaraciones generales:

	QApplication app(argc, argv);
    MainWindow window;
    window.show();
	return app.exec();
}



