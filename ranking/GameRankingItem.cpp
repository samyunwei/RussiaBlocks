#include "GameRankingItem.h"

GameRankingItem::GameRankingItem(QString theGamename, QString theUsername, int theMark, QString theGameID,QString theTime)
{
    m_Gamename = theGamename;
    m_Username = theUsername;
    m_Mark = theMark;
    m_GameID = theGameID;
    if(theTime == "None")
    {
        theTime = QDateTime::currentDateTime().toString();
    }else
    {
        m_Time = theTime;
    }

    if(theGameID == "None")
    {
        m_GameID = GetNewUUID();
    }else
    {
        m_GameID = theGameID;
    }
    SetSplitstr();
}

GameRankingItem::GameRankingItem(QString theItemstr)
{
    SetSplitstr();
    SetItemstr(theItemstr);
}

GameRankingItem::GameRankingItem()
{
    m_Gamename = "";
    m_Username = "";
    m_Mark = 0;
    m_Time = QDateTime::currentDateTime().toString();
    SetSplitstr();
}

GameRankingItem::GameRankingItem(const GameRankingItem &theGameRankingItem)
{
    if(this != &theGameRankingItem)
    {
        m_Gamename = theGameRankingItem.m_Gamename;
        m_Username = theGameRankingItem.m_Username;
        m_Mark = theGameRankingItem.m_Mark;
        m_GameID = theGameRankingItem.m_GameID;
        m_Time = theGameRankingItem.m_Time;
    }
}

GameRankingItem::~GameRankingItem()
{

}

QString GameRankingItem::GetItemstr()
{
    QStringList tempattrList;
    tempattrList.append(m_Gamename);
    tempattrList.append(m_Username);
    tempattrList.append(QString::number(m_Mark));
    tempattrList.append(m_GameID);
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

QString GameRankingItem::GetGameID()
{
    return m_GameID;
}

bool GameRankingItem::SetItemstr(QString theItemstr)
{
    QStringList theattrList = theItemstr.split(m_splitstr);
    if(theattrList.count() == 5)
    {
        m_Gamename = QString(theattrList[0]);
        m_Username = QString(theattrList[1]);
        m_Mark = QString(theattrList[2]).toInt();
        m_GameID = QString(theattrList[3]);
        m_Time = QString(theattrList[4]);
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

void GameRankingItem::SetGameID(QString theGameID)
{
    if(theGameID == "None")
    {
        m_GameID = GetNewUUID();
    }else
    {
        m_GameID = theGameID;
    }
}

void GameRankingItem::SetSplitstr(QString theSplitstr)
{
    m_splitstr = theSplitstr;
}

QString GameRankingItem::GetNewUUID()
{
    QString newUUID = QUuid::createUuid().toString();
    newUUID.replace("{","");
    newUUID.replace("}","");
    newUUID.replace("-","");
    return newUUID;
}

