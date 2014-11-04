#ifndef ADDPARAMETER_H
#define ADDPARAMETER_H

#include <QWidget>
#include <QLabel>
#include "messages/parameter.h"

namespace Ui {
class AddParameter;
}

class AddParameter : public QWidget
{
    Q_OBJECT

public:
    explicit AddParameter(QWidget *parent = 0);
    void requestParameters();
    ~AddParameter();

public slots:
    void AddResponse(QByteArray res);
    void SelectResponse(QByteArray res);

signals:
    void requestAvalible(MsgType, QByteArray ba);

    void requestReady();

private slots:
    void on_addParameter_clicked();
    void on_parameterType_currentIndexChanged(int i);

    void on_parametersView_doubleClicked(const QModelIndex &index);

private:
    Ui::AddParameter *ui;
    void disableAll();
    void enableLayout(QLayout *layout, bool enable = true);
    void disableLabelWithBuddy(QLabel *l, bool disable = true);
    void enableLabelWithBuddy(QLabel *l, bool enable = true);
};

#endif // ADDPARAMETER_H
