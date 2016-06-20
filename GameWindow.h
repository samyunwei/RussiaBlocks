#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <algorithm>
#include <QTime>
#include <QMessageBox>

#include "ZBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "IBlock.h"
#include "RLBlock.h"

#include "RussiaBlockController.h"
#include "GameThread.h"
#include "GameRankForm.h"
#include "GameRecordAddForm.h"
namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void CatchOldBlock(FatherBlock *theOldBlock);
     QList<QRect> GetStaticBlocksRects();
     void ProduceNewBlock(int theBlockType = 0);
     void GameWindowGuiSetting(int thewidth,int theheight);
     int GetMarkAndClearBlock(QList<QWidget*> &theBlockWidgets,int theColumnCount);
     int GetBlocksHight(QList<QWidget*> &theBlockWidgets);
     void CheckStaticBlocks();
     void GameOver();
     void SetRandSeed();
     void ReStartGame();
     int GetRandType();
private slots:
    void on_pushButton_Rotate_clicked();
    void on_pushButton_moveUp_clicked();
    void on_pushButton_moveLeft_clicked();
    void on_pushButton_moveRight_clicked();
    void on_pushButton_moveDown_clicked();
    void on_pushButton_produce_clicked();
    void on_pushButton_stop_clicked();

    void CurrentClearBlocksSlot(int thecount);
public slots:
    void CathchMoveDownGameThread();


protected:
    void	keyPressEvent ( QKeyEvent * event );
signals:
    void RotateNextSignal(); //发射变形信号
    void MoveUpSignal(int they); //位移量均为正
    void MoveDownSignal(int they);
    void MoveLeftSignal(int thex);
    void MoveRightSignal(int thex);
    void CurrentClearBlocksSignal(int thecount);
private:
    void judgeRotateNext();
    void judgeMoveUp();
    void judgeMoveDown();
    void judgeMoveLeft();
    void judgeMoveRight();
    int poslenth;
    int movepath;
    Ui::GameWindow *ui;
    QList<QWidget*>m_static_blocks;
    FatherBlock* m_currentFatherBlock;
    GameThread m_GameThread;
    GameRankForm m_GameRankForm;
    int m_AllClearBlocks;
};

#endif // GAMEWINDOW_H
