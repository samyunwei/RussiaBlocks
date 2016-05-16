#include "OBlock.h"

OBlock::OBlock(QWidget *parent) :
    FatherBlock(parent)
{
    this->SetBlockStyleSheet("background-color: rgb(255, 255, 0);");
    this->SetShape();
}

void OBlock::SetShape()
{
    this->SetSize(this->x(),this->y(),200,200);
    this->InitBlocksList();
    QBitArray newstatus(16);
    newstatus.setBit(0,true);
    newstatus.setBit(1,true);
    newstatus.setBit(4,true);
    newstatus.setBit(5,true);
    this->addStatus(newstatus);

    QBitArray newstatus1(16);
    newstatus1.setBit(0,true);
    newstatus1.setBit(1,true);
    newstatus1.setBit(4,true);
    newstatus1.setBit(5,true);
    this->addStatus(newstatus1);

}
