#include "mainwindow.h"
#include "connexion.h"
#include "login.h"
#include "home.h"
#include <QApplication>
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    login l;
    home h;

   bool test=c.createconnect();

       if(test)
       {

         /*   QMessageBox::critical(nullptr, QObject::tr("database is open"),
                       QObject::tr("connection successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);*/
        h.show();








       }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);








    return a.exec();
}
