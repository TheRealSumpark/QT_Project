#include "modifier_equipe.h"
#include "ui_modifier_equipe.h"
#include "gestion_equipe.h"
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
     ui->hide->hide();
    QPixmap pic("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/4026.jpg");
     ui->label_modif->setPixmap(pic);
     QPixmap pic1("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/white_back.jpg");
      ui->label_6->setPixmap(pic1);
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlDatabase db1;
     QSqlQuery qry,qry1;
     qry.prepare("SELECT * FROM \"Sportify\".\"EQUIPE\"");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
     ui->afficher_modif->setColumnHidden(1,true);
     ui->afficher_modif->setColumnHidden(2,true);
     ui->afficher_modif->setColumnHidden(3,true);
     ui->afficher_modif->setColumnHidden(4,true);
     ui->afficher_modif->setColumnHidden(5,true);
    qry1.prepare("create table \"Sportify\".\"Contenir_temp\" (id_je Number not null)");
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
    QSqlQuery qry,qry1;
    QString id_joeur_fadit;
    test_retire=0;
    ui->image_1->clear();
    save_id_joueur="";
    qry.prepare("select * from \"Sportify\".\"EQUIPE\" WHERE NOM_EQUIPE='"+val+"'");
   qry1.prepare("select C.NOM_EQ from \"Sportify\".\"Contenir_temp\" CO,\"Sportify\".\"CONTENIR\" C WHERE C.id_je=CO.id_je");
    if(qry.exec())
    {
        while(qry.next())
        {
             ui->hide->setText(qry.value(0).toString());
                if(qry1.exec())
                {
                    while(qry1.next())
                    {
                        id_joeur_fadit=qry1.value(0).toString();
                        if(id_joeur_fadit==ui->hide->text()){
            appl_equipe=0;
            ui->image_2->clear();
                        }
                        else
                             appl_equipe=1;

                    }
                }
            if(!appl_equipe)
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
        QSqlQueryModel * Modal=new  QSqlQueryModel();
         QSqlQuery qry1;
         qry1.prepare("SELECT * FROM \"Sportify\".\"CONTENIR\" where NOM_EQ='"+val+"'");
         qry1.exec();
         Modal->setQuery(qry1);
         ui->afficher_modif_2->setModel(Modal);
         ui->afficher_modif_2->setColumnHidden(1,true);
        save_nom_equipe=ui->in_nom->text();
        db1.close();
         }
        else{
          QMessageBox::critical(this,tr("Modifier"),tr("Veuillez appliquer la modification avant d'aller vers une autre equipe !"));
          ui->afficher_modif->clearSelection();

          QAbstractItemModel *modl = ui->afficher_modif->model();
          QSortFilterProxyModel proxy;
          proxy.setSourceModel(modl);
          proxy.setFilterKeyColumn(0);
          proxy.setFilterFixedString(save_nom_equipe);
          QModelIndex matchingIndex = proxy.mapToSource(proxy.index(0,0));
          int row=matchingIndex.row();

          ui->afficher_modif->scrollTo( ui->afficher_modif->model()->index(row,0) );
          ui->afficher_modif->selectionModel()->select(matchingIndex, QItemSelectionModel::Select);
        }
        }
    }
}

void modifier_equipe::on_afficher_modif_2_activated(const QModelIndex &index)
{
    test_retire=0;
    QSqlDatabase db1;
    QString val=ui->afficher_modif_2->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_1->clear();
    qry.prepare("select * from \"Sportify\".\"JOUEUR\" WHERE ID_J='"+val+"'");
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
QString test_id;
QSqlQuery qry,qry2,qry3;
qry.prepare("insert into \"Sportify\".\"Contenir_temp\" values('"+save_id_joueur+"')");
qry2.prepare("select * from \"Sportify\".\"CONTENIR\" WHERE ID_JE='"+save_id_joueur+"'");
qry3.prepare("select id_je from \"Sportify\".\"Contenir_temp\" WHERE id_je='"+save_id_joueur+"'");
if(qry3.exec())
{
while(qry3.next())
       {
 if(save_id_joueur==qry3.value(0).toString())
 {
 test_retire++;
 }
}
 }
if(test_retire>=1){
    QMessageBox::critical(this,tr("Retirer"),tr("Vous avez retirer le méme joueur plusieurs fois !"));
    appl_equipe=1;
   db1.close();
}

if(test_retire==0)
{
if(!save_id_joueur.isEmpty()){
qry.exec();
total_j++;
QMessageBox::critical(this,tr("Retirer"),tr("succés.\nNous vous recommandons d'appliquer sinon compléter."));
appl_equipe=1;
db1.close();
}
else{
   QMessageBox::critical(this,tr("Retirer"),tr("Vérifier que vous avez déjà séléctionner un joueur !"));
db1.close();
}
}
}

void modifier_equipe::on_Annuler_clicked()
{
    verif_annuler=1;
    QSqlDatabase db1;
    gestion_equipe g;
    QSqlQuery qry,qry1;
    QString verif="\"Sportify\".\"Contenir_temp\"";
    qry1.prepare("SELECT * FROM DBA_TABLES WHERE TABLE_NAME ='"+verif+"'");
   qry.prepare("drop table \"Sportify\".\"Contenir_temp\" ");
    if(verif_retirer==1)
{
   if(qry1.exec()){
   qry.exec();
   db1.close();
   this->close();
   g.exec();
   }
   else
   {
       printf("a la prochaine :)");
       this->close();
       g.exec();

   }
    }
    else{
        qry.exec();
        db1.close();
       this->close();
        g.exec();
    }
}

void modifier_equipe::on_modifier_equipe_finished(int result)
{
    QSqlDatabase db1;
    QSqlQuery qry,qry1;
    QString verif="\"Sportify\".\"Contenir_temp\"";
    qry1.prepare("SELECT * FROM DBA_TABLES WHERE TABLE_NAME ='"+verif+"'");
   qry.prepare("drop table \"Sportify\".\"Contenir_temp\" ");
   if(verif_annuler==0){
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
}

void modifier_equipe::on_Appliquer_modification_clicked()
{
    QSqlDatabase db1;
    QSqlQuery qry,qry1,qry2,qry3,qry4,qry5;
    QString nom,categorie,manager,image;
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlQueryModel * vide=new  QSqlQueryModel();
    QString total=QString::number(total_j);
//qry5.prepare("select C.NOM_EQ from \"Sportify\".\"Contenir_temp\" CO,CONTENIR C WHERE CO.ID_JE=C.id_je");

//if(qry5.exec())
//{
   // while(qry5.next())
    //{
        //save_nom_equipe=qry2.value(0).toString();
    QString val;
    val=ui->in_nom->text();
    if(val.isEmpty()){
      QMessageBox::critical(this,tr("Modifier"),tr("Veuillez Selectionner une équipe avant d'appliquer la modification."));
    }
   else{
    appl_equipe=0;
    qry.prepare("DELETE FROM \"Sportify\".\"CONTENIR\" WHERE EXISTS ( SELECT * FROM \"Sportify\".\"Contenir_temp\" WHERE \"Sportify\".\"Contenir_temp\".ID_JE = CONTENIR.ID_JE )");
    qry1.prepare("update \"Sportify\".\"EQUIPE\" set TOTAL_JOUEUR=TOTAL_JOUEUR-'"+total+"' where NOM_EQUIPE='"+save_nom_equipe+"'");

    categorie=ui->in_categorie->text();
    nom=ui->in_nom->text();
    manager=ui->in_manager->text();

   image=filename;
    int score=ui->in_score->text().toInt();

    QString sco=QString::number(score);
    QString total_sans_ret=QString::number(save_total_j);

       qry3.prepare("update  \"Sportify\".\"EQUIPE\" set NOM_EQUIPE='"+nom+"' ,TOTAL_JOUEUR='"+total_sans_ret+"' ,SCORE=:sco ,CATEGORIE='"+categorie+"' ,MANAGER_EQ='"+manager+"' ,IMAGE_EQUIPE='"+image+"' where NOM_EQUIPE='"+save_nom_equipe+"' ");
        qry4.prepare("update  \"Sportify\".\"CONTENIR\" set NOM_EQ='"+nom+"' where NOM_EQ='"+save_nom_equipe+"' ");
         qry3.bindValue(":sco", sco);


    //qry.bindValue(":total", total_j);

     qry2.prepare("SELECT * FROM \"Sportify\".\"CONTENIR\" where NOM_EQ='"+save_nom_equipe+"'");
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
        ui->afficher_modif_2->setModel(vide);
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
                   QMessageBox::critical(this,tr("Modifier"),tr("Modifier avec succés"));
                   db1.close();
                   foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                   le->clear();
                   }
                   ui->afficher_modif_2->setModel(vide);
                   ui->image_2->clear();
                   ui->image_1->clear();
               }
 }
      total_j=0;
}
// }
//}
}

void modifier_equipe::Afficher_modif_eq()
{
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlDatabase db1;
     QSqlQuery qry;
     qry.prepare("SELECT * FROM \"Sportify\".\"EQUIPE\"");
     qry.exec();
     Modal->setQuery(qry);
     ui->afficher_modif->setModel(Modal);
    db1.close();
}
