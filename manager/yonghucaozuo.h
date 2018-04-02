#ifndef YONGHUCAOZUO_H
#define YONGHUCAOZUO_H
#include<QSqlTableModel>

#include <QDialog>

namespace Ui {
class yonghucaozuo;
}

class yonghucaozuo : public QDialog
{
    Q_OBJECT

public:
    explicit yonghucaozuo(QWidget *parent = 0);
    ~yonghucaozuo();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::yonghucaozuo *ui;
    QSqlTableModel *model;
};

#endif // YONGHUCAOZUO_H
