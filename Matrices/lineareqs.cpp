#pragma once
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <QString>
#include <QDir>

#ifdef _WIN32
#include "windows.h"
#endif

void MainWindow::on_pushButton_6_clicked()
{
#ifdef _WIN32
	QProcess process;
	QMessageBox pathMsg;

	QString file = QCoreApplication::applicationDirPath() + "/" + "texlive/pdflatex.exe matrixtest.tex";

	process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
	process.start(file);

	if (!process.waitForStarted()) {
		pathMsg.setText(file + " : " + process.errorString());
	} else {
		pathMsg.setText("Iniciado");
	}

	if (process.waitForFinished())
	{
		pathMsg.setText(process.readAll());
	}

	pathMsg.exec();
#endif
}