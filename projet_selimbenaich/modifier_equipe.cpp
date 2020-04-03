#include "modifier_equipe.h"
#include "ui_modifier_equipe.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

modifier_equipe::modifier_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_equipe)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/4026.jpg");
     ui->label_modif->setPixmap(pic);
     QPixmap pic1("C:/Users/selim/Projet c++/projet_selimbenaich/white_back.jpg");
      ui->label_6->setPixmap(pic1);
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlDatabase db1;
     QSqlQuery qry,qry1;
     qry.prepare("SELECT * FROM EQUIPE");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
    qry1.prepare("create table Contenir_temp (id_je Number not null)");
    qry1.exec();
    db1.close();
}

modifier_equipe::~modifier_equipe()
{
    delete ui;
}

void modifier_equipe::on_b_image_clicked()
{
    filename=QFileDialog::getOpenFileName(this, tr("choose"), "",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
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

void modifier_equipe::on_afficher_modif_activated(const QModelIndex &index)
{
    QSqlDatabase db1;
    QString val=ui->afficher_modif->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_1->clear();
    ui->image_2->clear();
    qry.prepare("select * from EQUIPE WHERE NOM_EQUIPE='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->in_nom->setText(qry.value(0).toString());
            ui->in_number->setValue(qry.value(1).toInt());
            ui->in_score->setValue(qry.value(2).toInt());
            ui->in_categorie->setText(qry.value(3).toString());
            ui->in_manager->setText(qry.value(4).toString());
            ui->image_2->setText(qry.value(5).toString());
            filename=ui->image_2->text();
            save_total_j=qry.value(1).toInt();
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
        QSqlQueryModel * Modal=new  QSqlQueryModel();
         QSqlQuery qry1;
         qry1.prepare("SELECT * FROM CONTENIR where NOM_EQ='"+val+"'");
         qry1.exec();
         Modal->setQuery(qry1);
         ui->afficher_modif_2->setModel(Modal);
        save_nom_equipe=ui->in_nom->text();
        db1.close();
        }

}

void modifier_equipe::on_afficher_modif_2_activated(const QModelIndex &index)
{
    calcul_erreur=0;
    QSqlDatabase db1;
    QString val=ui->afficher_modif_2->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_1->clear();
    qry.prepare("select * from JOUEUR WHERE ID_J='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->image_1->setText(qry.value(7).toString());
            save_id_joueur=qry.value(0).toString();
            QString filename_2=ui->image_1->text();
            if (QString::compare(filename_2, QString())!=0)
            {
            QImage image;
            bool valid = image.load(filename_2);
            if(valid)
            {
              image=image.scaledToWidth(ui->image_1->width(), Qt::SmoothTransformation);
             ui->image_1->setPixmap(QPixmap::fromImage(image));
            }
                    else{
            printf("erreur !");
            }
            }
        }
        db1.close();
        }
}

void modifier_equipe::on_pushButton_3_clicked()
{
verif_retirer=1;
QSqlDatabase db1;
QSqlQuery qry,qry2;
qry.prepare("insert into Contenir_temp values('"+save_id_joueur+"')");
qry2.prepare("select * from CONTENIR WHERE ID_JE='"+save_id_joueur+"'");
if(qry2.exec())
{
    while(qry2.next())
    {
if(save_id_joueur==qry2.value(0).toString()){
calcul_erreur++;
}
else{
 calcul_erreur--;
}
    }
}
if(calcul_erreur<2)
{
if(!save_id_joueur.isEmpty()){
qry.exec();
total_j++;
QMessageBox::critical(this,tr("Ajouter"),tr("succés.\nNous vous recommandons d'appliquer sinon compléter."));
db1.close();
}
else{
   QMessageBox::critical(this,tr("Ajouter"),tr("Vérifier que vous avez déjà séléctionner un joueur !"));
db1.close();
}
}
else{
 QMessageBox::critical(this,tr("Ajouter"),tr("Vous avez séléctionner le méme joueur plusieurs fois !"));
db1.close();
}
}

void modifier_equipe::on_Annuler_clicked()
{
    verif_annuler=1;
    QSqlDatabase db1;
    QSqlQuery qry,qry1;
    QString verif="CONTENIR_TEMP";
    qry1.prepare("SELECT * FROM DBA_TABLES WHERE TABLE_NAME ='"+verif+"'");
   qry.prepare("drop table Contenir_temp ");
    if(verif_retirer==1){

   if(qry1.exec()){
   qry.exec();
   db1.close();
   this->close();
   }
   else
   {
       printf("a la prochaine :)");
       this->close();

   }
    }
    else{
        qry.exec();
        db1.close();
       this->close();
    }
}

void modifier_equipe::on_modifier_equipe_finished(int result)
{
    QSqlDatabase db1;
    QSqlQuery qry,qry1;
    QString verif="CONTENIR_TEMP";
    qry1.prepare("SELECT * FROM DBA_TABLES WHERE TABLE_NAME ='"+verif+"'");
   qry.prepare("drop table CONTENIR_TEMP ");
   if(verif_annuler==0){
    if(verif_retirer==1){

   if(qry1.exec()){
       /*while(qry1.next())
       {
       verif=qry1.value(2).toString();
       qDebug()<<verif;
       }*/
       //if(verif=="CONTENIR_TEMP")
   qry.exec();
   db1.close();
   this->close();
   }
  else
   {
       printf("a la prochaine :)");
       this->close();

   }
    }

    else{
        qry.exec();
        db1.close();
       this->close();
    }
    }
}

void modifier_equipe::on_Appliquer_modification_clicked()
{
    QSqlDatabase db1;
    QSqlQuery qry,qry1,qry2,qry3,qry4;
    QString nom,categorie,manager,image;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QString total=QString::number(total_j);

    QString val;
    val=ui->in_nom->text();
    if(val.isEmpty()){
      QMessageBox::critical(this,tr("Modifier"),tr("Veuillez Selectionner une équipe avant d'appliquer la modification."));
    }
   else{

    qry.prepare("DELETE FROM CONTENIR WHERE EXISTS ( SELECT * FROM CONTENIR_TEMP WHERE CONTENIR_TEMP.ID_JE = CONTENIR.ID_JE )");
    qry1.prepare("update EQUIPE set TOTAL_JOUEUR=TOTAL_JOUEUR-'"+total+"' where NOM_EQUIPE='"+save_nom_equipe+"'");

    categorie=ui->in_categorie->text();
    nom=ui->in_nom->text();
    manager=ui->in_manager->text();

   image=filename;
    int score=ui->in_score->text().toInt();

    QString sco=QString::number(score);
    QString total_sans_ret=QString::number(save_total_j);

       qry3.prepare("update  EQUIPE set NOM_EQUIPE='"+nom+"' ,TOTAL_JOUEUR='"+total_sans_ret+"' ,SCORE=:sco ,CATEGORIE='"+categorie+"' ,MANAGER_EQ='"+manager+"' ,IMAGE_EQUIPE='"+image+"' where NOM_EQUIPE='"+save_nom_equipe+"' ");
        qry4.prepare("update  CONTENIR set NOM_EQ='"+nom+"' where NOM_EQ='"+save_nom_equipe+"' ");
         qry3.bindValue(":sco", sco);


    //qry.bindValue(":total", total_j);

     qry2.prepare("SELECT * FROM CONTENIR where NOM_EQ='"+save_nom_equipe+"'");
      if(verif_retirer==1){
   if(qry.exec()){
       qry3.exec();
       qry4.exec();
       qry1.exec();
        qry2.exec();
        Modal->setQuery(qry2);
        ui->afficher_modif_2->setModel(Modal);
        Afficher_modif_eq();
        QMessageBox::critical(this,tr("Ajouter"),tr("Modifier avec succés"));
         db1.close();
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
        le->clear();
        }
        ui->image_2->clear();
        ui->image_1->clear();
 }
   total_j=0;
      }
      else{
               if(qry3.exec( ))
               {
                   qry4.exec();
                   qry2.exec();
                   Modal->setQuery(qry2);
                   ui->afficher_modif_2->setModel(Modal);
                   Afficher_modif_eq();
                   QMessageBox::critical(this,tr("Ajouter"),tr("Modifier avec succés"));
                   db1.close();
                   foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                   le->clear();
                   }
                   ui->image_2->clear();
                   ui->image_1->clear();
               }
 }
}
}

void modifier_equipe::Afficher_modif_eq()
{
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlDatabase db1;
     QSqlQuery qry;
     qry.prepare("SELECT * FROM EQUIPE");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
    db1.close();
}
