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

    void on_Main_button_ajouter_fournisseur_clicked();


    void on_Main_Menu_Oussema_clicked();



    void on_Go_Back_3_clicked();



    void on_Main_Menu_Taib_clicked();

    void on_Main_button_ajouter_equipement_clicked();

    void on_Main_button_afficher_fournisseurs_clicked();

    void on_Main_button_afficher_equipements_clicked();

    void on_Main_Menu_Khaled_clicked();

    void on_pushButton_clicked();

    void on_Main_Menu_Regarder_2_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
