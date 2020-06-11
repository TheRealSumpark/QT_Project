#include "equipements.h"
#include "ui_equipements.h"

Equipements::Equipements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipements)
{
    ui->setupUi(this);


    this->setFixedSize(600,500);
    ui->stackedWidget->setCurrentIndex(0);

    QPixmap Background_Pic("../images_projet/Equipements_Background.jpg");

    ui->Background_Pic->setPixmap(Background_Pic.scaled( ui->Background_Pic->width(), ui->Background_Pic->height()));


}

Equipements::~Equipements()
{
    delete ui;
}


void Equipements::on_Equipement_Ajout_Submit_clicked()

{
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);
        if(ui->Equipement_Ajout_Nom->text().trimmed().isEmpty())
    {     ui->Equipement_Ajout_Nom->setPalette(*red) ; error=1;}
        else {  ui->Equipement_Ajout_Nom->setPalette(*white); }
        if(ui->Equipement_Ajout_Quantite->value() <=0 || QString::compare(Logo,QString())==0)
      { error=1;
            QMessageBox::warning(nullptr, QObject::tr(""),
                                QObject::tr("Veuillez Remplir tous les champs , choisir Image et definir une quantite supérieure à 0 \n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}


 if (!error)
    Add_Values_To_Db(ui->Equipement_Ajout_Nom->text(),ui->Equipement_Ajout_Quantite->value(),Logo);
}




void Equipements::Add_Values_To_Db(QString Nom , int  Quantite ,QString Logo)
{


    QSqlQuery query;
    query.prepare(" insert into \"Sportify\".\"EQUIPEMENTS\""
                  "(Id,Nom,Quantite,Image) values (\"Sportify\".\"EQUIPEMENTS_SEQ\".NEXTVAL,?,?,?);");

    query.addBindValue(Nom);
    query.addBindValue(Quantite);
    query.addBindValue(Logo);


    if (!query.exec())
    {
    qDebug()<<"Error adding values to Equipements table";
    }

    else {
        QMessageBox::information(nullptr, QObject::tr(""),
                    QObject::tr("Ajout avec Succès\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void Equipements::Afficher_Liste_Equipements()
{   QSqlQuery query;

     ui->stackedWidget->setCurrentIndex(1);

     model = new QSqlTableModel(this);

     model->setTable("\"Sportify\".\"EQUIPEMENTS\"");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);


     model->select();


     model->setHeaderData(0, Qt::Horizontal, tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, tr("Quantite"));
     model->setHeaderData(3, Qt::Horizontal, tr("Image"));

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
            connect(deleteButton, &QPushButton::clicked,this, &Equipements::remove);
            connect(submitButton, &QPushButton::clicked, this, &Equipements::submit);
            connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
            connect(quitButton, &QPushButton::clicked, this, &Equipements::close);
            connect(pdfButton,&QPushButton::clicked, this, &Equipements::generate_Pdf);

            connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
            ui->horizontalLayout->addWidget(view);
            ui->horizontalLayout->addWidget(buttonBox);
            ui->horizontalLayout_2->setAlignment(Qt::AlignHCenter);
            ui->horizontalLayout_2->addWidget(buttonBox1);

                    setWindowTitle(tr("Liste Des Equipementss"));


                    qDebug()<<view->selectionModel()->selectedIndexes();
                    QModelIndex index = view->selectionModel()->currentIndex();
                   QString id=view->model()->index(index.row(),0).data().toString();
                  qDebug()<<id;


}

void Equipements::remove()
{
   // récupère la listes des lignes sélectionnées
    QModelIndexList selection = view->selectionModel()->selectedIndexes();


    for(int i=0; i< selection.count(); i++)
    {
       model->removeRow(selection[i].row());

    }



}


void Equipements::submit()
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




void Equipements::generate_Pdf()
{


    QString Filename = QFileDialog::getSaveFileName(this,
           tr("Sauvegarder Table Equipements"), "C://",
           tr("(*.pdf)"));
if (!Filename.isEmpty())

   { QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOrientation(QPrinter::Landscape);

    printer.setOutputFileName(Filename);


    QTextDocument doc;

    QString text("<table width=\"100%\" border=\"1\"><thead>");
    text.append("<caption>Liste des equipements </caption>");
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



 void Equipements::onTableClicked(const QModelIndex &index)
 {
     if (index.isValid()) {


         QModelIndex id_index = model->index(index.row(),0, QModelIndex());
         int id = id_index.data().toInt();
         qDebug()<<id;

         QSqlQuery query;
         query.prepare("select Image from \"Sportify\".\"EQUIPEMENTS\" where Id =:id;");
         query.bindValue(":id",id);
         if (!query.exec())
         {qDebug("Error fetching pics");}
            else {
             qDebug()<<query.first();
             qDebug()<<query.value(0).toString();

             QPixmap Background_Pic=(query.value(0).toString());


             ui->Equipement_Affichage_Logo->setPixmap(Background_Pic.scaled(ui->Equipement_Affichage_Logo->width(),ui->Equipement_Affichage_Logo->height(),Qt::KeepAspectRatio));


         }

     }


 }



void Equipements::on_Equipement_Ajout_Cancel_clicked()
{
    this->close();
}


void Equipements::on_Equipement_Ajout_Image_clicked()
{QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.jpeg *.png *.jpg *.bmp *.gif"));

    QImage pic;
        bool valid =pic.load(filename);
        if (QString::compare(filename,QString())!=0)
      {if (valid)
   {pic=pic.scaledToHeight(ui->Equipement_Ajout_Image->height(),Qt::SmoothTransformation);
          ui->Equipement_Ajout_Image_Display->setPixmap(QPixmap::fromImage(pic));
          Logo=filename;
            }}

}
