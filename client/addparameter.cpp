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
    ui->parametersView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->parametersView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->minLength->setMinimum(0);
    ui->maxLength->setMinimum(0);

    connect(ui->minLength, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int val){
       ui->maxLength->setMinimum(val);
    });
    connect(ui->minVal, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double val){
       ui->maxVal->setMinimum(val);
    });

    connect(ui->hasDefault, static_cast<void (QAbstractButton::*)(bool)>(&QAbstractButton::toggled),[=](bool enabled){
        enableLabelWithBuddy(ui->default_l, enabled);
    });
    connect(ui->hasLimitedLength, static_cast<void (QAbstractButton::*)(bool)>(&QAbstractButton::toggled),[=](bool enabled){
        enableLabelWithBuddy(ui->minLength_l, enabled);
        enableLabelWithBuddy(ui->maxLength_l, enabled);
    });
    connect(ui->hasLimitedValue, static_cast<void (QAbstractButton::*)(bool)>(&QAbstractButton::toggled),[=](bool enabled){
        enableLabelWithBuddy(ui->minVal_l, enabled);
        enableLabelWithBuddy(ui->maxVal_l, enabled);
    });

    auto type= ui->parameterType;

    type->insertItem(type->count(),tr("Całkowity bez znaku","Numeric without sign"), QVariant(protbuf::Parameter_Config::UINT));
    type->insertItem(type->count(),tr("Całkowity ze znakiem","Numeric with sign"), QVariant(protbuf::Parameter_Config::INT));
    type->insertItem(type->count(),tr("Zmiennoprzecinkowy","Numeric with sign"), QVariant(protbuf::Parameter_Config::DOUBLE));
    type->insertItem(type->count(),tr("Textowy","string"), QVariant(protbuf::Parameter_Config::STRING));
    type->insertItem(type->count(),tr("Temperatura","Temperature"), QVariant(protbuf::Parameter_Config::TEMPERATURE));
    type->insertItem(type->count(),tr("Data","calendar date"), QVariant(protbuf::Parameter_Config::DATE));
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
        addMessage.mutable_config()->set_defaultvalue(ui->defaultValue->text().toStdString());

    if(ui->hasLimitedValue->isChecked()){
        addMessage.mutable_config()->set_maxvalue(ui->maxVal->value());
        addMessage.mutable_config()->set_minvalue(ui->minVal->value());
    }
    if(ui->hasLimitedLength->isChecked()){
        addMessage.mutable_config()->set_maxlength(ui->maxLength->value());
        addMessage.mutable_config()->set_minlength(ui->minLength->value());
    }
    addMessage.mutable_config()->set_type(ParameterConfig::INT); ///TODO consolidate index with data

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

void AddParameter::disableLabelWithBuddy(QLabel *l, bool disable){
    l->setDisabled(disable);
    if(l->buddy())
        l->buddy()->setDisabled(disable);
}

void AddParameter::enableLabelWithBuddy(QLabel *l, bool enable){
    disableLabelWithBuddy(l, !enable);
}

void AddParameter::on_parameterType_currentIndexChanged(int i)
{
    auto type = ui->parameterType->itemData(i).toInt();
    disableAll();

    if (type == protbuf::Parameter_Config::UINT){
        enableLayout(ui->default_hl);
        disableLabelWithBuddy(ui->default_l);
        enableLayout(ui->value_hl);
        disableLabelWithBuddy(ui->minVal_l);
        disableLabelWithBuddy(ui->maxVal_l);
        ui->minVal->setMinimum(0.0);
    }
    else if(type == protbuf::Parameter_Config::INT){
        enableLayout(ui->default_hl);
        disableLabelWithBuddy(ui->default_l);
        enableLayout(ui->value_hl);
        disableLabelWithBuddy(ui->minVal_l);
        disableLabelWithBuddy(ui->maxVal_l);
    }
    else if(type == protbuf::Parameter_Config::STRING){
        enableLayout(ui->default_hl);
        disableLabelWithBuddy(ui->default_l);
        enableLayout(ui->length_hl);
    }
    else if(type == protbuf::Parameter_Config::TEMPERATURE){
        enableLayout(ui->default_hl);
        disableLabelWithBuddy(ui->default_l);
    }
}

void AddParameter::on_parametersView_doubleClicked(const QModelIndex &index)
{
    disableAll();

    auto data = ui->parametersView->model()->itemData(index);
    Parameter p;
    ParameterConfig pc;
    pc.fromJSON(data.value(p.kConfigFieldNumber, "{}").toByteArray() );

    for(int i=0;i<ui->parameterType->count();i++){
        if(ui->parameterType->itemData(i).toInt() == pc.valueType()){
            ui->parameterType->setCurrentIndex(i);
            on_parameterType_currentIndexChanged(i);
            break;
        }
    }

    ui->name->setText(data.value(p.kNameFieldNumber, "").toString());
    ui->symbol->setText(data.value(p.kSymbolFieldNumber, "").toString());
    ui->description->setText(data.value(p.kDescriptionFieldNumber, "").toString());

    if(pc.has_maxlength()){
        ui->hasLimitedLength->setChecked(true);
        ui->maxLength->setValue(pc.maxlength());
        ui->minLength->setValue(pc.minlength());
    }
    if(pc.has_maxvalue()){
        ui->hasLimitedValue->setChecked(true);
        ui->maxVal->setValue(pc.maxvalue() );
        ui->minVal->setValue(pc.minvalue() );
    }
    if(pc.has_defaultvalue()){
        ui->hasDefault->setChecked(true);
        ui->defaultValue->setText(pc.defaultvalue());
    }

    enableLabelWithBuddy(ui->default_l, ui->hasDefault->isChecked());
    enableLabelWithBuddy(ui->minVal_l, ui->hasLimitedValue->isChecked() );
    enableLabelWithBuddy(ui->maxVal_l, ui->hasLimitedValue->isChecked() );
    ui->minVal->setMinimum(0.0);
}
