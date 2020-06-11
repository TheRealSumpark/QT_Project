#include "logo.h"
#include "ui_logo.h"
#include "login.h"



LOGO::LOGO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LOGO)
{

    ui->setupUi(this);
     this->setFixedSize(720,480);
    player->setVideoOutput(video);
    player->setMedia(QUrl::fromLocalFile("../images_projet/199963.avi"));
    video->setGeometry(0,0,720,480);
    video->setParent(ui->Logo);

    player->play();
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
               this, SLOT(Media_Status_Changed(QMediaPlayer::MediaStatus)));


}

LOGO::~LOGO()
{
    delete ui;
}


void LOGO::Media_Status_Changed(QMediaPlayer::MediaStatus status)
{
    if (status== QMediaPlayer::EndOfMedia)
    {
        this->close();
      login *l = new login;
      l->show();

    }
}
