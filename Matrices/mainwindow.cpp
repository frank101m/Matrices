#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <qdir.h>
#include <iostream>
#include <stdarg.h>

//Partes numericas
#include "LinearSolver.h"

#ifdef _WIN32
#include "windows.h"
#endif // 



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
	setLinearEqTableValidator();
	setUpVarsValidation();

}



MainWindow::~MainWindow()
{
    delete webDisplay;
    delete ui;
}
void MainWindow::setUpVarsValidation(){
	ui->acceptVars->setEnabled(false);
	QRegExp re("^(([a-z]|[A-Z])|([a-z]_[0-9]|[A-Z]_[0-9]))(,(([a-z]|[A-Z])|([a-z]_[0-9]|[A-Z]_[0-9])))*$");
	QRegExpValidator *regVal = new QRegExpValidator(re);
	ui->lineEditVars->setValidator(regVal);
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

void MainWindow::setLinearEqTableValidator()
{
	for (int row = 0; row < ui->augMatrix->rowCount(); row++) {
		for (int column = 0; column < ui->augMatrix->columnCount(); column++) {
			QLineEdit *ql = new QLineEdit;
			ql->setValidator(new QDoubleValidator(ql));
			ui->augMatrix->setCellWidget(row, column, ql);
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


void MainWindow::on_pushButton_6_clicked()
{
#ifdef _WIN32
	QProcess process;
	QMessageBox pathMsg;
	QTableWidget *augMatrixTable = ui->augMatrix;

	int n = augMatrixTable->rowCount();
	int m = augMatrixTable->columnCount();

	QLineEdit *tempLineEdit;

	Matrix aug(n, m);
	Report testReport(6);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tempLineEdit = (QLineEdit*) augMatrixTable->cellWidget(i, j);
			aug.set(i, j, tempLineEdit->text().toDouble());
		}
	}

	std::vector<std::string> vars;

	for (int i = 0; i < n; i++) {
		std::ostringstream tempVar;
		tempVar << "a_";
		tempVar << i;

		vars.push_back(tempVar.str());
	}

	testReport.addAugmentMatrixElement(vars, aug);
	Matrix augEl = LinearSolver::getGaussianElimination(aug, vars, testReport);

	std::vector<RowOperationParameter> ops;

	for (int i = 0; i < aug.getRowsCount(); i++) {
		RowOperationParameter tempOp;

		tempOp.i = i;
		tempOp.j = i + 1;
		tempOp.m = 1.0;
		tempOp.skip = false;

		ops.push_back(tempOp);
	}

	std::ostringstream body;
	body << "\"\\def\\reportbody{";
	body << testReport.getReportBody();
	body << "}";
	body << "\\input{matrixtest.tex}\"";


	std::ostringstream catStream;
	catStream << "echo ";
	catStream << body.str();
	catStream << " > outstream.txt";

	std::cout << body.str() << std::endl;

	QString outputCat = QString::fromStdString(catStream.str());



	QString file = QCoreApplication::applicationDirPath() + "/" + "texlive/pdflatex.exe " + QString::fromStdString(body.str()) + " -interaction=nonstopmode";

	//pathMsg.setText(QString::fromStdString(body.str()));
	QProcess processCat;

	process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
	processCat.setWorkingDirectory(process.workingDirectory());
	processCat.start(outputCat);

	process.start(file);

	if (!process.waitForStarted()) {
		pathMsg.setText(file + " : " + process.errorString());
	}
	else {
		pathMsg.setText(process.readAll());
	}

	if (process.waitForFinished()) {
		pathMsg.setText(process.readAll());
	}


	pathMsg.exec();
#elif __linux__
	QProcess process;
	QMessageBox pathMsg;

	QString file = "pdftex -interaction=nonstopmode matrixtest.tex";

	process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
	process.start(file);


	if (!process.waitForStarted()) {
		pathMsg.setText(file + " : " + process.errorString());
	}
	else {
		pathMsg.setText("Iniciado");
	}

	if (process.waitForFinished()) {
		pathMsg.setText(process.readAll());
	}

	pathMsg.exec();

#endif
}


void MainWindow::renderResult(){
    QString js = "document.removeChild(document.documentElement);";
    webDisplay->page()->runJavaScript(js);

}

void MainWindow::initializeLinearEqModule()
{

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

void MainWindow::on_applyMatrixRange_clicked()
{
	ui->augMatrix->setRowCount(ui->spinnerRowCount->value());
	ui->augMatrix->setColumnCount(ui->spinnerColumnCount->value());
	setLinearEqTableValidator();
}

void MainWindow::on_acceptVars_clicked()
{
}

void MainWindow::on_lineEditVars_editingFinished()
{
	QMessageBox msg;
	msg.setText("Validated");
	msg.exec();
}
