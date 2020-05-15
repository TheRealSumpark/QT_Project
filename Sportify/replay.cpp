#include "replay.h"
#include "ui_replay.h"


Replay::Replay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Replay)
{
    ui->setupUi(this);
    this->setFixedSize(720,480);
    QPixmap Background_Pic("C:/Users/toshiba/Desktop/Sportify/Integration/images_projet/match.jpg");

    ui->Background_pic->setPixmap(Background_Pic.scaled( ui->Background_pic->width(), ui->Background_pic->height()));

    Video_Path="";
    Thumbnail_Path="";


}


void Replay::Ajouter_Replay()
{

    ui->stackedWidget->setCurrentIndex(0);

}

Replay::~Replay()
{
    delete ui;
}

void Replay::on_Replay_Video_clicked()
{
      Video_Path = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "C://", tr("Video Files (*.avi *.mp4 *.mkv *.mov)"));
      //QString::compare(Video_Path,QString())!=0
     if (!Video_Path.isEmpty())
     {
        ui->Replay_Video_Path->setText(Video_Path);

     }



}

void Replay::on_Replay_Thumbnail_clicked()
{
    Thumbnail_Path = QFileDialog::getOpenFileName(this,
       tr("Open Video"), "C://", tr("Video Files (*.png *.jpg *.bmp)"));


 if (QString::compare(Thumbnail_Path,QString())!=0)
    {
    QPixmap Thumbnail_Pic=(Thumbnail_Path);
    ui->Replay_Thumbnail_Path->setPixmap(Thumbnail_Pic.scaled(ui->Replay_Thumbnail_Path->width(),ui->Replay_Thumbnail_Path->height(),Qt::KeepAspectRatio));
    //ui->Replay_Thumbnail_Path->setText(Thumbnail_Path);

}

}

void Replay::on_Replay_Submit_clicked()
{
    QPalette red ;
    QPalette white  ;
    red.setColor(QPalette::Base,Qt::red);
    white.setColor(QPalette::Base,Qt::white);

    if (QString::compare(Thumbnail_Path,QString())!=0 && QString::compare(Video_Path,QString())!=0 && !ui->Replay_Title->text().trimmed().isEmpty())
    {
        Add_Values_To_Replays_Table();
    }

    else {
        if (!ui->Replay_Title->text().trimmed().isEmpty())
        {  ui->Replay_Title->setPalette(white);}
        else if (ui->Replay_Title->text().trimmed().isEmpty())
         { ui->Replay_Title->setPalette(red);}

        QMessageBox::warning(nullptr, QObject::tr(""),
                      QObject::tr("Veuillez Remplir tous les champs\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void Replay::Add_Values_To_Replays_Table()
{

    QSqlQuery query;
    query.prepare(" insert into \"Sportify\".\"REPLAYS\""
                  "(ID,THUMBNAIL_PATH,VIDEO_PATH,TITLE)"
              "values (\"Sportify\".\"REPLAYS_SEQ\".NEXTVAL,?,?,?);");

    query.addBindValue(Thumbnail_Path);
    query.addBindValue(Video_Path);
    query.addBindValue(ui->Replay_Title->text());

  if (!query.exec())
    {
    qDebug()<<"Error adding values to replays table";
    }

    else {
        QMessageBox::information(nullptr, QObject::tr(""),
                    QObject::tr("Ajout avec Succès\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}



void Replay::on_Replay_Cancel_clicked()
{
    this->close();
}
