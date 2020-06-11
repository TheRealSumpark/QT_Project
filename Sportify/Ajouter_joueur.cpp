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
    QPixmap pic("../images_projet/714297.jpg");
     ui->label_ajout->setPixmap(pic);
     PixTrueIcon=QPixmap("../Media_Player_Icons/True_icon.png");
     PixFalseIcon=QPixmap("../Media_Player_Icons/False_icon.png");

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
verifImage();
return filename;
}

void Dialog::on_Ajouter_joueur_clicked()
{
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

verifID();
verifImage();
verifNom();
verifPrenom();
verifdateNaissance();
verifPoids();
verifTaille();
verifNumero();
    if(verifID() && verifImage() && verifNom() && verifPrenom() && verifdateNaissance() && verifPoids() && verifTaille() && verifNumero()) {
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
       ui->in_poids->setValue(0.00);
       ui->in_taille->setValue(0.00);
       ui->in_number->setValue(0);
       ui->image_2->clear();
       ui->label_AgeControl->clear();
       ui->label_ProidsControl->clear();
       ui->label_TailleControl->clear();
       ui->label_NumeroControl->clear();
       ui->label_ImageControl->clear();
       ui->in_date->setDate( QDate::fromString( "01/01/2000", "dd/MM/yyyy" ) );
   }
   }
    else
 QMessageBox::critical(this,tr("Ajouter"),tr("Veuillez verifier les champs à saisir !"));
   }

void Dialog::on_pushButton_2_clicked()
{
    this->close();
    gestion_joueur g;
    g.exec();
}

bool Dialog::verifID(){
    if (ui->in_id->text().isEmpty() || ui->in_id->text().length()<3 || ui->in_id->text().contains(QRegExp("[^0-9]")))
    {
        ui->label_IDControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_IDControl->setPixmap(PixTrueIcon);
        return true;

    }
}

bool Dialog::verifImage(){
    if (!ui->image_2->pixmap()){
        ui->label_ImageControl->setPixmap(PixFalseIcon);
        return false;}
    else{
        ui->label_ImageControl->setPixmap(PixTrueIcon);
        return true;}
}

bool Dialog::verifPrenom()
{

    if (ui->in_prenom->text().contains(QRegExp("[^a-zA-Z ]")) || ui->in_prenom->text().isEmpty())
    {
        ui->label_PrenomControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_PrenomControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool Dialog::verifNom()
{

    if (ui->in_nom->text().contains(QRegExp("[^a-zA-Z ]")) || ui->in_nom->text().isEmpty())
    {
        ui->label_NomControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_NomControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool Dialog::verifdateNaissance()
{
    QDate legal=QDate::currentDate();
    if (legal.year()-ui->in_date->date().year()<=18)
    {
        ui->label_AgeControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_AgeControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool Dialog::verifPoids()
{
    if (ui->in_poids->value()<=0)
    {
        ui->label_ProidsControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_ProidsControl->setPixmap(PixTrueIcon);
        return true;
    }

}

bool Dialog::verifTaille()
{
    if (ui->in_taille->value()<=0)
    {
        ui->label_TailleControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_TailleControl->setPixmap(PixTrueIcon);
        return true;
    }

}

bool Dialog::verifNumero()
{
    if (ui->in_number->value()<=0)
    {
        ui->label_NumeroControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_NumeroControl->setPixmap(PixTrueIcon);
        return true;
    }

}

void Dialog::on_in_id_cursorPositionChanged(int arg1, int arg2)
{
if(!ui->in_id->text().isEmpty())
verifID();
else
ui->label_IDControl->clear();
}

void Dialog::on_in_prenom_cursorPositionChanged(int arg1, int arg2)
{
if(!ui->in_prenom->text().isEmpty())
verifPrenom();
else
ui->label_PrenomControl->clear();
}

void Dialog::on_in_nom_cursorPositionChanged(int arg1, int arg2)
{
if(!ui->in_nom->text().isEmpty())
verifNom();
else
ui->label_NomControl->clear();
}

void Dialog::on_in_date_userDateChanged(const QDate &date)
{
verifdateNaissance();
}

void Dialog::on_in_poids_valueChanged(double arg1)
{
verifPoids();
}

void Dialog::on_in_taille_valueChanged(double arg1)
{
verifTaille();
}

void Dialog::on_in_number_valueChanged(int arg1)
{
verifNumero();
}
