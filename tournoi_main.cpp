#include "tournoi_main.h"
#include "ui_tournoi_main.h"


Tournoi_Main::Tournoi_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tournoi_Main)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap Background_Pic("C:/Users/toshiba/Desktop/C++/QtApp/pics/cup.jpg");
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
     Db_Add_Values_To_Tournois_Table(ui->Tournoi_Nom->text(), ui->Tournoi_Categorie->text(),ui->Tournoi_Date->text(), ui->Tournoi_NbParticipants->value());
}


void Tournoi_Main::Db_Add_Values_To_Tournois_Table(QString Nom ,QString Categorie,QString Date_Lancement,int Nb_Participants)
{
    QSqlQuery query;
    query.prepare(" insert into \"Sumpark\".\"TOURNOIS\"(Id,Nom,Categorie,Date_Lancement,Nb_Participants) values (\"Sumpark\".\"TOURNOIS_SEQ\".NEXTVAL,?,?,?,?);");

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
    this->close();
    }

}

void Tournoi_Main::Db_Afficher_Liste_Tournois()
{
      ui->stackedWidget->setCurrentIndex(1);
      QSqlQuery query;

      model = new QSqlTableModel(this);
      model->setTable("\"Sumpark\".\"TOURNOIS\"");
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
             buttonBox->addButton(pdfButton, QDialogButtonBox::ActionRole);
             buttonBox->addButton(jsonButton,QDialogButtonBox::ActionRole);
             buttonBox->addButton(quitButton, QDialogButtonBox::ActionRole);

             QModelIndex curIndex =view->currentIndex();
             QSqlRecord record = model->record(curIndex.row());
             model->removeRow(curIndex.row());

             connect(submitButton, &QPushButton::clicked, this, &Tournoi_Main::submit);
             connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
             connect(quitButton, &QPushButton::clicked, this, &Tournoi_Main::close);
             connect(deleteButton,&QPushButton::clicked, this, &Tournoi_Main::remove);
             connect(pdfButton,&QPushButton::clicked, this, &Tournoi_Main::choose_Filename);
             connect(jsonButton,&QPushButton::clicked,this,&Tournoi_Main::generate_Json);

                    ui->horizontalLayout->addWidget(view);
                    ui->horizontalLayout->addWidget(buttonBox);


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
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOrientation(QPrinter::Landscape);
     QString BasePath="C:/Users/toshiba/Desktop/C++/";
     QString Filename=BasePath.append(this->getFilename()).append(".pdf");
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
    ui->stackedWidget->setCurrentIndex(1);

}

void Tournoi_Main::generate_Json()
{

   QJsonObject obj;//root object

       QJsonArray Tournois;//(2)

        QSqlQuery query;

       query.exec("select * from \"Sumpark\".\"TOURNOIS\"");
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

     QFile file("C:/Users/toshiba/Desktop/C++/text.json");
       file.open(QFile::WriteOnly);
       file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));



}


QString Tournoi_Main:: getFilename()
{
       return ui->Filename->text();
}

void Tournoi_Main::on_Filename_Cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Tournoi_Main::choose_Filename()
{

    ui->stackedWidget->setCurrentIndex(2) ;
    connect(ui->Filename_Submit,&QPushButton::clicked, this, &Tournoi_Main::generate_Pdf);
}

