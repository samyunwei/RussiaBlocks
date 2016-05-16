#include "ZBlock.h"

ZBlock::ZBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(170, 0, 255);");
    this->SetShape();
}

void ZBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(0,true);
    newstatus.setBit(1,true);
    newstatus.setBit(5,true);
    newstatus.setBit(6,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(1,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(5,true);
    newstatus1.setBit(8,true);
    this->addStatus(newstatus1);
}
