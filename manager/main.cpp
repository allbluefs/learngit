#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "zhuce.h"
#include "admin.h"
#include "history.h"
#include<QSqlDatabase>
#include<QDebug>


int main(int argc, char *argv[])
{
    QSqlDatabase dataBase=QSqlDatabase::addDatabase("QMYSQL");
          dataBase.setHostName("localhost");
          dataBase.setUserName("root");
          dataBase.setPassword("123456");
          dataBase.setDatabaseName("database");
          dataBase.setPort(3306);
          dataBase.open();
          bool ok=dataBase.open();
          if(ok){
              qDebug()<<"success";
          }
          else{
              qDebug()<<"false";
          }


    QApplication a(argc, argv);
    login m;
    m.show();
//    history h;
//    h.show();


    return a.exec();
}
