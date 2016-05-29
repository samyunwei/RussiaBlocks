#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T17:00:39
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = RussiaBlocks
TEMPLATE = app


SOURCES += main.cpp\
        GameWindow.cpp \
    FatherBlock.cpp \
    RussiaBlockController.cpp \
    BlockRow.cpp \
    GameThread.cpp \
    ZBlock.cpp \
    TBlock.cpp \
    LBlock.cpp \
    OBlock.cpp \
    SBlock.cpp \
    IBlock.cpp \
    RLBlock.cpp \
    ranking/GameRankingList.cpp \
    ranking/GameRankingItem.cpp

HEADERS  += GameWindow.h \
    FatherBlock.h \
    RussiaBlockController.h \
    BlockRow.h \
    GameThread.h \
    ZBlock.h \
    TBlock.h \
    LBlock.h \
    OBlock.h \
    SBlock.h \
    IBlock.h \
    RLBlock.h \
    ranking/GameRankingList.h \
    ranking/GameRankingItem.h

FORMS    += GameWindow.ui \
    FatherBlock.ui

INCLUDEPATH += ranking \


DESTDIR = ../bin/

OBJECTS_DIR = ../Builds/BuildRussiaBlocks
MOC_DIR = ../Builds/BuildRussiaBlocks
RCC_DIR = ../Builds/BuildRussiaBlocks
UI_DIR = ../Builds/BuildRussiaBlocks
UI_HEADERS_DIR = ../Builds/BuildRussiaBlocks
UI_SOURCES_DIR = ../Builds/BuildRussiaBlocks
