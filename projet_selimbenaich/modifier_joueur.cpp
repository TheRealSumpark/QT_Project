#include "modifier_joueur.h"
#include "ui_modifier_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

Modifier_joueur::Modifier_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier_joueur)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/714297.jpg");
     ui->label_modif->setPixmap(pic);
    QSqlQueryModel * Modal=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT * FROM JOUEUR");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
}

Modifier_joueur::~Modifier_joueur()
{
    delete ui;
}

void Modifier_joueur::on_afficher_modif_activated(const QModelIndex &index)
{
    QSqlDatabase db1;
    QString val=ui->afficher_modif->model()->data(index).toString();
    QSqlQuery qry;
    ui->id_sup_8->clear();
    qry.prepare("select * from JOUEUR WHERE ID_J='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->in_id->setText(qry.value(0).toString());
            ui->in_nom->setText(qry.value(1).toString());
            ui->in_prenom->setText(qry.value(2).toString());
            ui->in_poids->setValue(qry.value(3).toFloat());
            ui->in_taille->setValue(qry.value(4).toFloat());
            ui->in_number->setValue(qry.value(5).toInt());
            ui->in_date->setDate(qry.value(6).toDate());
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
    save_id=ui->in_id->text();
}

void Modifier_joueur::on_b_image_clicked()
{
    filename=QFileDialog::getOpenFileName(this, tr("choose"), "",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
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

void Modifier_joueur::on_pushButton_clicked()
{
    QSqlDatabase db1;
    QString nom,prenom,id,image;
    QDate datedenaissance;
    QSqlQuery qry,qry1;

    id=ui->in_id->text();
    nom=ui->in_nom->text();
    prenom=ui->in_prenom->text();
   datedenaissance=ui->in_date->date();
   image=filename;

    float poids=ui->in_poids->value();

    float taille = ui->in_taille->value();

    int numero=ui->in_number->text().toInt();

    QString num=QString::number(numero);
    QString tail=QString::number(taille);
    QString poid=QString::number(poids);

    if(id.isEmpty()){
      QMessageBox::critical(this,tr("Modifier"),tr("Veuillez Selectionner un joueur avant d'appliquer la modification."));
    }
    else {

       qry.prepare("update JOUEUR set ID_J='"+id+"',NOM='"+nom+"',PRENOM='"+prenom+"',POIDS=:poid,TAILLE=:tail,NUMERO='"+num+"',DATE_NAISSANCE=:date,IMAGE='"+image+"' where ID_J='"+save_id+"' ");
       qry1.prepare("update CONTENIR set ID_JE='"+id+"' where ID_JE='"+save_id+"' ");
         qry.bindValue(":tail", tail);
         qry.bindValue(":poid", poid);
         qry.bindValue(":date", datedenaissance);
   if(qry.exec( ))
   {
       QMessageBox::critical(this,tr("Modifier"),tr("Modifier avec succés."));
       if(qry1.exec( ))
       {
       db1.close();
   }
       Afficher_modif_j();
       foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
       }
       ui->id_sup_8->clear();
       ui->in_date->setDate( QDate::fromString( "01/01/2000", "dd/MM/yyyy" ) );
   }
    }
}

void Modifier_joueur::Afficher_modif_j()
{
    QSqlDatabase db1;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT * FROM JOUEUR");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
     db1.close();
}

void Modifier_joueur::on_pushButton_2_clicked()
{
 this->close();
}
