#ifndef GESTION_JOUEUR_H
#define GESTION_JOUEUR_H

#include <QDialog>

namespace Ui {
class gestion_joueur;
}

class gestion_joueur : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_joueur(QWidget *parent = nullptr);
    ~gestion_joueur();
private slots:
    void on_Ajouter_joueur_clicked();

    void on_Afficher_joueur_clicked();

    void on_Supprimer_joueur_clicked();

    void on_Modifier_joueur_clicked();

    void on_Afficher_joueur_2_clicked();

private:
    Ui::gestion_joueur *ui;
};

#endif // GESTION_JOUEUR_H
