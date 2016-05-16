#include "SBlock.h"

SBlock::SBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(85, 170, 255);");
    this->SetShape();
}

void SBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(1,true);
    newstatus.setBit(2,true);
    newstatus.setBit(4,true);
    newstatus.setBit(5,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(0,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(5,true);
    newstatus1.setBit(9,true);
    this->addStatus(newstatus1);
}
