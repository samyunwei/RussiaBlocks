#include "TBlock.h"

TBlock::TBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(0, 170, 255);");
    this->SetShape();
}

void TBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(1,true);
    newstatus.setBit(4,true);
    newstatus.setBit(5,true);
    newstatus.setBit(6,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(1,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(5,true);
    newstatus1.setBit(9,true);
    this->addStatus(newstatus1);

    QBitArray newstatus2(16);
    newstatus2.setBit(4,true);
    newstatus2.setBit(5,true);
    newstatus2.setBit(6,true);
    newstatus2.setBit(9,true);
    this->addStatus(newstatus2);

    QBitArray newstatus3(16);
    newstatus3.setBit(1,true);
    newstatus3.setBit(5,true);
    newstatus3.setBit(6,true);
    newstatus3.setBit(9,true);
    this->addStatus(newstatus3);

}
