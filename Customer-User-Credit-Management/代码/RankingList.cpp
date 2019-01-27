#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include<QMessageBox>
#include <QGridLayout>
#include<QHBoxLayout>
#include<QDebug>
#include <QDateTime>
#include <QTime>
#include "RankingList.h"
RankingList::RankingList(string name,QWidget *parent)
    : QWidget(parent){
    this->Name = name;
    A=FILE1.ReturnCon(A);
    A.sort();
index=0;
setWindowTitle(tr("查看排行"));

dengji = new QLabel("消费等级");
dazhe = new QLabel("享受优惠度(%)");
name1 = new QLabel("输入用户名");
name11 =new QLineEdit;
dengji1 = new QLabel("");
dazhe1  =new QLabel("");
paiming = new QLabel("排名");
paiming1 = new QLabel("");

login = new QPushButton(tr("查询"));
login_1=new QPushButton(tr("取消"));


QGridLayout *mainLayout = new QGridLayout(this);
mainLayout->addWidget(name1,0,0);
mainLayout->addWidget(dengji,1,0);
mainLayout->addWidget(dazhe,2,0);
mainLayout->addWidget( name11,0,1);
mainLayout->addWidget( dengji1,1,1);
mainLayout->addWidget( dazhe1 ,2,1);
mainLayout->addWidget( paiming,3,0);
mainLayout->addWidget( paiming1 ,3,1);


QHBoxLayout *hBoxLayout = new QHBoxLayout;
mainLayout->addLayout(hBoxLayout,5,0,2.5,5);
hBoxLayout->addStretch();
hBoxLayout->addWidget(login);
hBoxLayout->addWidget(login_1);

connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
}


void RankingList::slotLogin(){
    Node *p =A.head;
    int i=0;
    while(p!=NULL){
        i++;
        if(p->ConName==name11->text().toStdString())
            break;
        p=p->next;
    }
    if(p==NULL){
        QMessageBox::information(this,tr("提示"),tr("此用户不存在！"));
    }else{
    dengji1->setText(QString::fromStdString(p->ConEvalueate));
    dazhe1->setText(QString::number(p->Discount));
    paiming1->setText(QString::number(i));
    }
}

void RankingList::slotLogin_1(){
          this->hide();
}


