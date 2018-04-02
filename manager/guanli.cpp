#include "guanli.h"
#include "ui_guanli.h"
#include "uguanli.h"
#include <QString>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include<QMessageBox>
#include<QSqlError>

guanli::guanli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guanli)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);
    model->setTable("tea");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

guanli::~guanli()
{
    delete ui;
}



void guanli::on_pushButton_5_clicked()
{
    QString name=ui->lineEdit->text();
    model->setFilter(QObject::tr("tname='%1'").arg(name));
    model->select();
}//查询

void guanli::on_pushButton_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
        QMessageBox::warning(this,tr("result"),tr("success"));
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),tr("database wrong:%1").arg(model->lastError().text()));
    }
}//提交修改

void guanli::on_pushButton_2_clicked()
{
    model->revertAll();
}//撤销



void guanli::on_pushButton_3_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
   QString name=ui->lineEdit_2->text();
   QString code=ui->lineEdit_3->text();
   if(name.isEmpty()||code.isEmpty()){
       QMessageBox::warning(this,tr("error"),tr("can not be blank"));
   }else{
       model->insertRow(rowNum); //添加一行
       model->setData(model->index(rowNum,0),name);
       model->setData(model->index(rowNum,1),code);
       QMessageBox::warning(this,tr("result"),tr("success"));
       model->submitAll(); //可以直接提交
   }
}//添加教师

void guanli::on_pushButton_4_clicked()
{
    int curRow=ui->tableView->currentIndex().row();
    model->removeRow(curRow);
//    model->submitAll();

    int ok=QMessageBox::warning(this,tr("delect the current row"),tr("sure?"),QMessageBox::Yes,QMessageBox::No);

    if(ok==QMessageBox::No){
        model->revertAll();
    }else model->submitAll();
}//删除

void guanli::on_pushButton_7_clicked()
{
    uguanli *u=new uguanli();
    u->show();
    this->close();
}

void guanli::on_pushButton_6_clicked()
{
   model->setTable("tea");
   model->select();
}
