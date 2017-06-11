#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);

	QWebEngineView view;

	view.setUrl(QUrl(QStringLiteral("qrc:/mathjax.html")));
	view.resize(1024, 750);
	view.show();

	return app.exec();
}
