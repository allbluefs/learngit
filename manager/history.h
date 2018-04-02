#ifndef HISTORY_H
#define HISTORY_H
#include <QSqlTableModel>

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
class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::history *ui;
    QSqlTableModel *model;
    QGraphicsView *view1;
};

#endif // HISTORY_H
