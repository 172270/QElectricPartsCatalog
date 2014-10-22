#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addGroupWidget(new AddGroup),
    addParameter(new AddParameter)
{
    ui->setupUi(this);

    connect(ui->actionAddGroup, SIGNAL(triggered()), this, SLOT(showAddGroup()));
    connect(ui->actionAddParameter, SIGNAL(triggered()), this, SLOT(showAddParameter()));
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
