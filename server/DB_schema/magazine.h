#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>

class Magazine
{
public:
    Magazine();

    QString getName() const;
    void setName(const QString &value);

    quint32 getID() const;
    void setID(const quint32 &value);

private:
    QString name;
    quint32 ID;
};

#endif // MAGAZINE_H
