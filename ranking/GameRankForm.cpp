#include "GameRankForm.h"
#include "ui_GameRankForm.h"
#include <QDebug>
GameRankForm::GameRankForm(QString theRecodFile ,QString theGameName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRankForm)
{
    ui->setupUi(this);
    GuiSetting();
    m_RecordFile = theRecodFile;
    m_GameRankingList.SetGameName(theGameName);
    m_GameRankingList.InitWithFile(theRecodFile);
    m_GameName = theGameName;
    m_GameRankingList.SetGameName(theGameName);
}

GameRankForm::~GameRankForm()
{
    delete ui;
}

void GameRankForm::GuiSetting()
{
    ui->tableWidget_rank->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_rank->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_rank->verticalHeader()->setHidden(true);
}

void GameRankForm::RefreshRankList(bool thesortflag)
{
    QList<GameRankingItem> theList =  m_GameRankingList.GetItemsList();
    if(thesortflag)
    {
        GameRankingList::SortListbyMark(theList);
    }
    ClearTable();
    int count = theList.count();
    for(int i = 0;i<count;i++)
    {
        ui->tableWidget_rank->insertRow(i);
        ui->tableWidget_rank->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
        ui->tableWidget_rank->setItem(i,1,new QTableWidgetItem(QString(theList[i].GetUsername())));
        ui->tableWidget_rank->setItem(i,2,new QTableWidgetItem(QString::number(theList[i].GetMark())));
    }
}

void GameRankForm::ShowAddNewMarkFrom()
{
    GameRecordAddForm *newRecord = new GameRecordAddForm;
    newRecord->show();
    delete newRecord;
}

void GameRankForm::AddNewGameRecord(QString theUserName, int theMark)
{
    m_GameRankingList.AddGameRecord(theUserName,theMark);
}

void GameRankForm::SaveAsFile()
{
    m_GameRankingList.SaveAsFile(m_RecordFile);
}

void GameRankForm::ClearTable()
{
    ui->tableWidget_rank->clearContents();
    ui->tableWidget_rank->setRowCount(0);
}

void GameRankForm::on_pushButton_quit_clicked()
{
   SaveAsFile();
   emit this->accept();
}
