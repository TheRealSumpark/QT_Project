#ifndef GUESTS_H
#define GUESTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class Guests
{
public:
    Guests();
    Guests(int);
    Guests(int,QString,QString,QString,QString);
    QString get_name();
    QString get_lastname();
    QString get_job();
    QString get_contacts();
    int get_id();
    int get_level_of_importance();
    bool ajouter_guests();
    bool modifier_guests(int,int,QString,QString,QString,QString);
    QSqlQueryModel * afficher_guests();
    QSqlQueryModel *chercher_guests(int);
    bool supprimer_guests(int);
    QSqlQueryModel * trier_guests();
     QSqlQueryModel * trier_guests2();
private:
   int  id,level_of_importance;
     QString name, lastname,job,contacts;




};

#endif // GUESTS_H
