#include "statclass.h"

vector <QString> StatClass::GetVectStat(){

vector <QString> vectStat;
QSqlQuery query;
query.prepare("Select * from Employe");
query.exec();

while (query.next())
{
    vectStat.push_back(query.value(10).toString());
}
return vectStat;
}

