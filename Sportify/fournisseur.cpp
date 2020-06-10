#include "fournisseur.h"
#include "ui_fournisseur.h"

Fournisseur::Fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fournisseur)
{
    ui->setupUi(this);

    this->setFixedSize(600,500);
    ui->stackedWidget->setCurrentIndex(0);

    QPixmap Background_Pic("C:/Users/toshiba/Desktop/C++/QtApp/pics/match.jpg");

    ui->Background_Pic->setPixmap(Background_Pic.scaled( ui->Background_Pic->width(), ui->Background_Pic->height()));

}

Fournisseur::~Fournisseur()
{
    delete ui;
}

void Fournisseur::on_Fournisseur_Ajout_Cancel_clicked()
{
        this->close();
}

void Fournisseur::on_Fournisseur_Ajout_Submit_clicked()
{
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);
        if(ui->Fournisseur_Ajout_Nom->text().isEmpty())
    {     ui->Fournisseur_Ajout_Nom->setPalette(*red) ; error=1;}
        else {  ui->Fournisseur_Ajout_Nom->setPalette(*white); }
        if(ui->Fournisseur_Ajout_Adresse->text().isEmpty())
    {       ui->Fournisseur_Ajout_Adresse->setPalette(*red)  ;error=1;}
        else {  ui->Fournisseur_Ajout_Adresse->setPalette(*white); }

 if (!error)
    Add_Values_To_Db(ui->Fournisseur_Ajout_Nom->text(),ui->Fournisseur_Ajout_Adresse->text());
}




void Fournisseur::Add_Values_To_Db(QString Nom , QString Adresse)
{


    QSqlQuery query;
    query.prepare(" insert into \"Sportify\".\"FOURNISSEURS\""
                  "(Id,Nom,Adresse) values (\"Sportify\".\"FOURNISSEURS_SEQ\".NEXTVAL,?,?);");

    query.addBindValue(Nom);
    query.addBindValue(Adresse);


    if (!query.exec())
    {
    qDebug()<<"Error adding values to fournisseurs table";
    }

    else {
        QMessageBox::information(nullptr, QObject::tr(""),
                    QObject::tr("Ajout avec Succès\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void Fournisseur::Afficher_Liste_Fournisseurs()
{   QSqlQuery query;

     ui->stackedWidget->setCurrentIndex(1);

     model = new QSqlTableModel(this);

     model->setTable("\"Sportify\".\"FOURNISSEURS\"");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);


     model->select();


     model->setHeaderData(0, Qt::Horizontal, tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, tr("Adresse"));

     view= new QTableView;

     view->setStyleSheet("QTableView { border: none;"
                                         "background-color: white;"
                                         "selection-background-color: #999}");
     view->setModel(model);

     view->resizeColumnsToContents();
     view->setSortingEnabled(true);
     view->setColumnHidden(0,true);



            submitButton = new QPushButton(tr("Submit"));
            submitButton->setDefault(true);
            revertButton = new QPushButton(tr("&Revert"));
            deleteButton = new QPushButton(tr("Delete"));
            quitButton = new QPushButton(tr("Quit"));
            pdfButton= new QPushButton(tr("GeneratePdf"));


            buttonBox = new QDialogButtonBox(Qt::Vertical);
            buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
            buttonBox->addButton(deleteButton ,QDialogButtonBox::ActionRole);
            buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);

            buttonBox->addButton(quitButton, QDialogButtonBox::ActionRole);
            QDialogButtonBox *buttonBox1;
            buttonBox1 = new QDialogButtonBox(Qt::Horizontal);
            buttonBox1->addButton(pdfButton, QDialogButtonBox::ActionRole);

            buttonBox1->setCenterButtons(true);

            //Connection des boutons avec leurs fonctions relatives
            connect(deleteButton, &QPushButton::clicked,this, &Fournisseur::remove);
            connect(submitButton, &QPushButton::clicked, this, &Fournisseur::submit);
            connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
            connect(quitButton, &QPushButton::clicked, this, &Fournisseur::close);
            connect(pdfButton,&QPushButton::clicked, this, &Fournisseur::generate_Pdf);

            connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
            ui->horizontalLayout->addWidget(view);
            ui->horizontalLayout->addWidget(buttonBox);
            ui->horizontalLayout_2->setAlignment(Qt::AlignHCenter);
            ui->horizontalLayout_2->addWidget(buttonBox1);

                    setWindowTitle(tr("Liste Des Fournisseurs"));


                    qDebug()<<view->selectionModel()->selectedIndexes();
                    QModelIndex index = view->selectionModel()->currentIndex();
                   QString id=view->model()->index(index.row(),0).data().toString();
                  qDebug()<<id;


}

void Fournisseur::remove()
{
   // récupère la listes des lignes sélectionnées
    QModelIndexList selection = view->selectionModel()->selectedIndexes();


    for(int i=0; i< selection.count(); i++)
    {
       model->removeRow(selection[i].row());

    }



}


void Fournisseur::submit()
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




void Fournisseur::generate_Pdf()
{


    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Fournisseurs"), "C://",
           tr("(*.pdf)"));
if (!Filename.isEmpty())

   { QPrinter printer(QPrinter::PrinterResolution);
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



 void Fournisseur::onTableClicked(const QModelIndex &index)
 {
   /*  if (index.isValid()) {


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

     }*/


 }
