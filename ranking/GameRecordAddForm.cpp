#include "GameRecordAddForm.h"
#include "ui_GameRecordAddForm.h"

GameRecordAddForm::GameRecordAddForm(QString theLabelString,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRecordAddForm)
{
    ui->setupUi(this);
    m_LabelString = theLabelString;
}

GameRecordAddForm::~GameRecordAddForm()
{
    delete ui;
}
