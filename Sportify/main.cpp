#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

#include "match_main.h"

#include "logo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


   // LOGO l;
    //l.show();


    return a.exec();
}
