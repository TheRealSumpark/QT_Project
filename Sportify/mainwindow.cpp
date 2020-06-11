#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "match_main.h"
#include "tournoi_main.h"
#include "gestion_joueur.h"
#include "gestion_equipe.h"
#include "video_stream.h"
#include "fournisseur.h"
#include "evenement.h"
#include "equipements.h"




#include <QStackedWidget>
#include <QMediaPlayerControl>
#include <QPrintDialog>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setCentralWidget(ui->stackedWidget);
    this->setFixedSize(720,480);
    ui->stackedWidget->setCurrentIndex(1);
    this->Main_Menu();

}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::Main_Menu()
{

     ui->stackedWidget->setCurrentIndex(1);
      this->setStyleSheet("background-image: url(../images_projet/Sportify.png)");
      Connection c;
        bool test=c.createconnect();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



}
void MainWindow::Media_Status_Changed(QMediaPlayer::MediaStatus status )
{

    if (status== QMediaPlayer::EndOfMedia)
    {
      this->Main_Menu();
    }

}

void MainWindow::on_Main_Menu_Yassine_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Main_Menu_Selim_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}


void MainWindow::on_Main_button_match_clicked()
{
    Match_Main Match_ui;

    Match_ui.exec();
}

void MainWindow::on_Main_button_afficher_matchs_clicked()
{
    Match_Main Match_ui;
    Match_ui.Db_Afficher_Liste_Matchs();
    Match_ui.exec();
}


void MainWindow::on_Main_button_tournois_clicked()
{
    Tournoi_Main Tournoi_ui;
    Tournoi_ui.exec();
}

void MainWindow::on_Main_button_afficher_tournois_clicked()
{
    Tournoi_Main Tournoi_ui;
    Tournoi_ui.Db_Afficher_Liste_Tournois();
    Tournoi_ui.exec();
}

void MainWindow::on_Go_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
     qry.prepare("SELECT * FROM \"Sportify\".\"JOUEUR\"");
     qry.exec();
     Modal->setQuery(qry);
     table_joueur.setModel(Modal);

      qry1.prepare("SELECT * FROM \"Sportify\".\"EQUIPE\"");
      qry1.exec();
      Modal1->setQuery(qry1);
      table_equipe.setModel(Modal1);

      qry2.prepare("SELECT * FROM \"Sportify\".\"CONTENIR\" ");
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

void MainWindow::on_Go_Back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_Main_button_Afficher_Replay_clicked()
{
    Replay r;
    r.Ajouter_Replay();
    r.exec();
}


void MainWindow::on_Main_Menu_Regarder_clicked()
{

    VIDEO_STREAM  *v =new VIDEO_STREAM ;
    v->show();
}

void MainWindow::on_Main_button_ajouter_fournisseur_clicked()
{
    Fournisseur f;
    f.exec();

}


void MainWindow::on_Main_Menu_Oussema_clicked()
{
    Evenement e;
    e.exec();
}


void MainWindow::on_Go_Back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_Main_Menu_Taib_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Main_button_ajouter_equipement_clicked()
{
    Equipements e;
    e.exec();
}

void MainWindow::on_Main_button_afficher_fournisseurs_clicked()
{
    Fournisseur f;
    f.Afficher_Liste_Fournisseurs();
    f.exec();


}

void MainWindow::on_Main_button_afficher_equipements_clicked()
{
    Equipements e;
    e.Afficher_Liste_Equipements();
    e.exec();
}
