#ifndef ADDPARAMETER_H
#define ADDPARAMETER_H

#include <QWidget>
#include "messages/parameter.h"

namespace Ui {
class AddParameter;
}

class AddParameter : public QWidget
{
    Q_OBJECT

public:
    explicit AddParameter(QWidget *parent = 0);
    ~AddParameter();
public slots:
    void AddResponse(QByteArray res);
    void SelectResponse(QByteArray res);
signals:
    void messageAvalible(MsgType, QByteArray ba);
private slots:
    void on_addParameter_clicked();

private:
    Ui::AddParameter *ui;
};

#endif // ADDPARAMETER_H
