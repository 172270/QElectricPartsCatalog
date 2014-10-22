#include "addparameter.h"
#include "ui_addparameter.h"


AddParameter::AddParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddParameter)
{
    ui->setupUi(this);
}

AddParameter::~AddParameter()
{
    delete ui;
}

void AddParameter::responseRecived(QByteArray res)
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
    addMessage.syncConfig();

    emit messageAvalible(MsgType::addParameter, addMessage.toArray() );
}
