#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_stopwatch(new Stopwatch(this))
{
    ui->setupUi(this);

    connect(ui->clearButton, &QPushButton::clicked, m_stopwatch, &Stopwatch::reset);
    connect(ui->lapButton, &QPushButton::clicked, m_stopwatch, &Stopwatch::markRound);

    connect(m_stopwatch, &Stopwatch::timeChanged, this, &MainWindow::updateTimeDisplay);
    connect(m_stopwatch, &Stopwatch::roundCompleted, this, &MainWindow::addRoundToBrowser);

    ui->lapButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    if (ui->startStopButton->text() == "Старт") {
        ui->startStopButton->setText("Стоп");
        ui->lapButton->setEnabled(true);
        m_stopwatch->start();
    } else {
        ui->startStopButton->setText("Старт");
        ui->lapButton->setEnabled(false);
        m_stopwatch->stop();
    }
}

void MainWindow::updateTimeDisplay(int seconds, int mili)
{
    QString timeString = QString("%1:%2.%3").arg(seconds / 60, 2, 10, QChar('0')).arg(seconds % 60, 2, 10, QChar('0')).arg(mili - seconds * 1000, 2, 10, QChar('0'));
    ui->timeLabel->setText(timeString);
}

void MainWindow::addRoundToBrowser(int roundNumber, int elapsedSeconds)
{
    QString roundString = QString("Круг %1, время: %2 сек\n").arg(roundNumber).arg(elapsedSeconds);
    ui->roundsBrowser->append(roundString);
}

void MainWindow::on_clearButton_clicked()
{
    ui->roundsBrowser->clear();
}
