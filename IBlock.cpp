#include "IBlock.h"

IBlock::IBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(255, 7, 11);");
    this->SetShape();
}

void IBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(0,true);
    newstatus.setBit(1,true);
    newstatus.setBit(2,true);
    newstatus.setBit(3,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(0,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(8,true);
    newstatus1.setBit(12,true);
    this->addStatus(newstatus1);
}
