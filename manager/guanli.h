#ifndef GUANLI_H
#define GUANLI_H
#include<QSqlTableModel>
#include <QDialog>

namespace Ui {
class guanli;
}

class guanli : public QDialog
{
    Q_OBJECT

public:
    explicit guanli(QWidget *parent = 0);
    ~guanli();

private slots:

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::guanli *ui;
    QSqlTableModel *model;
};

#endif // GUANLI_H
