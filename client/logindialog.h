#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QAbstractSocket>
#include <QWebSocket>

#include "DB_schema/user.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void readyRead(QByteArray msg);
signals:
    void loginOk();
    void loginFailure();
private:
    Ui::LoginDialog *ui;
    QSettings setup;

private slots:
    void doConnectTest();
    void doReconnect();
    void doLogin();
private:
    User user;
    QWebSocket *m_socket;
};

#endif // LOGINDIALOG_H
