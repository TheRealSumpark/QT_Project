#include "supprimer_joueur.h"
#include "ui_supprimer_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

Supprimer_joueur::Supprimer_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_joueur)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/714297.jpg");
    ui->label_sup->setPixmap(pic);
    QSqlQueryModel * Modal=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT * FROM JOUEUR");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_sup->setModel(Modal);
}

Supprimer_joueur::~Supprimer_joueur()
{
    delete ui;
}

void Supprimer_joueur::on_afficher_sup_activated(const QModelIndex &index)
{
QSqlDatabase db1;
QString val=ui->afficher_sup->model()->data(index).toString();
QSqlQuery qry;
QString filename;
ui->id_sup_8->clear();
qry.prepare("select * from JOUEUR WHERE ID_J='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' ");
if(qry.exec())
{
    while(qry.next())
    {
        ui->id_sup->setText(qry.value(0).toString());
        ui->id_sup_2->setText(qry.value(1).toString());
        ui->id_sup_3->setText(qry.value(2).toString());
        ui->id_sup_4->setText(qry.value(3).toString());
        ui->id_sup_5->setText(qry.value(4).toString());
        ui->id_sup_6->setText(qry.value(5).toString());
        ui->id_sup_7->setText(qry.value(6).toString());
        ui->id_sup_8->setText(qry.value(7).toString());
        filename=ui->id_sup_8->text();
        if (QString::compare(filename, QString())!=0)
        {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
          image=image.scaledToWidth(ui->id_sup_8->width(), Qt::SmoothTransformation);
         ui->id_sup_8->setPixmap(QPixmap::fromImage(image));
        }
                else{
        printf("erreur !");
        }
        }
    }
    db1.close();
    }
}

void Supprimer_joueur::Afficher_supp_j()
{
    QSqlDatabase db1;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT * FROM JOUEUR");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_sup->setModel(Modal);
     db1.close();
}

void Supprimer_joueur::on_pushButton_clicked()
{
    QSqlDatabase db1;

     QSqlQuery qry1,qry,qry2,qry3;
     QString val;

    val=ui->id_sup->text();

    if(val.isEmpty()){
      QMessageBox::critical(this,tr("Supprimer"),tr("Veuillez selectionner un joueur."));
    }

else{
     qry1.prepare("Delete from JOUEUR WHERE ID_J='"+val+"'");
    qry2.prepare("select * from CONTENIR where ID_JE='"+val+"'");
    qry.prepare("Delete from CONTENIR WHERE ID_JE='"+val+"'");



 if(qry1.exec())
 {
     if(qry2.exec())
     {
          while (qry2.next()){
         QString equipe=qry2.value(1).toString();

         if(qry.exec())
         {

            qry3.prepare("update EQUIPE set TOTAL_JOUEUR=TOTAL_JOUEUR-1 WHERE NOM_EQUIPE='"+equipe+"'");
             if(qry3.exec())
             {
         }
     }
}
 }
 QMessageBox::critical(this,tr("Supprimer"),tr("Supprimer avec succés"));
 db1.close();
 Afficher_supp_j();
 foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
 le->clear();
 }
 ui->id_sup_8->clear();
    }
    }
}

void Supprimer_joueur::on_pushButton_2_clicked()
{
this->close();
}
