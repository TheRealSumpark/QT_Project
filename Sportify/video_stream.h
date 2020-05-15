#ifndef VIDEO_STREAM_H
#define VIDEO_STREAM_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QVideoFrame>
#include <QListWidget>
#include <QIcon>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QtSql>
#include "media_player.h"



namespace Ui {

class VIDEO_STREAM;
}


class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VIDEO_STREAM : public QDialog
{
    Q_OBJECT

public:
    explicit VIDEO_STREAM(QWidget *parent = nullptr);
    ~VIDEO_STREAM();

private slots :

  void  Play_Video(QListWidgetItem *item);

private:
    Ui::VIDEO_STREAM *ui;

};

#endif // VIDEO_STREAM_H
