/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalir;
    QAction *actionGenerar_reporte;
    QAction *actionResultado;
    QAction *actionManual;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *mainLayout;
    QTabWidget *mainTabWidget;
    QWidget *basicMatrixOperations;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *tab1MainLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QFrame *line_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QFrame *line_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QFrame *line_4;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *tab_2;
    QWebEngineView *webEngineView;
    QWidget *tab;
    QPushButton *pushButton_6;
    QTableWidget *augMatrix;
    QPushButton *applyMatrixRange;
    QSpinBox *spinnerRowCount;
    QSpinBox *spinnerColumnCount;
    QPushButton *acceptVars;
    QLineEdit *lineEditVars;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuVer;
    QMenu *menuAyuda;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(771, 454);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionGenerar_reporte = new QAction(MainWindow);
        actionGenerar_reporte->setObjectName(QStringLiteral("actionGenerar_reporte"));
        actionResultado = new QAction(MainWindow);
        actionResultado->setObjectName(QStringLiteral("actionResultado"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainTabWidget = new QTabWidget(widget);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));
        mainTabWidget->setTabShape(QTabWidget::Rounded);
        basicMatrixOperations = new QWidget();
        basicMatrixOperations->setObjectName(QStringLiteral("basicMatrixOperations"));
        verticalLayout_3 = new QVBoxLayout(basicMatrixOperations);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tab1MainLayout = new QVBoxLayout();
        tab1MainLayout->setSpacing(6);
        tab1MainLayout->setObjectName(QStringLiteral("tab1MainLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(basicMatrixOperations);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        line = new QFrame(basicMatrixOperations);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_2 = new QLabel(basicMatrixOperations);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);


        tab1MainLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(tab1MainLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(basicMatrixOperations);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(2);
        spinBox->setMaximum(15);

        horizontalLayout_2->addWidget(spinBox);

        spinBox_2 = new QSpinBox(basicMatrixOperations);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(2);
        spinBox_2->setMaximum(15);

        horizontalLayout_2->addWidget(spinBox_2);

        line_2 = new QFrame(basicMatrixOperations);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        spinBox_3 = new QSpinBox(basicMatrixOperations);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(2);
        spinBox_3->setMaximum(15);

        horizontalLayout_2->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(basicMatrixOperations);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(2);
        spinBox_4->setMaximum(15);

        horizontalLayout_2->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(basicMatrixOperations);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        line_3 = new QFrame(basicMatrixOperations);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        pushButton_2 = new QPushButton(basicMatrixOperations);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tableWidget = new QTableWidget(basicMatrixOperations);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_4->addWidget(tableWidget);

        line_4 = new QFrame(basicMatrixOperations);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_4);

        tableWidget_2 = new QTableWidget(basicMatrixOperations);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        horizontalLayout_4->addWidget(tableWidget_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_3 = new QPushButton(basicMatrixOperations);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(basicMatrixOperations);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(basicMatrixOperations);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_9 = new QPushButton(basicMatrixOperations);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout_4->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(basicMatrixOperations);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout_4->addWidget(pushButton_10);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_11 = new QPushButton(basicMatrixOperations);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_5->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(basicMatrixOperations);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_5->addWidget(pushButton_12);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_7 = new QPushButton(basicMatrixOperations);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(basicMatrixOperations);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        mainTabWidget->addTab(basicMatrixOperations, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        webEngineView = new QWebEngineView(tab_2);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setGeometry(QRect(0, 30, 751, 381));
        webEngineView->setProperty("url", QVariant(QUrl(QStringLiteral("about:blank"))));
        mainTabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 30, 75, 23));
        augMatrix = new QTableWidget(tab);
        if (augMatrix->columnCount() < 2)
            augMatrix->setColumnCount(2);
        if (augMatrix->rowCount() < 2)
            augMatrix->setRowCount(2);
        augMatrix->setObjectName(QStringLiteral("augMatrix"));
        augMatrix->setGeometry(QRect(30, 90, 321, 291));
        augMatrix->setMinimumSize(QSize(256, 0));
        augMatrix->setRowCount(2);
        augMatrix->setColumnCount(2);
        applyMatrixRange = new QPushButton(tab);
        applyMatrixRange->setObjectName(QStringLiteral("applyMatrixRange"));
        applyMatrixRange->setGeometry(QRect(100, 60, 75, 23));
        spinnerRowCount = new QSpinBox(tab);
        spinnerRowCount->setObjectName(QStringLiteral("spinnerRowCount"));
        spinnerRowCount->setGeometry(QRect(50, 10, 42, 22));
        spinnerRowCount->setMinimum(2);
        spinnerRowCount->setMaximum(20);
        spinnerColumnCount = new QSpinBox(tab);
        spinnerColumnCount->setObjectName(QStringLiteral("spinnerColumnCount"));
        spinnerColumnCount->setGeometry(QRect(100, 10, 42, 22));
        spinnerColumnCount->setMinimum(2);
        spinnerColumnCount->setMaximum(20);
        acceptVars = new QPushButton(tab);
        acceptVars->setObjectName(QStringLiteral("acceptVars"));
        acceptVars->setGeometry(QRect(650, 100, 75, 23));
        lineEditVars = new QLineEdit(tab);
        lineEditVars->setObjectName(QStringLiteral("lineEditVars"));
        lineEditVars->setGeometry(QRect(370, 70, 361, 20));
        mainTabWidget->addTab(tab, QString());
        spinnerColumnCount->raise();
        pushButton_6->raise();
        augMatrix->raise();
        applyMatrixRange->raise();
        spinnerRowCount->raise();
        acceptVars->raise();
        lineEditVars->raise();

        mainLayout->addWidget(mainTabWidget);


        verticalLayout_2->addLayout(mainLayout);

        MainWindow->setCentralWidget(widget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 771, 19));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuVer = new QMenu(menuBar);
        menuVer->setObjectName(QStringLiteral("menuVer"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuVer->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionGenerar_reporte);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuVer->addAction(actionResultado);
        menuAyuda->addAction(actionManual);

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionGenerar_reporte->setText(QApplication::translate("MainWindow", "Generar reporte", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionGenerar_reporte->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionResultado->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionManual->setShortcut(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("MainWindow", "Matriz A", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Matriz B", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Generar matriz A", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Generar matriz B", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Sumar matrices", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Restar matrices", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Multiplicar matrices", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Transponer matriz A", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Transponer matriz B", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "Inversa de A", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Inversa de B", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Determinante de matriz A", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Determinante de matriz B", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(basicMatrixOperations), QApplication::translate("MainWindow", "Operaciones b\303\241sicas con matrices", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Generar pdf", Q_NULLPTR));
        applyMatrixRange->setText(QApplication::translate("MainWindow", "Aplicar", Q_NULLPTR));
        acceptVars->setText(QApplication::translate("MainWindow", "Aceptar", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuVer->setTitle(QApplication::translate("MainWindow", "Ver", Q_NULLPTR));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
