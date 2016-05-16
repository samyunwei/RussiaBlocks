#include "RussiaBlockController.h"

RussiaBlockController::RussiaBlockController(QObject *parent) :
    QObject(parent)
{
}

bool RussiaBlockController::isBlocksInWindow(QList<QRect> theRectList, QRect theWindowRect,int x,int y)
{
    int count = theRectList.count();
    for(int i = 0;i<count;i++)
    {
        QRect tempBlockRect = QRect(theRectList[i]);
        tempBlockRect.setX(tempBlockRect.x() + x);
        tempBlockRect.setY(tempBlockRect.y() + y);
        if(!theWindowRect.contains(tempBlockRect))
        {
            return false;
        }
    }
    return true;
}

bool RussiaBlockController::isBlocksInsert(QList<QRect> theBlockRectList, QList<QRect> theWindowBlockRectList,int x,int y)
{
    int BlocksCount = theBlockRectList.count();
    for(int i = 0;i<BlocksCount;i++)
    {
        QRect tempBlockRect = QRect(theBlockRectList[i]);
        tempBlockRect.setX(tempBlockRect.x() + x);
        tempBlockRect.setY(tempBlockRect.y() + y);
        tempBlockRect.setWidth(theBlockRectList[i].width());
        tempBlockRect.setHeight(theBlockRectList[i].height());
        int WindowBlockCount = theWindowBlockRectList.count();
        for(int j = 0;j<WindowBlockCount;j++)
        {
            QRect tempWindowBlcokRect = QRect(theWindowBlockRectList[j]);
            if(tempBlockRect.intersects(tempWindowBlcokRect))
            {
                return true;
            }
        }
    }
    return false;
}

int RussiaBlockController::GetBottomIndex(QList<QWidget *> &theBlockWidgets, int theY)
{
    int result = theBlockWidgets.count();
    int count = theBlockWidgets.count();
    for(int i  = 0 ;i < count; i++)
    {
        if(theY >= theBlockWidgets[i]->y())
        {
            result = i-1;
            return i;
        }
    }
    return result;
}

int RussiaBlockController::GetMarkAndClearBlock(QList<QWidget *> &theBlockWidgets, int theColumnCount)
{
    if(theBlockWidgets.count() == 0)
    {
        return -1;
    }
    int theClearCount = 0;
    int theBeginindex = 0;
    int theheight = theBlockWidgets[0]->height();
    while(theBeginindex != theBlockWidgets.count()-1)
    {
        int tempy = theBlockWidgets[0]->y();
        bool theclearFlag = true;
        int tempclearcount = 0;
        for(int i = theBeginindex;i< theBeginindex+theColumnCount;i++)
        {
            if((theBlockWidgets[i]->y() != tempy))
            {
                theBeginindex = i;
                theclearFlag = false;
                break;
            }
            tempclearcount ++;
        }
        if(tempclearcount != theColumnCount)
        {
            theBeginindex += tempclearcount;
        }
        if(theclearFlag && tempclearcount == theColumnCount)
        {
            for(int i = 0;i<theColumnCount;i++)
            {
                theBlockWidgets.removeAt(theBeginindex);
                theClearCount++;
            }
            for(int i = theBeginindex;theBlockWidgets.count();i++)
            {
                theBlockWidgets[i]->setGeometry(theBlockWidgets[i]->x(),theBlockWidgets[i]->y()+theheight,theBlockWidgets[i]->width(),theBlockWidgets[i]->height());
            }
        }
    }
    return theClearCount;
}

int RussiaBlockController::Min(int a, int b)
{
    if(a<b)
    {
        return a;
    }else
    {
        return b;
    }
}

int RussiaBlockController::ProcessClearBlocks(QList<QWidget *> &theBlockWidgets)
{
    int count = theBlockWidgets.count();
    for(int i = 0; i <count;i++)
    {
        QWidget *temp = theBlockWidgets[i];
        delete temp;
    }
    return count;
}

QString RussiaBlockController::GetResult(int theClearCount)
{
    QString theSentence = "";
    if(theClearCount < 60)
    {
        theSentence = "谁的猪蹄?";
    }else if(theClearCount < 100)
    {
        theSentence = "终于有人来玩了！";
    }else
    {
        theSentence = "灵巧的双手!Good Job!";
    }
    return QString("得分为%1\n%2").arg(theClearCount).arg(theSentence);
}
