#ifndef SBLOCK_H
#define SBLOCK_H
#include "FatherBlock.h"
class SBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit SBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // SBLOCK_H
