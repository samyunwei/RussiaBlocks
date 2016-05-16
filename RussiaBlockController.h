#ifndef RUSSIABLOCKCONTROLLER_H
#define RUSSIABLOCKCONTROLLER_H

#include <QObject>
#include <QList>
#include <QRect>
#include <QDebug>
#include <QWidget>
class RussiaBlockController : public QObject
{
    Q_OBJECT
public:
    explicit RussiaBlockController(QObject *parent = 0);
    static bool isBlocksInWindow(QList<QRect> theRectList,QRect theWindowRect,int x= 0,int y = 0);
    static bool isBlocksInsert(QList<QRect>theBlockRectList,QList<QRect>theWindowBlockRectList,int x= 0,int y = 0);
    static int GetBottomIndex(QList<QWidget*> &theBlockWidgets,int theY);
    static int GetMarkAndClearBlock(QList<QWidget*> &theBlockWidgets,int theColumnCount);
    static int Min(int a,int b);
    static int ProcessClearBlocks(QList<QWidget*> &theBlockWidgets);
    static QString GetResult(int theClearCount);
signals:
    
public slots:
private:

};

#endif // RUSSIABLOCKCONTROLLER_H
