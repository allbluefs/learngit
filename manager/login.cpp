#include "login.h"
#include "ui_login.h"
#include "zhuce.h"
#include "mainwindow.h"
#include "admin.h"
#include "teacher.h"
#include "apassword.h"
#include "user.h"
#include <QString>
#include <QDebug>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QSqlRecord>
#include<QLineEdit>
#include <QButtonGroup>
QString sig=0;
QString sig2=0;
QString sig3=0;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    lineEdit_2=new QLineEdit(this);
    lineEdit_2->setGeometry(120,139,113,21);
    lineEdit_2->setEchoMode(QLineEdit::Password);//隐藏密码

    pButtonGroup=new QButtonGroup(this);
    pButtonGroup->addButton(ui->checkBox);
    pButtonGroup->addButton(ui->checkBox_2);
    pButtonGroup->addButton(ui->checkBox_3);//单选checkbox

}

login::~login()
{
    delete ui;
}

void login::on_btn2_clicked()
{
    zhuce *zhuc=new zhuce();
    zhuc->show();
    this->close();
}

void login::on_btn1_clicked()
{
    QSqlQuery up;
    int sign=0;
    QString login= ui->lineEdit->text();
    QString password = lineEdit_2->text();
    if(ui->checkBox->checkState()==Qt::Checked){

        up.prepare("select * from user where username=:username");
        QString str2=QString("%1").arg(login); //login替换%1
        up.bindValue(":username",str2);//
        up.exec();
        QSqlRecord rec=up.record();//用户

    while(up.next())
    {
    sign=1;
    rec=up.record();
    int spassword=rec.indexOf("password");
    QString value=up.value(spassword).toString();//用户

    if(value==password)
    {
    sig2=ui->lineEdit->text();
    qDebug()<<"denglu chenggong";
    QMessageBox::warning(this,tr("result"),tr("user login successful"));
    user *u=new user();
    u->show();
    this->close();
    }
    else
    {
    qDebug()<<"mima cuowu";
    QMessageBox::warning(this,tr("error"),tr("wrong password"));
    }//用户

    }

    if(sign==0)
    {
    QMessageBox::warning(this,tr("error"),tr("account does not exist"));
    }
}

   else if(ui->checkBox_2->checkState()==Qt::Checked){
       QSqlQuery te;
       te.prepare("select * from tea where tname=:tname");
       QString tea=QString("%1").arg(login);
       te.bindValue(":tname",tea);
       te.exec();
       QSqlRecord rec2=te.record();//教师

       while(te.next()){
           sign=1;
           rec2=te.record();
           int tpassword=rec2.indexOf("password");
           QString value2=te.value(tpassword).toString();

           if(value2==password){
               sig3=ui->lineEdit->text();
               qDebug()<<"login successful";
               QMessageBox::warning(this,tr("result"),tr("teacher login successful"));
               teacher *t=new teacher();
               t->show();
               this->close();
           }
           else{
               qDebug()<<"wrong password";
               QMessageBox::warning(this,tr("error"),tr("wrong password"));
           }
       }//教师
       if(sign==0)
       {
       QMessageBox::warning(this,tr("error"),tr("account does not exist"));
       }

   }//教师


   else if(ui->checkBox_3->checkState()==Qt::Checked){
       QSqlQuery ad;
       ad.prepare("select * from admin where adminname=:adminname");
       QString adm=QString("%1").arg(login);
       ad.bindValue(":adminname",adm);
       ad.exec();
       QSqlRecord rec1=ad.record();//管理员

       while(ad.next())
       {
           sign=1;
           rec1=ad.record();
           int apassword=rec1.indexOf("password");
           QString value1=ad.value(apassword).toString();//管理员

           if(value1==password)
           {
               sig=ui->lineEdit->text();
               qDebug()<<"administrator login successful";
               QMessageBox::warning(this,tr("result"),tr("administrator login successful"));//管理员
               admin *a=new admin();
               a->show();
               this->close();
           }
           else{
               qDebug()<<"wrong password";
               QMessageBox::warning(this,tr("error"),tr("wrong password"));
           }
       }
       if(sign==0)
       {
       QMessageBox::warning(this,tr("error"),tr("account does not exist"));
       }
   }//管理员
   else{
       QMessageBox::warning(this,tr("error"),tr("select the login object"));
   }

}
