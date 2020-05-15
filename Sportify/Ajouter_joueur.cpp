#include "Ajouter_joueur.h"
#include "ui_Ajouter_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include "gestion_joueur.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/714297.jpg");
     ui->label_ajout->setPixmap(pic);

}

Dialog::~Dialog()
{
    delete ui;
}
QString Dialog::on_b_image_clicked()
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
return filename;
}

void Dialog::on_Ajouter_joueur_clicked()
{
    verif=0;
    QSqlDatabase db1;
    QString nom,prenom,id,image;
    QDate datedenaissance;
    QSqlQuery qry;
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

    foreach(QLineEdit* le1, findChildren<QLineEdit*>()) {
    if(le1->isModified())
        verif++;
    }

    if(verif<3){
      QMessageBox::critical(this,tr("Ajouter"),tr("les champs id,nom,prenom sont obligatoires."));
    }

    else {
       qry.prepare("insert into \"Sportify\".\"JOUEUR\" (ID_J,NOM,PRENOM,POIDS,TAILLE,NUMERO,DATE_NAISSANCE,IMAGE) values('"+id+"','"+nom+"','"+prenom+"', :poid, :tail,'"+num+"', :date,'"+image+"')");
         qry.bindValue(":tail", tail);
         qry.bindValue(":poid", poid);
         qry.bindValue(":date", datedenaissance);
   if(qry.exec( ))
   {
       QMessageBox::critical(this,tr("Ajouter"),tr("Ajouter avec succés"));
       db1.close();
       foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
       }
       ui->image_2->clear();
       ui->in_date->setDate( QDate::fromString( "01/01/2000", "dd/MM/yyyy" ) );
   }
   }
   }

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    gestion_joueur g;
    g.exec();
}
