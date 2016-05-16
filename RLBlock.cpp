#include "RLBlock.h"

RLBlock::RLBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(0, 255, 0);");
    this->SetShape();
}

void RLBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(0,true);
    newstatus.setBit(1,true);
    newstatus.setBit(4,true);
    newstatus.setBit(8,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(0,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(5,true);
    newstatus1.setBit(6,true);
    this->addStatus(newstatus1);

    QBitArray newstatus2(16);
    newstatus2.setBit(1,true);
    newstatus2.setBit(5,true);
    newstatus2.setBit(8,true);
    newstatus2.setBit(9,true);
    this->addStatus(newstatus2);

    QBitArray newstatus3(16);
    newstatus3.setBit(0,true);
    newstatus3.setBit(1,true);
    newstatus3.setBit(5,true);
    newstatus3.setBit(9,true);
    this->addStatus(newstatus3);
}
