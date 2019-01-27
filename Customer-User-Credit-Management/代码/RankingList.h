#ifndef RANKINGLIST_H
#define RANKINGLIST_H
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include "SinglyLinkedList.h"
#include "FileOperation.h"
#include "RankingList.h"
class RankingList : public QWidget
{
    Q_OBJECT
public :
    RankingList(string name,QWidget *parent=0);
    ~RankingList() {}
private:
string Name;
int index;
FileOperation FILE1;
SinglyLinkedList A;
QLabel *dengji;
QLabel *dazhe;
QLabel *name1;
QLineEdit *name11;
QLabel *dengji1;
QLabel *dazhe1;
QLabel *paiming;
QLabel *paiming1;
QPushButton *login;
QPushButton *login_1;
private slots:
void slotLogin();
void slotLogin_1();
};
#endif // RANKINGLIST_H
