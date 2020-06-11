#include "event.h"
#include <QSqlRecord>
#include <QDebug>
event::event()
{
    id=0;
    budget=0;
    name="";
    goal="";
    guestlist="";

}


event::event(int idc)
{
this->id= idc;

}


event::event(QString name,QDate date,QString goal,QString guestlist,int budget)
{

    this->budget=budget;
    this->name=name;

    this->goal=goal;
    this->guestlist=guestlist;
    this->date=date;
}
QString event::get_name(){return name;}
QString event::get_goal(){return goal;}
QString event::get_guestlist(){return guestlist;}
QDate event::get_date(){return date;}
int event::get_id(){return id;}
int event::get_budget(){return budget;}

bool event::ajouter_event(){
    QSqlQuery query;
    QString res2= date.toString("yyyy.MM.dd");
    QString res1= QString::number(budget);
    query.prepare("INSERT INTO EVENTS (ID, BUDGET ,GOAL ,DATE1,NAME,GUESTLIST) VALUES (EVENTS_SEQ.NEXTVAL,:budget,:goal,:date,:name,:guestlist)");

    query.bindValue(":budget",res1);
    query.bindValue(":goal",goal);
    query.bindValue(":date",res2);
    query.bindValue(":name",name);
    query.bindValue(":guestlist",guestlist);


    return query.exec();
}
QSqlQueryModel * event::afficher_event()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from EVENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GOAL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE1"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NAME "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("GUESTLIST"));

return model;
}
QSqlQueryModel * event::chercher_event(int idd){
QSqlQuery q;
q.prepare("select * from EVENTS where ID=:idd");
q.bindValue(":idd", idd);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GOAL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE1"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NAME "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("GUESTLIST"));


QSqlRecord rec = model->record(0);
int id = rec.value("ID").toInt();
if( id == idd){
    return model;
  }
    return nullptr;
}

bool event::supprimer_event(int idc)
{
QSqlQuery query;
QString ident1= QString::number(idc);
query.prepare("Delete from EVENTS where ID = :id ");
query.bindValue(":id",ident1);
return    query.exec();
}



bool event::modifier_event(int id,QString name,QDate date,QString goal,QString guestlist,int budget)
{



    QString res2= date.toString("yyyy.MM.dd");
int idc=id;
    QString res1= QString::number(budget);
    QSqlQuery query;

    query.prepare("UPDATE EVENTS SET name =:NAME, BUDGET=:BUDGET, GOAL=:GOAL,DATE1=:DATE,GUESTLIST=:GOALLIST WHERE ID = :id");

    query.bindValue(":id",idc);

     query.bindValue(":budget",res1);

    query.bindValue(":goal",goal);
    query.bindValue(":date",res2);
    query.bindValue(":name",name);
      query.bindValue(":guestlist",guestlist);

            return    query.exec();

}


