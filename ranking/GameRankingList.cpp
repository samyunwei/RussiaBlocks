#include "GameRankingList.h"
#include <QDebug>
GameRankingList::GameRankingList(QString theGameName,QObject *parent) : QObject(parent)
{
    m_GameName = theGameName;
}

GameRankingList::~GameRankingList()
{
    m_GameRankingItemList.clear();
}

bool GameRankingList::InitWithFile(QString FilePath)
{
    if(!QFile::exists(FilePath))
    {
        return false;
    }
    QFile theFile(FilePath);
    if (theFile.open(QFile::ReadOnly )) {
        QTextStream Read(&theFile);
        GameRankingItem newItem;
        QString theLine;
        do {
            theLine = Read.readLine();
            if(newItem.SetItemstr(theLine))
            {
                if(newItem.GetGamename() == m_GameName)
                {
                    m_GameRankingItemList.append(newItem);
                }
            }
        } while (!theLine.isNull());
        theFile.close();
        return true;
    }else
    {
        return false;
    }
    return false;
}

bool GameRankingList::SaveAsFile(QString FilePath)
{
    QFile theFile(FilePath);
    if(theFile.open(QFile::WriteOnly))
    {
        QTextStream WriteStream(&theFile);
        int count = m_GameRankingItemList.count();
        for(int i = 0;i<count;i++)
        {
            WriteStream<<m_GameRankingItemList[i].GetItemstr()<<"\n";
        }
        theFile.close();
        return true;
    }else
    {
        return false;
    }
    return false;
}

void GameRankingList::SetGameName(QString theGameName)
{
    m_GameName = theGameName;
}

int GameRankingList::FindGameRecord(GameRankingItem &theItem)
{
    int count = m_GameRankingItemList.count();
    int res = -1;
    for(int i = 0;i<count;i++)
    {
        if(theItem.GetGameID() == m_GameRankingItemList[i].GetGameID())
        {
            res = i;
            break;
        }
    }
    return res;
}

bool GameRankingList::AddGameRecord(GameRankingItem theItem)
{
    if(FindGameRecord(theItem) == -1)
    {
        m_GameRankingItemList.append(theItem);
        return true;
    }else
    {
        return false;
    }
    return false;
}

bool GameRankingList::AddGameRecord(QString theUserName, int theMark)
{
    GameRankingItem newGameRecord(m_GameName,theUserName,theMark);
    m_GameRankingItemList.append(newGameRecord);
    return true;
}

bool GameRankingList::RemoveGameRecord(GameRankingItem theItem)
{
    int  theindex = FindGameRecord(theItem);
    if(theindex != -1)
    {
        m_GameRankingItemList.removeAt(theindex);
        return true;
    }else
    {
        return false;
    }
}

bool GameRankingList::UpdateGameRecord(GameRankingItem theItem)
{
    int  theindex = FindGameRecord(theItem);
    if(theindex != -1)
    {
        m_GameRankingItemList.replace(theindex,theItem);
        return true;
    }else
    {
        return false;
    }
}

bool GameRankingList::ClearAllGameRecord()
{
    m_GameRankingItemList.clear();
    return true;
}

QString GameRankingList::GetGameName()
{
    return m_GameName;
}

void GameRankingList::SortListbyMark(QList<GameRankingItem> &theList)
{
    int count = theList.count();
    if(count == 0)
    {
        return;
    }
    int op = 0;
    while(op < count)
    {
        int theMinindex = 0;
        for(int i = 0;i<count -op;i++)
        {
            if(theList[i].GetMark() > theList[theMinindex].GetMark())
            {
                theList.swap(i,theMinindex);
                theMinindex = i;
            }else
            {
                theMinindex = i;
            }
        }
        op++;
    }
}

QList<GameRankingItem> GameRankingList::GetItemsList()
{
    return m_GameRankingItemList;
}

