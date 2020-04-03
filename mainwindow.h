#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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
    void on_Main_button_match_clicked();

    void on_Main_button_tournois_clicked();

    void on_Main_button_afficher_matchs_clicked();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_Main_button_afficher_tournois_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
