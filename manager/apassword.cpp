#include "apassword.h"
#include "ui_apassword.h"
#include "login.h"
#include <QString>
#include<QMessageBox>
#include<QSqlQuery>
#include "admin.h"
#include "user.h"
#include "teacher.h"

extern QString sig;
extern QString sig2;
extern QString sig3;

apassword::apassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apassword)
{
    ui->setupUi(this);
}

apassword::~apassword()
{
    delete ui;
}

void apassword::on_pushButton_clicked()
{
    QString newpass=ui->lineEdit_6->text();
    QString newpass1=ui->lineEdit_7->text();
    if(sig!=0){
    if(newpass.isEmpty()||newpass1.isEmpty()){
        QMessageBox::warning(this,tr("error"),tr("can not be black"));
    }
    else if(newpass==newpass1){
               QSqlQuery ad;
               ad.prepare("update admin set password=:password where adminname=:adminname");
               ad.bindValue(":password",newpass);
               ad.bindValue(":adminname",sig);
               ad.exec();
               if(ad.exec()){
                   QMessageBox::warning(this,tr("result"),tr("success"));
               }
    }
    else{
        QMessageBox::warning(this,tr("error"),tr("the two codes are not consistent with each other"));
    }
 }//管理员
    if(sig2!=0){
        if(newpass.isEmpty()||newpass1.isEmpty()){
            QMessageBox::warning(this,tr("error"),tr("can not be black"));
        }
        else if(newpass==newpass1){
                   QSqlQuery us;
                   us.prepare("update user set password=:password where username=:username");
                   us.bindValue(":password",newpass);
                   us.bindValue(":username",sig2);
                   us.exec();
                   if(us.exec()){
                       QMessageBox::warning(this,tr("result"),tr("success"));
                   }
        }
        else{
            QMessageBox::warning(this,tr("error"),tr("the two codes are not consistent with each other"));
        }
    }//用户
    if(sig3!=0){
        if(newpass.isEmpty()||newpass1.isEmpty()){
            QMessageBox::warning(this,tr("error"),tr("can not be black"));
        }
        else if(newpass==newpass1){
                   QSqlQuery te;
                   te.prepare("update tea set password=:password where tname=:tname");
                   te.bindValue(":password",newpass);
                   te.bindValue(":tname",sig3);
                   te.exec();
                   if(te.exec()){
                       QMessageBox::warning(this,tr("result"),tr("success"));
                   }
        }
        else{
            QMessageBox::warning(this,tr("error"),tr("the two codes are not consistent with each other"));
        }
    }//老师
}
void apassword::on_pushButton_2_clicked()
{
    if(sig!=0){
        admin *a=new admin();
        a->show();
        this->close();
    }
    if(sig2!=0){
        user *u=new user();
        u->show();
        this->close();
    }
    if(sig3!=0){
        teacher *t=new teacher();
        t->show();
        this->close();
    }
}
