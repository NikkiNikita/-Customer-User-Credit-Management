#ifndef BWIDGET_H
#define BWIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include "FileOperation.h"
#include "SinglyLinkedList.h"

class Client: public QWidget
{
    Q_OBJECT
public :
    Client(string name,QWidget *parent=0);
    ~Client();
   /* bool IsLeap(int year);
    bool StringToDate(QString date ,int& year, int& month, int& day);
    int DayInYear(int year, int month, int day);
    int DaysBetween2Date(QString date1, QString date2);
    void swap(int a,int b);*/
private:
FileOperation file;
SinglyLinkedList A;
string Name;
QLabel *userNameLabel;
QLabel *passWordLabel;
QLabel *sexLbel;
QLabel *DateLabel;
QLabel *userNameLineEdit;
QLabel *passWordLineEdit;
QLabel *sexComboxBOX;
QLabel *DateDateEdit;
QPushButton *login;
QPushButton *login_1;
QPushButton *login_2;
QPushButton *login_3;
private slots:
void slotLogin();
void slotLogin_1();
void slotLogin_2();
void slotLogin_3();
};
#endif // BWIDGET_H
