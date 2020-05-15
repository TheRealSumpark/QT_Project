#include "video_stream.h"
#include "ui_video_stream.h"
#include <QUrl>

VIDEO_STREAM::VIDEO_STREAM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VIDEO_STREAM)
{
    ui->setupUi(this);
    this->setFixedSize(720,480);

    QVBoxLayout *layout=new QVBoxLayout(this);
    QListWidget *list=new  QListWidget;
    layout->addWidget(list);
    list->setViewMode(QListView::IconMode);
    list->setMovement(QListView::Static);
    list->setIconSize(QSize(200,150));




    QString path;
    QSqlQuery query;
    QString title;
   query.exec("select * from \"Sportify\".\"REPLAYS\"");

 //QListWidgetItem *item = new QListWidgetItem;
int id;
  while  (query.next())
   {    id=query.value(0).toInt();
        path=query.value(query.record().indexOf("THUMBNAIL_PATH")).toString();
        title=query.value(query.record().indexOf("TITLE")).toString();

        QListWidgetItem *item = new QListWidgetItem (QIcon(path), QString::number(id)+"_"+title );
          list->addItem(item);

   }

   connect(list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,SLOT(Play_Video(QListWidgetItem*)) );
}

VIDEO_STREAM::~VIDEO_STREAM()
{
    delete ui;
}
void VIDEO_STREAM::Play_Video(QListWidgetItem * item)
{


    QSqlQuery query;
    query.prepare("select * from \"Sportify\".\"REPLAYS\" where ID=:id");

     query.bindValue(":id",item->text().section('_',0,0).toInt());

     qDebug()<<item->text().section('_',0,0);
       query.exec();
       query.first();
     QString path=query.value(query.record().indexOf("VIDEO_PATH")).toString();
     qDebug()<<query.value(query.record().indexOf("VIDEO_PATH")).toString();
    MEDIA_PLAYER *player=new MEDIA_PLAYER(path);
    player->setWindowModality(Qt::ApplicationModal);
    player->show();


}
