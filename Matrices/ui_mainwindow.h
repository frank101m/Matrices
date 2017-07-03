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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *actionResultado;
    QAction *actionManual;
    QAction *action1_Matriz;
    QAction *action2_Matrices;
    QAction *actionGauss;
    QAction *actionJacobi;
    QAction *actionNormas_vectoriales;
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
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QTableWidget *tableWidget_3;
    QWidget *tab;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_12;
    QTableWidget *augMatrix;
    QTableWidget *tableWidget_4;
    QTableWidget *tableWidget_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_6;
    QSpinBox *spinnerRowCount;
    QPushButton *applyMatrixRange;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuGenerar_reporte;
    QMenu *menuOperaciones_basicas;
    QMenu *menuSEL;
    QMenu *menuVer;
    QMenu *menuAyuda;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(716, 600);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionResultado = new QAction(MainWindow);
        actionResultado->setObjectName(QStringLiteral("actionResultado"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        action1_Matriz = new QAction(MainWindow);
        action1_Matriz->setObjectName(QStringLiteral("action1_Matriz"));
        action2_Matrices = new QAction(MainWindow);
        action2_Matrices->setObjectName(QStringLiteral("action2_Matrices"));
        actionGauss = new QAction(MainWindow);
        actionGauss->setObjectName(QStringLiteral("actionGauss"));
        actionJacobi = new QAction(MainWindow);
        actionJacobi->setObjectName(QStringLiteral("actionJacobi"));
        actionNormas_vectoriales = new QAction(MainWindow);
        actionNormas_vectoriales->setObjectName(QStringLiteral("actionNormas_vectoriales"));
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainTabWidget->sizePolicy().hasHeightForWidth());
        mainTabWidget->setSizePolicy(sizePolicy);
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
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
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
        tableWidget->setMinimumSize(QSize(0, 200));

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
        tableWidget_2->setMinimumSize(QSize(0, 200));

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
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(120, 0));
        label_3->setMaximumSize(QSize(120, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        spinBox_5 = new QSpinBox(tab_2);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_5->sizePolicy().hasHeightForWidth());
        spinBox_5->setSizePolicy(sizePolicy2);
        spinBox_5->setMinimumSize(QSize(120, 0));
        spinBox_5->setMaximumSize(QSize(120, 16777215));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(30);

        verticalLayout_6->addWidget(spinBox_5);

        pushButton_13 = new QPushButton(tab_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy2.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy2);
        pushButton_13->setMinimumSize(QSize(120, 0));
        pushButton_13->setMaximumSize(QSize(120, 16777215));

        verticalLayout_6->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(tab_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy2.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy2);
        pushButton_14->setMinimumSize(QSize(120, 0));
        pushButton_14->setMaximumSize(QSize(120, 16777215));

        verticalLayout_6->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(tab_2);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy2.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy2);
        pushButton_15->setMinimumSize(QSize(120, 0));
        pushButton_15->setMaximumSize(QSize(120, 16777215));

        verticalLayout_6->addWidget(pushButton_15);

        tableWidget_3 = new QTableWidget(tab_2);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        if (tableWidget_3->rowCount() < 1)
            tableWidget_3->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem9);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy3);
        tableWidget_3->setMinimumSize(QSize(120, 0));
        tableWidget_3->setMaximumSize(QSize(120, 16777215));

        verticalLayout_6->addWidget(tableWidget_3);


        horizontalLayout_6->addLayout(verticalLayout_6);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        mainTabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_10 = new QVBoxLayout(tab);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));

        verticalLayout_10->addLayout(verticalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);
        label_6->setMinimumSize(QSize(256, 0));

        horizontalLayout_8->addWidget(label_6);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setMinimumSize(QSize(120, 0));
        label_4->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(label_4);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);
        label_5->setMinimumSize(QSize(120, 0));
        label_5->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(label_5);


        verticalLayout_10->addLayout(horizontalLayout_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        augMatrix = new QTableWidget(tab);
        if (augMatrix->columnCount() < 2)
            augMatrix->setColumnCount(2);
        if (augMatrix->rowCount() < 2)
            augMatrix->setRowCount(2);
        augMatrix->setObjectName(QStringLiteral("augMatrix"));
        sizePolicy.setHeightForWidth(augMatrix->sizePolicy().hasHeightForWidth());
        augMatrix->setSizePolicy(sizePolicy);
        augMatrix->setMinimumSize(QSize(256, 200));
        augMatrix->setRowCount(2);
        augMatrix->setColumnCount(2);

        horizontalLayout_12->addWidget(augMatrix);

        tableWidget_4 = new QTableWidget(tab);
        if (tableWidget_4->columnCount() < 1)
            tableWidget_4->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        if (tableWidget_4->rowCount() < 2)
            tableWidget_4->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_4->setItem(1, 0, __qtablewidgetitem13);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));
        tableWidget_4->setMinimumSize(QSize(120, 200));
        tableWidget_4->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_12->addWidget(tableWidget_4);

        tableWidget_5 = new QTableWidget(tab);
        if (tableWidget_5->columnCount() < 1)
            tableWidget_5->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        if (tableWidget_5->rowCount() < 2)
            tableWidget_5->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem16);
        tableWidget_5->setObjectName(QStringLiteral("tableWidget_5"));
        tableWidget_5->setMinimumSize(QSize(120, 200));
        tableWidget_5->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_12->addWidget(tableWidget_5);


        verticalLayout_10->addLayout(horizontalLayout_12);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_10->addWidget(pushButton_6);

        spinnerRowCount = new QSpinBox(tab);
        spinnerRowCount->setObjectName(QStringLiteral("spinnerRowCount"));
        spinnerRowCount->setMinimum(2);
        spinnerRowCount->setMaximum(20);

        horizontalLayout_10->addWidget(spinnerRowCount);

        applyMatrixRange = new QPushButton(tab);
        applyMatrixRange->setObjectName(QStringLiteral("applyMatrixRange"));

        horizontalLayout_10->addWidget(applyMatrixRange);

        pushButton_17 = new QPushButton(tab);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        horizontalLayout_10->addWidget(pushButton_17);

        pushButton_16 = new QPushButton(tab);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        horizontalLayout_10->addWidget(pushButton_16);


        verticalLayout_8->addLayout(horizontalLayout_10);


        verticalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        verticalLayout_7->addLayout(horizontalLayout_9);


        verticalLayout_10->addLayout(verticalLayout_7);

        mainTabWidget->addTab(tab, QString());

        mainLayout->addWidget(mainTabWidget);


        verticalLayout_2->addLayout(mainLayout);

        MainWindow->setCentralWidget(widget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 19));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuGenerar_reporte = new QMenu(menuArchivo);
        menuGenerar_reporte->setObjectName(QStringLiteral("menuGenerar_reporte"));
        menuOperaciones_basicas = new QMenu(menuGenerar_reporte);
        menuOperaciones_basicas->setObjectName(QStringLiteral("menuOperaciones_basicas"));
        menuSEL = new QMenu(menuGenerar_reporte);
        menuSEL->setObjectName(QStringLiteral("menuSEL"));
        menuVer = new QMenu(menuBar);
        menuVer->setObjectName(QStringLiteral("menuVer"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuVer->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(menuGenerar_reporte->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuGenerar_reporte->addAction(menuOperaciones_basicas->menuAction());
        menuGenerar_reporte->addAction(actionNormas_vectoriales);
        menuGenerar_reporte->addAction(menuSEL->menuAction());
        menuOperaciones_basicas->addAction(action1_Matriz);
        menuOperaciones_basicas->addAction(action2_Matrices);
        menuSEL->addAction(actionGauss);
        menuSEL->addAction(actionJacobi);
        menuVer->addAction(actionResultado);
        menuAyuda->addAction(actionManual);

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gauss", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionResultado->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionManual->setShortcut(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action1_Matriz->setText(QApplication::translate("MainWindow", "1 Matriz", Q_NULLPTR));
        action2_Matrices->setText(QApplication::translate("MainWindow", "2 Matrices", Q_NULLPTR));
        actionGauss->setText(QApplication::translate("MainWindow", "Gauss", Q_NULLPTR));
        actionJacobi->setText(QApplication::translate("MainWindow", "Jacobi", Q_NULLPTR));
        actionNormas_vectoriales->setText(QApplication::translate("MainWindow", "Normas vectoriales", Q_NULLPTR));
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
        label_3->setText(QApplication::translate("MainWindow", "Vector", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "Generar vector", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "Norma infinita", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "Norma euclideana", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Normas vectoriales", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Matriz de coeficientes", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Igualaci\303\263n", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Aproximaci\303\263n inicial", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_4->isSortingEnabled();
        tableWidget_4->setSortingEnabled(false);
        tableWidget_4->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Generar pdf", Q_NULLPTR));
        applyMatrixRange->setText(QApplication::translate("MainWindow", "Establecer n\303\272mero de variables", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("MainWindow", "Jacobi", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "Gauss", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Resolucion de sistemas de ecuaciones", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuGenerar_reporte->setTitle(QApplication::translate("MainWindow", "Generar reporte", Q_NULLPTR));
        menuOperaciones_basicas->setTitle(QApplication::translate("MainWindow", "Operaciones basicas", Q_NULLPTR));
        menuSEL->setTitle(QApplication::translate("MainWindow", "SEL", Q_NULLPTR));
        menuVer->setTitle(QApplication::translate("MainWindow", "Ver", Q_NULLPTR));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
