#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ViewHandler.h"
#include "GraphicsView.h"
#include <QLineEdit>
#include <QGraphicsScene>
#include <math.h>
#include <QVBoxLayout>

MainWindow* MainWindow::mainWindow = 0;
QMutex MainWindow::mutex;

MainWindow *MainWindow::instance()
{
    if (mainWindow == NULL) {
        QMutexLocker locker(&mutex);
        if (mainWindow == NULL) {
            mainWindow = new MainWindow;
        }
    }
    return mainWindow;
}

int MainWindow::getHeuristicType()
{
    ui->comboBox->currentIndex();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

    m_pViewHandler = new ViewHandler(ui->graphicsView);
    populateView();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_pViewHandler)
    {
        delete m_pViewHandler;
        m_pViewHandler = 0;
    }
}

void MainWindow::showLog(QString log)
{
    QString s = log;
    ui->textEdit->setText(ui->textEdit->toPlainText() + "\n" + s);
    //保持编辑器在光标最后一行
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
    //如果超过一定行数清空一下
    if (ui->textEdit->document()->lineCount() > 300)
    {
        ui->textEdit->clear();
    }
}

void MainWindow::updateView()
{
    m_pViewHandler->updateView();
}

void MainWindow::populateView()
{
    int row = ui->lineEdit_row->text().toInt();
    int column = ui->lineEdit_column->text().toInt();
    int width = ui->lineEdit_width->text().toInt();
    int time = ui->lineEdit_time->text().toInt();
    int percent =ui->lineEdit_obstacle->text().toInt();
    m_pViewHandler->newRanMap(row, column, width, percent, time);
}


void MainWindow::on_pushButton_gen_clicked()
{
    on_pushButton_clear_clicked();
    populateView();
}

void MainWindow::on_pushButton_clear_clicked()
{
    m_pViewHandler->clear();
}

void MainWindow::on_pushButton_startFinding_clicked()
{
    m_pViewHandler->findPath();
}


void MainWindow::on_pushButton_clearLog_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_clearPath_clicked()
{
    m_pViewHandler->clearPath();
}
