#include "mainwindow.h"
#include "gestion_equipe.h"
#include "gestion_joueur.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
          QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/projet77c.png");
           ui->label->setPixmap(pic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Gestion_joueur_clicked()
{
gestion_joueur g;
g.exec();
}

void MainWindow::on_Modifier_joueur_clicked()
{
 gestion_equipe g;
 g.exec();
}
