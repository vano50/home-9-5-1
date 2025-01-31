#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent), m_running(false), m_rounds(0), m_elapsedMilliseconds(0)
{
    connect(&m_timer, &QTimer::timeout, this, &Stopwatch::updateTime);
    m_timer.setInterval(100);
}

void Stopwatch::start()
{
    if (!m_running) {
        m_timer.start();
        m_running = true;
    }
}

void Stopwatch::stop()
{
    if (m_running) {
        m_timer.stop();
        m_running = false;
    }
}

void Stopwatch::reset()
{
    m_elapsedMilliseconds = 0;
    m_rounds = 0;
    emit timeChanged(0);
}
int lastElapsedSeconds = 0;
void Stopwatch::markRound()
{
    if (m_running) {
        int elapsedSeconds = m_elapsedMilliseconds / 1000;
        emit roundCompleted(++m_rounds, elapsedSeconds - lastElapsedSeconds);
        lastElapsedSeconds = m_elapsedMilliseconds / 1000;
    }
}

void Stopwatch::updateTime()
{
    m_elapsedMilliseconds += m_timer.interval();
    emit timeChanged(m_elapsedMilliseconds / 1000);
}
