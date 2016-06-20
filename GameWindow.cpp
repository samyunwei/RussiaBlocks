#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    poslenth = 10;
    movepath = 5;
    m_currentFatherBlock = NULL;
    GameWindowGuiSetting(510,700);
    connect(&m_GameThread,SIGNAL(SignalMoveDown()),this,SLOT(CathchMoveDownGameThread()));
    connect(this,SIGNAL(CurrentClearBlocksSignal(int)),this,SLOT(CurrentClearBlocksSlot(int)));
    m_AllClearBlocks = 0;
}

GameWindow::~GameWindow()
{
    delete ui;
    m_currentFatherBlock = NULL;
}

void GameWindow::on_pushButton_Rotate_clicked()
{
    emit this->RotateNextSignal();
}

void GameWindow::on_pushButton_moveUp_clicked()
{
    emit this->MoveUpSignal(poslenth);
}

void GameWindow::on_pushButton_moveLeft_clicked()
{
    emit this->MoveLeftSignal(poslenth);
}

void GameWindow::on_pushButton_moveRight_clicked()
{
    emit this->MoveRightSignal(poslenth);
}

void GameWindow::on_pushButton_moveDown_clicked()
{
    emit this->MoveDownSignal(poslenth);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    int keyValue = event->key();
    switch(keyValue)
    {
    case Qt::Key_O:
    {
        judgeRotateNext();
        break;
    }
    case Qt::Key_W:
    {
        //judgeMoveUp();
        break;
    }
    case Qt::Key_A:
    {
        for(int i = 0;i<movepath;i++)
        {
            judgeMoveLeft();
        }
        break;
    }
    case Qt::Key_D:
    {
        for(int i = 0;i<movepath;i++)
        {
            judgeMoveRight();
        }
        break;
    }
    case Qt::Key_S:
    {
        judgeMoveDown();
        break;
    }
        /////////////////////第二种操作
    case Qt::Key_Up:
    {
        judgeRotateNext();
        break;
    }
    case Qt::Key_Left:
    {
        for(int i = 0;i<movepath;i++)
        {
            judgeMoveLeft();
        }
        break;
    }
    case Qt::Key_Right:
    {
        for(int i = 0;i<movepath;i++)
        {
            judgeMoveRight();
        }
        break;
    }
    case Qt::Key_Down:
    {
        judgeMoveDown();
        break;
    }
    default:
    {
        break;
    }
    }
}

void GameWindow::on_pushButton_produce_clicked()
{
    if(m_currentFatherBlock == NULL)
    {
        ProduceNewBlock(GetRandType());
    }
    if(!m_GameThread.isRunning())
    {
        m_GameThread.SetRunFlag(true);
        m_GameThread.start();
    }
}

void GameWindow::CatchOldBlock(FatherBlock *theOldBlock)
{
    theOldBlock->SetMoveFlag(false);
    QString tempStyleSheet = theOldBlock->GetBlocksStyleSheet();
    m_currentFatherBlock = NULL;
    QList<QWidget*>theOldBlockEnableWidgets = theOldBlock->GetEnableBlocksWidget();
    int count = theOldBlockEnableWidgets.count();
    for(int i = 0 ;i<count;i++)
    {
        int theindex = RussiaBlockController::GetBottomIndex(m_static_blocks,theOldBlockEnableWidgets[i]->y());
        m_static_blocks.insert(theindex,theOldBlockEnableWidgets[i]);
        theOldBlockEnableWidgets[i]->setParent(ui->widget_Game);
        theOldBlockEnableWidgets[i]->show();
        theOldBlockEnableWidgets[i]->setStyleSheet(tempStyleSheet);
    }
    delete theOldBlock;
}

QList<QRect> GameWindow::GetStaticBlocksRects()
{
    QList<QRect> theStaticBlocksRects;
    int count = m_static_blocks.count();
    for(int i = 0;i<count;i++)
    {
        QRect tempstaticBlockRect = m_static_blocks[i]->geometry();
        tempstaticBlockRect.setWidth(m_static_blocks[i]->width());
        tempstaticBlockRect.setHeight(m_static_blocks[i]->height());
        theStaticBlocksRects.append(tempstaticBlockRect);
    }
    return theStaticBlocksRects;
}

void GameWindow::ProduceNewBlock(int theBlockType)
{
    FatherBlock *theNewBlock;
    switch (theBlockType)
    {
    case 0:
    {
        theNewBlock = new LBlock(ui->widget_Game);
        break;
    }
    case 1:
    {
        theNewBlock = new OBlock(ui->widget_Game);
        break;
    }
    case 2:
    {
        theNewBlock = new IBlock(ui->widget_Game);
        break;
    }
    case 3:
    {
        theNewBlock = new RLBlock(ui->widget_Game);
        break;
    }
    case 4:
    {
        theNewBlock = new ZBlock(ui->widget_Game);
        break;
    }
    case 5:
    {
        theNewBlock = new SBlock(ui->widget_Game);
        break;
    }
    case 6:
    {
        theNewBlock = new TBlock(ui->widget_Game);
        break;
    }
    default:
    {
        theNewBlock = new LBlock(ui->widget_Game);
        break;
    }
    }
    QObject::connect(this,SIGNAL(RotateNextSignal()),theNewBlock,SLOT(RotateNextSlot()));
    QObject::connect(this,SIGNAL(MoveDownSignal(int)),theNewBlock,SLOT(MoveDownSlot(int)));
    QObject::connect(this,SIGNAL(MoveLeftSignal(int)),theNewBlock,SLOT(MoveLeftSlot(int)));
    QObject::connect(this,SIGNAL(MoveRightSignal(int)),theNewBlock,SLOT(MoveRightSlot(int)));
    QObject::connect(this,SIGNAL(MoveUpSignal(int)),theNewBlock,SLOT(MoveUpSlot(int)));
    m_currentFatherBlock = theNewBlock;
    theNewBlock->show();
    theNewBlock->RotateNext();
}

void GameWindow::GameWindowGuiSetting(int thewidth, int theheight)
{
    ui->widget_Game->setMaximumHeight(theheight);
    ui->widget_Game->setMinimumHeight(theheight);

    ui->widget_Game->setMaximumWidth(thewidth);
    ui->widget_Game->setMinimumWidth(thewidth);
}

void GameWindow::judgeRotateNext()
{
    if(m_currentFatherBlock != NULL)
    {
       QList<QRect> tempEnableBlocks = m_currentFatherBlock->GetEnableBlockRects(m_currentFatherBlock->GetNextStatusIndex());
        if(RussiaBlockController::isBlocksInWindow(tempEnableBlocks,QRect(ui->widget_Game->rect()),0,0))
        {
            if(!RussiaBlockController::isBlocksInsert(m_currentFatherBlock->GetEnableBlockRects(m_currentFatherBlock->GetNextStatusIndex(),true),GetStaticBlocksRects(),0,0))
            {
            emit this->RotateNextSignal();
            }
        }
    }
}

void GameWindow::judgeMoveUp()
{
    if(m_currentFatherBlock != NULL)
    {
        QList<QRect> tempEnableBlocks = m_currentFatherBlock->GetEnableBlockRects();
        if(RussiaBlockController::isBlocksInWindow(tempEnableBlocks,QRect(ui->widget_Game->rect()),0,-poslenth))
        {
            if(!RussiaBlockController::isBlocksInsert(m_currentFatherBlock->GetEnableBlockRects(-1,true),GetStaticBlocksRects(),0,-poslenth))
            {
                emit this->MoveUpSignal(poslenth);
            }
        }
    }
}

void GameWindow::judgeMoveDown()
{
    if(m_currentFatherBlock != NULL)
    {
        QList<QRect> tempEnableBlocks = m_currentFatherBlock->GetEnableBlockRects();
        if(RussiaBlockController::isBlocksInWindow(tempEnableBlocks,QRect(ui->widget_Game->rect()),0,poslenth))
        {
            if(!RussiaBlockController::isBlocksInsert(m_currentFatherBlock->GetEnableBlockRects(-1,true),GetStaticBlocksRects(),0,poslenth))
            {
                emit this->MoveDownSignal(poslenth);
            }else
            {
                CatchOldBlock(m_currentFatherBlock);
                CheckStaticBlocks();
                emit CurrentClearBlocksSignal(GetMarkAndClearBlock(m_static_blocks,10));
                if(ui->widget_Game->height() > GetBlocksHight(m_static_blocks))
                {

                    ProduceNewBlock(GetRandType());
                }else
                {
                    this->GameOver();
                }
            }
        }else
        {
            CatchOldBlock(m_currentFatherBlock);
            CheckStaticBlocks();
            emit CurrentClearBlocksSignal(GetMarkAndClearBlock(m_static_blocks,10));
            if(ui->widget_Game->height() > GetBlocksHight(m_static_blocks))
            {
                ProduceNewBlock(GetRandType());
            }else
            {
                this->GameOver();
            }
        }
    }
}

void GameWindow::judgeMoveLeft()
{
    if(m_currentFatherBlock != NULL)
    {
        if(RussiaBlockController::isBlocksInWindow(m_currentFatherBlock->GetEnableBlockRects(),QRect(ui->widget_Game->rect()),-poslenth,0))
        {
            if(!RussiaBlockController::isBlocksInsert(m_currentFatherBlock->GetEnableBlockRects(-1,true),GetStaticBlocksRects(),-poslenth,0))
            {
                emit this->MoveLeftSignal(poslenth);
            }
        }
    }
}

void GameWindow::judgeMoveRight()
{
    if(m_currentFatherBlock != NULL)
    {
        QList<QRect> tempEnableBlocks = m_currentFatherBlock->GetEnableBlockRects();
        if(RussiaBlockController::isBlocksInWindow(tempEnableBlocks,QRect(ui->widget_Game->rect()),poslenth,0))
        {
            if(!RussiaBlockController::isBlocksInsert(m_currentFatherBlock->GetEnableBlockRects(-1,true),GetStaticBlocksRects(),poslenth,0))
            {
                emit this->MoveRightSignal(poslenth);
            }
        }
    }
}

void GameWindow::CheckStaticBlocks()
{
    int count = m_static_blocks.count();
    for(int i =0;i<count;i++)
    {
        //qDebug()<<"X"<<m_static_blocks[i]->x() << "Y:" <<m_static_blocks[i]->y()<<i;
    }
}

int GameWindow::GetMarkAndClearBlock(QList<QWidget *> &theBlockWidgets, int theColumnCount)
{
    if(theBlockWidgets.count() == 0)
    {
        return -1;
    }
    int theClearCount = 0;
    int theBeginindex = 0;
    int theheight = theBlockWidgets[0]->height();
    while((theBeginindex != theBlockWidgets.count()-1) && (theBlockWidgets.count() != 0))
    {
        int tempy = theBlockWidgets[theBeginindex]->y();
        bool theclearFlag = true;
        for(int i = theBeginindex;i < theBeginindex+theColumnCount;i++)
        {
            if(i >= theBlockWidgets.count())
            {
                theBeginindex = theBlockWidgets.count()-1;
                theclearFlag = false;
                break;
            }
            if((theBlockWidgets[i]->y() != tempy))
            {
                theBeginindex = i;
                theclearFlag = false;
                break;
            }
        }
        if(theclearFlag)
        {
            QList<QWidget*>theClearBlocks;
            for(int i = 0;i<theColumnCount;i++)
            {
                QWidget *temp = theBlockWidgets[theBeginindex];
                theBlockWidgets.removeAt(theBeginindex);
                theClearBlocks.append(temp);
                theClearCount++;
            }
            RussiaBlockController::ProcessClearBlocks(theClearBlocks);
            for(int i = theBeginindex;i<theBlockWidgets.count();i++)
            {
                theBlockWidgets[i]->setGeometry(theBlockWidgets[i]->x(),theBlockWidgets[i]->y()+theheight,theBlockWidgets[i]->width(),theBlockWidgets[i]->height());
            }
        }
    }
    return theClearCount;
}

void GameWindow::CathchMoveDownGameThread()
{
    judgeMoveDown();
}



void GameWindow::on_pushButton_stop_clicked()
{
    m_GameThread.quit();
    m_GameThread.SetRunFlag(false);
}

int GameWindow::GetBlocksHight(QList<QWidget *> &theBlockWidgets)
{
    int  TheResult = 0;
    int tempBlockY = 0;
    int count = theBlockWidgets.count();
    for(int  i = 0;i < count;i++)
    {
        if(tempBlockY != theBlockWidgets[i]->y())
        {
            tempBlockY = theBlockWidgets[i]->y();
            TheResult += theBlockWidgets[i]->height();
        }
    }
    return TheResult;
}

void GameWindow::GameOver()
{
    m_GameThread.quit();
    m_GameThread.SetRunFlag(false);
    GameRecordAddForm newRecord(RussiaBlockController::GetResult(m_AllClearBlocks));
    newRecord.setWindowTitle("Game Over!");
    newRecord.exec();
    m_GameRankForm.AddNewGameRecord(newRecord.GetUserName(),m_AllClearBlocks);
    m_GameRankForm.RefreshRankList();
    m_GameRankForm.setWindowTitle("Ranking");
    m_GameRankForm.exec();
     ReStartGame();
}

void GameWindow::SetRandSeed()
{
    QTime t;
    t = QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
}

void GameWindow::CurrentClearBlocksSlot(int thecount)
{
    m_AllClearBlocks += thecount;
    int tempwaittime = m_GameThread.GetWaitTime();
    if(tempwaittime > 50)
    {
        m_GameThread.SetWaitTime(tempwaittime - thecount*2);
    }
    ui->label_mark->setText(QString("得分：%1").arg(m_AllClearBlocks));
}

void GameWindow::ReStartGame()
{
    while(!m_static_blocks.isEmpty())
    {
        delete m_static_blocks.takeFirst();
    }
    m_AllClearBlocks = 0;
    m_GameThread.SetWaitTime(200);
     ui->label_mark->setText(QString("得分：0"));
}

int GameWindow::GetRandType()
{
    SetRandSeed();
    int theType =qrand() % 7;
    return theType;
}
