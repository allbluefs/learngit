#include "zhuce.h"
#include "ui_zhuce.h"
#include "login.h"
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>

zhuce::zhuce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);
}

zhuce::~zhuce()
{
    delete ui;
}

void zhuce::on_btn4_clicked()
{
    login *log=new login();
    log->show();
    this->close();
}

void zhuce::on_btn3_clicked()
{   QSqlQuery query;
    QSqlQuery cha;
    int sign=0;
    QString username="\""+ui->lineEdit_3->text()+"\"";
    QString zhanghaochaxun=ui->lineEdit_3->text();
    QString password="\""+ui->lineEdit_4->text()+"\"";
    QString yanzheng="\""+ui->lineEdit_5->text()+"\"";
    if(ui->checkBox_4->checkState()==Qt::Checked){
        cha.prepare("select * from user where username=:username");
        QString str=QString("%1").arg(zhanghaochaxun);
        cha.bindValue(":username",str);
        cha.exec();
        QString input1=ui->lineEdit_3->text();
        QString input2=ui->lineEdit_4->text();
        QString input3=ui->lineEdit_5->text();

        if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty())
        {
            QMessageBox::warning(this,tr("error"),tr("can not be blank"));
        }

        else{
        while(cha.next())
        {
        sign=1;
        QMessageBox::warning(this,tr("error"),tr("the user aleady exist"));
        }
        if(sign==0)
        {
        if(yanzheng==password)
        {
                QString str=QString("insert into user(username,password)values(%1,%2)").arg(username).arg(password);
                query.exec(str);
                QMessageBox::warning(this,tr("result"),tr("success"));
        }
        else
        {
        QMessageBox::warning(this,tr("error"),tr("the two codes are not consistent with each other"));//密码不一致
        }
        }
    }
    }
    else if(ui->checkBox_5->checkState()==Qt::Checked){
        cha.prepare("select * from tea where tname=:tname");
        QString str=QString("%1").arg(zhanghaochaxun);
        cha.bindValue(":tname",str);
        cha.exec();
        QString input1=ui->lineEdit_3->text();
        QString input2=ui->lineEdit_4->text();
        QString input3=ui->lineEdit_5->text();

        if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty())
        {
            QMessageBox::warning(this,tr("error"),tr("can not be blank"));
        }

        else{
        while(cha.next())
        {
        sign=1;
        QMessageBox::warning(this,tr("error"),tr("the user aleady exist"));
        }
        if(sign==0)
        {
        if(yanzheng==password)
        {
                QString str=QString("insert into tea(tname,password)values(%1,%2)").arg(username).arg(password);
                query.exec(str);
                QMessageBox::warning(this,tr("result"),tr("success"));
        }
        else
        {
        QMessageBox::warning(this,tr("error"),tr("the two codes are not consistent with each other"));//密码不一致
        }
        }
    }
    }//教师
    else{
        QMessageBox::warning(this,tr("error"),tr("select the registered object"));

    }


}
