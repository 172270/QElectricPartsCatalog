#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QAbstractSocket>
#include <QWebSocket>

#include <QSharedPointer>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

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
    QWebSocket *m_socket;
    bool isConnected = false;
};

#endif // LOGINDIALOG_H
