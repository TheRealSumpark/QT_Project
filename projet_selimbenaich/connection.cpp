#include "connection.h"
#include<QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{
 bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("test");
db.setUserName("selim");//inserer nom de l'utilisateur
db.setPassword("speaky");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

else
    qDebug()<< db.lastError().text();



    return  test;
}

/*void Connection::conneclose()
{
QSqlDatabase db;
db.close();
db.removeDatabase(QSqlDatabase::defaultConnection);

}*/
