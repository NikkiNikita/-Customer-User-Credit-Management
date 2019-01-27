/*注册界面实现*/
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
#include "AWidget.h"
AWidget::AWidget(QWidget *parent)
    : QWidget(parent){
index=0;
setWindowTitle(tr("注册"));

userNameLabel = new QLabel("用户名:");
passWordLabel = new QLabel("密码:");
sexLbel = new QLabel("性别:");
DateLabel = new QLabel("出生年月:");
EmailLabel = new QLabel("联系邮箱:");

userNameLineEdit = new QLineEdit;
passWordLineEdit = new QLineEdit;
sexComboxBOX = new QComboBox();
sexComboxBOX->addItem(QWidget::tr("male"));
sexComboxBOX->addItem(QWidget::tr("female"));
DateDateEdit = new QDateEdit;
EmailLineEdit = new QLineEdit;
passWordLineEdit->setEchoMode(QLineEdit::Password);


login = new QPushButton(tr("确定"));
login_1=new QPushButton(tr("取消"));


QGridLayout *mainLayout = new QGridLayout(this);
mainLayout->addWidget(userNameLabel,0,0);
mainLayout->addWidget(passWordLabel,1,0);
mainLayout->addWidget(sexLbel,2,0);
mainLayout->addWidget(DateLabel,3,0);
mainLayout->addWidget(EmailLabel,4,0);
mainLayout->addWidget( userNameLineEdit,0,1);
mainLayout->addWidget( passWordLineEdit,1,1);
mainLayout->addWidget( sexComboxBOX,2,1);
mainLayout->addWidget( DateDateEdit,3,1);
mainLayout->addWidget( EmailLineEdit ,4,1);


QHBoxLayout *hBoxLayout = new QHBoxLayout;
mainLayout->addLayout(hBoxLayout,5,0,2.5,5);
hBoxLayout->addStretch();
hBoxLayout->addWidget(login);
hBoxLayout->addWidget(login_1);

connect (login,SIGNAL(clicked()),this,SLOT(slotLogin()));
connect (login_1,SIGNAL(clicked()),this,SLOT(slotLogin_1()));
}
AWidget::~AWidget(){}
void AWidget::slotLogin(){
    SinglyLinkedList B;
    B = FILE1.ReturnCon(B);
    if(userNameLineEdit->text()!=""&&passWordLineEdit->text()!=""&&EmailLineEdit->text()!=""){

        if(B.getNode(userNameLineEdit->text().toStdString())){
            qDebug() << "重复的用户名";
            QMessageBox::information(this,tr("注册提示"),tr("用户名已经存在！"));
        }else{
          ReturnResult();
          QMessageBox::information(this,tr("注册提示"),tr("注册成功"));
          FILE1.WriteFile(A);
          this->hide();
        }
    }else{
        qDebug() << "信息不全！";
        QMessageBox::information(this,tr("注册提示"),tr("请输入填写完相应信息！"));
    }
}

void AWidget::slotLogin_1(){
          this->hide();
}

void AWidget:: ReturnResult(){

    //QDateTime current_date_time = QDateTime::currentDateTime();
   // QString strBuffer;
   // strBuffer = current_date_time.toString("yyyy/MM/dd");
    //cout<<strBuffer.toStdString()<<endl;

   // QDateTime start = QDateTime::fromString(DateDateEdit->text(),"yyyy/MM/dd");
   // QDateTime end = QDateTime::fromString(strBuffer, "yyyy/MM/dd");

   // cout<<start.toString("yyyy/MM/dd").toStdString()<<endl;

    //uint stime = start.toTime_t();
    //uint etime = end.toTime_t();
    //int ndaysec = 24*60*60;
    //int k = (etime - stime)/(ndaysec) + ((etime - stime)%(ndaysec)+(ndaysec-1))/(ndaysec) - 1;
    //qDebug() << "Day = " << k;
    //int k = DaysBetween2Date(strBuffer,DateDateEdit->text());
    char *buffer = FILE1.OutputNumFile();
        string ConNo=buffer;
        string ConName= userNameLineEdit->text().toStdString();
        string ConPassword=passWordLineEdit->text().toStdString();
        string ConSex=sexComboxBOX->currentText().toStdString();
        string ConAge=DateDateEdit->text().toStdString();
        string ConEmail=EmailLineEdit->text().toStdString();
        string ConAmount ="0";
        string ConRank= "1000";
        string ConconAge="0";
        string ConEvalueate= "E";
        int Discount= 0;
    FILE1.InputNumFile();
    A.insert(ConNo, ConName, ConPassword , ConSex,
             ConAge , ConEmail , ConAmount ,
             ConRank , ConconAge , ConEvalueate , Discount,index++);
}
/*bool AWidget::IsLeap(int year){
    return (year % 4 ==0 || year % 400 ==0) && (year % 100 !=0);
}
bool AWidget::StringToDate(QString date ,int& year, int& month, int& day){
    year = date.mid(0,4).toInt();
    month = date.mid(4,2).toInt();
    day = date.mid(6,2).toInt();
    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeap(year)){
        DAY[1] = 29;
    }
    return year >= 0 && month<=12 && month>0 && day<=DAY[month-1] && day>0;
}
 int AWidget::DayInYear(int year, int month, int day){
     int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     if(IsLeap(year)){
         DAY[1] = 29;
     }
     for(int i=0; i<month - 1; ++i){
       day += DAY[i];
     }
     return day;
 }
 int AWidget::DaysBetween2Date(QString date1, QString date2){
     int year1, month1, day1;
     int year2, month2, day2;
     if(!StringToDate(date1, year1, month1, day1) || !StringToDate(date2, year2,month2,day2))
     {
         return -1;
     }
     if(year1 == year2 && month1 == month2)
     {
         return day1 > day2 ? day1 - day2 : day2 - day1;
     }else if(year1 == year2){
         int d1, d2;
         d1 = DayInYear(year1, month1, day1);
         d2 = DayInYear(year2, month2, day2);
         return d1 > d2 ? d1 - d2 : d2 - d1;
     }else{
         if(year1 > year2)
         {
             swap(year1, year2);
             swap(month1, month2);
             swap(day1, day2);
         }
         int d1,d2,d3;
         if(IsLeap(year1))
             d1 = 366 - DayInYear(year1,month1, day1);
         else
             d1 = 365 - DayInYear(year1,month1, day1);
         d2 = DayInYear(year2,month2,day2);
         d3 = 0;
         for(int year = year1 + 1; year < year2; year++){
             if(IsLeap(year))
                 d3 += 366;
             else
                 d3 += 365;
         }
         return d1 + d2 + d3;
     }
 }
 void AWidget::swap(int a,int b){
     a=a^b;
     b=a^b;
     a=a^b;
 }*/
