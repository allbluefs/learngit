#include "teacher.h"
#include "ui_teacher.h"
#include "mainwindow.h"
#include "apassword.h"
#include "login.h"
#include "history.h"
#include<QString>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>
#include<QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QSqlQuery>


teacher::teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher)
{
    ui->setupUi(this);
}

teacher::~teacher()
{
    delete ui;
}

void teacher::on_btn17_clicked()
{
    MainWindow *m=new MainWindow();
    m->show();
    this->close();
}

void teacher::on_btn18_clicked()
{
    this->close();
}

void teacher::on_btn16_clicked()
{
    apassword *a=new apassword();
    a->show();
    this->close();
}

void teacher::on_btn15_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,tr("OPEN FILE"),"C://Users//Administrator//Desktop//work","Image files(*.jpg *.png *.bmp)");
    QString filename(path);
    QImage *image=new QImage;
    if(!(image->load(filename)))
    {
        QMessageBox::information(this,tr("no"),tr("no"));
        delete image;
        return;
    }
    qDebug()<<filename;
    QString saveFileName=QFileDialog::getSaveFileName(this,tr("save file"),"C://Users//Administrator//Desktop//work","Image files(*.jpg *.bmp *.png)");
    QFile file(saveFileName);
    file.copy(filename,saveFileName);
    qDebug()<<saveFileName;
}//添加图片

void teacher::on_pushButton_clicked()
{
    login *l=new login();
    l->show();
    this->close();
}

void teacher::on_pushButton_2_clicked()
{
    QSqlQuery a1;
     int i=0,j=0,m=0,n=0,e=0,p=0;
     a1.prepare("select * from grade where image='image1'");
     a1.exec();
     while(a1.next()){
         p++;
         QString c=a1.value(1).toString();
         if(c=='5'){
             i++;
         }
         else if(c=='4'){
             j++;
         }
         else if(c=='3'){
             m++;
         }
         else if(c=='2'){
             n++;
         }else{
             e++;
         }
     }
     int x=(i*5+j*4+m*3+n*2+e)/p;
     qDebug()<<i <<j <<m<<n<<e<<x;
     //图一自然感


      QSqlQuery a2;
      int i1=0,j1=0,m1=0,n1=0,e1=0,p1=0;
      a2.prepare("select * from grade where image='image2'");
      a2.exec();
      while(a2.next()){
          p1++;
          int c1=a2.value(1).toInt();
          if(c1==5) i1++;
          else if(c1==4) j1++;
          else if(c1==3) m1++;
          else if(c1==2) n1++;
          else e1++;
      }
      int x1=(i1*5+j1*4+m1*3+n1*2+e1)/p1;
      qDebug()<<i1 <<j1 <<m1<<n1<<e1<<x1<<"wenti";


 //图二自然感
      QSqlQuery a3;
      int i2=0,j2=0,m2=0,n2=0,e2=0,p2=0;
      a3.prepare("select * from grade where image='image3'");
      a3.exec();
      while(a3.next()){
          p2++;
          QString c2=a3.value(1).toString();
          if(c2=='5'){
              i2++;
          }
          else if(c2=='4'){
              j2++;
          }
          else if(c2=='3'){
              m2++;
          }
          else if(c2=='2'){
              n2++;
          }else{
              e2++;
          }
      }
      int x2=(i2*5+j2*4+m2*3+n2*2+e2)/p2;
      qDebug()<<i2 <<j2 <<m2<<n2<<e2<<x2;
      //图三自然感

      QSqlQuery a4;
      int i3=0,j3=0,m3=0,n3=0,e3=0,p3=0;
      a4.prepare("select * from grade where image='image1'");
      a4.exec();
      while(a4.next()){
          p3++;
          QString c3=a4.value(2).toString();
          if(c3=='5'){
              i3++;
          }
          else if(c3=='4'){
              j3++;
          }
          else if(c3=='3'){
              m3++;
          }
          else if(c3=='2'){
              n3++;
          }else{
              e3++;
          }
      }
      int x3=(i3*5+j3*4+m3*3+n3*2+e3)/p3;
      qDebug()<<i3 <<j3 <<m3<<n3<<e3<<x3<<"image1 mar";
 //图一边缘清晰度

      QSqlQuery a5;
      int i4=0,j4=0,m4=0,n4=0,e4=0,p4=0;
      a5.prepare("select * from grade where image='image2'");
      a5.exec();
      while(a5.next()){
          p4++;
          QString c4=a5.value(2).toString();
          if(c4=='5'){
              i4++;
          }
          else if(c4=='4'){
              j4++;
          }
          else if(c4=='3'){
              m4++;
          }
          else if(c4=='2'){
              n4++;
          }else{
              e4++;
          }
      }
      int x4=(i4*5+j4*4+m4*3+n4*2+e4)/p4;
      qDebug()<<i4 <<j4 <<m4<<n4<<e4<<x4<<"image2 mar";//图二边缘清晰度

      QSqlQuery a6;
      int i5=0,j5=0,m5=0,n5=0,e5=0,p5=0;
      a6.prepare("select * from grade where image='image3'");
      a6.exec();
      while(a6.next()){
          p5++;
          QString c5=a6.value(2).toString();
          if(c5=='5'){
              i5++;
          }
          else if(c5=='4'){
              j5++;
          }
          else if(c5=='3'){
              m5++;
          }
          else if(c5=='2'){
              n5++;
          }else{
              e5++;
          }
      }
      int x5=(i5*5+j5*4+m5*3+n5*2+e5)/p5;
      qDebug()<<i5 <<j5 <<m5<<n5<<e5<<x5<<"image3 mar";//图三边缘清晰度

      QSqlQuery a7;
      int i6=0,j6=0,m6=0,n6=0,e6=0,p6=0;
      a7.prepare("select * from grade where image='image1'");
      a7.exec();
      while(a7.next()){
          p6++;
          QString c6=a7.value(3).toString();
          if(c6=='5'){
              i6++;
          }
          else if(c6=='4'){
              j6++;
          }
          else if(c6=='3'){
              m6++;
          }
          else if(c6=='2'){
              n6++;
          }else{
              e6++;
          }
      }
      int x6=(i6*5+j6*4+m6*3+n6*2+e6)/p6;
      qDebug()<<i6 <<j6 <<m6<<n6<<e6<<x6<<"image1 imf";//图一信息量

      QSqlQuery a8;
      int i7=0,j7=0,m7=0,n7=0,e7=0,p7=0;
      a8.prepare("select * from grade where image='image2'");
      a8.exec();
      while(a8.next()){
          p7++;
          QString c7=a8.value(3).toString();
          if(c7=='5'){
              i7++;
          }
          else if(c7=='4'){
              j7++;
          }
          else if(c7=='3'){
              m7++;
          }
          else if(c7=='2'){
              n7++;
          }else{
              e7++;
          }
      }
      int x7=(i7*5+j7*4+m7*3+n7*2+e7)/p7;
      qDebug()<<i7 <<j7 <<m7<<n7<<e7<<x7<<"image2 imf";//图二信息量

      QSqlQuery a9;
      int i8=0,j8=0,m8=0,n8=0,e8=0,p8=0;
      a9.prepare("select * from grade where image='image3'");
      a9.exec();
      while(a9.next()){
          p8++;
          QString c8=a9.value(3).toString();
          if(c8=='5'){
              i8++;
          }
          else if(c8=='4'){
              j8++;
          }
          else if(c8=='3'){
              m8++;
          }
          else if(c8=='2'){
              n8++;
          }else{
              e8++;
          }
      }
      int x8=(i8*5+j8*4+m8*3+n8*2+e8)/p8;
      qDebug()<<i8 <<j8 <<m8<<n8<<e8<<x8<<"image3 imf";//图三信息量

      QSqlQuery a10;
      int i9=0,j9=0,m9=0,n9=0,e9=0,p9=0;
      a10.prepare("select * from grade where image='image1'");
      a10.exec();
      while(a10.next()){
          p9++;
          QString c9=a10.value(4).toString();
          if(c9=='5'){
              i9++;
          }
          else if(c9=='4'){
              j9++;
          }
          else if(c9=='3'){
              m9++;
          }
          else if(c9=='2'){
              n9++;
          }else{
              e9++;
          }
      }
      int x9=(i9*5+j9*4+m9*3+n9*2+e9)/p9;
      qDebug()<<i9 <<j9 <<m9<<n9<<e9<<x9<<"image1 com";//图一综合评价

      QSqlQuery a11;
      int i10=0,j10=0,m10=0,n10=0,e10=0,p10=0;
      a11.prepare("select * from grade where image='image2'");
      a11.exec();
      while(a11.next()){
          p10++;
          QString c10=a11.value(4).toString();
          if(c10=='5'){
              i10++;
          }
          else if(c10=='4'){
              j10++;
          }
          else if(c10=='3'){
              m10++;
          }
          else if(c10=='2'){
              n10++;
          }else{
              e10++;
          }
      }
      int x10=(i10*5+j10*4+m10*3+n10*2+e10)/p10;
      qDebug()<<i10 <<j10 <<m10<<n10<<e10<<x10<<"image2 com";//图二综合评价

      QSqlQuery a12;
      int i11=0,j11=0,m11=0,n11=0,e11=0,p11=0;
      a12.prepare("select * from grade where image='image3'");
      a12.exec();
      while(a12.next()){
          p11++;
          QString c11=a12.value(4).toString();
          if(c11=='5'){
              i11++;
          }
          else if(c11=='4'){
              j11++;
          }
          else if(c11=='3'){
              m11++;
          }
          else if(c11=='2'){
              n11++;
          }else{
              e11++;
          }
      }
      int x11=(i11*5+j11*4+m11*3+n11*2+e11)/p11;
      qDebug()<<i11 <<j11 <<m11<<n11<<e11<<x11<<"image3 com";



     QGraphicsScene *scene=new QGraphicsScene(0, 0, 960, 560);
     view=new QGraphicsView(scene);
     view->setRenderHint(QPainter::Antialiasing);
     view->setMinimumSize(1000, 600);
     view->setSceneRect(0, 0, 960, 560);

     auto barChart = new QChart();
     barChart->setTitle("Simple Bar Charts");
     barChart->setAnimationOptions(QChart::SeriesAnimations);
     auto bars = new QBarSeries();

     auto setJan = new QBarSet("图一");
     setJan->setBrush(QBrush(Qt::darkRed));
     *setJan << x << x3 << x6<<x9;
     bars->append(setJan);
     auto setFeb = new QBarSet("图二");
     setFeb->setBrush(QBrush(Qt::darkBlue));
     bars->append(setFeb);
     setFeb->append(x1);
     setFeb->append(x4);
     setFeb->append(x7);
     setFeb->append(x10);
     auto setMar = new QBarSet("图三");
     bars->append(setMar);
     *setMar << x2 << x5 << x8 <<x11;

     barChart->setGeometry(40, 40, 900, 520);
     barChart->setBackgroundPen(QPen(Qt::lightGray));
     barChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
     barChart->addSeries(bars);

     QStringList categories;
     categories << "NaturalSense" << "MarginalDefinition" << "TheAmountOfInformation"<<"TheComprehensiveScore";
     auto axisX = new QBarCategoryAxis();
     axisX->append(categories);
     barChart->createDefaultAxes();
     barChart->setAxisX(axisX, bars);

     QValueAxis *axisY=new QValueAxis();
     axisY->setRange(1,5);
     axisY->setLabelFormat("%.2f");//刻度的格式
     axisY->setGridLineVisible(true);//是否显示网格线
     barChart->setAxisY(axisY,bars);

     barChart->legend()->setVisible(true);
     barChart->legend()->setAlignment(Qt::AlignBottom);

     scene->addItem(barChart);

     view->show();


     int ok=QMessageBox::warning(this,tr("save the result"),tr("sure?"),QMessageBox::Yes,QMessageBox::No);
     if(ok==QMessageBox::Yes){
         QSqlQuery all;
         all.prepare("insert into allgrade(id,a,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11)values(:id,:a,:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11)");
         all.bindValue(":id","");
         all.bindValue(":a",x);
         all.bindValue(":a1",x1);
         all.bindValue(":a2",x2);
         all.bindValue(":a3",x3);
         all.bindValue(":a4",x4);
         all.bindValue(":a5",x5);
         all.bindValue(":a6",x6);
         all.bindValue(":a7",x7);
         all.bindValue(":a8",x8);
         all.bindValue(":a9",x9);
         all.bindValue(":a10",x10);
         all.bindValue(":a11",x11);
         all.exec();
         qDebug()<<"saved";
     }
}

void teacher::on_pushButton_3_clicked()
{
    history *h=new history();
    h->show();
    this->close();
}
