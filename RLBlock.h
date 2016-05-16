#ifndef RLBLOCK_H
#define RLBLOCK_H
#include "FatherBlock.h"

class RLBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit RLBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // RLBLOCK_H
