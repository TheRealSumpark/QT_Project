#include "gestion_joueur.h"
#include "Ajouter_joueur.h"
#include "afficher_joueur.h"
#include "supprimer_joueur.h"
#include "modifier_joueur.h"
#include "ui_gestion_joueur.h"
#include <QtWidgets>

gestion_joueur::gestion_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_joueur)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/projet77c.png");
     ui->label->setPixmap(pic);
}

gestion_joueur::~gestion_joueur()
{
    delete ui;
}

void gestion_joueur::on_Ajouter_joueur_clicked()
{
    Dialog d;


      d.exec();
}

void gestion_joueur::on_Afficher_joueur_clicked()
{
    Afficher_joueur a;


      a.exec();
}

void gestion_joueur::on_Supprimer_joueur_clicked()
{
Supprimer_joueur s;
s.exec();
}

void gestion_joueur::on_Modifier_joueur_clicked()
{
Modifier_joueur m;
m.exec();
}

void gestion_joueur::on_Afficher_joueur_2_clicked()
{
 this->close();
}
