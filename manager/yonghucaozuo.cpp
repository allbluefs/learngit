#include "yonghucaozuo.h"
#include "ui_yonghucaozuo.h"
#include "uguanli.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include<QSqlError>
#include<QItemSelection>
#include<QModelIndexList>


yonghucaozuo::yonghucaozuo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yonghucaozuo)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

yonghucaozuo::~yonghucaozuo()
{
    delete ui;
}

void yonghucaozuo::on_pushButton_3_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
        QMessageBox::warning(this,tr("result"),tr("success"));
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),tr("database wrong:%1").arg(model->lastError().text()));
    }
}//修改操作

void yonghucaozuo::on_pushButton_4_clicked()
{
    model->revertAll();
}//撤销

void yonghucaozuo::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    model->setFilter(QObject::tr("username='%1'").arg(name));
    model->select();
}//查询操作

void yonghucaozuo::on_pushButton_2_clicked()
{
    model->setTable("user");
    model->select();
}//返回全表



void yonghucaozuo::on_pushButton_6_clicked()
{
    int curRow=ui->tableView->currentIndex().row();
    model->removeRow(curRow);
//    model->submitAll();

    int ok=QMessageBox::warning(this,tr("delect the current row"),tr("sure?"),QMessageBox::Yes,QMessageBox::No);

    if(ok==QMessageBox::No){
        model->revertAll();
    }else model->submitAll();
}

void yonghucaozuo::on_pushButton_5_clicked()
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
}//添加用户

void yonghucaozuo::on_pushButton_7_clicked()
{
    uguanli *u=new uguanli();
    u->show();
    this->close();
}
