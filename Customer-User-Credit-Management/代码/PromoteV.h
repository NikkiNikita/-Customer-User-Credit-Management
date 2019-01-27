#ifndef PROMOTEV_H
#define PROMOTEV_H
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include "SinglyLinkedList.h"
#include "FileOperation.h"
class PrommoteV : public QWidget
{
    Q_OBJECT
public :
    void ReturnResult();
    PrommoteV(string name,QWidget *parent=0);
    ~PrommoteV();
private:
string Name;
int index;
FileOperation FILE1;
SinglyLinkedList A;
QLabel *chongzhi;
QLabel *passWordLabel;
QLineEdit *chongzhi1;
QLineEdit *passWordLineEdit;
QPushButton *login;
QPushButton *login_1;
private slots:
void slotLogin();
void slotLogin_1();
};
#endif // PROMOTEV_H
