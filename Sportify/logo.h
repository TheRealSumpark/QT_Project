#ifndef LOGO_H
#define LOGO_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "mainwindow.h"


namespace Ui {
class LOGO;
}

class LOGO : public QMainWindow
{
    Q_OBJECT

public:
    explicit LOGO(QWidget *parent = nullptr);
    ~LOGO();
private slots:
    void Media_Status_Changed(QMediaPlayer::MediaStatus);

private:
    Ui::LOGO *ui;
    QMediaPlayer *player =new QMediaPlayer;
    QVideoWidget *video = new QVideoWidget;
};

#endif // LOGO_H
