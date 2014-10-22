#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>

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

    QWebSocket *getSocket() const;
    void setSocket(QWebSocket *ws);

public slots:
    void showAddGroup();
    void showAddParameter();

private:
    QWebSocket *socket;
    Ui::MainWindow *ui;

    AddGroup *addGroupWidget;
    AddParameter *addParameter;
};

#endif // MAINWINDOW_H
