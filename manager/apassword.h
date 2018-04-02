#ifndef APASSWORD_H
#define APASSWORD_H

#include <QDialog>

namespace Ui {
class apassword;
}

class apassword : public QDialog
{
    Q_OBJECT

public:
    explicit apassword(QWidget *parent = 0);
    ~apassword();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::apassword *ui;
};

#endif // APASSWORD_H
