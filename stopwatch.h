#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

signals:
    void timeChanged(int seconds, int mili);
    void roundCompleted(int roundNumber, int elapsedSeconds);

public slots:
    void start();
    void stop();
    void reset();
    void markRound();

private slots:
    void updateTime();

private:
    QTimer m_timer;
    int m_elapsedMilliseconds;
    bool m_running;
    int m_rounds;
    static int lastElapsedSeconds;
};

#endif // STOPWATCH_H
