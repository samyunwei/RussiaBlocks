#ifndef FATHERBLOCK_H
#define FATHERBLOCK_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QDebug>
#include <QBitArray>
#include <QPalette>
#include <QRect>
#include <QColor>
namespace Ui {
class FatherBlock;
}

class FatherBlock : public QWidget
{
    Q_OBJECT
    
public:
    explicit FatherBlock(QWidget *parent = 0);
    ~FatherBlock();
    void SetSize(int theX,int theY,int theWidth,int theHight); //初始化大小方便后期调整大小
    void SetMoveFlag(bool theMoveFlag);
    void SetBlockStyleSheet(QString theStyleSheet);

    bool RotateNext(int theStatusIndex = -1);//变形
    bool RotateShape(int theStatusIndex); //变形为形状列表中的一种形状

    bool MoveDown(int theY);
    bool MoveUp(int theY);

    bool MoveLeft(int theX);
    bool MoveRight(int theX);

    int GetSingleBlockHeight();
    int GetSingleBlockWidth();
    QString GetBlocksStyleSheet();

    bool InitBlocksList(int theRow = 4,int theColunm = 4,int theBlockType = 0); //构建样式图形
    QWidget* GetSingleBlock(int theBlockType =0); //获得填充图形

    virtual void GeneralGuiSetting(QWidget *parent); //设置图形总体样子 default in center
    virtual void SetStatusList(QList<QBitArray> theStatusList); //初始化图形状态表
    virtual bool addStatus(QBitArray theStatus);

    virtual bool SetStatusEnable(QWidget* theBlock); //设置显示形状
    virtual bool SetStatusDisable(QWidget* theBlock); //设置隐藏形状

    QList<QRect> GetEnableBlockRects(int theStatusIndex = -1,bool theRealBlocksFlag = false);
    QList<QWidget *>GetEnableBlocksWidget(int theStatusIndex = -1);



    int GetNextStatusIndex();
public slots:
    void RotateNextSlot(); //旋转下一个槽
    void RotatShapeSlot(int theindex); //旋转为指定图形

    void MoveUpSlot(int they); //位移量均为正
    void MoveDownSlot(int they);
    void MoveLeftSlot(int thex);
    void MoveRightSlot(int thex);
private:
    bool hasBottomBlock(int theBlockIndex);
    bool hasRightBlock(int theBlockIndex);
protected:
    int m_x; //坐标X
    int m_y;//坐标Y

    int m_width;//方块宽度
    int m_height;//方块高度
    int m_block_type;//方块类型

    int m_block_row_count; //方块行
    int m_block_column_count; //方块列

    int m_block_width;
    int m_block_height;

    bool m_initFlag; //初始化标志
    bool m_moveFlag;//可移动标志
    QList<QWidget*> m_blocks_list; //填充体存储链表
    int m_current_status_index; //当前状态

    QList<QBitArray>m_status_list;  //变化状态链表
private:
    Ui::FatherBlock *ui;

    QString m_BlockStyleSheet;
};

#endif // FATHERBLOCK_H
