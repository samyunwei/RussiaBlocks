#ifndef GAMERANKINGLIST_H
#define GAMERANKINGLIST_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "GameRankingItem.h"
class GameRankingList : public QObject
{
    Q_OBJECT
public:
    explicit GameRankingList(QString theGameName = "UnKnown",QObject *parent = 0);
    ~GameRankingList();

    bool InitWithFile(QString FilePath); //Only InitSameGame;
    bool SaveAsFile(QString FilePath);

    void SetGameName(QString theGameName);

    int  FindGameRecord(GameRankingItem &theItem); // if find return index else return -1
    bool AddGameRecord(GameRankingItem theItem); //Use GameID(default:UUID) As Primary Key just Like DB;
    bool AddGameRecord(QString theUserName,int theMark);
    bool RemoveGameRecord(GameRankingItem theItem);
    bool UpdateGameRecord(GameRankingItem theItem);
    bool ClearAllGameRecord();

    QString GetGameName();
    static void SortListbyMark(QList<GameRankingItem> &theList);
    QList<GameRankingItem> GetItemsList();
signals:

public slots:
private:
    QList<GameRankingItem> m_GameRankingItemList; //I think use hash may be fast
    QString m_GameName;
};

#endif // GAMERANKINGLIST_H
