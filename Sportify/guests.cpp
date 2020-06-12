#include "guests.h"
#include <QSqlRecord>
#include <QDebug>
Guests::Guests()
{
    id =0;
    level_of_importance=0;
    name="";
    lastname="";
    job="";
    contacts="";

}
Guests::Guests(int idc){
    this->id=idc;
}
   Guests::Guests(int level_of_importance,QString name,QString lastname,QString contacts,QString job){

    this->level_of_importance=level_of_importance;
    this->name=name;
    this->lastname=lastname;
    this->contacts=contacts;
    this->job=job;
}
QString Guests::get_name(){return name;}
QString Guests::get_lastname(){return lastname;}
QString Guests::get_job(){return job;}
QString Guests::get_contacts(){return contacts;}
int Guests::get_id(){return id;}
int Guests::get_level_of_importance(){return level_of_importance;}

bool Guests::ajouter_guests(){
    QSqlQuery query;

    QString res1= QString::number(level_of_importance);

    query.prepare("INSERT INTO \"Sportify\".\"GUESTS\" (ID, level_of_importance ,name ,lastname ,job,contacts) VALUES (GUESTS_SEQ.NEXTVAL,:level_of_importance,:name,:lastname,:job,:contacts)");

     query.bindValue(":level_of_importance",res1);
       query.bindValue(":name",name);
    query.bindValue(":lastname",lastname);
    query.bindValue(":job",job);
      query.bindValue(":contacts",contacts);
    return query.exec();
}
QSqlQueryModel * Guests::afficher_guests()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from\"Sportify\".\"GUESTS\"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LEVEL_OF_IMPORTANCE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NAME"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LASTNAME"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("JOB"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CONTACTS"));

return model;
}


QSqlQueryModel * Guests::chercher_guests(int idd){
QSqlQuery q;
q.prepare("select * from \"Sportify\".\"GUESTS\" where ID=:idd");
q.bindValue(":idd", idd);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("LEVEL_OF_IMPORTANCE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NAME"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LASTNAME"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("JOB"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CONTACTS"));

QSqlRecord rec = model->record(0);
int id = rec.value("ID").toInt();
if( id == idd){
    return model;
  }
    return nullptr;
}

bool Guests::supprimer_guests(int idc)
{
QSqlQuery query;
QString ident1= QString::number(idc);
query.prepare("Delete from \"Sportify\".\"GUESTS\" where ID = :id ");
query.bindValue(":id",ident1);
return    query.exec();
}
bool Guests::modifier_guests(int id,int level_of_importance,QString name,QString lastname,QString contacts,QString job)
{



    QString res= QString::number(id);
    QString res1= QString::number(level_of_importance);
    QSqlQuery query;

    query.prepare("UPDATE \"Sportify\".\"GUESTS\" SET level_of_importance=:level, name=:name, lastname=:lastname,contacts=:contacts,job=:job WHERE ID = :id");

    query.bindValue(":level_of_importance",res1);
    query.bindValue(":name",name);
    query.bindValue(":lastname",lastname);
    query.bindValue(":contacts",contacts);
    query.bindValue(":job",job);

            return    query.exec();
}
