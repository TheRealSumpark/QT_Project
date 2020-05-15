#include "modifier_joueur.h"
#include "mainwindow.h"
#include "ui_modifier_joueur.h"
#include <QtWidgets>
#include "connection.h"
#include "gestion_joueur.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QSqlTableModel>

Modifier_joueur::Modifier_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier_joueur)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/714297.jpg");
     ui->label_modif->setPixmap(pic);
     ui->in_id->hide();
     Db_Afficher_Liste_Matchs();
}

Modifier_joueur::~Modifier_joueur()
{
    delete ui;
}

void Modifier_joueur::on_b_image_clicked()
{
    filename=QFileDialog::getOpenFileName(this, tr("choose"), "",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString())!=0)
    {
    QImage image;
    bool valid = image.load(filename);
    if(valid)
    {
      image=image.scaledToWidth(ui->id_sup_8->width(), Qt::SmoothTransformation);
     ui->id_sup_8->setPixmap(QPixmap::fromImage(image));
    }
            else{
    printf("erreur !");
    }
    }
}

void Modifier_joueur::Display()
{
    gestion_joueur g;
    g.exec();
 }
void Modifier_joueur::Db_Afficher_Liste_Matchs()
{
     model = new QSqlTableModel(this);  // Déclaration d'un nouveau model pour contenir toutes les données
                                       //réccupérées de la base
     model->setTable("\"Sportify\".\"JOUEUR\""); //Définition de la base sur laquelle opère le model
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);//Définition de la stratégie de modification
                        //dans notre cas un double clique sur une cellule  octroie à l'utilisateur de modifier sa
                        //valeur
     model->select();//remplir le model par les différentes données issues de la table  "Sumpark"."Matchs"


    view = new QTableView;
     //Configuration du style
     view->setStyleSheet("QTableView { border: none;"
                                         "background-color: white;"
                                         "selection-background-color: #999}");
     view->setModel(model);
     //definition du model a représenter
     view->resizeColumnsToContents();
     view->setSortingEnabled(true); //Permet le tri des colonnes
    view->setColumnHidden(0,true); //Rendre invisible la colonne des ID


     //Création des bouton
            submitButton = new QPushButton(tr("Submit"));
            submitButton->setDefault(true);
            revertButton = new QPushButton(tr("&Revert"));

            quitButton = new QPushButton(tr("Quit"));


            buttonBox = new QDialogButtonBox(Qt::Vertical);
            buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);

            buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);

            buttonBox->addButton(quitButton, QDialogButtonBox::ActionRole);

            //Connection des boutons avec leurs fonctions relatives

            connect(submitButton, &QPushButton::clicked, this, &Modifier_joueur::submit);
            connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
            connect(quitButton, &QPushButton::clicked, this, &Modifier_joueur::close);
          connect(quitButton, &QPushButton::clicked, this,&Modifier_joueur::Display);


            connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
                   ui->horizontalLayout_4->addWidget(view);
                   ui->horizontalLayout_2->addWidget(buttonBox);


                    setWindowTitle(tr("Modifier"));


                    /*qDebug()<<view->selectionModel()->selectedIndexes();
                    QModelIndex index = view->selectionModel()->currentIndex();
                   int id=view->model()->index(index.row(),0).data().toInt();
                  qDebug()<<id;*/


}

void Modifier_joueur::onTableClicked(const QModelIndex &index)
{
      QSqlDatabase db1;
    if (index.isValid()) {
     QModelIndex id_index = model->index(index.row(),0, QModelIndex());
             int id = id_index.data().toInt();
     QSqlQuery qry;
     ui->id_sup_8->clear();
     qry.prepare("select * from \"Sportify\".\"JOUEUR\" WHERE ID_J=:val");
     qry.bindValue(":val", id);
     if(qry.exec())
     {
         while(qry.next())
         {
             ui->in_id->setText(qry.value(0).toString());
             ui->id_sup_8->setText(qry.value(7).toString());
             filename=ui->id_sup_8->text();
             if (QString::compare(filename, QString())!=0)
             {
             QImage image;
             bool valid = image.load(filename);
             if(valid)
             {
               image=image.scaledToWidth(ui->id_sup_8->width(), Qt::SmoothTransformation);
              ui->id_sup_8->setPixmap(QPixmap::fromImage(image));
             }
                     else{
             printf("erreur !");
             }
             }
         }
         db1.close();
         }
     save_id=ui->in_id->text();
}
}

void Modifier_joueur::submit()
{
    QSqlDatabase db1;
    QString image;
    QSqlQuery qry;

   image=filename;

       qry.prepare("update \"Sportify\".\"JOUEUR\" set IMAGE='"+image+"' where ID_J='"+save_id+"' ");

   if(qry.exec( ))
   {
       QMessageBox::critical(this,tr("Modifier"),tr("Modifier avec succés."));

       db1.close();

       ui->id_sup_8->clear();

    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
   }
}
