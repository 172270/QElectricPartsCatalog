#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "addgroup.h"
#include "addparameter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showAddGroup();
    void showAddParameter();

private:
    Ui::MainWindow *ui;

    AddGroup *addGroupWidget;
    AddParameter *addParameter;
};

#endif // MAINWINDOW_H
