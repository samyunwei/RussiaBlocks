#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>

class GameThread : public QThread
{
    Q_OBJECT
public:
    explicit GameThread(QObject *parent = 0);
     void run();
     void SetWaitTime(int theWaitTime);
     void SetRunFlag(bool theRunFlag);
     int GetWaitTime();
signals:
    void SignalMoveDown();
public slots:
private:
    bool m_RunFlag;
   int m_WaitTime;
};

#endif // GAMETHREAD_H
