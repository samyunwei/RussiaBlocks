#include "BlockRow.h"

BlockRow::BlockRow(int they,QObject *parent) :
    QObject(parent)
{
    m_y = they;
}

void BlockRow::SetY(int they)
{
    m_y = they;
}

void BlockRow::AddBlockIndex(int theindex)
{
    m_BlockIndexs.append(theindex);
}

QList<int> BlockRow::GetAllIndexs()
{
    return m_BlockIndexs;
}

int BlockRow::GetY()
{
    return m_y;
}

void BlockRow::ReduceIndexs(int thenum)
{
    int count = m_BlockIndexs.count();
    for(int i = 0;i<count;i++)
    {
        m_BlockIndexs[i] -= thenum;
    }
}
