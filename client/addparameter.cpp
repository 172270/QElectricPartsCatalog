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
