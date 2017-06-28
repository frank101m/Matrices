#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebEngineView>
#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void on_actionResultado_triggered();

    void on_actionSalir_triggered();
	void on_applyMatrixRange_clicked();
	void on_acceptVars_clicked();
	void on_lineEditVars_editingFinished();

private:
    QWebEngineView *webDisplay;
    Ui::MainWindow *ui;
    void setTableValidatorA();
    void setTableValidatorB();
	void setLinearEqTableValidator();
    void renderResult();
	void initializeLinearEqModule();
	void setUpVarsValidation();
};

#endif // MAINWINDOW_H
