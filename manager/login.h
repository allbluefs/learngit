#ifndef LOGIN_H
#define LOGIN_H
#include<QLineEdit>
#include<QButtonGroup>
#include <QDialog>
#include "zhuce.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_btn2_clicked();

    void on_btn1_clicked();

private:
    Ui::login *ui;
    QLineEdit *lineEdit_2;
    QButtonGroup *pButtonGroup;

};

#endif // LOGIN_H
