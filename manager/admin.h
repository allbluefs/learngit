#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QMainWindow>
#include <QtCharts>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
using namespace QtCharts;
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_btn11_clicked();

    void on_btn13_clicked();

    void on_btn12_clicked();

    void on_btn10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn14_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin *ui;
    QGraphicsView *view;

};

#endif // ADMIN_H
