/*成功登陆后界面实现*/
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QComboBox>
#include <QDateEdit>
#include "BWidget.h"
#include "mainwindow.h"
#include<QMessageBox>
#include <QGridLayout>
#include<QHBoxLayout>
#include <sstream>
#include<QDebug>
#include <iostream>
#include "FileOperation.h"
#include "SinglyLinkedList.h"
#include "UpdateConPane.h"
#include "PromoteV.h"
#include "RankingList.h"
#include <QTableWidget>
#include <QHeaderView>
Client:: Client(string name,QWidget *parent)
        : QWidget(parent)
{

         this->Name=name;

         this->setAutoFillBackground(true);
         QPalette palette;
         QPixmap pixmap("haha.jpg");
         palette.setBrush(QPalette::Window, QBrush(pixmap));
         this->setPalette(palette);

    setWindowTitle(tr("您的消费信息"));




    userNameLabel = new QLabel("消费次数:");
    userNameLabel->setFont(QFont("消费次数:",10,QFont::Bold));
    passWordLabel = new QLabel("号龄:");
    passWordLabel->setFont(QFont("号龄:",10,QFont::Bold));
    sexLbel = new QLabel("您的V等级:");
    sexLbel->setFont(QFont("您的V等级:",10,QFont::Bold));
    DateLabel = new QLabel("享受优惠:");
    DateLabel->setFont(QFont("享受优惠:",10,QFont::Bold));


    A=file.ReturnCon(A);
    Node *p =A.BackOneMessage(Name);
    userNameLineEdit = new QLabel(QString::fromStdString(p->ConAmount));
    userNameLineEdit->setFont(QFont(QString::fromStdString(p->ConAmount),10,QFont::Bold));
    passWordLineEdit = new QLabel(QString::fromStdString(p->ConconAge));
    passWordLineEdit->setFont(QFont(QString::fromStdString(p->ConconAge)));
    sexComboxBOX = new QLabel(QString::fromStdString(p->ConEvalueate));
    sexComboxBOX->setFont(QFont(QString::fromStdString(p->ConEvalueate)));
    DateDateEdit = new QLabel(QString::number(p->Discount));
    DateDateEdit->setFont(QString::number(p->Discount));



    login = new QPushButton(tr("修改我的信息"));
    login_1=new QPushButton(tr("查看排行"));
    login_2=new QPushButton(tr("提升V等级"));
    login_3= new QPushButton(tr("不再使用"));


    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(userNameLabel,0,0);
    mainLayout->addWidget(passWordLabel,1,0);
    mainLayout->addWidget(sexLbel,2,0);
    mainLayout->addWidget(DateLabel,3,0);
    mainLayout->addWidget( userNameLineEdit,0,1);
    mainLayout->addWidget( passWordLineEdit,1,1);
    mainLayout->addWidget( sexComboxBOX,2,1);
    mainLayout->addWidget( DateDateEdit,3,1);




    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    mainLayout->addLayout(hBoxLayout,5,0,2.5,5);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(login);
    hBoxLayout->addWidget(login_1);
    hBoxLayout->addWidget(login_2);
    hBoxLayout->addWidget(login_3);

    connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
    connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
    connect (login_2,SIGNAL(clicked()),this,SLOT(slotLogin_2()));
    connect (login_3,SIGNAL(clicked()),this,SLOT(slotLogin_3()));
}


Client::~Client(){}

void Client::slotLogin(){
  UpdateCon *UC = new UpdateCon(Name);
  UC->show();

}

void Client::slotLogin_1(){
    RankingList *w1= new RankingList(Name);
    w1->show();

}
void Client::slotLogin_2(){
   PrommoteV *w= new PrommoteV(Name);
   w->show();

}

void Client::slotLogin_3(){
   Node *p = A.head;
   int i=0;
   while(p!=NULL){
       if(p->ConName==Name)
           break;
       else{
       p=p->next;
       i++;
       }
   }
   A.remove(A,i);
   file.deleteFile();
   file.UpdateFile(A,A.RenNum(0));
   QMessageBox::information(this,tr("提示"),tr("感谢您的使用！"));
   this->hide();
}
