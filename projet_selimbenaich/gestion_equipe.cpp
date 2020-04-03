#include "gestion_equipe.h"
#include "ajouter_equipe.h"
#include "afficher_equipe.h"
#include "supprimer_equipe.h"
#include "modifier_equipe.h"
#include "ajouter_joueur_equipe.h"
#include "ui_gestion_equipe.h"

gestion_equipe::gestion_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_equipe)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/projet77c.png");
     ui->label->setPixmap(pic);
}

gestion_equipe::~gestion_equipe()
{
    delete ui;
}

void gestion_equipe::on_Ajouter_equipe_clicked()
{
Ajouter_equipe a;
a.exec();
}

void gestion_equipe::on_Afficher_equipe_clicked()
{
afficher_equipe a;
a.exec();
}

void gestion_equipe::on_Supprimer_equipe_clicked()
{
supprimer_equipe s;
s.exec();
}

void gestion_equipe::on_Modifier_equipe_clicked()
{
modifier_equipe m;
m.exec();
}

void gestion_equipe::on_Afficher_equipe_2_clicked()
{
    this->close();
}

void gestion_equipe::on_Ajouter_equipe_2_clicked()
{
ajouter_joueur_equipe a;
a.exec();
}
