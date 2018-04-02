#ifndef RULE_H
#define RULE_H

#include <QDialog>

namespace Ui {
class rule;
}

class rule : public QDialog
{
    Q_OBJECT

public:
    explicit rule(QWidget *parent = 0);
    ~rule();

private:
    Ui::rule *ui;
};

#endif // RULE_H
