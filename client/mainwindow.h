#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "addgroup.h"

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

private:
    Ui::MainWindow *ui;

    AddGroup *addGroupWidget;
};

#endif // MAINWINDOW_H
