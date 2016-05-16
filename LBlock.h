#ifndef LBLOCK_H
#define LBLOCK_H
#include "FatherBlock.h"
class LBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit LBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // LBLOCK_H
