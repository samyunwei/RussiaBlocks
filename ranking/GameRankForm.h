#ifndef GAMERANKFORM_H
#define GAMERANKFORM_H

#include <QDialog>

#include "GameRankingList.h"
#include "GameRecordAddForm.h"
namespace Ui {
class GameRankForm;
}

class GameRankForm : public QDialog
{
    Q_OBJECT

public:
    explicit GameRankForm(QString theRecodFile = "./record.mk",QString theGameName = "NoName",QWidget *parent = 0);
    ~GameRankForm();


    void GuiSetting();
    void RefreshRankList(bool thesortflag = true);
    void ShowAddNewMarkFrom();

    void AddNewGameRecord(QString theUserName,int theMark);
    void SaveAsFile();

    void ClearTable();

    void MarkBests(int therow);
private slots:
    void on_pushButton_quit_clicked();

private:
    Ui::GameRankForm *ui;

    GameRankingList m_GameRankingList;
    QString m_RecordFile;
    QString m_GameName;
};

#endif // GAMERANKFORM_H
