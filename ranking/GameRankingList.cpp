#include "GameRankingList.h"

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
    QFile theFile("output.txt");
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
    }
    return true;
}

void GameRankingList::SetGameName(QString theGameName)
{
    m_GameName = theGameName;
}

QString GameRankingList::GetGameName()
{
    return m_GameName;
}

QList<GameRankingItem> GameRankingList::GetItemsList()
{
    return m_GameRankingItemList;
}

