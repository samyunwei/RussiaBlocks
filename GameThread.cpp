#include "GameThread.h"
#include <QDebug>
GameThread::GameThread(QObject *parent) :
    QThread(parent)
{
    m_WaitTime = 200;
    m_RunFlag = true;
}

void GameThread::run()
{
    while(m_RunFlag)
    {
        this->msleep(m_WaitTime);
        emit SignalMoveDown();
    }
}

void GameThread::SetWaitTime(int theWaitTime)
{
    m_WaitTime = theWaitTime;
}

void GameThread::SetRunFlag(bool theRunFlag)
{
    m_RunFlag = theRunFlag;
}

int GameThread::GetWaitTime()
{
    return m_WaitTime;
}
