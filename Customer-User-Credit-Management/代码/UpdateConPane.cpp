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
#include "UpdateConPane.h"
UpdateCon::UpdateCon(string name,QWidget *parent)
    : QWidget(parent){
    this->Name = name;
index=0;
setWindowTitle(tr("修改信息"));

userNameLabel = new QLabel("用户名:");
passWordLabel = new QLabel("密码:");
EmailLabel = new QLabel("联系邮箱:");

userNameLineEdit = new QLineEdit;
passWordLineEdit = new QLineEdit;
EmailLineEdit = new QLineEdit;
passWordLineEdit->setEchoMode(QLineEdit::Password);


login = new QPushButton(tr("确定"));
login_1=new QPushButton(tr("取消"));


QGridLayout *mainLayout = new QGridLayout(this);
mainLayout->addWidget(userNameLabel,0,0);
mainLayout->addWidget(passWordLabel,1,0);
mainLayout->addWidget(EmailLabel,2,0);
mainLayout->addWidget( userNameLineEdit,0,1);
mainLayout->addWidget( passWordLineEdit,1,1);
mainLayout->addWidget( EmailLineEdit ,2,1);


QHBoxLayout *hBoxLayout = new QHBoxLayout;
mainLayout->addLayout(hBoxLayout,5,0,2.5,5);
hBoxLayout->addStretch();
hBoxLayout->addWidget(login);
hBoxLayout->addWidget(login_1);

connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
}

UpdateCon::~UpdateCon(){}

void UpdateCon::slotLogin(){
    A = FILE1.ReturnCon(A);
        if(userNameLineEdit->text()!=""&&passWordLineEdit->text()!=""&&EmailLineEdit->text()!=""){
        if(A.getNode(userNameLineEdit->text().toStdString())&&userNameLineEdit->text().toStdString()!=Name){
            qDebug() << "重复的用户名";
            QMessageBox::information(this,tr("修改提示"),tr("用户名已经存在！"));
        }else{
          A.update(Name,userNameLineEdit->text().toStdString(),passWordLineEdit->text().toStdString(),EmailLineEdit->text().toStdString());
          QMessageBox::information(this,tr("修改提示"),tr("修改成功"));
          FILE1.deleteFile();
          FILE1.UpdateFile(A,A.RenNum(0));
          this->hide();
        }
        }else{
            QMessageBox::information(this,tr("修改提示"),tr("请输入完整信息,不修改则输入原来的信息！"));
        }
}

void UpdateCon::slotLogin_1(){
          this->hide();
}


