#include "supprimer_equipe.h"
#include "ui_supprimer_equipe.h"
#include <QtWidgets>
#include "connection.h"
#include "gestion_equipe.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

supprimer_equipe::supprimer_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_equipe)
{
    ui->setupUi(this);
    QPixmap pic("../images_projet/714297.jpg");
    ui->label_sup->setPixmap(pic);
    QSqlDatabase db1;
    QSqlQueryModel * Modal1=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT NOM_EQUIPE FROM EQUIPE");
     qry.exec();
     Modal1->setQuery(qry);
     ui->comboBox_equipe->setModel(Modal1);
     ui->comboBox_equipe->setCurrentIndex(-1);
     foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
     le->clear();
     }
     ui->image_2->clear();
     ui->image_3->clear();
      db1.close();
}

supprimer_equipe::~supprimer_equipe()
{
    delete ui;
}

void supprimer_equipe::on_annuler_la_suppression_clicked()
{
    this->close();
    gestion_equipe g;
    g.exec();
}

void supprimer_equipe::on_comboBox_equipe_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase db1;
    QString val=ui->comboBox_equipe->currentText();
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlQuery qry,qry1;
    ui->image_2->clear();
    ui->image_3->clear();
    qry.prepare("select * from EQUIPE WHERE NOM_EQUIPE='"+val+"' ");
    qry1.prepare("SELECT * FROM JOUEUR WHERE ID_J IN (SELECT ID_JE FROM CONTENIR WHERE NOM_EQ='"+val+"' ) ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->list_e_nom->setText(qry.value(0).toString());
            ui->liste_e_manager->setText(qry.value(4).toString());
            ui->image_2->setText(qry.value(5).toString());
            QString filename=ui->image_2->text();
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
         qry1.exec();
         Modal->setQuery(qry1);
         ui->listView->setModel(Modal);
        save_nom_equipe=ui->list_e_nom->text();
        db1.close();
        }
}

void supprimer_equipe::on_listView_activated(const QModelIndex &index)
{
    QSqlDatabase db1;
    QString val=ui->listView->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_3->clear();
    qry.prepare("select * from JOUEUR WHERE ID_J='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->image_3->setText(qry.value(7).toString());
            QString filename_2=ui->image_3->text();
            if (QString::compare(filename_2, QString())!=0)
            {
            QImage image;
            bool valid = image.load(filename_2);
            if(valid)
            {
              image=image.scaledToWidth(ui->image_3->width(), Qt::SmoothTransformation);
             ui->image_3->setPixmap(QPixmap::fromImage(image));
            }
                    else{
            printf("erreur !");
            }
            }
        }
        db1.close();
        }
}

void supprimer_equipe::on_supprimer_equipe_2_clicked()
{
    QMessageBox msgBox;
     msgBox.setMinimumSize(300, 423);
    QSqlDatabase db1;
    QSqlQuery qry,qry1;
    QString val;
    val=ui->list_e_nom->text();
    if(val.isEmpty()){
      QMessageBox::critical(this,tr("Supprimer"),tr("Veuillez selectionner une équipe."));
    }

else{
    qry.prepare("delete from EQUIPE WHERE NOM_EQUIPE='"+save_nom_equipe+"'");
    qry1.prepare("delete from CONTENIR WHERE NOM_EQ='"+save_nom_equipe+"'");


    //msgBox.setText("The sports team has been Deleted.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save:
qry.exec();
qry1.exec();
Afficher_supp_eq();
          break;
      case QMessageBox::Cancel:
          break;
      default:
          break;
    }
    }
}

void supprimer_equipe::Afficher_supp_eq()
{
    QSqlDatabase db1;
    QSqlQueryModel * Modal1=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT NOM_EQUIPE FROM EQUIPE");
     qry.exec();
     Modal1->setQuery(qry);
     ui->comboBox_equipe->setModel(Modal1);
     ui->comboBox_equipe->setCurrentIndex(-1);
     foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
     le->clear();
     }
     ui->image_2->clear();
     ui->image_3->clear();
    db1.close();
}
