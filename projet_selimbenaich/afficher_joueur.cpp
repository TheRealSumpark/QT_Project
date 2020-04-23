#include "afficher_joueur.h"
#include "ui_afficher_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include "gestion_joueur.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableWidget>
#include <QPrinter>
#include <QPrintDialog>
#include <QSortFilterProxyModel>
#include <QVector>

Afficher_joueur::Afficher_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher_joueur)
{
    ui->setupUi(this);
    QPixmap pic("../images_projet/projet77c.png");
     ui->label_affich->setPixmap(pic);
     //ui->customPlot->addGraph();
     QSqlDatabase db1;
     QSqlQueryModel * Modal=new  QSqlQueryModel();
     QSqlTableModel * Modal1=new QSqlTableModel;
      QSqlQuery qry;
      qry.prepare("SELECT * FROM JOUEUR");
      qry.exec();
      Modal->setQuery(qry);
      Modal1->setTable("JOUEUR");
      Modal1->select();
      QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
      m->setDynamicSortFilter(true);
      m->setSourceModel(Modal);
      ui->tableView->setModel(m);
      ui->tableView->setSortingEnabled(true);
      ui->tableView->hide();
      ui->pushButton->hide();
     /* ui->customPlot->xAxis->setLabel("DATE_NAISSANCE");
      ui->customPlot->yAxis->setLabel("NUMERO");
      QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
      dateTicker->setDateTimeFormat("dd/MM/yyyy hh:mm:ss");
      ui->customPlot->xAxis->setTicker(dateTicker);

      QVector<QCPGraphData> timeData(Modal1->rowCount());

      for(int i=0; i< Modal1->rowCount(); ++i){
          timeData[i].key = Modal1->index(i, Modal1->fieldIndex("DATE_NAISSANCE")).data().toDateTime().toTime_t();
          timeData[i].value = Modal1->index(i, Modal1->fieldIndex("ID_J")).data().toDouble();
      }

      double Tmin = (*std::min_element(timeData.begin(), timeData.end(),
                                      [](const QCPGraphData& x, const QCPGraphData& y)
      {  return x.key < y.key; })).key;
      double Tmax = (*std::max_element(timeData.begin(), timeData.end(),
                                      [](const QCPGraphData& x, const QCPGraphData& y)
      {  return x.key < y.key; })).key;

      double Ymin = (*std::min_element(timeData.begin(), timeData.end(),
                                      [](const QCPGraphData& x, const QCPGraphData& y)
      {  return x.value < y.value; })).value;

      double Ymax = (*std::max_element(timeData.begin(), timeData.end(),
                                      [](const QCPGraphData& x, const QCPGraphData& y)
      {  return x.value < y.value; })).value;

      ui->customPlot->xAxis->setRange(Tmin, Tmax);
      ui->customPlot->yAxis->setRange(Ymin, Ymax);
      ui->customPlot->graph(0)->data()->set(timeData);
      ui->customPlot->replot();*/

      QVector <double> x(100),y(100);

          vector <QString> vectStat;
          vectStat=statClass.GetVectStat();


          for (unsigned int i=0;i<vectStat.size();i++)
          {
              qDebug()<<vectStat[i];
          }

          int j=-1;


          for (unsigned int i=0;i<vectStat.size();i++)
                    {
                        j++;
                        y[j]=j;
                        QString timeString=vectStat[i];
                        QDateTime time=QDateTime::fromString(timeString,"yyyy-MM-ddThh:mm:ss");
                       qDebug()<<y[j];
                        x[j]=time.toTime_t();
                       // qDebug()<<x[j];
                    }
                    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
                    ui->customPlot->setInteraction(QCP::iRangeZoom, true);
                    ui->customPlot->addGraph();
                    ui->customPlot->graph(0)->setData(x,y);
                    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
                    ui->customPlot->xAxis->setDateTimeFormat("yyyy-MM-dd");
                    ui->customPlot->xAxis->setLabel("Date de Naissance");
                    ui->customPlot->yAxis->setLabel("ordre des joueurs");
                    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));
                    ui->customPlot->xAxis->setRange(x.first(),x.last());
                    ui->customPlot->yAxis->setRange(0,10);

      db1.close();
}

Afficher_joueur::~Afficher_joueur()
{
    delete ui;
}

void Afficher_joueur::on_pushButton_clicked()
{
    this->close();
    gestion_joueur g;
    g.exec();
}

void Afficher_joueur::on_tableView_activated(const QModelIndex &index)
{
    QSqlDatabase db1;
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_2->clear();
    qry.prepare("select * from JOUEUR WHERE ID_J='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->image_2->setText(qry.value(7).toString());
            QString filename_2=ui->image_2->text();
            if (QString::compare(filename_2, QString())!=0)
            {
            QImage image;
            bool valid = image.load(filename_2);
            if(valid)
            {
              image=image.scaledToWidth(ui->image_2->width(), Qt::SmoothTransformation);
             ui->image_2->setPixmap(QPixmap::fromImage(image));
            }
                    else{
            printf("erreur !");
            }
            }
        }
        db1.close();
        }
}
