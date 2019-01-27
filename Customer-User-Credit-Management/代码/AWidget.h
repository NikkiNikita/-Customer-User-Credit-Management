#ifndef AWIDGET_H
#define AWIDGET_H

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include "SinglyLinkedList.h"
#include "FileOperation.h"
class AWidget : public QWidget
{
    Q_OBJECT
public :
    AWidget(QWidget *parent=0);
    ~AWidget();
    void ReturnResult();
   /* bool IsLeap(int year);
    bool StringToDate(QString date ,int& year, int& month, int& day);
    int DayInYear(int year, int month, int day);
    int DaysBetween2Date(QString date1, QString date2);
    void swap(int a,int b);*/
private:
int index;
FileOperation FILE1;
SinglyLinkedList A;
QLabel *userNameLabel;
QLabel *passWordLabel;
QLabel *sexLbel;
QLabel *DateLabel;
QLabel *EmailLabel;
QLineEdit *userNameLineEdit;
QLineEdit *passWordLineEdit;
QComboBox *sexComboxBOX;
QDateEdit *DateDateEdit;
QLineEdit *EmailLineEdit;
QPushButton *login;
QPushButton *login_1;
private slots:
void slotLogin();
void slotLogin_1();
};
#endif // AWIDGET_H
