#ifndef STATCLASS_H
#define STATCLASS_H
#include <QString>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QDebug>
#include <QBuffer>
#include <QSqlQuery>
#include <QRegExp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <QStringListModel>
#include <QList>
#include <QListView>
#include "vector"
using namespace std;
class StatClass
{
public:
    vector <QString> GetVectStat();
};

#endif // STATCLASS_H
