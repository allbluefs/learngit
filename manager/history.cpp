#include "history.h"
#include "ui_history.h"
#include "admin.h"
#include "teacher.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QSqlQuery>
#include<QFileDialog>
#include<QValueAxis>
extern QString sig;
extern QString sig3;

using namespace QtCharts;

history::history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);
    model->setTable("allgrade");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
}

history::~history()
{
    delete ui;
}

void history::on_pushButton_3_clicked()
{
    if(sig!=0){
    admin *a=new admin();
    a->show();
    this->close();}
    if(sig3!=0){
        teacher *t=new teacher();
        t->show();
        this->close();
    }
}

void history::on_pushButton_2_clicked()
{
    int curRow=ui->tableView->currentIndex().row();
    model->removeRow(curRow);

    int ok=QMessageBox::warning(this,tr("delect the current row"),tr("sure?"),QMessageBox::Yes,QMessageBox::No);

    if(ok==QMessageBox::No){
        model->revertAll();
    }else model->submitAll();
}//删除

void history::on_pushButton_4_clicked()
{
    model->setTable("allgrade");
    model->select();
}//返回所有结果

void history::on_pushButton_clicked()
{
    QString id=ui->lineEdit->text();
    QSqlQuery a;
    a.prepare("select * from allgrade where id=:id");
    a.bindValue(":id",id);
    a.exec();
    if(a.next()){
        qDebug()<<"1";
    }
    int  c=a.value(1).toInt();
    int  c1=a.value(2).toInt();
    int  c2=a.value(3).toInt();
    int  c3=a.value(4).toInt();
    int  c4=a.value(5).toInt();
    int  c5=a.value(6).toInt();
    int  c6=a.value(7).toInt();
    int  c7=a.value(8).toInt();
    int  c8=a.value(9).toInt();
    int  c9=a.value(10).toInt();
    int  c10=a.value(11).toInt();
    int  c11=a.value(12).toInt();



    QGraphicsScene *scene=new QGraphicsScene(0, 0, 960, 560);

    view1=new QGraphicsView(scene);
    view1->setRenderHint(QPainter::Antialiasing);
    view1->setMinimumSize(1000, 600);
    view1->setSceneRect(0, 0, 960, 560);

    auto barChart = new QChart();
    barChart->setTitle("Simple Bar Charts");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    auto bars = new QBarSeries();

    auto setJan = new QBarSet("图一");
    setJan->setBrush(QBrush(Qt::darkRed));

    *setJan <<c<<c3<<c6<<c9;
    bars->append(setJan);
    auto setFeb = new QBarSet("图二");
    setFeb->setBrush(QBrush(Qt::darkBlue));
    bars->append(setFeb);
    setFeb->append(c1);
    setFeb->append(c4);
    setFeb->append(c7);
    setFeb->append(c10);
    auto setMar = new QBarSet("图三");
    bars->append(setMar);
    *setMar <<c2<<c5 <<c8 <<c11;

    barChart->setGeometry(40, 40, 900, 520);
    barChart->setBackgroundPen(QPen(Qt::lightGray));
    barChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    barChart->addSeries(bars);

    QStringList categories;
    categories << "NaturalSense" << "MarginalDefinition" << "TheAmountOfInformation"<<"TheComprehensiveScore";
    auto axisX = new QBarCategoryAxis();
    axisX->append(categories);

    QValueAxis *axisY=new QValueAxis();\
    axisY->setRange(1,5);
    axisY->setLabelFormat("%.2f");
    axisY->setGridLineVisible(true);

    barChart->createDefaultAxes();
    barChart->setAxisX(axisX, bars);
    barChart->setAxisY(axisY,bars);



    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);

    scene->addItem(barChart);

    view1->show();
}
