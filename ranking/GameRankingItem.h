#ifndef GAMERANKINGITEM_H
#define GAMERANKINGITEM_H

#include <QString>
#include <QDateTime>
#include <QString>
#include <QUuid>

class GameRankingItem
{
public:
    explicit GameRankingItem(QString theGamename,QString theUsername,int theMark,QString theGameID = "None",QString theTime = "None");
    explicit GameRankingItem(QString theItemstr);
    explicit GameRankingItem();
    explicit GameRankingItem(const GameRankingItem &theGameRankingItem);

    ~GameRankingItem();
    QString GetItemstr(); //Temp
    QString GetGamename();
    QString GetUsername();
    int GetMark();
    QString GetTime();
    QString GetSplitstr();
    QString GetGameID(); //Temp Use UUID

    bool SetItemstr(QString theItemstr);
    void SetGamename(QString theGamename);
    void SetUsername(QString theUsername);
    void SetMark(int theMark);
    void SetTime(QString theTime = "None");
    void SetGameID(QString theGameID = "None");
    virtual void SetSplitstr(QString theSplitstr = "$$"); //default use in constructor

    static QString GetNewUUID();
private:
    QString m_Gamename;
    QString m_Username;
    QString m_GameID;
    int m_Mark;
    QString m_Time;
    QString m_splitstr;

};

#endif // GAMERANKINGITEM_H
