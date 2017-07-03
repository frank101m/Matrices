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
    webDisplay2 = new QWebEngineView;
    webDisplay->setUrl(QUrl("qrc:///html/m1.htm"));
    webDisplay->setMaximumHeight(500);
    webDisplay2->setUrl(QUrl("qrc:///html/m1.htm"));
    ui->basicMatrixOperations->layout()->addWidget(webDisplay);
    ui->tab_2->layout()->addWidget(webDisplay2);
    setTableValidatorA();
    setTableValidatorB();
	setLinearEqTableValidator();
    //setUpVarsValidation();
    setTableValidatorV();
    webDisplay3 = new QWebEngineView;
    webDisplay3->setUrl(QUrl("qrc:///html/m1.htm"));
    webDisplay3->setMaximumHeight(500);
    ui->tab->layout()->addWidget(webDisplay3);
}



MainWindow::~MainWindow()
{
    delete webDisplay;
    delete ui;
}
/*void MainWindow::setUpVarsValidation(){
	ui->acceptVars->setEnabled(false);
	QRegExp re("^(([a-z]|[A-Z])|([a-z]_[0-9]|[A-Z]_[0-9]))(,(([a-z]|[A-Z])|([a-z]_[0-9]|[A-Z]_[0-9])))*$");
	QRegExpValidator *regVal = new QRegExpValidator(re);
	ui->lineEditVars->setValidator(regVal);
}*/

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

void MainWindow::setTableValidatorV(){
    for(int i = 0; i < ui->tableWidget_3->rowCount(); i++){
        QLineEdit *ql = new QLineEdit;
        ql->setValidator(new QDoubleValidator(ql));
        ui->tableWidget_3->setCellWidget(i, 0, ql);
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
        QLineEdit *ql = new QLineEdit;
        ql->setValidator(new QDoubleValidator(ql));
        ui->tableWidget_4->setCellWidget(row, 0, ql);

        QLineEdit *ql2 = new QLineEdit;
        ql2->setValidator(new QDoubleValidator(ql2));
        ui->tableWidget_5->setCellWidget(row, 0, ql2);

	}
}


void MainWindow::on_pushButton_3_clicked()
{


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
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
            }
        }
        this->renderResult(a, b, res, 0, 0);

    }
    else{
        QString msg = "error en la configuracion matricial";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();

    }



}

void MainWindow::on_pushButton_4_clicked()
{
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
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
            }
        }
         this->renderResult(a, b, res, 1, 0);

    }
    else{
        QString msg = "error en la configuracion matricial";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }



}

void MainWindow::on_pushButton_5_clicked()
{
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
        for(int i = 0; i < res.getRowsCount(); i++){
            for(int j = 0; j < res.getColumnsCount(); j++){
            }
        }

        this->renderResult(a, b, res, 2, 0);

    }
    else{
        QString msg = "error en la configuracion matricial";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }




}


void MainWindow::on_pushButton_6_clicked()
{
#ifdef _WIN32
	QProcess process;
	QMessageBox pathMsg;
	QTableWidget *augMatrixTable = ui->augMatrix;

	int n = augMatrixTable->rowCount();

	QLineEdit *tempLineEdit;

	Matrix A(n, n);
	Matrix C(n, 1);

	Report testReport(6);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tempLineEdit = (QLineEdit*) augMatrixTable->cellWidget(i, j);
			A.set(i, j, tempLineEdit->text().toDouble());
		}
	}

	for (int i = 0; i < n; i++) {
		tempLineEdit = (QLineEdit*) ui->tableWidget_4->cellWidget(i, 0);
		C.set(i, 0, tempLineEdit->text().toDouble());
	}

	std::vector<std::string> vars;

	for (int i = 0; i < n; i++) {
		std::ostringstream tempVar;
		tempVar << "a_";
		tempVar << i;

		vars.push_back(tempVar.str());
	}

	Matrix res = LinearSolver::getGaussianElimination(A, C, vars, testReport);
	Matrix Xvec = LinearSolver::getBackSubstitution(res, vars, testReport);

	std::ostringstream body;
	body << testReport.getReportBody();
	body << std::endl;
	body << "\\input{gauss.tex}\"";


	std::cout << body.str() << std::endl;

	OutputDebugStringA(body.str().c_str());

	QString file = QCoreApplication::applicationDirPath() + "/" + "texlive/pdflatex.exe " + QString::fromStdString(body.str()) + " -interaction=nonstopmode";

	//pathMsg.setText(QString::fromStdString(body.str()));

	process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
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
    QTableWidget *augMatrixTable = ui->augMatrix;

    int n = augMatrixTable->rowCount();

    QLineEdit *tempLineEdit;

    Matrix A(n, n);
    Matrix C(n, 1);

    Report testReport(6);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempLineEdit = (QLineEdit*) augMatrixTable->cellWidget(i, j);
            A.set(i, j, tempLineEdit->text().toDouble());
        }
    }

    for (int i = 0; i < n; i++) {
        tempLineEdit = (QLineEdit*) ui->tableWidget_4->cellWidget(i, 0);
        C.set(i, 0, tempLineEdit->text().toDouble());
    }

    std::vector<std::string> vars;

    for (int i = 0; i < n; i++) {
        std::ostringstream tempVar;
        tempVar << "a_";
        tempVar << i;

        vars.push_back(tempVar.str());
    }

    Matrix res = LinearSolver::getGaussianElimination(A, C, vars, testReport);
    Matrix Xvec = LinearSolver::getBackSubstitution(res, vars, testReport);

    std::ostringstream body;
    body << testReport.getReportBody();
    body << std::endl;
    body << "\\input{gauss.tex}\"";


    std::cout << body.str() << std::endl;

//    OutputDebugStringA(body.str().c_str());

    //QString file = QCoreApplication::applicationDirPath() + "/" + "texlive/pdflatex.exe " + QString::fromStdString(body.str()) + " -interaction=nonstopmode";
    QString file = "./pdflatex -interaction=nonstopmode "+ QString::fromStdString(body.str());
    //pathMsg.setText(QString::fromStdString(body.str()));

    process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
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

#endif*/
}

void MainWindow::clearWebDisplay(){
    QString js = "document.body.innerHTML = '"
                 "';";
    webDisplay->page()->runJavaScript(js);

}


void MainWindow::renderResult2(Matrix a, double d, int code){
    QString js = "document.body.innerHTML = '"
                 "';";
    webDisplay2->page()->runJavaScript(js);
    switch (code) {
    case 0:
        js = "var tex = document.createElement('tex');";
        webDisplay2->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";
        js += " \\\\left| \\\\left| \\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += " \\\\end{bmatrix} \\\\right| \\\\right| _{2} = ";
        js+= QString::number(d);

        js+="');";
        webDisplay2->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay2->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay2->page()->runJavaScript(js);


        break;

    case 1:
        js = "var tex = document.createElement('tex');";
        webDisplay2->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";
        js += " \\\\left| \\\\left| \\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += " \\\\end{bmatrix} \\\\right| \\\\right| _{\\\\infty} = ";
        js+= QString::number(d);

        js+="');";
        webDisplay2->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay2->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay2->page()->runJavaScript(js);


        break;




    }
    js = "var txlist = document.getElementsByTagName('tex');";
    webDisplay2->page()->runJavaScript(js);
    js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
    webDisplay2->page()->runJavaScript(js);

}





void MainWindow::clearWebDisplay2(){
    QString js = "document.body.innerHTML = '"
                 "';";
    webDisplay->page()->runJavaScript(js);
}



void MainWindow::renderResult(Matrix a, Matrix b, Matrix c, int code, double d){

    QString js = "document.body.innerHTML = '"
                 "';";
    webDisplay->page()->runJavaScript(js);

    switch (code) {
    case 0:
        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} + ";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getColumnsCount(); j++){

                if(j != b.getColumnsCount()-1)
                    js += QString::number(b.at(i, j)) + "&";
                else{
                    if(i != c.getRowsCount()-1)
                    js += QString::number(b.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(b.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} = ";

        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);




        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < c.getRowsCount(); i++)
            for(int j = 0; j < c.getColumnsCount(); j++){

                if(j != c.getColumnsCount()-1)
                    js += QString::number(c.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(c.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(c.at(i, j));
                }


        }
        js += "\\\\end{bmatrix}";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);


        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);
        break;

    case 1:
        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} - ";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getColumnsCount(); j++){

                if(j != b.getColumnsCount()-1)
                    js += QString::number(b.at(i, j)) + "&";
                else{
                    if(i != c.getRowsCount()-1)
                    js += QString::number(b.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(b.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} = ";

        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);




        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < c.getRowsCount(); i++)
            for(int j = 0; j < c.getColumnsCount(); j++){

                if(j != c.getColumnsCount()-1)
                    js += QString::number(c.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(c.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(c.at(i, j));
                }


        }
        js += "\\\\end{bmatrix}";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);


        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);
        break;

    case 2:

        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} \\\\times ";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getColumnsCount(); j++){

                if(j != b.getColumnsCount()-1)
                    js += QString::number(b.at(i, j)) + "&";
                else{
                    if(i != b.getRowsCount()-1)
                    js += QString::number(b.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(b.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} = ";

        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);




        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < c.getRowsCount(); i++)
            for(int j = 0; j < c.getColumnsCount(); j++){

                if(j != c.getColumnsCount()-1)
                    js += QString::number(c.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(c.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(c.at(i, j));
                }


        }
        js += "\\\\end{bmatrix}";

        js+="');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);


        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);
        break;

    case 3:

        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += " { \\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} }^{T} =  ";

        js+=" ');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getColumnsCount(); j++){

                if(j != b.getColumnsCount()-1)
                    js += QString::number(b.at(i, j)) + "&";
                else{
                    if(i != c.getRowsCount()-1)
                    js += QString::number(b.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(b.at(i, j));
                }


        }
        js += "\\\\end{bmatrix}";

        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);

        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);

        break;

    case 4:


        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "  \\\\begin{vmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{vmatrix}  =  ";

        js+=" ');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += QString::number(d);
        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);

        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);

        break;




    case 5:
        js = "var tex = document.createElement('tex');";
        webDisplay->page()->runJavaScript(js);
        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += " { \\\\begin{bmatrix}";
        for(int i = 0; i < a.getRowsCount(); i++)
            for(int j = 0; j < a.getColumnsCount(); j++){

                if(j != a.getColumnsCount()-1)
                    js += QString::number(a.at(i, j)) + "&";
                else{
                    if(i != a.getRowsCount()-1)
                    js += QString::number(a.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(a.at(i, j));
                }


        }
        js += "\\\\end{bmatrix} }^{-1} =  ";

        js+=" ');";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);



        js ="var content = document.createTextNode('";


        //js+="A_{m,n} = \\\\begin{pmatrix} a_{1,1} & a_{1,2} & \\\\cdots & a_{1,n} \\\\\\\\\\\\\\\\ ";
        //js+="a_{2,1} & a_{2,2} & \\\\cdots & a_{2,n} \\\\\\\\\\\\\\\\ \\\\vdots  & \\\\vdots  & \\\\ddots & \\\\vdots  \\\\\\\\\\\\\\\\ ";
        //js+="a_{m,1} & a_{m,2} & \\\\cdots & a_{m,n} \\\\end{pmatrix}";

        js += "\\\\begin{bmatrix}";
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getColumnsCount(); j++){

                if(j != b.getColumnsCount()-1)
                    js += QString::number(b.at(i, j)) + "&";
                else{
                    if(i != c.getRowsCount()-1)
                    js += QString::number(b.at(i, j)) + "\\\\\\\\\\\\\\\\";
                    else
                        js += QString::number(b.at(i, j));
                }


        }
        js += "\\\\end{bmatrix}";

        js+="') 	 ;";
        webDisplay->page()->runJavaScript(js);
        js ="tex.appendChild(content);";
        webDisplay->page()->runJavaScript(js);
        js = "document.body.appendChild(tex);";
        webDisplay->page()->runJavaScript(js);

        //rendering
        js = "var txlist = document.getElementsByTagName('tex');";
        webDisplay->page()->runJavaScript(js);
        js = "for (var i = 0; i < txlist.length; i++) { var tx = txlist[i]; var txtext = tx.textContent; katex.render(txtext, tx, { displayMode: true }); }";
        webDisplay->page()->runJavaScript(js);



        break;
    }
}

void MainWindow::initializeLinearEqModule()
{

}

void MainWindow::on_actionResultado_triggered()
{
    if(webDisplay->isHidden()){
        webDisplay->show();
        webDisplay2->show();
    }
    else{
        webDisplay->hide();
        webDisplay2->hide();
    }
}

void MainWindow::on_actionSalir_triggered()
{
    QApplication::quit();
}

void MainWindow::on_applyMatrixRange_clicked()
{
	ui->augMatrix->setRowCount(ui->spinnerRowCount->value());
    ui->augMatrix->setColumnCount(ui->spinnerRowCount->value());
    ui->tableWidget_4->setRowCount(ui->spinnerRowCount->value());
    ui->tableWidget_5->setRowCount(ui->spinnerRowCount->value());
	setLinearEqTableValidator();
}

void MainWindow::on_acceptVars_clicked()
{

}


void MainWindow::on_pushButton_7_clicked()
{

    if(ui->tableWidget->columnCount() == ui->tableWidget->rowCount()){
        Matrix *a = new Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());

        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
               a->set(i, j, ql->text().toDouble());
            }



        double det = Matrix::detGauss(a);

        Matrix b = Matrix(a->getRowsCount(), a->getColumnsCount());
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getRowsCount(); j++)
                b.set(i, j, a->at(i, j));

        this->renderResult(b, b, b, 4, det);
    }
    else{
        QString msg = "error en la configuracion matricial";

        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }

   // this->renderResult();

}

void MainWindow::on_pushButton_8_clicked()
{


    if(ui->tableWidget_2->columnCount() == ui->tableWidget_2->rowCount()){
        Matrix *a = new Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());

        for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
            for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
               QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
               a->set(i, j, ql->text().toDouble());
            }


        double det = Matrix::detGauss(a);

        Matrix b = Matrix(a->getRowsCount(), a->getColumnsCount());
        for(int i = 0; i < b.getRowsCount(); i++)
            for(int j = 0; j < b.getRowsCount(); j++)
                b.set(i, j, a->at(i, j));

        this->renderResult(b, b, b, 4, det);

    }
    else{
        QString msg = "error en la configuracion matricial";

        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }



    //this->renderResult();


}

void MainWindow::on_pushButton_9_clicked()
{
    Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
           QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
           a.set(i, j, ql->text().toDouble());
        }
    Matrix t = a.transpose();
    for(int i = 0; i < t.getRowsCount(); i++){
        for(int j = 0; j < t.getColumnsCount(); j++){
        }
    }

   this->renderResult(a, t, a, 3 ,0);
}

void MainWindow::on_pushButton_10_clicked()
{
    Matrix a = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());
    for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
           QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
           a.set(i, j, ql->text().toDouble());
        }
    Matrix t = a.transpose();
    for(int i = 0; i < t.getRowsCount(); i++){
        for(int j = 0; j < t.getColumnsCount(); j++){
        }
    }

    this->renderResult(a, t, a, 3 ,0);
}

void MainWindow::on_pushButton_11_clicked()
{
    this->clearWebDisplay();

    QString msg;

    if(ui->tableWidget->rowCount() == ui->tableWidget->columnCount()){

    Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
           QLineEdit *ql = (QLineEdit*) ui->tableWidget->cellWidget(i, j);
           a.set(i, j, ql->text().toDouble());
        }
    Matrix b = a.inverse();
    for(int i = 0; i < b.getRowsCount(); i++){
        for(int j = 0; j < b.getColumnsCount(); j++){
        }
    }

    int f = 0;
    for(int i = 0; i < a.getRowsCount(); i++)
        for(int j = 0; j < a.getColumnsCount(); j++)
            if(b.at(i, j) == 0 || b.at(i, j) != b.at(i, j))
                f++;
    if(f!=(a.getColumnsCount()*a.getRowsCount())){
        this->renderResult(a, b, a, 5, 0);
    }else{
        msg = "La matriz no posee inversa";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }


    }
    else{
        msg = "Error en la configuracion matricial";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }



}

void MainWindow::on_pushButton_12_clicked()
{
    this->clearWebDisplay();
    QString msg;

    if(ui->tableWidget_2->rowCount() == ui->tableWidget_2->columnCount()){

    Matrix a = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount());
    for(int i = 0; i < ui->tableWidget_2->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget_2->columnCount(); j++){
           QLineEdit *ql = (QLineEdit*) ui->tableWidget_2->cellWidget(i, j);
           a.set(i, j, ql->text().toDouble());
        }
    Matrix b = a.inverse();
    for(int i = 0; i < b.getRowsCount(); i++){
        for(int j = 0; j < b.getColumnsCount(); j++){
        }
    }
    int f = 0;
    for(int i = 0; i < a.getRowsCount(); i++)
        for(int j = 0; j < a.getColumnsCount(); j++)
            if(b.at(i, j) == 0 || b.at(i, j) != b.at(i, j))
                f++;
    if(f!=(a.getColumnsCount()*a.getRowsCount())){
        this->renderResult(a, b, a, 5, 0);
    }else{
        msg = "La matriz no posee inversa";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }



    }
    else{
        msg = "Error en la configuracion matricial";
        QMessageBox msgBox;

        msgBox.setText(msg);
        msgBox.setWindowTitle("Resultado:");
        msgBox.setWindowModality(Qt::WindowModal);
        msgBox.exec();
    }



    }


void MainWindow::on_pushButton_13_clicked()
{
    ui->tableWidget_3->setRowCount(ui->spinBox_5->value());
    setTableValidatorV();
}

void MainWindow::on_pushButton_14_clicked()
{
    //remember to clear webdisplay
    Matrix a = Matrix(ui->tableWidget_3->rowCount(), 1);
    for(int i = 0; i < a.getRowsCount(); i++){
        QLineEdit *ql = (QLineEdit*) ui->tableWidget_3->cellWidget(i, 0);
        a.set(i, 0, ql->text().toDouble());
    }

    double normInf = a.infNorm();

    this->renderResult2(a, normInf, 1);


}


void MainWindow::on_pushButton_15_clicked()
{
    //remember to clear webdisplay
    Matrix a = Matrix(ui->tableWidget_3->rowCount(), 1);
    for(int i = 0; i < a.getRowsCount(); i++){
        QLineEdit *ql = (QLineEdit*) ui->tableWidget_3->cellWidget(i, 0);
        a.set(i, 0, ql->text().toDouble());
    }

    double normEuc = a.eucNorm();

    this->renderResult2(a, normEuc, 0);

}

void MainWindow::on_pushButton_17_clicked()
{
    if(ui->augMatrix->rowCount() == ui->augMatrix->columnCount()){

    std::vector<std::string> vars;
    Matrix g =  Matrix(ui->augMatrix->rowCount(), ui->augMatrix->columnCount());
    Matrix c = Matrix(g.getRowsCount(), g.getColumnsCount());
    Matrix o = Matrix(g.getRowsCount(), g.getColumnsCount());


    for(int i = 0; i < g.getRowsCount(); i++){
        for(int j = 0; j < g.getColumnsCount(); j++){
            QLineEdit *ql = (QLineEdit*) ui->augMatrix->cellWidget(i, j);
            g.set(i, j, ql->text().toDouble());
        }

        vars.push_back("a_"+std::to_string(i));

        QLineEdit *ql = (QLineEdit*) ui->tableWidget_4->cellWidget(i, 0);
        c.set(i, 0, ql->text().toDouble());

        QLineEdit *ql2 = (QLineEdit*) ui->tableWidget_5->cellWidget(i, 0);
        o.set(i, 0, ql2->text().toDouble());
    }


    Report r = Report(1);

    Matrix res = LinearSolver::getJacobiMethod(g, c, o, 0.0001, 10, vars, r);

    QString msag = "";
    for(int i = 0; i < res.getRowsCount(); i++){
        for(int j = 0; j < res.getColumnsCount(); j++){
            msag+= QString::number(res.at(i, j)) + ", ";
        }
        msag +="\n";
    }

    QMessageBox msg;
    msg.setText(msag);
    msg.exec();

}
    //filling matrix:

}

void MainWindow::on_pushButton_16_clicked()
{
    if(ui->augMatrix->rowCount() == ui->augMatrix->columnCount()){

    std::vector<std::string> vars;
    Matrix g =  Matrix(ui->augMatrix->rowCount(), ui->augMatrix->columnCount());
    Matrix c = Matrix(g.getRowsCount(), g.getColumnsCount());
    Matrix o = Matrix(g.getRowsCount(), g.getColumnsCount());


    for(int i = 0; i < g.getRowsCount(); i++){
        for(int j = 0; j < g.getColumnsCount(); j++){
            QLineEdit *ql = (QLineEdit*) ui->augMatrix->cellWidget(i, j);
            g.set(i, j, ql->text().toDouble());
        }

        vars.push_back("a_"+std::to_string(i));

        QLineEdit *ql = (QLineEdit*) ui->tableWidget_4->cellWidget(i, 0);
        c.set(i, 0, ql->text().toDouble());

        QLineEdit *ql2 = (QLineEdit*) ui->tableWidget_5->cellWidget(i, 0);
        o.set(i, 0, ql2->text().toDouble());
    }


    Report r = Report(1);

    //Matrix res = LinearSolver::getJacobiMethod(g, c, o, 0.0001, 10, vars, r);

    Matrix res = LinearSolver::getGaussianElimination(g, c, vars,r);

    QString msag = "";
    for(int i = 0; i < res.getRowsCount(); i++){
        for(int j = 0; j < res.getColumnsCount(); j++){
            msag+= QString::number(res.at(i, j)) + ", ";
        }
        msag +="\n";
    }

    QMessageBox msg;
    msg.setText(msag);
    msg.exec();

}
}

void MainWindow::on_actionManual_triggered()
{
     h = new QWebEngineView;
    h->setUrl(QUrl("qrc:///html/index.htm"));
    h->setWindowFlags(Qt::Window);
    h->show();
}

void MainWindow::on_action1_Matriz_triggered()
{

	Matrix a = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
	for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
		for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
			QLineEdit *ql = (QLineEdit*)ui->tableWidget->cellWidget(i, j);
			a.set(i, j, ql->text().toDouble());
		}
	}

	Matrix at = a.transpose();
	double adet = 0.0;
	std::ostringstream adet_stream;


	Report singleMatrixReport(5);

	singleMatrixReport.addBMatrix(Report::DEF_OP_MATRIX_A, a);
	singleMatrixReport.addBMatrix(Report::DEF_OP_MATRIX_AT, at);
	singleMatrixReport.addVMatrix(Report::DEF_OP_MATRIX_DET_A, a);

	if (a.getColumnsCount() == a.getRowsCount()) {
		adet = a.detGauss(&a);
		singleMatrixReport.addVMatrix(Report::DEF_OP_MATRIX_DET_A, a);
		adet_stream << adet;
		singleMatrixReport.addDefinition(Report::DEF_OP_VAL_DET_A, adet_stream.str());
	} else {
		adet = 0.0;
		singleMatrixReport.addDefinition(Report::DEF_OP_VAL_DET_A, std::string("\\not\\exists"));
	}

	if (adet != 0.0) {
		double adet = a.detGauss(&a);
		Matrix ainv = a.inverse();
		singleMatrixReport.addBMatrix(Report::DEF_OP_MATRIX_INV_A, ainv);
	} else {
		singleMatrixReport.addDefinition(Report::DEF_OP_MATRIX_INV_A, std::string("\\not\\exists"));
	}

	std::ostringstream reportBodyEnd;
	reportBodyEnd << singleMatrixReport.getReportBody();
	reportBodyEnd << std::endl;
	reportBodyEnd << "\\input{ops1.tex}";
	generateReport(reportBodyEnd.str());

}

void MainWindow::on_action2_Matrices_triggered()
{
    //dos matrices
}

void MainWindow::generateReport(const std::string & body)
{
	QProcess process;
	QMessageBox pathMsg;

#ifdef _WIN32
	OutputDebugStringA(body.c_str());
	QString file = QCoreApplication::applicationDirPath() + "/" + "texlive/pdflatex.exe " + QString::fromStdString(body) + " -interaction=nonstopmode";

#elif __linux__
    QString file = "./pdflatex -interaction=nonstopmode "+ QString::fromStdString(body);
#endif // 


	process.setWorkingDirectory(QDir::currentPath().append(QDir::separator()).append("texlive"));
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
}

void MainWindow::on_actionInfinita_triggered()
{
    //norma infinita
    int i;
}

void MainWindow::on_actionEuclideana_triggered()
{
    //norma euclideana
    int j;
}

void MainWindow::on_actionGauss_triggered()
{
    //SEL Gauss
    int k;
}

void MainWindow::on_actionJacobi_triggered()
{
    //SEL Jacobi
    int m;
}
