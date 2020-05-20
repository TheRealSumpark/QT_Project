#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()

{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("khaled");//inserer nom de l'utilisateur
    db.setPassword("khaled");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;





        return  test;



}
void connexion::closeconnect()
{
    db.close();
}

