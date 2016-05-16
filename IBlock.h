#ifndef IBLOCK_H
#define IBLOCK_H
#include "FatherBlock.h"
class IBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit IBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // IBLOCK_H
