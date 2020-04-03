#include "match_main.h"
#include "ui_match_main.h"

#include "mainwindow.h"



Match_Main::Match_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Match_Main)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentIndex(0);
     QPixmap Background_Pic("C:/Users/toshiba/Desktop/C++/QtApp/pics/match.jpg");
     ui->Background_pic->setPixmap(Background_Pic.scaled(ui->Background_pic->width(),ui->Background_pic->height()));
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
 Db_Add_Values_To_Match_Table(ui->Match_Home->text(),ui->Match_Visitor->text(),ui->Match_date->selectedDate(), ui->Match_stadium->text(),Home_Team_Pic,Away_Team_Pic);
}




void Match_Main::Db_Add_Values_To_Match_Table(QString Home_Team,QString Visitor_Team , QDate Play_Date, QString Location,QString Home_Team_Pic,QString Away_Team_Pic)
{
    QSqlQuery query;
    query.prepare(" insert into \"Sumpark\".\"Matchs\"(Id,Home_Team,Visitor_Team,Play_Date,Location,Home_Team_Pic,Away_Team_Pic) values (\"Sumpark\".\"Matchs_SEQ\".NEXTVAL,?,?,?,?,?,?);");

    query.addBindValue(Home_Team);
    query.addBindValue(Visitor_Team);
    //query.addBindValue(QDateTime::fromString("mm/dd/yyyy"));
    query.addBindValue(Play_Date);
    query.addBindValue(Location);
    query.addBindValue(Home_Team_Pic);
    query.addBindValue(Away_Team_Pic);

    if (!query.exec())
    {
    qDebug()<<"Error adding values to matchs table";
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
   // QSqlQueryModel *Model= new QSqlQueryModel();



     ui->stackedWidget->setCurrentIndex(1);

     //TableEditor  editor("\"Sumpark\".\"Matchs\"",ui->page_2);

   // query.exec("select * from \"Sumpark\".\"Matchs\" ");
   // Model->setQuery(query);

   //ui->Matchs_List->setModel(editor);

   // editor.show();

     model = new QSqlTableModel(this);
     model->setTable("\"Sumpark\".\"Matchs\"");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     model->select();

     model->setHeaderData(0, Qt::Horizontal, tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, tr("Home Team"));
     model->setHeaderData(2, Qt::Horizontal, tr("Visitor Team"));
     model->setHeaderData(3, Qt::Horizontal, tr("Location"));
     model->setHeaderData(4, Qt::Horizontal, tr("Play Date"));



     //view = ui->Matchs_List;
     QTableView *view= new QTableView;
     view->setModel(model);
     view->resizeColumnsToContents();


            submitButton = new QPushButton(tr("Submit"));
            submitButton->setDefault(true);
            revertButton = new QPushButton(tr("&Revert"));
            deleteButton = new QPushButton(tr("Delete"));
            quitButton = new QPushButton(tr("Quit"));
            pdfButton= new QPushButton(tr("GeneratePdf"));
            jsonButton =new QPushButton (tr("Generate Json"));

            buttonBox = new QDialogButtonBox(Qt::Vertical);
            buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
            buttonBox->addButton(revertButton, QDialogButtonBox::ResetRole);
            buttonBox->addButton(deleteButton , QDialogButtonBox::ActionRole);
            buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
            buttonBox->addButton(pdfButton, QDialogButtonBox::ActionRole);
            buttonBox->addButton(jsonButton,QDialogButtonBox::ActionRole);

          /*  QModelIndex curIndex =view->currentIndex();
            QSqlRecord record = model->record(curIndex.row());
            model->removeRow(curIndex.row());*/

            connect(submitButton, &QPushButton::clicked, this, &Match_Main::submit);
            connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
            connect(quitButton, &QPushButton::clicked, this, &Match_Main::close);
            connect(deleteButton,&QPushButton::clicked, this, &Match_Main::remove);
            connect(pdfButton,&QPushButton::clicked, this, &Match_Main::choose_Filename);
            connect(jsonButton,&QPushButton::clicked,this,&Match_Main::generate_Json);
            connect(view, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
                   ui->horizontalLayout_4->addWidget(view);
                   ui->horizontalLayout_4->addWidget(buttonBox);


                    setWindowTitle(tr("Cached Table"));

            QModelIndex index = view->selectionModel()->currentIndex();
           QString id=view->model()->index(index.row(),0).data().toString();
          qDebug()<<id;



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

void Match_Main::remove()
{


    QModelIndexList selection = view->selectionModel()->selectedRows();

    // Multiple rows can be selected
    for(int i=0; i< selection.count(); i++)
    {
       model->removeRow(i);

    }



}



void Match_Main::choose_Filename()
{

    ui->stackedWidget->setCurrentIndex(2) ;
    connect(ui->Filename_Submit,&QPushButton::clicked, this, &Match_Main::generate_Pdf);
}



 QString Match_Main:: getFilename()
 {
        return ui->File_name->text();
 }

void Match_Main::on_Filename_Cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Match_Main::generate_Pdf()
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

void Match_Main::generate_Json()
{

   QJsonObject obj;//root object

       QJsonArray Matchs;//(2)

        QSqlQuery query;

       query.exec("select * from \"Sumpark\".\"Matchs\"");
       while(query.next())//load all data from the database
       {
           QJsonObject Match;//(3)
           Match["Id"] = query.value(0).toInt();//(4)
           Match["Home_Team"] = query.value(1).toString();
           Match["Visitor_Team"] = query.value(2).toString();
           Match["Location"] = query.value(3).toString();
           Match["Play_Date"] = query.value(4).toString();
           Matchs.append(Match);//(5)
       }
       obj["Matchs"] = Matchs;//(6)

     QFile file("C:/Users/toshiba/Desktop/C++/text.json");
       file.open(QFile::WriteOnly);
       file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));



}
void Match_Main::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {


        QModelIndex id_index = model->index(index.row(),0, QModelIndex());
        int id = id_index.data().toInt();
        qDebug()<<id;

        QSqlQuery query;
        query.prepare("select Home_Team_Pic,Away_Team_Pic from \"Sumpark\".\"Matchs\" where Id =:id;");
        query.bindValue(":id",id);
        if (!query.exec())
        {qDebug("Error fetching pics");}
           else {
            qDebug()<<query.first();
            qDebug()<<query.value(0).toString();
            qDebug()<<query.value(1).toString();
            QPixmap Background_Pic=(query.value(0).toString());
            ui->Home_Team_Pic->setPixmap(Background_Pic.scaled(ui->Home_Team_Pic->width(),ui->Home_Team_Pic->height()));
            Background_Pic=(query.value(1).toString());
            ui->Away_Team_Pic->setPixmap(Background_Pic.scaled(ui->Away_Team_Pic->width(),ui->Away_Team_Pic->height()));

        }

    }
}
