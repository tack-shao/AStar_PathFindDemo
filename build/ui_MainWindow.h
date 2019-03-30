/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "GraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_column;
    QLabel *label_2;
    QLineEdit *lineEdit_row;
    QLabel *label;
    QLineEdit *lineEdit_obstacle;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_width;
    QLineEdit *lineEdit_time;
    QComboBox *comboBox;
    QPushButton *pushButton_gen;
    QPushButton *pushButton_clear;
    QLabel *label_6;
    QLabel *label_5;
    QPushButton *pushButton_clearPath;
    QPushButton *pushButton_startFinding;
    QPushButton *pushButton_clearLog;
    QTextEdit *textEdit;
    GraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1058, 681);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_column = new QLineEdit(centralWidget);
        lineEdit_column->setObjectName(QStringLiteral("lineEdit_column"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_column->sizePolicy().hasHeightForWidth());
        lineEdit_column->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_column, 0, 3, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_row = new QLineEdit(centralWidget);
        lineEdit_row->setObjectName(QStringLiteral("lineEdit_row"));
        sizePolicy.setHeightForWidth(lineEdit_row->sizePolicy().hasHeightForWidth());
        lineEdit_row->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_row, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_obstacle = new QLineEdit(centralWidget);
        lineEdit_obstacle->setObjectName(QStringLiteral("lineEdit_obstacle"));
        sizePolicy.setHeightForWidth(lineEdit_obstacle->sizePolicy().hasHeightForWidth());
        lineEdit_obstacle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_obstacle, 0, 7, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        lineEdit_width = new QLineEdit(centralWidget);
        lineEdit_width->setObjectName(QStringLiteral("lineEdit_width"));
        sizePolicy.setHeightForWidth(lineEdit_width->sizePolicy().hasHeightForWidth());
        lineEdit_width->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_width, 0, 5, 1, 1);

        lineEdit_time = new QLineEdit(centralWidget);
        lineEdit_time->setObjectName(QStringLiteral("lineEdit_time"));
        sizePolicy.setHeightForWidth(lineEdit_time->sizePolicy().hasHeightForWidth());
        lineEdit_time->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_time, 0, 9, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox, 0, 11, 1, 1);

        pushButton_gen = new QPushButton(centralWidget);
        pushButton_gen->setObjectName(QStringLiteral("pushButton_gen"));

        gridLayout->addWidget(pushButton_gen, 0, 13, 1, 1);

        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        gridLayout->addWidget(pushButton_clear, 0, 12, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 10, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 8, 1, 1);

        pushButton_clearPath = new QPushButton(centralWidget);
        pushButton_clearPath->setObjectName(QStringLiteral("pushButton_clearPath"));

        gridLayout->addWidget(pushButton_clearPath, 0, 14, 1, 1);

        pushButton_startFinding = new QPushButton(centralWidget);
        pushButton_startFinding->setObjectName(QStringLiteral("pushButton_startFinding"));

        gridLayout->addWidget(pushButton_startFinding, 0, 15, 1, 1);

        pushButton_clearLog = new QPushButton(centralWidget);
        pushButton_clearLog->setObjectName(QStringLiteral("pushButton_clearLog"));

        gridLayout->addWidget(pushButton_clearLog, 3, 13, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 13, 2, 3);

        graphicsView = new GraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 3, 13);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1058, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lineEdit_column->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "column", Q_NULLPTR));
        lineEdit_row->setText(QApplication::translate("MainWindow", "45", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "row", Q_NULLPTR));
        lineEdit_obstacle->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\351\232\234\347\242\215%", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "width", Q_NULLPTR));
        lineEdit_width->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        lineEdit_time->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\233\274\345\223\210\351\241\277\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\257\271\350\247\222\347\272\277\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\254\247\345\207\240\351\207\214\345\276\227\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\271\263\346\226\271\346\254\247\345\207\240\351\207\214\345\276\227\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Dijkstra", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Breaking ties", Q_NULLPTR)
        );
        pushButton_gen->setText(QApplication::translate("MainWindow", "gennerate", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\220\257\345\217\221\345\207\275\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        pushButton_clearPath->setText(QApplication::translate("MainWindow", "clear path", Q_NULLPTR));
        pushButton_startFinding->setText(QApplication::translate("MainWindow", "start finding", Q_NULLPTR));
        pushButton_clearLog->setText(QApplication::translate("MainWindow", "clear log", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
