#include "match_main.h"
#include "ui_match_main.h"

#include "mainwindow.h"



Match_Main::Match_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Match_Main)
{
     ui->setupUi(this);


     this->setFixedSize(600,500);
     ui->stackedWidget->setCurrentIndex(0);

     QPixmap Background_Pic("C:/Users/toshiba/Desktop/C++/QtApp/pics/match.jpg");

     ui->Background_pic->setPixmap(Background_Pic.scaled( ui->Background_pic->width(), ui->Background_pic->height()));


}

Match_Main::~Match_Main()
{
    delete ui;
}

void Match_Main::on_Match_Cancel_clicked()
{

        this->close();

}


void Match_Main::on_Match_Home_Pic_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.jpeg *.png *.jpg *.bmp *.gif"));

        QImage pic;
            bool valid =pic.load(filename);
            if (QString::compare(filename,QString())!=0)
          {if (valid)
       {pic=pic.scaledToHeight(ui->Home_Team_Label->height(),Qt::SmoothTransformation);
              ui->Home_Team_Label->setPixmap(QPixmap::fromImage(pic));
              Home_Team_Pic=filename;
                }}

}


void Match_Main::on_Match_Away_Pic_clicked()
{   QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.jpeg *.png *.jpg *.bmp *.gif"));

    QImage pic;
        bool valid =pic.load(filename);
        if (QString::compare(filename,QString())!=0)
      {if (valid)
   {pic=pic.scaledToHeight(ui->Home_Team_Label->height(),Qt::SmoothTransformation);
          ui->Visiting_Team_Label->setPixmap(QPixmap::fromImage(pic));
            Away_Team_Pic=filename;}}

}

void Match_Main::on_Match_Submit_clicked()
{
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);
        if(ui->Match_stadium->text().isEmpty())
    {     ui->Match_stadium->setPalette(*red) ; error=1;}
        else {  ui->Match_stadium->setPalette(*white); }
        if(ui->Match_Home->text().isEmpty())
    {       ui->Match_Home->setPalette(*red)  ;error=1;}
        else {  ui->Match_Home->setPalette(*white); }
        if(ui->Match_Visitor->text().isEmpty())
    {     ui->Match_Visitor->setPalette(*red );error=1;}
        else {  ui->Match_Visitor->setPalette(*white); }
 if (!error)
 Db_Add_Values_To_Match_Table(ui->Match_Home->text(),ui->Match_Visitor->text(),ui->Match_date->selectedDate().toString("dd/MM/yyyy"), ui->Match_stadium->text(),Home_Team_Pic,Away_Team_Pic);
}




void Match_Main::Db_Add_Values_To_Match_Table(QString Home_Team,QString Visitor_Team , QString Play_Date, QString Location,QString Home_Team_Pic,QString Away_Team_Pic)
{
    QSqlQuery query;
    query.prepare(" insert into \"Sportify\".\"MATCHS\""
                  "(Id,Home_Team,Visitor_Team,Play_Date,Location"
                  ",Home_Team_Pic,Away_Team_Pic) values (\"Sportify\".\"MATCHS_SEQ\".NEXTVAL,?,?,?,?,?,?);");

    query.addBindValue(Home_Team);
    query.addBindValue(Visitor_Team);
    query.addBindValue(Play_Date);
    query.addBindValue(Location);
    query.addBindValue(Home_Team_Pic);
    query.addBindValue(Away_Team_Pic);

    if (!query.exec())
    {
    qDebug()<<"Error adding values to matchs table";
    }

    else {
        QMessageBox::information(nullptr, QObject::tr(""),
                    QObject::tr("Ajout avec Succès\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

/*


void Match_Main::Db_Create_Table()
{

QString query ="create table  \"Sumpark\".\"Matchs\" (Id number ,"
               "Home_Team varchar2(50),"
               "Visitor_Team varchar2(50),"
               "Play_Date varchar2(50),"
               "Location varchar2(50),"
               " PRIMARY KEY (Id));";

QSqlQuery Query;
if (!Query.exec(query))
{
qDebug()<<"Error creating Table";
}


query="CREATE SEQUENCE sequence_1"
        "start with 20"
       " increment by 1"
       " minvalue 0"
       " maxvalue 100"
       " cycle;";
Query.exec(query);

*/
}


void Match_Main::Db_Afficher_Liste_Matchs()
{   QSqlQuery query;

     ui->stackedWidget->setCurrentIndex(1);// Definir l'onglet actuel du stacked Widget

     model = new QSqlTableModel(this);  // Déclaration d'un nouveau model pour contenir toutes les données
                                       //réccupérées de la base
     model->setTable("\"Sportify\".\"MATCHS\""); //Définition de la base sur laquelle opère le model
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);//Définition de la stratégie de modification
                        //dans notre cas un double clique sur une cellule  octroie à l'utilisateur de modifier sa
                        //valeur
     model->select();//remplir le model par les différentes données issues de la table  "Sumpark"."Matchs"

     //Configutarion  des nom de colonnes
     model->setHeaderData(0, Qt::Horizontal, tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, tr("Home Team"));
     model->setHeaderData(2, Qt::Horizontal, tr("Visitor Team"));
     model->setHeaderData(3, Qt::Horizontal, tr("Location"));
     model->setHeaderData(4, Qt::Horizontal, tr("Play Date"));
     model->setHeaderData(5, Qt::Horizontal, tr("Home_Team_Pic"));
     model->setHeaderData(6, Qt::Horizontal, tr("Away_Team_Pic"));



     view= new QTableView;
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
            deleteButton = new QPushButton(tr("Delete"));
            quitButton = new QPushButton(tr("Quit"));
            pdfButton= new QPushButton(tr("GeneratePdf"));
            jsonButton =new QPushButton (tr("Generate Json"));

            buttonBox = new QDialogButtonBox(Qt::Vertical);
            buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
            buttonBox->addButton(deleteButton ,QDialogButtonBox::ActionRole);
            buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);

            buttonBox->addButton(quitButton, QDialogButtonBox::ActionRole);
            QDialogButtonBox *buttonBox1;
            buttonBox1 = new QDialogButtonBox(Qt::Horizontal);
            buttonBox1->addButton(pdfButton, QDialogButtonBox::ActionRole);
            buttonBox1->addButton(jsonButton,QDialogButtonBox::ActionRole);
            buttonBox1->setCenterButtons(true);

            //Connection des boutons avec leurs fonctions relatives
            connect(deleteButton, &QPushButton::clicked,this, &Match_Main::remove);
            connect(submitButton, &QPushButton::clicked, this, &Match_Main::submit);
            connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
            connect(quitButton, &QPushButton::clicked, this, &Match_Main::close);
            connect(pdfButton,&QPushButton::clicked, this, &Match_Main::generate_Pdf);
            connect(jsonButton,&QPushButton::clicked,this,&Match_Main::generate_Json);
            connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
                   ui->horizontalLayout_4->addWidget(view);
                   ui->horizontalLayout_4->addWidget(buttonBox);
                   ui->horizontalLayout_6->addWidget(buttonBox1);

                    setWindowTitle(tr("Liste Des Matchs"));


                    qDebug()<<view->selectionModel()->selectedIndexes();
                    QModelIndex index = view->selectionModel()->currentIndex();
                   QString id=view->model()->index(index.row(),0).data().toString();
                  qDebug()<<id;


}

void Match_Main::remove()
{
   // récupère la listes des lignes sélectionnées
    QModelIndexList selection = view->selectionModel()->selectedIndexes();


    for(int i=0; i< selection.count(); i++)
    {
       model->removeRow(selection[i].row());

    }



}


void Match_Main::submit()
{

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




void Match_Main::generate_Pdf()
{


    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Matchs"), "C://",
           tr("(*.pdf)"));
if (!Filename.isEmpty())

   { QPrinter printer(QPrinter::PrinterResolution);//Déclaration du printer qui s'occupera de la création du fichier
    printer.setOutputFormat(QPrinter::PdfFormat);//Definition du format
     printer.setOrientation(QPrinter::Landscape);//Definition de l'orientation , dans ce cas c'est paysage

    printer.setOutputFileName(Filename);
        //Définition du chemin d'accès de l'output

    QTextDocument doc;
        //Préparation du  document
        //Formatage des données sous forme de tableau
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
    QMessageBox::question(this, tr("File Saved in :"), Filename, QMessageBox::Ok );//POPUP indiquant le chemin d'accès du fichier
  }
ui->stackedWidget->setCurrentIndex(1);//Nous renvoie vers la pages d'affichage

}

void Match_Main::generate_Json()
{
    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Matchs"), "C://",
           tr("(*.json)"));

    if (!Filename.isEmpty())

    { QJsonObject obj;//L'objet
       QJsonArray Matchs;//Création d'un Tableau intitulé Matchs
        QSqlQuery query;
       query.exec("select * from \"Sportify\".\"MATCHS\""); // Récupération des données de la base
       while(query.next()) //Lire les données récupérés
       {
           QJsonObject Match;//création d'un objet  json
           Match["Id"] = query.value(0).toInt();//Attribution des valeurs appropriées à chaque attribut
           Match["Home_Team"] = query.value(1).toString();
           Match["Visitor_Team"] = query.value(2).toString();
           Match["Location"] = query.value(3).toString();
           Match["Play_Date"] = query.value(4).toString();
           Matchs.append(Match);//(5)
       }
       obj["Matchs"] = Matchs;//(6)

       QFile file(Filename); //Création du fichier
       file.open(QFile::WriteOnly);
       file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));
       QMessageBox::question(this, tr("File Saved in :"), Filename, QMessageBox::Ok );//POPUP indiquant le chemin d'accès du fichier
}

}
void Match_Main::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {


        QModelIndex id_index = model->index(index.row(),0, QModelIndex());
        int id = id_index.data().toInt();
        qDebug()<<id;

        QSqlQuery query;
        query.prepare("select Home_Team_Pic,Away_Team_Pic from \"Sportify\".\"MATCHS\" where Id =:id;");
        query.bindValue(":id",id);
        if (!query.exec())
        {qDebug("Error fetching pics");}
           else {
            qDebug()<<query.first();
            qDebug()<<query.value(0).toString();
            qDebug()<<query.value(1).toString();
            QPixmap Background_Pic=(query.value(0).toString());


            ui->Home_Team_Pic->setPixmap(Background_Pic.scaled(ui->Home_Team_Pic->width(),ui->Home_Team_Pic->height(),Qt::KeepAspectRatio));
            Background_Pic=(query.value(1).toString());
            ui->Away_Team_Pic->setPixmap(Background_Pic.scaled(ui->Away_Team_Pic->width(),ui->Away_Team_Pic->height(),Qt::KeepAspectRatio));

        }

    }
}
