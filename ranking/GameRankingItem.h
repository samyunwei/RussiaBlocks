#ifndef GAMERANKINGITEM_H
#define GAMERANKINGITEM_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QString>
class GameRankingItem : public QObject
{
    Q_OBJECT
public:
    explicit GameRankingItem(QString theGamename,QString theUsername,int theMark,QString theTime = "None",QObject *parent = 0);
    explicit GameRankingItem(QString theItemstr,QObject *parent = 0);
    explicit GameRankingItem(QObject *parent = 0);


    QString GetItemstr(); //Temp
    QString GetGamename();
    QString GetUsername();
    int GetMark();
    QString GetTime();
    QString GetSplitstr();

    bool SetItemstr(QString theItemstr);
    void SetGamename(QString theGamename);
    void SetUsername(QString theUsername);
    void SetMark(int theMark);
    void SetTime(QString theTime = "None");
    virtual void SetSplitstr(QString theSplitstr = "$$"); //default use in constructor


signals:

public slots:
private:
    QString m_Gamename;
    QString m_Username;
    int m_Mark;
    QString m_Time;
    QString m_splitstr;

};

#endif // GAMERANKINGITEM_H
