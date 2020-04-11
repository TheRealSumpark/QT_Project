#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "match_main.h"
#include "tournoi_main.h"

#include <QStackedWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Main_button_match_clicked()
{
    Match_Main Match_ui;

    Match_ui.exec();
}

void MainWindow::on_Main_button_afficher_matchs_clicked()
{
    Match_Main Match_ui;
    Match_ui.Db_Afficher_Liste_Matchs();
    Match_ui.exec();




}

void MainWindow::on_Main_button_tournois_clicked()
{
        Tournoi_Main Tournoi_ui;
        Tournoi_ui.exec();
}



void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

    MainWindow ui;
    ui.adjustSize();
}


void MainWindow::on_Main_button_afficher_tournois_clicked()
{
    Tournoi_Main Tournoi_ui;
    Tournoi_ui.Db_Afficher_Liste_Tournois();
    Tournoi_ui.exec();

}
