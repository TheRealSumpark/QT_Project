#include "afficher_equipe.h"
#include "ui_afficher_equipe.h"
#include <QtWidgets>
#include "connection.h"
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>

afficher_equipe::afficher_equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_equipe)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/selim/Projet c++/projet_selimbenaich/projet77c.png");
     ui->label_affich->setPixmap(pic);
    QSqlDatabase db1;
    QSqlQueryModel * Modal1=new  QSqlQueryModel();
     QSqlQuery qry;
     qry.prepare("SELECT NOM_EQUIPE FROM EQUIPE order by score ASC ");
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

afficher_equipe::~afficher_equipe()
{
    delete ui;
}

void afficher_equipe::on_comboBox_equipe_currentIndexChanged(const QString &arg1)
{
    QSqlDatabase db1;
    QString val=ui->comboBox_equipe->currentText();
    QSqlQueryModel * Modal=new  QSqlQueryModel();
    QSqlQuery qry,qry1;
    ui->image_2->clear();
    ui->image_3->clear();
    qry.prepare("select * from EQUIPE WHERE NOM_EQUIPE='"+val+"'");
    qry1.prepare("SELECT NOM FROM JOUEUR WHERE ID_J IN (SELECT ID_JE FROM CONTENIR WHERE NOM_EQ='"+val+"' ) ");
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
         ui->undoView->setModel(Modal);
        db1.close();
        }
}

void afficher_equipe::on_undoView_activated(const QModelIndex &index)
{
    QSqlDatabase db1;
    QString val=ui->undoView->model()->data(index).toString();
    QSqlQuery qry;
    ui->image_3->clear();
    qry.prepare("select * from JOUEUR WHERE NOM='"+val+"'");
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

void afficher_equipe::on_pushButton_clicked()
{
 this->close();
}
