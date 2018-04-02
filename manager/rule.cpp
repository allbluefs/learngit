#include "rule.h"
#include "ui_rule.h"

rule::rule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rule)
{
    ui->setupUi(this);
}

rule::~rule()
{
    delete ui;
}
