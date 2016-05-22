#ifndef GAMERANKINGLIST_H
#define GAMERANKINGLIST_H

#include <QObject>

class GameRankingList : public QObject
{
    Q_OBJECT
public:
    explicit GameRankingList(QObject *parent = 0);

signals:

public slots:
};

#endif // GAMERANKINGLIST_H
