#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebEngineView>
#include <QMainWindow>
#include <QLineEdit>
#include <Matrix.h>

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

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_actionManual_triggered();

private:
    QWebEngineView *webDisplay;
    QWebEngineView *webDisplay2;
    QWebEngineView *webDisplay3;
    QWebEngineView *h;


    Ui::MainWindow *ui;
    void setTableValidatorA();
    void setTableValidatorB();
	void setLinearEqTableValidator();
    void renderResult(Matrix, Matrix, Matrix, int, double);
    void renderResult2(Matrix, double, int);
    void clearWebDisplay();
	void initializeLinearEqModule();
	void setUpVarsValidation();
    void setTableValidatorV();
    void clearWebDisplay2();

};

#endif // MAINWINDOW_H
