#-------------------------------------------------
#
# Project created by QtCreator 2018-01-09T16:49:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WZN
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AWidget.cpp \
    SinglyLinkedList.cpp \
    FileOperation.cpp \
    BWidget.cpp \
    UpdateConPane.cpp \
    PromoteV.cpp \
    RankingList.cpp

HEADERS  += mainwindow.h \
    AWidget.h \
    Node.h \
    SinglyLinkedList.h \
    FileOperation.h \
    BWidget.h \
    UpdateConPane.h \
    RankingList.h \
    PromoteV.h

FORMS    += mainwindow.ui
