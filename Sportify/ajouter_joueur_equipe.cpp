#include "ajouter_joueur_equipe.h"
#include "ui_ajouter_joueur_equipe.h"
#include "gestion_equipe.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QComboBox>

ajouter_joueur_equipe::ajouter_joueur_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_joueur_equipe)
{
    ui->setupUi(this);
    QPixmap pic("../images_projet/projet77c.png");
     ui->label_ajout->setPixmap(pic);
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlQueryModel * Modal1=new  QSqlQueryModel();
     QSqlQuery qry,qry1;
     qry.prepare("SELECT NOM FROM \"Sportify\".\"JOUEUR\" WHERE ID_J NOT IN (SELECT ID_JE FROM \"Sportify\".\"CONTENIR\") ");
     qry1.prepare("SELECT NOM_EQUIPE FROM \"Sportify\".\"EQUIPE\"");
     qry.exec();
     qry1.exec();
     Modal->setQuery(qry);
     Modal1->setQuery(qry1);
     ui->comboBox_joueur->setModel(Modal);
     ui->comboBox_equipe->setModel(Modal1);
     ui->comboBox_joueur->setCurrentIndex(-1);
     ui->comboBox_equipe->setCurrentIndex(-1);
     foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
     le->clear();
     }
     ui->image_2->clear();
     ui->image_3->clear();
}

ajouter_joueur_equipe::~ajouter_joueur_equipe()
{
    delete ui;
}

void ajouter_joueur_equipe::on_comboBox_joueur_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase db1;
    QString val=ui->comboBox_joueur->currentText();
    QSqlQuery qry;
    qry.prepare("select * from \"Sportify\".\"JOUEUR\" WHERE NOM='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->list_j_id->setText(qry.value(0).toString());
            ui->list_j_nom->setText(qry.value(1).toString());
            ui->list_j_prenom->setText(qry.value(2).toString());
            ui->image_2->setText(qry.value(7).toString());
            save_number=qry.value(5).toInt();
            QString filename=ui->image_2->text();
            if (QString::compare(filename, QString())!=0)
            {
            QImage image;
            bool valid = image.load(filename);
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

void ajouter_joueur_equipe::on_comboBox_equipe_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase db1;
    QString val=ui->comboBox_equipe->currentText();
    QSqlQuery qry;
    qry.prepare("select * from \"Sportify\".\"EQUIPE\" WHERE NOM_EQUIPE='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->list_e_nom->setText(qry.value(0).toString());
            ui->liste_e_manager->setText(qry.value(4).toString());
            ui->image_3->setText(qry.value(5).toString());
            QString filename=ui->image_3->text();
            if (QString::compare(filename, QString())!=0)
            {
            QImage image;
            bool valid = image.load(filename);
            if(valid)
            {
              image=image.scaledToWidth(ui->image_3->width(), Qt::SmoothTransformation);
             ui->image_3->setPixmap(QPixmap::fromImage(image));
            }
                    else{
            printf("erreur !");
            }
            }

        }
        db1.close();
        }
}

void ajouter_joueur_equipe::on_pushButton_2_clicked()
{
    this->close();
    gestion_equipe g;
    g.exec();
}

void ajouter_joueur_equipe::on_Ajouter_joueur_equipe_clicked()
{
    int s=0,verif=0;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlQueryModel * Modal1=new  QSqlQueryModel();
    QString nom_equipe,id_joueur;
    nom_equipe=ui->list_e_nom->text();
    id_joueur=ui->list_j_id->text();
    QSqlDatabase db1;
    QSqlQuery qry,qry1,qry2,qry3,qry_bonus;

        if(nom_equipe.isEmpty()){
          QMessageBox::critical(this,tr("Appliquer"),tr("Veuillez séléctionner une équipe."));
        }
       else if(id_joueur.isEmpty()){
          QMessageBox::critical(this,tr("Applique"),tr("Veuillez séléctionner un joueur."));
        }
        else {
    qry_bonus.prepare(" select j.* from \"Sportify\".\"JOUEUR\" j, \"Sportify\".\"CONTENIR\" c where j.id_j=c.id_je and c.nom_eq='"+nom_equipe+"' ");
    qry.prepare("insert into \"Sportify\".\"CONTENIR\" (ID_JE,NOM_EQ) select j.ID_J,e.NOM_EQUIPE from \"Sportify\".\"JOUEUR\" j,\"Sportify\".\"EQUIPE\" e where j.ID_J='"+id_joueur+"' and e.NOM_EQUIPE='"+nom_equipe+"' ");
    qry1.prepare("update \"Sportify\".\"EQUIPE\" set TOTAL_JOUEUR=TOTAL_JOUEUR+1 where NOM_EQUIPE='"+nom_equipe+"'");
    qry2.prepare("SELECT NOM FROM \"Sportify\".\"JOUEUR\" WHERE ID_J NOT IN (SELECT ID_JE FROM \"Sportify\".\"CONTENIR\") ");
    qry3.prepare("SELECT NOM_EQUIPE FROM \"Sportify\".\"EQUIPE\"");

if(qry_bonus.exec())
{
    while(qry_bonus.next())
    {
        s=qry_bonus.value(5).toInt();
        if(s==save_number){
          verif++;
        }

    }
}
if(verif==0)
{
if(qry.exec( ))
{
QMessageBox::critical(this,tr("Ajouter"),tr("Ajouter avec succés."));
if(qry1.exec( ))
{
qry2.exec();
 qry3.exec();
 Modal->setQuery(qry2);
 Modal1->setQuery(qry3);
 ui->comboBox_joueur->setModel(Modal);
 ui->comboBox_equipe->setModel(Modal1);
ui->comboBox_joueur->setCurrentIndex(-1);
ui->comboBox_equipe->setCurrentIndex(-1);
foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
le->clear();
}
ui->image_2->clear();
ui->image_3->clear();
db1.close();
}
}
}
else {
QMessageBox::critical(this,tr("Ajouter"),tr("Le numéro, comme le joueur, est unique.\nVérifier qu'il n'est pas doublé dans l'équipe %1.\nOu bien modifier la valeur. :)").arg(nom_equipe));
}

}
}
