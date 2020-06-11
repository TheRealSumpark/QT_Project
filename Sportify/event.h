#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class event
{
    public :
        event();
        event(int);
        event(QString,QDate,QString,QString,int);
        QString get_name();
        QString get_goal();
        QString get_guestlist();
        int get_id();
        int get_budget();
        QDate get_date();
bool ajouter_event();

QSqlQueryModel * afficher_event();
QSqlQueryModel * trier_event();
 QSqlQueryModel * trier_event2();
QSqlQueryModel *chercher_event(int);
bool supprimer_event(int);
bool modifier_event(int,QString,QDate,QString,QString,int);

    private:
        int id,budget;
        QString name,goal,guestlist;
        QDate date;
};



#endif // EVENT_H
