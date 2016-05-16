#ifndef BLOCKROW_H
#define BLOCKROW_H

#include <QObject>
#include <QList>
class BlockRow : public QObject
{
    Q_OBJECT
public:
    explicit BlockRow(int they,QObject *parent = 0);
    void SetY(int they);
    int GetY();
    void AddBlockIndex(int theindex);
    QList<int> GetAllIndexs();
    void ReduceIndexs(int thenum);
    //void ReduceY(int theY,int );
signals:
    
public slots:
private:
    int m_y;
    QList<int> m_BlockIndexs;

};

#endif // BLOCKROW_H
