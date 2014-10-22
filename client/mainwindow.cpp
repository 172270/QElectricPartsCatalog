#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addGroupWidget(new AddGroup),
    addParameter(new AddParameter),
    handler(new MessaheHandler(this))
{
    ui->setupUi(this);

    connect(ui->actionAddGroup, SIGNAL(triggered()), this, SLOT(showAddGroup()));
    connect(ui->actionAddParameter, SIGNAL(triggered()), this, SLOT(showAddParameter()));

    connect(addParameter, SIGNAL(messageAvalible(MsgType,QByteArray)),
            handler, SLOT(sendBinaryMessage(MsgType,QByteArray)));
    connect(handler, SIGNAL(recived_resAddParameter(QByteArray)),
            addParameter, SLOT(responseRecived(QByteArray)));
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
