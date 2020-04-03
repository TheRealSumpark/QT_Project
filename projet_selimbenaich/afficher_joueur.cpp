#include "afficher_joueur.h"
#include "ui_afficher_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

Afficher_joueur::Afficher_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher_joueur)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/projet77c.png");
     ui->label_affich->setPixmap(pic);
     QSqlDatabase db1;
     QSqlQueryModel * Modal=new  QSqlQueryModel();
      QSqlQuery qry;
      qry.prepare("SELECT * FROM JOUEUR order by DATE_NAISSANCE DESC");
      qry.exec();
      Modal->setQuery(qry);
      ui->tableView->setModel(Modal);
      db1.close();
}

Afficher_joueur::~Afficher_joueur()
{
    delete ui;
}

void Afficher_joueur::on_pushButton_clicked()
{
    this->close();
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
