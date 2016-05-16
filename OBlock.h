#ifndef OBLOCK_H
#define OBLOCK_H
#include "FatherBlock.h"
class OBlock : public FatherBlock
{
    Q_OBJECT
public:
    explicit OBlock(QWidget *parent = 0);
    void SetShape();
signals:
    
public slots:
    
};

#endif // OBLOCK_H
