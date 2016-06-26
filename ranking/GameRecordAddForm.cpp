#include "GameRecordAddForm.h"
#include "ui_GameRecordAddForm.h"

GameRecordAddForm::GameRecordAddForm(QString theLabelString,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRecordAddForm)
{
    ui->setupUi(this);
    m_LabelString = theLabelString;
    ui->label_Score->setText(m_LabelString);
    GuiSetting();
}

GameRecordAddForm::~GameRecordAddForm()
{
    delete ui;
}

void GameRecordAddForm::GuiSetting()
{
    ui->lineEdit_UserName->setText("No Name");
}

QString GameRecordAddForm::GetUserName()
{
    return ui->lineEdit_UserName->text();
}


void GameRecordAddForm::on_pushButton_OK_clicked()
{
    this->close();
}
