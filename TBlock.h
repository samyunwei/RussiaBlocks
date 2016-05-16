#ifndef TBLOCK_H
#define TBLOCK_H
#include "FatherBlock.h"
class TBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit TBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // TBLOCK_H
