#include "evenement.h"
#include "ui_evenement.h"
#include "guests.h"
#include "event.h"
#include "QDate"
#include <QMessageBox>
#include "qcustomplot.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QDialog>
#include <QtDebug>
#include <QtSql>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include <QWidget>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QSqlTableModel>
#include <QVariant>
#include <QList>
#include "stati.h"
#include "ui_stati.h"
#include <QTableView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextTableFormat>
#include <QTextTableCell>
#include <QTableWidget>
#include <QModelIndex>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QFileDialog>
#include <QChar>
#include <string>
#include <QTableView>
#include <QPalette>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QStringList>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>

#include <QSortFilterProxyModel>

QT_CHARTS_USE_NAMESPACE

Evenement::Evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Evenement)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(../images_projet/Sportify.png)");
    this->setFixedSize(ui->stackedWidget->width(),ui->stackedWidget->height());
    ui->stackedWidget->setCurrentIndex(0);

   on_pushButton_8_clicked(); // affichage des events

}

Evenement::~Evenement()
{
    delete ui;
}





int Evenement :: getIDFromTableView(QTableView * tv){
    int id =-1;
    if(tv->currentIndex().isValid() == true){
    QModelIndexList indexes = tv->selectionModel()->selection().indexes();
    QVariant qv = indexes.at(0).data();
    QString ss = qv.toString();
    std::string cc = ss.toStdString();
    id = std::atoi (cc.c_str());
    }else{
        id = -1;
    }
    return id;
}

/*void Evenement::submit()
{


    QSqlQueryModel * model = temp.afficher_event();
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1"))
                             ;
    }
}
*/
void Evenement::on_pushButton_22_clicked()
{
    QSqlQueryModel * model = temp.afficher_event();

    QString Filename = QFileDialog::getSaveFileName(this, tr("Sauvegarder events "), "C://",tr("(*.pdf)"));
if (!Filename.isEmpty())

   {
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName(Filename);
    QTextDocument doc;
    QString text("<table width=\"100%\" border=\"1\"><thead>");
    text.append("<tr>");
     for (int i = 0; i < model->columnCount(); i++) {
        text.append("<th>").append(model->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < model->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < model->columnCount(); j++) {
         text.append("<td>").append(model->index(i,j).data().toString()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
    QMessageBox::question(this, tr("File Saved in :"), Filename, QMessageBox::Ok );
  }
ui->stackedWidget->setCurrentIndex(1);

}
void Evenement::on_pushButton_7_clicked() //mailing
{
   /* Sender smtp(QLatin1String("smtp.gmail.com"), 465, Sender::SslConnection);

    // We need to set the username (your email address) and password
    // for smtp authentification.

    smtp.setUser(QLatin1String("your_email_address@host.com"));
    smtp.setPassword(QLatin1String("your_password"));

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender(QLatin1String("your_email_address@host.com"), QLatin1String("Your Name"));
    message.setSender(sender);

    EmailAddress to(QLatin1String("recipient@host.com"), QLatin1String("Recipient's Name"));
    message.addTo(to);

    message.setSubject(QLatin1String("SmtpClient for Qt - Demo"));

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(QLatin1String("Hi,\nThis is a simple email message.\n"));

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail
    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << smtp.lastError();
    }

    smtp.quit();



       stati  stat ;
        stat.setModal(true);
        stat.exec();
*/  }



void Evenement::on_pushButton_8_clicked()
{
    QSqlQueryModel * model = temp.afficher_event();
   ui->tableView->setModel( model);
   QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
       m->setDynamicSortFilter(true);
       m->setSourceModel(model);
       ui->tableView->setModel(m);
       ui->tableView->setSortingEnabled(true);
}

void Evenement::on_pushButton_19_clicked() //ajout event
{


int error=0;
QPalette *red = new QPalette();
QPalette *white = new QPalette();
 red->setColor(QPalette::Base,Qt::red);
  white->setColor(QPalette::Base,Qt::white);
 if(ui->nameaddevent->text().isEmpty())

{     ui->eventnamelabel->setText("<html><font color='red'>Empty Name Entry </font></html>");
          ui->eventnamelabel->setVisible(true);
    error=1;}
    else {  ui->eventnamelabel->setVisible(false); }

    if(ui->guestsaddevent->text().isEmpty())
    {     ui->eventguestslabel->setText("<html><font color='red'>Empty guests Entry </font></html>");
        ui->eventguestslabel->setVisible(true);
    error=1;}
  else {  ui->eventguestslabel->setVisible(false); }
  if(ui->goaladdevent->text().isEmpty())
    {    ui->eventgoallabel->setText("<html><font color='red'>Empty goal Entry </font></html>");
      ui->eventgoallabel->setVisible(true);
    error=1;}
    else {  ui->eventgoallabel->setVisible(false); }
     if(ui->budgetaddevent->text().isEmpty())
    {    ui->eventbudgetlabel->setText("<html><font color='red'>Empty budget Entry </font></html>");
     ui->eventbudgetlabel->setVisible(true);
    error=1;}
    else {  ui->eventbudgetlabel->setVisible(false); }
    if(ui->dateaddevent->text().isEmpty())
    {     ui->eventdatelabel->setText("<html><font color='red'>Empty date Entry </font></html>");
       ui->eventdatelabel->setVisible(true);
    error=1;}
    else {  ui->eventdatelabel->setVisible(false); }
   if (!error){

    QString name = ui->nameaddevent->text();
  QString  guestlist= ui->guestsaddevent->text();
 QString   goal = ui->goaladdevent->text();
   int budget = ui->budgetaddevent->text().toInt();
   QDate date= ui->dateaddevent->date();

    QSqlQueryModel * model = temp.afficher_event();
   class event c( name,date,goal,guestlist,budget);

   bool test=c.ajouter_event();

    if(test)
  {
        ui->tableView->setModel(model);

  QMessageBox::information(nullptr, QObject::tr("Ajouter un event"),
                    QObject::tr("event ajoutÃ©.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un event"),
                    QObject::tr("Erreur , Ã©chec d'ajout !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}
}
void Evenement::on_pushButton_20_clicked() //modifier un event
{
int id = getIDFromTableView(ui->tableView);
    QString name = ui->namemodifyevent->text();
  QString  guestlist= ui->guestsmodifyevent->text();
 QString   goal = ui->goalmodifyevent->text();
   int budget = ui->budgetmodifyevent->text().toInt();
   QDate date= ui->datemodifyevent->date();

         bool test = temp.modifier_event(id,name, date,goal,guestlist,budget);

             if (test)

             {
                 ui->stackedWidget->setCurrentIndex(2);

                  ui->tableView->setModel( temp.afficher_event());
                  QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                      m->setDynamicSortFilter(true);
                      m->setSourceModel(temp.afficher_event());
                      ui->tableView->setModel(m);
                      ui->tableView->setSortingEnabled(true);

                 QMessageBox::information(nullptr, QObject::tr("Successfully modified!"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("Modification Failed !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void Evenement::on_pushButton_10_clicked()
{


    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);
     if(ui->nameaddguest->text().isEmpty())

    {     ui->guestsnamelabel->setText("<html><font color='red'>Empty Name Entry </font></html>");
              ui->guestsnamelabel->setVisible(true);
        error=1;}
        else {  ui->guestsnamelabel->setVisible(false); }

        if(ui->lastaddguest->text().isEmpty())
        {     ui->guestslastlabel->setText("<html><font color='red'>Empty LastName Entry </font></html>");
            ui->guestslastlabel->setVisible(true);
        error=1;}
      else {  ui->guestslastlabel->setVisible(false); }
      if(ui->jobaddguest->text().isEmpty())
        {    ui->guestsjoblabel->setText("<html><font color='red'>Empty job Entry </font></html>");
          ui->guestsjoblabel->setVisible(true);
        error=1;}
        else {  ui->guestsjoblabel->setVisible(false); }
         if(ui->leveladdguest->text().isEmpty())
        {    ui->guestslevellabel->setText("<html><font color='red'>Empty level of importance Entry </font></html>");
         ui->guestslevellabel->setVisible(true);
        error=1;}
        else {  ui->guestslevellabel->setVisible(false); }
        if(ui->contactaddguest->text().isEmpty())
        {     ui->guestscontactslabel->setText("<html><font color='red'>Empty contacts Entry </font></html>");
           ui->guestscontactslabel->setVisible(true);
        error=1;}
        else {  ui->guestscontactslabel->setVisible(false); }
       if (!error){


    QString name = ui->nameaddguest->text();
    QString lastname = ui->lastaddguest->text();
    QString job = ui->jobaddguest->text();
    int level = ui->leveladdguest->text().toInt();
    QString contact = ui->contactaddguest->text();


class Guests rs(level,name,lastname,job,contact);

  bool test=rs.ajouter_guests();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajoutÃ©e.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}}

void Evenement::on_pushButton_9_clicked() // modifier reservation
{
    int id = getIDFromTableView(ui->tableView_2);
    QString name = ui->namemodifyguests->text();
    QString lastname = ui->lastmodifyguests->text();
    QString job = ui->jobmodifyguests->text();
    int level = ui->levelmodifyguests->text().toInt();
    QString contact = ui->contactmodifyguests->text();


         bool test = tempr.modifier_guests(id,level,name,lastname,job,contact);
             if (test)

             {
                     QSqlQueryModel * model = tempr.afficher_guests();

                  ui->tableView_2->setModel( model);
                  QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                      m->setDynamicSortFilter(true);
                      m->setSourceModel(model);
                      ui->tableView->setModel(m);
                      ui->tableView->setSortingEnabled(true);


                 QMessageBox::information(nullptr, QObject::tr("Successfully modified !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modification Failed !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}







void Evenement::on_pushButton_clicked()  //chercher event
{
    int ID = ui->lineEdit_19->text().toInt();
    QSqlQueryModel * test=temp.chercher_event(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher un event"),
                    QObject::tr("event trouvÃ©.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher un event"),
                    QObject::tr("Erreur , event introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Evenement::on_pushButton_21_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}



void Evenement::on_pushButton_24_clicked() //aller a ajout
{
    ui->label_43->setVisible(false);
   ui->stackedWidget->setCurrentIndex(3);
}


void Evenement::on_pushButton_25_clicked() // aller a modif
{
    QSqlQuery query;
    int id = getIDFromTableView(ui->tableView);
    if(id != -1){
        query.prepare("Select * from events where ID= :id");
        query.bindValue(":id" ,id);
        query.exec();
        QSqlQueryModel model;
        model.setQuery(query);
       //fill the blanks ...
        ui->label_50->setVisible(false);
        ui->stackedWidget->setCurrentIndex(4);
      }
    else
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);
}

void Evenement::on_pushButton_26_clicked() // supp du event
{
    int id = getIDFromTableView(ui->tableView);
    if(id != -1){

      class event * c = new class event(id);
        c->supprimer_event(id);
     }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);

    }
    on_pushButton_8_clicked(); // this function call is to refresh the table afte
    //clicking go back button
}

void Evenement::on_pushButton_3_clicked() // aller ajout res
{

  ui->label_52->setVisible(false);
   ui->stackedWidget_2->setCurrentIndex(3);

}

void Evenement::on_pushButton_4_clicked() // aller a modif res
{
   int id = getIDFromTableView(ui->tableView_2);
   if(id != -1){
    QSqlQuery query;
    query.prepare("Select * from GUESTS where ID= :id ");
   query.bindValue(":id", id);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    ui->label_40->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(1);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);
    }
}

void Evenement::on_pushButton_5_clicked() //aller au supp res
{
    bool test=0;
     int id = getIDFromTableView(ui->tableView_2);
     if(id != -1){

          test=tempr.supprimer_guests(id);
      }else{
         QMessageBox::critical(nullptr, QObject::tr("Selection"),
                               QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);

     }


    if(test)
     {
        QSqlQueryModel * model = tempr.afficher_guests();
         ui->tableView_2->setModel(model);
         QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
             m->setDynamicSortFilter(true);
             m->setSourceModel(model);
             ui->tableView->setModel(m);
             ui->tableView->setSortingEnabled(true);

         QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                     QObject::tr("Reservation supprimÃ©e.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                     QObject::tr("Erreur , Echec de suppression !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
 }
 }





void Evenement::on_pushButton_11_clicked() //affichage res
{
    QSqlQueryModel * model = tempr.afficher_guests();
   ui->tableView_2->setModel(model);
   QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
       m->setDynamicSortFilter(true);
       m->setSourceModel(model);
       ui->tableView->setModel(m);
       ui->tableView->setSortingEnabled(true);

}


void Evenement::on_pushButton_2_clicked() //aller au recherche res
{
   ui->label_54->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(4);
}



void Evenement::on_pushButton_28_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void Evenement::on_pushButton_29_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void Evenement::on_pushButton_23_clicked()
{
   int ID = ui->lineEdit_18->text().toInt();
   QSqlQueryModel * test=tempr.chercher_guests(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher une resrvation"),
                    QObject::tr("Res trouvÃ©.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_5->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une reservation"),
                    QObject::tr("Erreur , Res introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Evenement::on_pushButton_12_clicked()
{
    ui->label->setVisible(false);
  ui->stackedWidget_2->setCurrentIndex(0);
}

void Evenement::on_pushButton_13_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Evenement::on_pushButton_14_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Evenement::on_pushButton_15_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Evenement::on_pushButton_16_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void Evenement::on_pushButton_17_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void Evenement::on_pushButton_18_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void Evenement::on_pushButton_27_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(5);
}
void Evenement::on_events_button_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void Evenement::on_guests_button_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(1);
}
/*void on_return_button_clicked(){
    QMessageBox::information(nullptr, QObject::tr("chercher une resrvation"),
                QObject::tr("Res trouvÃ©.\n"
                            "Click Cancel to get informations."), QMessageBox::Cancel);
}
*/


void Evenement::on_pushButton_30_clicked()
{
    this->close();
}
