#include "FatherBlock.h"
#include "ui_FatherBlock.h"

FatherBlock::FatherBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FatherBlock)
{
    ui->setupUi(this);
    GeneralGuiSetting(parent);
    m_current_status_index = 0;
    m_block_width = 0;
    m_block_height = 0;
    m_block_type = 0;
    m_moveFlag = true;
}

FatherBlock::~FatherBlock()
{
    delete ui;
}

void FatherBlock::SetSize(int thex, int they, int thewidth, int thehight)
{
    this->setGeometry(thex,they,thewidth,thehight);
    this->repaint();
    m_x = thex;
    m_y = they;
    m_width = thewidth;
    m_height = thehight;
}

bool FatherBlock::RotateNext(int theStatusIndex)
{
    if(m_status_list.count() == 0)
    {
        return false;
    }
    if(theStatusIndex != -1)
    {
        if(theStatusIndex < m_status_list.count())
          {
            m_current_status_index = theStatusIndex;
            this->RotateShape(m_current_status_index);
            return true;
        }else
        {
            return false;
        }
    }else
    {
         m_current_status_index++;
        if(m_current_status_index < m_status_list.count())
        {
           this->RotateShape(m_current_status_index);
            return true;
        }else
        {
            m_current_status_index = 0;
            this->RotateShape(m_current_status_index);
        }
    }
    return false;
}

bool FatherBlock::InitBlocksList(int theRow, int theColunm, int theBlockType)
{
    for(int i = 0;i<theRow;i++)
    {
        for(int j = 0;j<theColunm;j++)
        {
            QWidget *theSingleBlock = GetSingleBlock(theBlockType);
            theSingleBlock->setStyleSheet(m_BlockStyleSheet);
            ui->gridLayout->addWidget(theSingleBlock,i,j);
            m_blocks_list.append(theSingleBlock);
        }
    }
    m_block_row_count = theRow;
    m_block_column_count = theColunm;
    m_block_type = theBlockType;
    if(m_blocks_list.count())
    {
        m_block_width = m_blocks_list[0]->width();
        m_block_height = m_blocks_list[0]->height();
    }
    return true;
}

QWidget *FatherBlock::GetSingleBlock(int theBlockType)
{
    switch (theBlockType)
    {
    case 0:
    {
        QWidget *theSingleBolck = new QPushButton();
        theSingleBolck->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        return theSingleBolck;
        break;
    }
    default:
    {
        QWidget *theSingleBolck = new QPushButton();
        theSingleBolck->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        return theSingleBolck;
        break;
    }
    }
}

void FatherBlock::GeneralGuiSetting(QWidget *parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->setAutoFillBackground(false);
    this->setAcceptDrops(true);
    this->setGeometry(this->x()+200,this->y(),this->width(),this->width());
    m_x = this->x();
    m_y = this->y();
    m_width = this->width();
    m_height = this->width();
}

void FatherBlock::SetStatusList(QList<QBitArray> theStatusList)
{
    m_status_list = theStatusList;
}

bool FatherBlock::RotateShape(int theStatusIndex)
{
    if(theStatusIndex < m_status_list.count())
    {
        QBitArray theStatus = m_status_list[theStatusIndex];
        int count = theStatus.count()-1;
        while(count >= 0)
        {
            if(theStatus.testBit(count) == true)
            {
                SetStatusEnable(m_blocks_list[count]);
            }else
            {
                SetStatusDisable(m_blocks_list[count]);
            }
            count--;
        }
        return true;
    }else
    {
        return false;
    }
}

bool FatherBlock::addStatus(QBitArray theStatus)
{
    if(theStatus.count() == m_blocks_list.count())
    {
        m_status_list.append(theStatus);
        return true;
    }else
    {
        return false;
    }
}

bool FatherBlock::SetStatusEnable(QWidget *theBlock)
{
    QPushButton* theSetBlock = static_cast<QPushButton*>(theBlock);
    theSetBlock->setEnabled(true);
     theSetBlock->setFlat(false);
     theSetBlock->setStyleSheet(m_BlockStyleSheet);
    return true;
}

bool FatherBlock::SetStatusDisable(QWidget *theBlock)
{
    QPushButton* theSetBlock = static_cast<QPushButton*>(theBlock);
    theSetBlock->setDisabled(true);
    theSetBlock->setFlat(true);
    theSetBlock->setStyleSheet("background::transparent");
    return true;
}

void FatherBlock::RotateNextSlot()
{
    if(m_moveFlag)
    {
        this->RotateNext();
    }
}

void FatherBlock::RotatShapeSlot(int theindex)
{
    if(m_moveFlag)
    {
        this->RotateShape(theindex);
    }
}

bool FatherBlock::MoveDown(int theY)
{
    this->setGeometry(this->x(),this->y()+theY,this->width(),this->width());
    this->repaint();
    return true;
}

bool FatherBlock::MoveUp(int theY)
{
    this->setGeometry(this->x(),this->y()-theY,this->width(),this->width());
    this->repaint();
    return true;
}

bool FatherBlock::MoveLeft(int theX)
{
    this->setGeometry(this->x()-theX,this->y(),this->width(),this->width());
    this->repaint();
    return true;
}

bool FatherBlock::MoveRight(int theX)
{
    this->setGeometry(this->x()+theX,this->y(),this->width(),this->width());
    this->repaint();
    return true;
}

void FatherBlock::MoveUpSlot(int they)
{
    if(m_moveFlag)
    {
        this->MoveUp(they);
    }
}

void FatherBlock::MoveDownSlot(int they)
{
    if(m_moveFlag)
    {
        this->MoveDown(they);
    }
}

void FatherBlock::MoveLeftSlot(int thex)
{
    if(m_moveFlag)
    {
        this->MoveLeft(thex);
    }
}

void FatherBlock::MoveRightSlot(int thex)
{
    if(m_moveFlag)
    {
        this->MoveRight(thex);
    }
}

QList<QRect> FatherBlock::GetEnableBlockRects(int theStatusIndex,bool theRealBlocksFlag)
{
    QList<QRect>theBlockRects;
    if(theStatusIndex == -1)
    {
        theStatusIndex = m_current_status_index;
    }
    if(theStatusIndex < m_status_list.count())
    {
        QBitArray theStatus = m_status_list[theStatusIndex];
        int count = theStatus.count()-1;
        while(count >= 0)
        {
            if(theStatus.testBit(count) == true)
            {
                QRect ChildBlockRect =  QRect(m_blocks_list[count]->geometry());
                ChildBlockRect.setX(ChildBlockRect.x() + this->x());
               ChildBlockRect.setY(ChildBlockRect.y() + this->y());
               ChildBlockRect.setWidth(m_blocks_list[count]->width());
               ChildBlockRect.setHeight(m_blocks_list[count]->height());
                if(!hasBottomBlock(count) && !theRealBlocksFlag)
                {
                    QRect tempBlock(ChildBlockRect);
                    tempBlock.setY(ChildBlockRect.y()+m_blocks_list[count]->height());
                    theBlockRects.append(tempBlock);
                }
                if(!hasRightBlock(count) && !theRealBlocksFlag)
                {
                    QRect tempBlock(ChildBlockRect);
                    tempBlock.setX(ChildBlockRect.x() + m_blocks_list[count]->width());
                    theBlockRects.append(tempBlock);
                }
                 theBlockRects.append(ChildBlockRect);
            }
            count--;
        }
    }
    return theBlockRects;
}

bool FatherBlock::hasBottomBlock(int theBlockIndex)
{
    theBlockIndex += m_block_column_count;
    if(theBlockIndex < m_status_list[m_current_status_index].count())
    {
        if(m_status_list[m_current_status_index][theBlockIndex])
        {
            return true;
        }else
        {
            return false;
        }
    }else
    {
        return false;
    }
}

bool FatherBlock::hasRightBlock(int theBlockIndex)
{
    theBlockIndex += 1;
    if(theBlockIndex < m_status_list[m_current_status_index].count())
    {
        if(m_status_list[m_current_status_index][theBlockIndex])
        {
            return true;
        }else
        {
            return false;
        }
    }else
    {
        return false;
    }
}

int FatherBlock::GetNextStatusIndex()
{
    int theNextStatus = m_current_status_index;
    theNextStatus++;
    if(theNextStatus < m_status_list.count())
    {
        return theNextStatus;
    }else
    {
        return 0;
    }
}

void FatherBlock::SetMoveFlag(bool theMoveFlag)
{
    m_moveFlag = theMoveFlag;
}

QList<QWidget *> FatherBlock::GetEnableBlocksWidget(int theStatusIndex)
{
    QList<QWidget *>theBlockWidgets;
    if(theStatusIndex == -1)
    {
        theStatusIndex = m_current_status_index;
    }
    if(theStatusIndex < m_status_list.count())
    {
        QBitArray theStatus = m_status_list[theStatusIndex];
        int count = theStatus.count()-1;
        while(count >= 0)
        {
            if(theStatus.testBit(count) == true)
            {
                QWidget *ChildBlockWidget = GetSingleBlock(m_block_type);
                ChildBlockWidget->setStyleSheet(m_BlockStyleSheet);
                ChildBlockWidget->setGeometry(m_blocks_list[count]->geometry());
                ChildBlockWidget->setGeometry(ChildBlockWidget->x()+this->x(),ChildBlockWidget->y()+this->y(),ChildBlockWidget->width(),ChildBlockWidget->height());
                theBlockWidgets.append(ChildBlockWidget);
            }
            count--;
        }
    }
    return theBlockWidgets;
}

int FatherBlock::GetSingleBlockHeight()
{
    int theheight = -1;
    if(m_blocks_list.count() != 0)
    {
        theheight = m_blocks_list[0]->height();
    }
    return theheight;
}

int FatherBlock::GetSingleBlockWidth()
{
    int thewidth = -1;
    if(m_blocks_list.count() != 0)
    {
        thewidth = m_blocks_list[0]->width();
    }
    return thewidth;
}

void FatherBlock::SetBlockStyleSheet(QString theStyleSheet)
{
    m_BlockStyleSheet = theStyleSheet;
    int count = m_blocks_list.count();
    for(int i = 0;i<count;i++)
    {
        m_blocks_list[i]->setStyleSheet(m_BlockStyleSheet);
    }
}

QString FatherBlock::GetBlocksStyleSheet()
{
    return m_BlockStyleSheet;
}



