#ifndef REPLAY_H
#define REPLAY_H

#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>


namespace Ui {
class Replay;
}

class Replay : public QDialog
{
    Q_OBJECT

public:
    explicit Replay(QWidget *parent = nullptr);
    ~Replay();

    QString Video_Path;
    QString Thumbnail_Path;
    void Ajouter_Replay();
    void Add_Values_To_Replays_Table();
private slots:
    void on_Replay_Video_clicked();

    void on_Replay_Thumbnail_clicked();

    void on_Replay_Submit_clicked();

    void on_Replay_Cancel_clicked();

private:
    Ui::Replay *ui;


};

#endif // REPLAY_H
