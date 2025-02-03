#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startStopButton_clicked();
    void on_clearButton_clicked();
    void updateTimeDisplay(int seconds, int mili);
    void addRoundToBrowser(int roundNumber, int elapsedSeconds);

private:
    Ui::MainWindow *ui;
    Stopwatch *m_stopwatch;
};

#endif // MAINWINDOW_H
