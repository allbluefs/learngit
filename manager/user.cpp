#include "user.h"
#include "ui_user.h"
#include "login.h"
#include "mainwindow.h"
#include "apassword.h"

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_3_clicked()
{
    this->close();
}

void user::on_pushButton_4_clicked()
{
    login *l=new login();
    l->show();
    this->close();
}

void user::on_pushButton_clicked()
{
    MainWindow *m=new MainWindow();
    m->show();
    this->close();
}

void user::on_pushButton_2_clicked()
{
    apassword *a=new apassword();
    a->show();
    this->close();
}
