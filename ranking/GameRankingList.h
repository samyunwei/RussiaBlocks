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
    explicit GameRankingList(QString theGameName,QObject *parent = 0);
    ~GameRankingList();
    bool InitWithFile(QString FilePath);

    void SetGameName(QString theGameName);

    QString GetGameName();
    QList<GameRankingItem> GetItemsList();
signals:

public slots:
private:
    QList<GameRankingItem> m_GameRankingItemList;
    QString m_GameName;
};

#endif // GAMERANKINGLIST_H
