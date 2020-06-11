#include "ajouter_equipe.h"
#include "ui_ajouter_equipe.h"
#include "gestion_equipe.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>

Ajouter_equipe::Ajouter_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_equipe)
{
    ui->setupUi(this);
    QPixmap pic("../images_projet/714297.jpg");
     ui->label_ajout->setPixmap(pic);
     PixTrueIcon=QPixmap("../Media_Player_Icons/True_icon.png");
     PixFalseIcon=QPixmap("../Media_Player_Icons/False_icon.png");
}

Ajouter_equipe::~Ajouter_equipe()
{
    delete ui;
}

void Ajouter_equipe::on_b_image_clicked()
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
}

void Ajouter_equipe::on_pushButton_2_clicked()
{
    this->close();
    gestion_equipe g;
    g.exec();
}

void Ajouter_equipe::on_Ajouter_equipe_2_clicked()
{
    QSqlDatabase db1;
    QString nom,categorie,manager,image;
    QSqlQuery qry;

    categorie=ui->in_categorie->text();
    nom=ui->in_nom->text();
    manager=ui->in_manager->text();

   image=filename;

    int score=ui->in_score->text().toInt();

    QString sco=QString::number(score);


       qry.prepare("insert into \"Sportify\".\"EQUIPE\" (NOM_EQUIPE,TOTAL_JOUEUR,SCORE,CATEGORIE,MANAGER_EQ,IMAGE_EQUIPE) values('"+nom+"',0, :sco, '"+categorie+"', '"+manager+"', '"+image+"')");
         qry.bindValue(":sco", sco);

verifNom();
verifCategorie();
verifManager();
verifScore();
verifImage();
if(verifNom() && verifCategorie() && verifManager() && verifScore() && verifImage()){

    QMessageBox msgBox;
    msgBox.setText("The sports team has been added.");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
         switch (ret) {
           case QMessageBox::Save:
             qry.exec();
                 QMessageBox::critical(this,tr("Ajouter"),tr("Ajouter avec succés"));
                 db1.close();
                 foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                 le->clear();
                 }
                 ui->image_2->clear();
                 ui->label_NomControl->clear();
                 ui->label_CategorieControl->clear();
                 ui->label_ManagerControl->clear();
                 ui->label_ImageControl->clear();
                 ui->in_score->setValue(0);
               break;
           case QMessageBox::Cancel:
              QMessageBox::critical(this,tr("Annuler"),tr("Vous pouvez modifier les données :)"));
               break;
           default:
               break;

         }
}
else{
  QMessageBox::critical(this,tr("Annuler"),tr("Veuillez verifier les champs à saisir !"));
}
}


bool Ajouter_equipe::verifNom()
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

bool Ajouter_equipe::verifCategorie()
  {

      if (ui->in_categorie->text().contains(QRegExp("[^a-zA-Z ]")) || ui->in_categorie->text().isEmpty())
      {
          ui->label_CategorieControl->setPixmap(PixFalseIcon);
          return false;
      }
      else
      {
          ui->label_CategorieControl->setPixmap(PixTrueIcon);
          return true;
      }
  }

bool Ajouter_equipe::verifManager()
  {

      if (ui->in_manager->text().contains(QRegExp("[^a-zA-Z ]")) || ui->in_manager->text().isEmpty())
      {
          ui->label_ManagerControl->setPixmap(PixFalseIcon);
          return false;
      }
      else
      {
          ui->label_ManagerControl->setPixmap(PixTrueIcon);
          return true;
      }
  }

bool Ajouter_equipe::verifImage(){
    if (!ui->image_2->pixmap()){
        ui->label_ImageControl->setPixmap(PixFalseIcon);
        return false;}
    else{
        ui->label_ImageControl->setPixmap(PixTrueIcon);
        return true;}
}

bool Ajouter_equipe::verifScore()
{
    if (ui->in_score->value()<=0)
    {
        ui->label_ScoreControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_ScoreControl->setPixmap(PixTrueIcon);
        return true;
    }

}

void Ajouter_equipe::on_in_nom_cursorPositionChanged(int arg1, int arg2)
{
    if(!ui->in_nom->text().isEmpty())
    verifNom();
    else
    ui->label_NomControl->clear();
}

void Ajouter_equipe::on_in_categorie_cursorPositionChanged(int arg1, int arg2)
{
    if(!ui->in_categorie->text().isEmpty())
    verifCategorie();
    else
    ui->label_NomControl->clear();
}

void Ajouter_equipe::on_in_manager_cursorPositionChanged(int arg1, int arg2)
{
    if(!ui->in_categorie->text().isEmpty())
    verifManager();
    else
    ui->label_NomControl->clear();
}

void Ajouter_equipe::on_in_score_valueChanged(int arg1)
{
verifScore();
}
