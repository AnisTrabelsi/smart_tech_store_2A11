#include "mainwindow.h"
#include "connexion.h"
#include "client.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      connexion c;


    client cl;





    bool test=c.ouvrirconnexion();
     MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

















    w.show();
    return a.exec();
}
