#include "uguanli.h"
#include "ui_uguanli.h"
#include "admin.h"
#include "guanli.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include"yonghucaozuo.h"


uguanli::uguanli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uguanli)
{
    ui->setupUi(this);
}

uguanli::~uguanli()
{
    delete ui;
}

void uguanli::on_pushButton_clicked()
{
    yonghucaozuo *g=new yonghucaozuo();
    g->show();
    this->close();
}//查询

void uguanli::on_pushButton_3_clicked()
{
    admin *a=new admin();
    a->show();
    this->close();
}

void uguanli::on_pushButton_2_clicked()
{
    guanli *h=new guanli();
    h->show();
    this->close();
}
