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
class UpdateCon : public QWidget
{
    Q_OBJECT
public :
    void ReturnResult();
    UpdateCon(string name,QWidget *parent=0);
    ~UpdateCon();
private:
string Name;
int index;
FileOperation FILE1;
SinglyLinkedList A;
QLabel *userNameLabel;
QLabel *passWordLabel;
QLabel *EmailLabel;
QLineEdit *userNameLineEdit;
QLineEdit *passWordLineEdit;
QLineEdit *EmailLineEdit;
QPushButton *login;
QPushButton *login_1;
private slots:
void slotLogin();
void slotLogin_1();
};
#endif // AWIDGET_H
