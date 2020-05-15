#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "connection.h"
#include "replay.h"
#include "video_stream.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


private slots:


    void  Media_Status_Changed(QMediaPlayer::MediaStatus status );

    void Main_Menu();

    void on_Main_Menu_Yassine_clicked();

    void on_Main_Menu_Selim_clicked();

    void on_Main_button_afficher_matchs_clicked();

    void on_Main_button_match_clicked();

    void on_Main_button_tournois_clicked();

    void on_Main_button_afficher_tournois_clicked();




    void on_Go_Back_clicked();

    void on_Gestion_joueur_clicked();

    void on_Modifier_joueur_clicked();

    void on_fichier_pdf_clicked();

    void on_Go_Back_2_clicked();

    void on_Main_button_Afficher_Replay_clicked();


    void on_Main_Menu_Regarder_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
