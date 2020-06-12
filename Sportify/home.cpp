#include "home.h"
#include "ui_home.h"
#include "connection.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QSqlTableModel>
#include <QPrintDialog>


home::home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap Background_Pic("../images_projet/Sportify.png");
    ui->Background_Pic->setPixmap(Background_Pic.scaled(ui->Background_Pic->width(),ui->Background_Pic->height()));

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

home::~home()
{
    delete ui;
}

void home::on_pushButton_clicked()
{
    home::close();
}

void home::on_terrain_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void home::on_employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void home::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void home::on_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void home::on_home_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void home::on_report_clicked()
{
 ui->stackedWidget->setCurrentIndex(3);
}

/*

void home::on_loadview_clicked()
{
        Connection  conn;
        QSqlQueryModel * modal = new QSqlQueryModel();
        conn.createconnect();
        QSqlQuery * qry = new QSqlQuery(conn.db);

        qry -> prepare("select NOM,LOCALISATION,NBEMPLOYE from stades");
        qry ->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug() << (modal->rowCount());
        conn.closeconnect();
        QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
        m->setDynamicSortFilter(true);
        m->setSourceModel(modal);
        ui->tableView->setModel(m);
        ui->tableView->setSortingEnabled(true);
}*/

void home::on_add_clicked()
{
    QString nom , prenom , age,salaire,post;

    nom=ui-> nom_emp ->text();
    prenom=ui->prenom_emp->text();
    age=ui->age_emp->text();
    salaire=ui->salaire_emp->text();
    post =ui -> post_emp->currentText();

    QSqlQuery query;

    query.prepare("INSERT INTO \"Sportify\".\"EMPLOYES\" (NOM,PRENOM,AGE,SALAIRE,POST) values ('"+nom+"','"+prenom+"','"+age+"','"+salaire+"','"+post+"')");





    if (query.exec()) {
        //successful
        QMessageBox::information(nullptr, QObject::tr("add"),
                    QObject::tr("add successful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        // unsuccessful either no match or bad SQL
        QMessageBox::warning(nullptr, QObject::tr("add"),
                    QObject::tr("add unsuccessful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}
/*
void home::on_update_clicked()
{
    QString nom , prenom , age,salaire,post;

    nom=ui-> nom_emp ->text();
    prenom=ui->prenom_emp->text();
    age=ui->age_emp->text();
    salaire=ui->salaire_emp->text();
    post =ui -> post_emp->currentText();

    QSqlQuery query;

    query.prepare("update EMPLOYES set NOM='"+nom+"',PRENOM='"+prenom+"',AGE='"+age+"',SALAIRE='"+salaire+"',POST='"+post+"' where  NOM='"+nom+"' ");





    if (query.exec()) {
        //successful
        QMessageBox :: information(this,"update","success");

    }
    else {
        // unsuccessful either no match or bad SQL
            QMessageBox::warning(this,"update","error failed"),query.lastError().text();
    }

}
*/
void home::on_delete_2_clicked()
{
    QString nom , prenom , age,salaire,post;

    nom=ui-> nom_emp ->text();
    prenom=ui->prenom_emp->text();
    age=ui->age_emp->text();
    salaire=ui->salaire_emp->text();
    post =ui -> post_emp->currentText();

    QSqlQuery query;

    query.prepare("Delete from \"Sportify\".\"EMPLOYES\" where NOM='"+nom+"'");




    query.exec();
        if (query.numRowsAffected()>0) {
        //successful
        QMessageBox::information(nullptr, QObject::tr("delete"),
                    QObject::tr("delete successful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {
        // unsuccessful either no match or bad SQL

        QMessageBox::warning(nullptr, QObject::tr("delete"),
                    QObject::tr("delete unsuccessful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void home::on_load_table_clicked()
{
        Connection conn;
        //QSqlQueryModel * modal = new QSqlQueryModel();
        conn.createconnect();
       // QSqlQuery * qry = new QSqlQuery(conn.db);

/*
        qry -> prepare("select NOM  from EMPLOYES"); ,PRENOM,AGE,SALAIRE,POST
        qry ->exec();
        modal->setQuery(*qry);
        ui->tableView_2->setModel(modal);
       ui->comboBox->setModel(modal);

        conn.closeconnect();
        qDebug() << (modal->rowCount());

       QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
        m->setDynamicSortFilter(true);

        m->setSourceModel(modal);
        ui->tableView_2->setModel(m);
        ui->ta<bleView_2->setSortingEnabled(true);*/
        modal = new QSqlTableModel(this);
          modal->setTable("\"Sportify\".\"EMPLOYES\"");
        //modal->setQuery("select NOM  from EMPLOYES");
        modal ->select();

        ui->tableView_2->setModel(modal);

}



/*

void home::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();

    Connection  conn;
    conn.createconnect();
    QSqlQuery qry;
    qry.prepare("select NOM from EMPLOYES where NOM='"+val+"'");

    if(qry.exec())
    {

            ui->nom_emp->setText("qry.value(0).toString()");



    }
    conn.closeconnect();

}
*/

void home::on_pdf_clicked()
{
    QSqlDatabase db1;
       QTableView table_employes;
       QSqlQueryModel * Modal=new  QSqlQueryModel();

       QSqlQuery qry;
        qry.prepare("SELECT * FROM \"Sportify\".\"EMPLOYES\"");
        qry.exec();
        Modal->setQuery(qry);
        table_employes.setModel(Modal);



        db1.close();


        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = table_employes.model()->rowCount();
        const int columnCount =  table_employes.model()->columnCount();

        const QString strTitle ="Document";


        out <<  "<html>\n"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
           << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: red ; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Tous les Employes")
           <<"<br>"
            <<"<table border=1 cellspacing=0 cellpadding=2>\n";

        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!table_employes.isColumnHidden(column))
                out << QString("<th>%1</th>").arg(table_employes.model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!table_employes.isColumnHidden(column)) {
                        QString data = table_employes.model()->data(table_employes.model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                    "<br><br>"


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
void home::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_sender->text(), ui->lineEdit_pass->text(), ui->lineEdit_smtp->text(), ui->lineEdit_465->text().toInt());

      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_sender->text(), ui->lineEdit_recepiant->text() , ui->lineEdit_subject->text(),ui->lineEdit_text->text());


  //initialiser_0();
}




void home::on_add_stade_clicked()
{
        int error=0;
       QPalette *red = new QPalette();
       QPalette *white = new QPalette();
        red->setColor(QPalette::Base,Qt::red);
         white->setColor(QPalette::Base,Qt::white);

           if(ui->nom_stade->text().isEmpty())

       {
               ui->nom_stade->setPalette(*red) ; error=1;}

           else {

               ui->nom_stade->setPalette(*white); }

           if(ui->adress_stade->text().isEmpty())
       {       ui->adress_stade->setPalette(*red)  ;error=1;}
           else {  ui->adress_stade->setPalette(*white); }
           if(ui->nb_emp->text().isEmpty())
       {     ui->nb_emp->setPalette(*red );error=1;}
           else {  ui->nb_emp->setPalette(*white); }


           if(ui->capacite_stade->text().isEmpty())

       {
               ui->capacite_stade->setPalette(*red) ; error=1;}

           else {

               ui->capacite_stade->setPalette(*white); }



           if(ui->size->text().isEmpty())

       {
               ui->size->setPalette(*red) ; error=1;}

           else {

               ui->size->setPalette(*white); }





    QString nom , localisation,nbemploye,capacite,F_size;


           nom = ui -> nom_stade ->text();
           localisation = ui -> adress_stade ->text();
           nbemploye = ui-> nb_emp ->text();
           capacite = ui-> capacite_stade ->text();
           F_size = ui->size->text();


           QSqlQuery query;
           if (!error)
           query.prepare("INSERT INTO \"Sportify\".\"STADES\" (NOM,LOCALISATION,NBEMPLOYE,CAPACITE,FIELD_SIZE) values ('"+nom+"','"+localisation+"','"+nbemploye+"','"+capacite+"','"+F_size+"')");





           if (query.exec()) {
               //successful
               QMessageBox::information(nullptr, QObject::tr("add"),
                           QObject::tr("add successful .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);


           }
           else {
               // unsuccessful either no match or bad SQL
               QMessageBox::warning(nullptr, QObject::tr("add"),
                           QObject::tr("add unsuccessful .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }

}

void home::on_load_table_stade_clicked()
{
    Connection conn;
    //QSqlQueryModel * modal = new QSqlQueryModel();
    conn.createconnect();
   // QSqlQuery * qry = new QSqlQuery(conn.db);
/*
    qry -> prepare("select NOM  from EMPLOYES"); ,PRENOM,AGE,SALAIRE,POST
    qry ->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
   ui->comboBox->setModel(modal);

    conn.closeconnect();
    qDebug() << (modal->rowCount());

   QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);

    m->setSourceModel(modal);
    ui->tableView_2->setModel(m);
    ui->ta<bleView_2->setSortingEnabled(true);*/
    modal = new QSqlTableModel(this);
      modal->setTable("\"Sportify\".\"STADES\"");
    //modal->setQuery("select NOM  from EMPLOYES");
    modal ->select();

    ui->tableView_3->setModel(modal);

}

void home::on_delete_stade_clicked()
{
    QString nom , localisation,nbemploye,capacite,F_size;


           nom = ui -> nom_stade ->text();
           localisation = ui -> adress_stade ->text();
           nbemploye = ui-> nb_emp ->text();
           capacite = ui-> capacite_stade ->text();
           F_size = ui->size->text();

    QSqlQuery query;

    query.prepare("Delete from \"Sportify\".\"STADES\" where NOM='"+nom+"'");




query.exec();
    if (query.numRowsAffected()>0) {
        //successful
        QMessageBox::information(nullptr, QObject::tr("delete"),
                    QObject::tr("delete successful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        // unsuccessful either no match or bad SQL
        QMessageBox::warning(nullptr, QObject::tr("delete"),
                    QObject::tr("delete unsuccessful .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void home::on_pdf_2_clicked()
{
    QSqlDatabase db1;
       QTableView table_stade;
       QSqlQueryModel * Modal=new  QSqlQueryModel();

       QSqlQuery qry;
        qry.prepare("SELECT * FROM \"Sportify\".\"STADES\"");
        qry.exec();
        Modal->setQuery(qry);
        table_stade.setModel(Modal);



        db1.close();


        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = table_stade.model()->rowCount();
        const int columnCount =  table_stade.model()->columnCount();

        const QString strTitle ="Document";


        out <<  "<html>\n"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
             << "<img src=\"../../../sportify.png\">\n"
           << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: green; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Tous les stades")
           <<"<br>"
            <<"<table border=1 cellspacing=0 cellpadding=2>\n";

        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!table_stade.isColumnHidden(column))
                out << QString("<th>%1</th>").arg(table_stade.model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!table_stade.isColumnHidden(column)) {
                        QString data =table_stade.model()->data(table_stade.model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                    "<br><br>"


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

void home::on_home_5_clicked()
{
    this->close();
}

void home::on_Qr_Code_clicked()
{
    QProcess *proc = new QProcess;
    QString progName = "../Qr_Code/QRCode_Generator.exe";
    proc->start(progName);
    proc->errorString();
    proc->errorString();
    qDebug()<< " Started the process"<<endl;
}
