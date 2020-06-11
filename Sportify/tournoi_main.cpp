#include "tournoi_main.h"
#include "ui_tournoi_main.h"


Tournoi_Main::Tournoi_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tournoi_Main)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap Background_Pic("../images_projet/cup.jpg");
    ui->Tournoi_Background_Pic->setPixmap(Background_Pic.scaled(ui->Tournoi_Background_Pic->width(),ui->Tournoi_Background_Pic->height()));
}

Tournoi_Main::~Tournoi_Main()
{
    delete ui;
}

void Tournoi_Main::on_pushButton_clicked()
{
    this->close();
}


void Tournoi_Main::on_Tournoi_Main_Submit_clicked()
{
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);
        if(ui->Tournoi_Nom->text().trimmed().isEmpty())
    {     ui->Tournoi_Nom->setPalette(*red) ; error=1;}
        else {  ui->Tournoi_Nom->setPalette(*white); }
        if(ui->Tournoi_Categorie->text().trimmed().isEmpty())
    {       ui->Tournoi_Categorie->setPalette(*red)  ;error=1;}
        else {  ui->Tournoi_Categorie->setPalette(*white); }
        if(ui->Tournoi_NbParticipants->value()<=0)
    {     ui->Tournoi_NbParticipants->setPalette(*red );error=1;}
        else {  ui->Tournoi_NbParticipants->setPalette(*white); }
 if (!error)
    Db_Add_Values_To_Tournois_Table(ui->Tournoi_Nom->text(), ui->Tournoi_Categorie->text(),ui->Tournoi_Date->text(), ui->Tournoi_NbParticipants->value());
}


void Tournoi_Main::Db_Add_Values_To_Tournois_Table(QString Nom ,QString Categorie,QString Date_Lancement,int Nb_Participants)
{
    QSqlQuery query;
    query.prepare(" insert into \"Sportify\".\"TOURNOIS\"(Id,Nom,Categorie,Date_Lancement,Nb_Participants) values (\"Sportify\".\"TOURNOIS_SEQ\".NEXTVAL,?,?,?,?);");


    query.addBindValue(Nom);
    query.addBindValue(Categorie);
    //query.addBindValue(QDateTime::fromString("mm/dd/yyyy"));
    query.addBindValue(Date_Lancement);
    query.addBindValue(Nb_Participants);

    if (!query.exec())
    {
    qDebug()<<"Error adding values to tournois table";
    }

        else {
            QMessageBox::information(nullptr, QObject::tr(""),
                        QObject::tr("Ajout avec Succès\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }


}

void Tournoi_Main::Db_Afficher_Liste_Tournois()
{
      ui->stackedWidget->setCurrentIndex(1);
      QSqlQuery query;

      model = new QSqlTableModel(this);
      model->setTable("\"Sportify\".\"TOURNOIS\"");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();

      model->setHeaderData(0, Qt::Horizontal, tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, tr("Description"));
      model->setHeaderData(3, Qt::Horizontal, tr("Date_Lancement"));
      model->setHeaderData(4, Qt::Horizontal, tr("Nb_Participants"));




      view= new QTableView;
      view->setModel(model);

      view->resizeColumnsToContents();
      view->setStyleSheet("QTableView { border: none;"
                                          "background-color: white;"
                                          "selection-background-color: #999}");

      view->setSortingEnabled(true);
      view->setColumnHidden(0,true);

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


             QModelIndex curIndex =view->currentIndex();
             QSqlRecord record = model->record(curIndex.row());
             model->removeRow(curIndex.row());

             connect(submitButton, &QPushButton::clicked, this, &Tournoi_Main::submit);
             connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
             connect(quitButton, &QPushButton::clicked, this, &Tournoi_Main::close);
             connect(deleteButton,&QPushButton::clicked, this, &Tournoi_Main::remove);
             connect(pdfButton,&QPushButton::clicked, this, &Tournoi_Main::generate_Pdf);
             connect(jsonButton,&QPushButton::clicked,this,&Tournoi_Main::generate_Json);


                    ui->horizontalLayout->addWidget(view);
                    ui->horizontalLayout->addWidget(buttonBox);
                    ui->horizontalLayout_3->setAlignment(Qt::AlignHCenter);
                    ui->horizontalLayout_3->addWidget(buttonBox1);

                     setWindowTitle(tr("Cached Table"));



}





void Tournoi_Main::submit()
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



void Tournoi_Main::remove()
{


    QModelIndexList selection = view->selectionModel()->selectedRows();

    // Multiple rows can be selected
    for(int i=0; i< selection.count(); i++)
    {
       model->removeRow(i);

    }



}

void Tournoi_Main::generate_Pdf()
{
    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Tournois"), "C://",
           tr("(*.pdf)"));

if (!Filename.isEmpty())

   { QPrinter printer(QPrinter::PrinterResolution);//Déclaration du printer qui s'occupera de la création du fichier
    printer.setOutputFormat(QPrinter::PdfFormat);//Definition du format
     printer.setOrientation(QPrinter::Landscape);//Definition de l'orientation , dans ce cas c'est paysage

    printer.setOutputFileName(Filename);
        //Définition du chemin d'accès de l'output

    QTextDocument doc;
        //Préparationdu  document
        //Formatage des données sous forme de tableau
    QString text("<table width=\"100%\" border=\"1\"><thead>");
     text.append("<caption>Liste des tournois </caption>");
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

void Tournoi_Main::generate_Json()
{

    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Tournois"), "C://",
           tr("(*.json)"));

    if (!Filename.isEmpty())
   {   QJsonObject obj;//root object
       QJsonArray Tournois;//(2)
        QSqlQuery query;

       query.exec("select * from \"Sportify\".\"TOURNOIS\"");
       while(query.next())//load all data from the database
       {
           QJsonObject Tournoi;//(3)
           Tournoi["Id"] = query.value(0).toInt();//(4)
           Tournoi["Nom"] = query.value(1).toString();
           Tournoi["Categorie"] = query.value(2).toString();
           Tournoi["Date_Lancement"] = query.value(3).toString();
           Tournoi["Nb_Participants"] = query.value(4).toInt();
           Tournois.append(Tournoi);//(5)
       }
       obj["Tournois"] = Tournois;//(6)

    QFile file(Filename); //Création du fichier
      file.open(QFile::WriteOnly);
      file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));
      QMessageBox::question(
          this, tr("File Saved in :"), Filename, QMessageBox::Ok );//POPUP indiquant le chemin d'accès du fichier

}

}

