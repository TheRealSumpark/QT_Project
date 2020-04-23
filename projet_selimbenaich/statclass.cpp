#include "statclass.h"

vector <QString> StatClass::GetVectStat(){

vector <QString> vectStat;
QSqlQuery query;
query.prepare("Select * from JOUEUR");
query.exec();

while (query.next())
{
    vectStat.push_back(query.value(6).toString());
}
return vectStat;
}

