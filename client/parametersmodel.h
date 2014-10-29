#ifndef PARAMETERSMODEL_H
#define PARAMETERSMODEL_H

#include <QAbstractTableModel>
#include <QStandardItem>
#include <QList>

#include "messages/parameter.h"

class ParametersModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ParametersModel(QObject *parent = 0);

signals:

public slots:


    // QAbstractItemModel interface
public:

    void res(){
        beginResetModel();
        int count = m_data.count();
        for(int i =0;i<count;i++){
            delete m_data.takeAt(0);
        }
    }

    void add(Parameter *p){
        m_data.append(p);
    }

    void resModel(){
        endResetModel();
    }

    QModelIndex index(int row, int column, const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        if (row >= m_data.size() || row < 0 || column >= 8)
            return QModelIndex();

        Parameter* pkt = m_data.at(row);
        return createIndex(row, column, pkt);
    }

    QModelIndex parent(const QModelIndex &child) const
    {
        Q_UNUSED(child);
        return QModelIndex();
    }
    int rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent)
//        if(parent.isValid())
            return m_data.size();
//        return 0;
    }
    int columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return 3;
    }
    QVariant data(const QModelIndex &index, int role) const
    {
        if(!index.isValid())
            return QVariant();
        if(index.row() > m_data.size() )
            return QVariant();

        Parameter *p= m_data.at(index.row());
        if (role == Qt::DisplayRole ) {

            if (index.column() == 0){
                // return name(symbol)
                return QString(p->getName() +" "+ ( p->getSymbol().size()>0?QString("("+p->getSymbol()+")"):QString("") ) );
            }
            else if(index.column() == 1){
                // return type
                return QString(p->config().valueType() );
            }
            else if(index.column() == 2){
                // zakresy
                QString  str, ret;

                if (p->config().hasMinValue() && p->config().hasMaxValue() ){
                    str.append("Zakres zmiennej (%1, %2)");
                    ret = str.arg(p->config().getMinValue()).arg(p->config().getMaxValue());
                }
                if (p->config().hasMaxTextLength() && p->config().hasMinTextLength() ){
                    str.clear();
                    if(ret.size()>0){
                        str.append("oraz ");
                    }
                    str.append("długość textu zmiennej (%1, %2)");
                    ret.append(str.arg(p->config().minTextLength()).arg(p->config().maxTextLength()));
                }
                return ret;
            }
        }
        else if( role == Qt::ToolTipRole){
            return p->getDescription();
        }

        return QVariant();
    }

private:
    QList<Parameter*> m_data;
};

#endif // PARAMETERSMODEL_H
