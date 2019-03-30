#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>

class ViewHandler;

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * 封装成单例模式，方便其他模块调用UI
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static MainWindow* instance();
    static void destroyInstance(){
        if (mainWindow)
        {
            delete mainWindow;
            mainWindow = 0;
        }
    }
    int getHeuristicType();
private:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showLog(QString log);
    void updateView();
private slots:
    void on_pushButton_gen_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_startFinding_clicked();

    void on_pushButton_clearLog_clicked();

    void on_pushButton_clearPath_clicked();

private:
    Ui::MainWindow *ui;
    ViewHandler* m_pViewHandler;
private:
    void populateView();
private:
    static MainWindow* mainWindow;
    static QMutex mutex;
};

#ifndef gUiService
#define gUiService (MainWindow::instance())
#endif

#endif // MAINWINDOW_H
