#pragma once

#include <QDoubleSpinBox>
#include <QDoubleValidator>
#include <QLineEdit>
#include <QVariant>
#include <QDebug>
#include <QString>

class QEngineerSpinBox : public QDoubleSpinBox
{
Q_OBJECT
public:
    QEngineerSpinBox(QWidget * parent = 0);

    int decimals() const;
    void setDecimals(int value);

    QString textFromValue ( double value ) const;
    double valueFromText ( const QString & text ) const;

    QValidator::State validate(QString &, int &) const;
private:
    int dispDecimals;

public slots:
    void stepDown();
    void stepUp();
};
