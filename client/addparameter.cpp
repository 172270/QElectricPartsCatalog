#include "addparameter.h"
#include "ui_addparameter.h"

#include <QStandardItemModel>
#include "float.h"
#include "parametersmodel.h"

AddParameter::AddParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddParameter)
{
    ui->setupUi(this);
    ParametersModel *model = new ParametersModel();
    ui->parametersView->setModel(model);
    ui->minLength->setMinimum(0);
    ui->maxLength->setMinimum(0);

    connect(ui->minLength, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int val){
       ui->maxLength->setMinimum(val);
    });
    connect(ui->minVal, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double val){
       ui->maxVal->setMinimum(val);
    });

    auto type= ui->parameterType;

    type->insertItem(type->count(),tr("Całkowity bez znaku","Numeric without sign"), QVariant("uint"));
    type->insertItem(type->count(),tr("Całkowity ze znakiem","Numeric with sign"), QVariant("int"));
    type->insertItem(type->count(),tr("Zmiennoprzecinkowy","Numeric with sign"), QVariant("double"));
    type->insertItem(type->count(),tr("Textowy","string"), QVariant("string"));
    type->insertItem(type->count(),tr("Temperatura","Temperature"), QVariant("temperature"));
    type->insertItem(type->count(),tr("Data","calendar date"), QVariant("cal"));
}

void AddParameter::requestParameters()
{
    RequestParameters reqParameters;
    emit requestAvalible(MsgType::reqParameters, reqParameters.toArray() );
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

    ParametersModel *model = dynamic_cast<ParametersModel*>(ui->parametersView->model());
    model->res();
    for(int i=0;i<param.parameters_size();i++){
        Parameter *p = new Parameter();
        p->CopyFrom(param.parameters(i));
        p->ParametersModel();
        model->add(p);
    }
    model->resModel();
}

void AddParameter::on_addParameter_clicked()
{
    Parameter addMessage;
    addMessage.set_name(ui->name->text());
    addMessage.set_symbol(ui->symbol->text());

    if(ui->description->toPlainText().size())
        addMessage.set_description(ui->description->toHtml());
    if(ui->hasDefault->isChecked() )
        addMessage.config().setDefaultValue(ui->defaultValue->text());

    if(ui->hasLimitedValue->isChecked()){
        addMessage.config().setMaxValue(ui->maxVal->value());
        addMessage.config().setMinValue(ui->minVal->value());
    }
    if(ui->hasLimitedLength->isChecked()){
        addMessage.config().setMaxTextLength(ui->maxLength->value());
        addMessage.config().setMinTextLength(ui->minLength->value());
    }
    addMessage.config().setValueType(ui->parameterType->currentData().toString() );
    qDebug()<< addMessage.config().toString();

    emit requestAvalible(MsgType::addParameter, addMessage.toArray() );
    requestParameters();
    emit requestReady();
}

void AddParameter::enableLayout(QLayout *layout, bool enable){
    QWidget *child;
    QLayoutItem *item;
    int i = 0;
    while ((item = layout->itemAt(i++)) != 0) {
        child = item->widget();
        child->setEnabled(enable);

        auto *cb = dynamic_cast<QCheckBox*> (child);
        if(cb)
            cb->setChecked(false);
    }
}

void AddParameter::disableAll(){
    enableLayout(ui->default_hl,false);
    enableLayout(ui->value_hl,false);
    enableLayout(ui->length_hl,false);

    ui->minVal->setMinimum(-DBL_MAX);
    ui->maxVal->setMaximum(DBL_MAX);
}

void AddParameter::on_parameterType_currentIndexChanged(int)
{
    auto type = ui->parameterType->currentData();
    disableAll();

    if (type == "uint"){
        enableLayout(ui->default_hl);
        enableLayout(ui->value_hl);

        ui->minVal->setMinimum(0.0);
    }
    else if(type == "int"){
        enableLayout(ui->default_hl);
        enableLayout(ui->value_hl);
    }
    else if(type == "string"){
        enableLayout(ui->default_hl);
        enableLayout(ui->length_hl);
    }
}
