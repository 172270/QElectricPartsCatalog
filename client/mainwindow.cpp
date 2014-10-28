#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addGroupWidget(new AddGroup),
    addParameter(new AddParameter),
    handler(new MessaheHandler(this))
{
    ui->setupUi(this);

    spinbox = new QScienceSpinBox();
    eSpinBox = new QEngineerSpinBox();
    spinbox->setValue(0);
    auto doubleSpinBox = new QDoubleSpinBox();
    auto doubleSpinBox2 = new QDoubleSpinBox();
    doubleSpinBox->setDecimals(20);
    doubleSpinBox->setMaximum(99999999999999999999999.0);
    doubleSpinBox->setMinimum(-99999999999999999999999.0);
    doubleSpinBox2->setDecimals(20);
    doubleSpinBox2->setMaximum(99999999999999999999999.0);
    doubleSpinBox2->setMinimum(-99999999999999999999999.0);

    connect(ui->actionAddGroup, SIGNAL(triggered()), this, SLOT(showAddGroup()));
    connect(ui->actionAddParameter, SIGNAL(triggered()), this, SLOT(showAddParameter()));

    connect(addParameter, SIGNAL(requestAvalible(MsgType,QByteArray)),
            handler, SLOT(queryMessage(MsgType,QByteArray)));
    connect(addParameter, SIGNAL(requestReady()),
            handler, SLOT(sendPandingMessages()));

    connect(handler, SIGNAL(recived_resAddParameter(QByteArray)),
            addParameter, SLOT(AddResponse(QByteArray)));
    connect(handler, SIGNAL(recived_resParameters(QByteArray)),
            addParameter, SLOT(SelectResponse(QByteArray)));

    connect(spinbox, SIGNAL(valueChanged(double)),
            doubleSpinBox, SLOT(setValue(double)));
    connect(doubleSpinBox, SIGNAL(valueChanged(double)),
            spinbox, SLOT(setValue(double)));
    connect(doubleSpinBox, SIGNAL(valueChanged(double)),
            eSpinBox, SLOT(setValue(double)));
    connect(eSpinBox, SIGNAL(valueChanged(double)),
            doubleSpinBox2, SLOT(setValue(double)));

    ui->layout->addWidget(spinbox);
    ui->layout->addWidget(doubleSpinBox);
    ui->layout->addWidget(eSpinBox);
    ui->layout->addWidget(doubleSpinBox2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddGroup()
{
    addGroupWidget->show();
}

void MainWindow::showAddParameter()
{
    addParameter->show();
}

QWebSocket *MainWindow::getSocket() const
{
    return handler->getSocket();
}

void MainWindow::setSocket(QWebSocket *ws)
{
    handler->setSocket(ws);
}
