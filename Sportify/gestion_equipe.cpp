#include "gestion_equipe.h"
#include "ajouter_equipe.h"
#include "afficher_equipe.h"
#include "supprimer_equipe.h"
#include "modifier_equipe.h"
#include "mainwindow.h"
#include "ajouter_joueur_equipe.h"
#include "ui_gestion_equipe.h"

gestion_equipe::gestion_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_equipe)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/Sportify.png)");
   // QPixmap pic("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/projet77c.png");
    // ui->label->setPixmap(pic);
     ui->Afficher_equipe->hide();
}

gestion_equipe::~gestion_equipe()
{
    delete ui;
}

void gestion_equipe::on_Ajouter_equipe_clicked()
{
this->close();
Ajouter_equipe a;
a.exec();
}

void gestion_equipe::on_Afficher_equipe_clicked()
{
this->close();
afficher_equipe a;
a.exec();
}

void gestion_equipe::on_Supprimer_equipe_clicked()
{
this->close();
supprimer_equipe s;
s.exec();
}

void gestion_equipe::on_Modifier_equipe_clicked()
{
this->close();
modifier_equipe m;
m.exec();
}

void gestion_equipe::on_Ajouter_equipe_2_clicked()
{
this->close();
ajouter_joueur_equipe a;
a.exec();
}

void gestion_equipe::on_Afficher_equipe_2_clicked()
{
    this->close();
    MainWindow *w=new MainWindow;
    w->show();

}
