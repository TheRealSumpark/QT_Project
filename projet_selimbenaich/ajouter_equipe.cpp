#include "ajouter_equipe.h"
#include "ui_ajouter_equipe.h"
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
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/714297.jpg");
     ui->label_ajout->setPixmap(pic);
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
}

void Ajouter_equipe::on_pushButton_2_clicked()
{
    this->close();
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


       qry.prepare("insert into EQUIPE (NOM_EQUIPE,TOTAL_JOUEUR,SCORE,CATEGORIE,MANAGER_EQ,IMAGE_EQUIPE) values('"+nom+"',0, :sco, '"+categorie+"', '"+manager+"', '"+image+"')");
         qry.bindValue(":sco", sco);

foreach(QLineEdit* le1, findChildren<QLineEdit*>()) {
if(le1->isModified())
    verif++;
}
if(verif>=3){

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
               break;
           case QMessageBox::Cancel:
              QMessageBox::critical(this,tr("Annuler"),tr("Vous pouvez modifier les données :)"));
               break;
           default:
               break;

         }
}
else{
  QMessageBox::critical(this,tr("Annuler"),tr("Tu n'arrivera pas a ajouter tant que les champs sont vides :("));
}
}
