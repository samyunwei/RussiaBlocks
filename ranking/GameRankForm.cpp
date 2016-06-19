#include "GameRankForm.h"
#include "ui_GameRankForm.h"
#include <QDebug>
GameRankForm::GameRankForm(QString theRecodFile ,QString theGameName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRankForm)
{
    ui->setupUi(this);
    GuiSetting();
    m_RecordFile = theRecodFile;
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
}

void GameRankForm::RefreshRankList()
{
    QList<GameRankingItem> theList =  m_GameRankingList.GetItemsList();

    ClearTable();
    int count = theList.count();
    for(int i = 0;i<count;i++)
    {
        ui->tableWidget_rank->insertRow(0);
        ui->tableWidget_rank->setItem(0,0,new QTableWidgetItem(QString::number(count - i)));
        ui->tableWidget_rank->setItem(0,1,new QTableWidgetItem(QString(theList[i].GetUsername())));
        ui->tableWidget_rank->setItem(0,2,new QTableWidgetItem(QString::number(theList[i].GetMark())));
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
}
