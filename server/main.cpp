#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTcpSocket>
#include "qcatalogserver.h"


int keepassx_main_impl(int argc, char *argv[], int (*app_run)() )
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("ECatalog_server");
    QCoreApplication::setOrganizationName("BAPP");

    QFile *prog;
    QString *msg;

    prog = new QFile(argv [0]);
    msg = new QString();

    msg->append(QString::fromUtf8("Program ma wielkość "));
    msg->append(QString::number(prog->size()));
    msg->append(QString::fromUtf8(" bajtów, czyli "));
    msg->append(QString::number((double)prog->size()/1024));
    msg->append(QString::fromUtf8(" kilobajtów\n"));
    msg->append(QString::fromUtf8("Został skompilowany w dniu "));
    msg->append(__DATE__);
    msg->append(" o godzinie ");
    msg->append(__TIME__);
    msg->append("\nna kompilatorze GCC w wersji ");
    msg->append(__VERSION__);
    msg->append(QString::fromUtf8("\nkożystając z QT w wersji "));
    msg->append(QT_VERSION_STR);
    qDebug() << msg->toUtf8();

    delete prog;
    delete msg;

    QCatalogServer server;
    server.startServer();

    return app_run();
}

int qApp_exec(){
    return qApp->exec();
}

int keepassx_main(int argc, char** argv ){
    return keepassx_main_impl(argc,argv,qApp_exec);
}



