#include "mainwindow.h"
#include "gestion_equipe.h"
#include "gestion_joueur.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QtWidgets>
#include <QMessageBox>
#include<QDebug>
#include<QtGlobal>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
          QPixmap pic("../images_projet/projet77c.png");
           ui->label->setPixmap(pic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Gestion_joueur_clicked()
{
this->close();
gestion_joueur g;
g.exec();
}

void MainWindow::on_Modifier_joueur_clicked()
{
this->close();
 gestion_equipe g;
 g.exec();
}

void MainWindow::on_fichier_pdf_clicked()
{
         QSqlDatabase db1;
         QTableView table_joueur,table_equipe,table_contenir;
         QSqlQueryModel * Modal=new  QSqlQueryModel();
         QSqlQueryModel * Modal1=new  QSqlQueryModel();
         QSqlQueryModel * Modal2=new  QSqlQueryModel();
         QSqlQuery qry,qry1,qry2;
          qry.prepare("SELECT * FROM JOUEUR");
          qry.exec();
          Modal->setQuery(qry);
          table_joueur.setModel(Modal);

           qry1.prepare("SELECT * FROM EQUIPE");
           qry1.exec();
           Modal1->setQuery(qry1);
           table_equipe.setModel(Modal1);

           qry2.prepare("SELECT * FROM CONTENIR ");
           qry2.exec();
           Modal2->setQuery(qry2);
           table_contenir.setModel(Modal2);

          db1.close();


          QString strStream;
          QTextStream out(&strStream);

          const int rowCount = table_joueur.model()->rowCount();
          const int columnCount =  table_joueur.model()->columnCount();

          const int rowCount_eq = table_equipe.model()->rowCount();
          const int columnCount_eq =  table_equipe.model()->columnCount();

          const int rowCount_c = table_contenir.model()->rowCount();
          const int columnCount_c =  table_contenir.model()->columnCount();

          const QString strTitle ="Document";


          out <<  "<html>\n"
              "<head>\n"
                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
              <<  QString("<title>%1</title>\n").arg(strTitle)
              <<  "</head>\n"
              "<body bgcolor=#ffffff link=#5000A0>\n"
             << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Tous les joueurs")
             <<"<br>"
              <<"<table border=1 cellspacing=0 cellpadding=2>\n";

          out << "<thead><tr bgcolor=#f0f0f0>";
          for (int column = 0; column < columnCount; column++)
              if (!table_joueur.isColumnHidden(column))
                  out << QString("<th>%1</th>").arg(table_joueur.model()->headerData(column, Qt::Horizontal).toString());
          out << "</tr></thead>\n";

          for (int row = 0; row < rowCount; row++) {
              out << "<tr>";
              for (int column = 0; column < columnCount; column++) {
                  if (!table_joueur.isColumnHidden(column)) {
                      QString data = table_joueur.model()->data(table_joueur.model()->index(row, column)).toString().simplified();
                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                  }
              }
              out << "</tr>\n";
          }
          out <<  "</table>\n"
                  "<br><br>"
                  << QString("<h3 style=\"font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center; \">%1</h3>\n").arg("Les équipes")
                  <<"<br>"
                  <<"<table border=1 cellspacing=0 cellpadding=2>\n";

              out << "<thead><tr bgcolor=#f0f0f0>";
              for (int column = 0; column < columnCount_eq; column++)
                  if (!table_equipe.isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(table_equipe.model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              for (int row = 0; row < rowCount_eq; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount_eq; column++) {
                      if (!table_equipe.isColumnHidden(column)) {
                          QString data = table_equipe.model()->data(table_equipe.model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                      "<br><br>"
                      << QString("<h3 style=\"font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("La liste de toutes les équipes et leurs joueurs")
                      <<"<br>"
                      <<"<table width=400 border=1 cellspacing=0 cellpadding=2>\n";

                  out << "<thead><tr bgcolor=#f0f0f0>";
                  for (int column = 0; column < columnCount_c; column++)
                      if (!table_contenir.isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(table_contenir.model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  for (int row = 0; row < rowCount_c; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount_c; column++) {
                          if (!table_contenir.isColumnHidden(column)) {
                              QString data = table_contenir.model()->data(table_contenir.model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table>\n"

              "</body>\n"
              "</html>\n";

          QTextDocument *document = new QTextDocument();
          document->setHtml(strStream);

          QPrinter printer;

          QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
          if (dialog->exec() == QDialog::Accepted) {
              document->print(&printer);
          }

          delete document;
}
