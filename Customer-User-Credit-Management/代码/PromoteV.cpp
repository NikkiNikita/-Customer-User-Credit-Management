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
#include "PromoteV.h"
#include <sstream>
PrommoteV::PrommoteV(string name,QWidget *parent)
    : QWidget(parent){
    this->Name = name;
index=0;
setWindowTitle(tr("请适度消费"));

chongzhi = new QLabel("输入充值额度:");
passWordLabel = new QLabel("密码确认:");

chongzhi1 = new QLineEdit;
passWordLineEdit = new QLineEdit;
passWordLineEdit->setEchoMode(QLineEdit::Password);


login = new QPushButton(tr("确定"));
login_1=new QPushButton(tr("取消"));


QGridLayout *mainLayout = new QGridLayout(this);
mainLayout->addWidget(chongzhi,0,0);
mainLayout->addWidget(passWordLabel,1,0);
mainLayout->addWidget( chongzhi1,0,1);
mainLayout->addWidget( passWordLineEdit,1,1);


QHBoxLayout *hBoxLayout = new QHBoxLayout;
mainLayout->addLayout(hBoxLayout,5,0,2.5,5);
hBoxLayout->addStretch();
hBoxLayout->addWidget(login);
hBoxLayout->addWidget(login_1);

connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
}

PrommoteV::~PrommoteV(){}

void PrommoteV::slotLogin(){

    /***
      *判断一个字符串是否为纯数字
      */
        QByteArray ba = chongzhi1->text().toLatin1();//QString 转换为 char*
         const char *s = ba.data();

        while(*s && *s>='0' && *s<='9') s++;

        if (*s)
        { //不是纯数字
            QMessageBox::information(this,tr("充值提示"),tr("请输入正确的金额！"));
        }
        else
        { //纯数字

            A= FILE1.ReturnCon(A);
            if(A.getNode(Name,passWordLineEdit->text().toStdString())){
            string str=chongzhi1->text().toStdString();
            stringstream strStream;
            strStream<<str;
            int val;
            strStream>>val;
            A.promote(Name,val);
            FILE1.deleteFile();
            FILE1.UpdateFile(A,A.RenNum(0));
            QMessageBox::information(this,tr("充值提示"),tr("充值成功！"));
            this->hide();
            }else{
                QMessageBox::information(this,tr("充值提示"),tr("请输入正确的密码！"));
            }
        }


}

void PrommoteV::slotLogin_1(){
          this->hide();
}
