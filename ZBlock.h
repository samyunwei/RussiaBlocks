#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "FatherBlock.h"
class ZBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit ZBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // ZBLOCK_H
