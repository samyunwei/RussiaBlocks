#include <QApplication>
#include <QTextCodec>
#include <QObject>

#include "GameWindow.h"
#include "FatherBlock.h"
#include "GameRankingList.h"
#include "GameRankForm.h"
void SetCodec()
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
}

//测试兼主函数
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetCodec();
    qDebug()<<QCoreApplication::applicationDirPath();
    //单元测试方框父类

//    FatherBlock testFatherBlock;
//    testFatherBlock.InitBlocksList();
//    testFatherBlock.show();
//       QBitArray newstatus(16);
//       newstatus.setBit(0,true);
//       newstatus.setBit(1,true);
//       newstatus.setBit(5,true);
//       newstatus.setBit(6,true);
//       qDebug()<<testFatherBlock.addStatus(newstatus);

//       QBitArray newstatus1(16);
//       newstatus1.setBit(1,true);
//       newstatus1.setBit(4,true);
//       newstatus1.setBit(5,true);
//       newstatus1.setBit(8,true);
//       qDebug()<<testFatherBlock.addStatus(newstatus1);


    //单元测试游戏窗体
    GameWindow w;
    w.show();

 // TestUnit for Ranking
//    GameRankingList TestGame;
    //TestItem
//    GameRankingItem newItem("testgame","testUser",100);
//    GameRankingItem newItem2(newItem);
//    qDebug()<<newItem.GetItemstr()<<"Item1";
//    qDebug()<<newItem2.GetItemstr()<<"Item2";
    //TestList
//    for(int i = 0;i<100;i++)
//    {
//        TestGame.AddGameRecord("TestUser",i);
//    }
//    qDebug()<<TestGame.SaveAsFile("TestRecord.txt");
//    TestGame.InitWithFile("TestRecord.txt");
//    QList<GameRankingItem> theList = TestGame.GetItemsList();
//    for(int i = 0;i<theList.count();i++)
//    {
//        qDebug()<<theList[i].GetItemstr();
//    }

 // TestForRankingForm
//    GameRankForm theTestForm;
//    for(int i = 0;i<100;i++)
//    {
//        theTestForm.AddNewGameRecord("TestUser",i);
//    }
//    theTestForm.RefreshRankList();
//    theTestForm.show();



    return a.exec();
}
