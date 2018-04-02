#ifndef UGUANLI_H
#define UGUANLI_H

#include <QDialog>

namespace Ui {
class uguanli;
}

class uguanli : public QDialog
{
    Q_OBJECT

public:
    explicit uguanli(QWidget *parent = 0);
    ~uguanli();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::uguanli *ui;
};

#endif // UGUANLI_H
