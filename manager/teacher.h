#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include <QtCharts>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
using namespace QtCharts;

namespace Ui {
class teacher;
}

class teacher : public QDialog
{
    Q_OBJECT

public:
    explicit teacher(QWidget *parent = 0);
    ~teacher();

private slots:
    void on_btn17_clicked();

    void on_btn18_clicked();

    void on_btn16_clicked();

    void on_btn15_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::teacher *ui;
    QGraphicsView *view;
};

#endif // TEACHER_H
