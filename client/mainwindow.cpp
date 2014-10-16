#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addGroupWidget(new AddGroup)
{
    ui->setupUi(this);

    connect(ui->actionAddGroup, SIGNAL(triggered()), this, SLOT(showAddGroup()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddGroup()
{
    ///TODO connect not existing "recive message" fignals to slots
    /// e.g. "got new parameters" signal to addGroup Widget
    addGroupWidget->show();
}
