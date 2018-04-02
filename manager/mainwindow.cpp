#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "admin.h"
#include "user.h"
#include "teacher.h"
#include<QFileDialog>
#include<QString>
#include<QMessageBox>
#include<QLabel>
#include<QDebug>
#include<QSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QMessageBox>
#include "rule.h"
extern QString sig;
extern QString sig2;
extern QString sig3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn9_clicked()
{
    login *log=new login();
    log->show();
    this->close();
}

void MainWindow::on_btn8_clicked()
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

void MainWindow::on_btn5_clicked()   //评分
{

         QString item[20];
         item[0]=ui->comboBox1->currentText();
         item[1]=ui->comboBox2->currentText();
         item[2]=ui->comboBox3->currentText();
         item[3]=ui->comboBox4->currentText();
         item[4]=ui->comboBox5->currentText();
         item[5]=ui->comboBox6->currentText();
         item[6]=ui->comboBox7->currentText();
         item[7]=ui->comboBox8->currentText();
         item[8]=ui->comboBox9->currentText();
         item[9]=ui->comboBox10->currentText();
         item[10]=ui->comboBox11->currentText();
         item[11]=ui->comboBox12->currentText();

         QSqlQuery query;
         query.prepare("insert into grade(image,NaturalSense,MarginalDefinition,TheAmountOfInformation,TheComprehensiveScore)values(:image,:NaturalSense,:MarginalDefinition,:TheAmountOfInformation,:TheComprehensiveScore)");
         query.bindValue(":image","image1");
         query.bindValue(":NaturalSense",item[0]);
         query.bindValue(":MarginalDefinition",item[1]);
         query.bindValue(":TheAmountOfInformation",item[2]);
         query.bindValue(":TheComprehensiveScore",item[3]);
         QSqlQuery query1;
         query1.prepare("insert into grade(image,NaturalSense,MarginalDefinition,TheAmountOfInformation,TheComprehensiveScore)values(:image,:NaturalSense,:MarginalDefinition,:TheAmountOfInformation,:TheComprehensiveScore)");
         query1.bindValue(":image","image2");
         query1.bindValue(":NaturalSense",item[4]);
         query1.bindValue(":MarginalDefinition",item[5]);
         query1.bindValue(":TheAmountOfInformation",item[6]);
         query1.bindValue(":TheComprehensiveScore",item[7]);
         QSqlQuery query2;
         query2.prepare("insert into grade(image,NaturalSense,MarginalDefinition,TheAmountOfInformation,TheComprehensiveScore)values(:image,:NaturalSense,:MarginalDefinition,:TheAmountOfInformation,:TheComprehensiveScore)");
         query2.bindValue(":image","image3");
         query2.bindValue(":NaturalSense",item[8]);
         query2.bindValue(":MarginalDefinition",item[9]);
         query2.bindValue(":TheAmountOfInformation",item[10]);
         query2.bindValue(":TheComprehensiveScore",item[11]);

         query.exec();
         query1.exec();
         query2.exec();
         QMessageBox::warning(this,tr("result"),tr("success"));


}

void MainWindow::on_btn7_clicked()
{

    QString path=QFileDialog::getOpenFileName(this,tr("OPEN FILE"),"C://Users//Administrator//Desktop//work//manager","Image files(*.jpg *.png *.bmp)");
    QString filename(path);
    QImage *image=new QImage;
    if(!(image->load(filename)))
    {
        QMessageBox::information(this,tr("no"),tr("no"));
        delete image;
        return;
    }
    ui->label2->setScaledContents(true);//图片自适应大小
    ui->label2->setPixmap(QPixmap::fromImage(*image));

    QString path1=QFileDialog::getOpenFileName(this,tr("OPEN FILE"),"C://Users//Administrator//Desktop//work//manager","Image files(*.jpg *.png *.bmp)");
    QString filename1(path1);
    QImage *image1=new QImage;
    if(!(image1->load(filename1)))
    {
        QMessageBox::information(this,tr("no"),tr("no"));
        delete image1;
        return;
    }
    ui->label3->setScaledContents(true);//图片自适应大小
    ui->label3->setPixmap(QPixmap::fromImage(*image1));

    QString path2=QFileDialog::getOpenFileName(this,tr("OPEN FILE"),"C://Users//Administrator//Desktop//work//manager","Image files(*.jpg *.png *.bmp)");
    QString filename2(path2);
    QImage *image2=new QImage;
    if(!(image2->load(filename2)))
    {
        QMessageBox::information(this,tr("no"),tr("no"));
        delete image2;
        return;
    }
    ui->label4->setScaledContents(true);//图片自适应大小
    ui->label4->setPixmap(QPixmap::fromImage(*image2));

    QSqlQuery de;
    de.prepare("delete from grade");
    de.exec();


}//下一组

void MainWindow::on_btn6_clicked()
{
    rule *r=new rule();
    r->show();
}
