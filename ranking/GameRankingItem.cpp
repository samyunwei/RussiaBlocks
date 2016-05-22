#include "GameRankingItem.h"

GameRankingItem::GameRankingItem(QString theGamename, QString theUsername, int theMark, QString theTime, QObject *parent)
{
    m_Gamename = theGamename;
    m_Username = theUsername;
    m_Mark = theMark;
    if(theTime == "None")
    {
        theTime = QDateTime::currentDateTime().toString();
    }else
    {
        m_Time = theTime;
    }
    SetSplitstr();
}

GameRankingItem::GameRankingItem(QString theItemstr, QObject *parent)
{
    SetSplitstr();
    SetItemstr(theItemstr);
}

GameRankingItem::GameRankingItem(QObject *parent) : QObject(parent)
{
    m_Gamename = "";
    m_Username = "";
    m_Mark = 0;
    m_Time = QDateTime::currentDateTime().toString();
    SetSplitstr();
}

QString GameRankingItem::GetItemstr()
{
    QStringList tempattrList;
    tempattrList.append(m_Gamename);
    tempattrList.append(m_Username);
    tempattrList.append(QString::number(m_Mark));
    tempattrList.append(m_Time);
    return tempattrList.join(m_splitstr);
}

QString GameRankingItem::GetGamename()
{
    return m_Gamename;
}

QString GameRankingItem::GetUsername()
{
    return m_Username;
}

int GameRankingItem::GetMark()
{
    return m_Mark;
}

QString GameRankingItem::GetTime()
{
    return m_Time;
}

QString GameRankingItem::GetSplitstr()
{
    return m_splitstr;
}

bool GameRankingItem::SetItemstr(QString theItemstr)
{
    QStringList theattrList = theItemstr.split(m_splitstr);
    if(theattrList.count() == 4)
    {
        m_Gamename = QString(theattrList[0]);
        m_Username = QString(theattrList[1]);
        m_Mark = QString(theattrList[2]).toInt();
        m_Time = QString(theattrList[3]);
        return true;
    }else
    {
        return false;
    }
}

void GameRankingItem::SetGamename(QString theGamename)
{
    m_Gamename = theGamename;
}

void GameRankingItem::SetUsername(QString theUsername)
{
    m_Username = theUsername;
}

void GameRankingItem::SetMark(int theMark)
{
    m_Mark = theMark;
}

void GameRankingItem::SetTime(QString theTime)
{
    m_Time = theTime;
}

void GameRankingItem::SetSplitstr(QString theSplitstr)
{
    m_splitstr = theSplitstr;
}

