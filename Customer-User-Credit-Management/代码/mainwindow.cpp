/*登录界面实现*/
#include "mainwindow.h"
#include<QMessageBox>
#include <QGridLayout>
#include<QHBoxLayout>
#include <sstream>
#include<QDebug>
#include "AWidget.h"
#include <iostream>
#include "BWidget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setWindowTitle(tr("客户登录"));

    userNameLabel = new QLabel("用户名:");
    passWordLabel = new QLabel("密码:");

    userNameLineEdit = new QLineEdit;
    passWordLineEdit = new QLineEdit;
    passWordLineEdit->setEchoMode(QLineEdit::Password);


    login = new QPushButton(tr("登录"));
    login_1=new QPushButton(tr("注册"));


    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(userNameLabel,0,0);
    mainLayout->addWidget(passWordLabel,1,0);
    mainLayout->addWidget( userNameLineEdit,0,1);
    mainLayout->addWidget( passWordLineEdit,1,1);


    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    mainLayout->addLayout(hBoxLayout,2,0,1,2);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(login);
    hBoxLayout->addWidget(login_1);
    connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
    connect (passWordLineEdit,SIGNAL(returnPressed()),this,SLOT(slotLogin()));

    connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
}
Widget::~Widget(){}
void Widget::slotLogin(){
     if (userNameLineEdit->text()!=""&&passWordLineEdit->text()!=""){
        A=FILE1.ReturnCon(A);
     if(A.getNode(userNameLineEdit->text().toStdString(),passWordLineEdit->text().toStdString()))
    {
          qDebug() << "登录成功！";
          QMessageBox::information(this,tr("登录提示"),tr("登录成功"));
          this->hide();
          Client *C = new Client(userNameLineEdit->text().toStdString());
          C->show();
     }
     else
     {
          qDebug() << "用户名或密码错误！";
          QMessageBox::information(this,tr("登录提示"),tr("用户名或密码错误！"));
     }
     }
     else
     {
         QMessageBox::information(this,tr("登录提示"),tr("请输入用户名和密码！"));
     }
}
void Widget::slotLogin_1(){
    AWidget *w_1;
    w_1 = new AWidget();
    w_1->show();
}
