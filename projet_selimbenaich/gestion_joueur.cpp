#include "gestion_joueur.h"
#include "Ajouter_joueur.h"
#include "afficher_joueur.h"
#include "supprimer_joueur.h"
#include "modifier_joueur.h"
#include "ui_gestion_joueur.h"
#include "mainwindow.h"
#include <QtWidgets>

gestion_joueur::gestion_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_joueur)
{
    ui->setupUi(this);
    QPixmap pic("../images_projet/projet77c.png");
     ui->label->setPixmap(pic);
     //ui->Afficher_joueur->hide();
}

gestion_joueur::~gestion_joueur()
{
    delete ui;
}

void gestion_joueur::on_Ajouter_joueur_clicked()
{
    this->close();
    Dialog d;


      d.exec();
}

void gestion_joueur::on_Afficher_joueur_clicked()
{
    //this->close();
    Afficher_joueur a;


      a.exec();
}

void gestion_joueur::on_Supprimer_joueur_clicked()
{
    this->close();
Supprimer_joueur s;
s.exec();
}

void gestion_joueur::on_Modifier_joueur_clicked()
{
    this->close();
Modifier_joueur m;
m.exec();
}

void gestion_joueur::on_Afficher_joueur_2_clicked()
{
     this->close();

        MainWindow *w=new MainWindow;
        w->show();


}
