#include "addparameter.h"
#include "ui_addparameter.h"

#include <QStandardItemModel>

AddParameter::AddParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddParameter)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel();
    ui->parametersView->setModel(model);
}

AddParameter::~AddParameter()
{
    delete ui;
}

void AddParameter::AddResponse(QByteArray res)
{
    ResponseAddParameter resp;
    resp.fromArray(res);
    if(resp.replay(0) == protbuf::addParameterReplay::addOk){
        ui->status->setText("Parametr "+ ui->name->text() +" dodany pomyslnie");
    }
    else{
        ui->status->setText("Parametr już istnieje w bazie danych");
    }
}

void AddParameter::SelectResponse(QByteArray res)
{
    ResponseParameters param;
    param.fromArray(res);

    QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->parametersView->model());
    model->setRowCount(param.parameters_size());
    model->setColumnCount(1);

    for(int i=0;i<param.parameters_size();i++){
        Parameter p;
        p.CopyFrom(param.parameters(i));
        QStandardItem *it = new QStandardItem(p.getName());
        model->setItem(i,0,it);
    }
}

void AddParameter::on_addParameter_clicked()
{
    Parameter addMessage;

    addMessage.set_name(ui->name->text());
    addMessage.set_symbol(ui->symbol->text());
    if(ui->description->toPlainText().size())
        addMessage.set_description(ui->description->toPlainText());
    if(ui->defaultValue->text().size())
        addMessage.config().setDefaultValue(ui->defaultValue->text());
    addMessage.config().setMaxValue(ui->maxVal->value());
    addMessage.config().setMinValue(ui->minVal->value());

    emit messageAvalible(MsgType::addParameter, addMessage.toArray() );
}
