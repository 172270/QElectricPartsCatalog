#ifndef ADDPARAMETER_H
#define ADDPARAMETER_H

#include <QWidget>

namespace Ui {
class AddParameter;
}

class AddParameter : public QWidget
{
    Q_OBJECT

public:
    explicit AddParameter(QWidget *parent = 0);
    ~AddParameter();

private:
    Ui::AddParameter *ui;
};

#endif // ADDPARAMETER_H
