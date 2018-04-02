#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn9_clicked();

    void on_btn8_clicked();

    void on_btn5_clicked();

    void on_btn7_clicked();

    void on_btn6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
