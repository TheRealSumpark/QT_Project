#ifndef SUPPRIMER_JOUEUR_H
#define SUPPRIMER_JOUEUR_H

#include <QDialog>

namespace Ui {
class Supprimer_joueur;
}

class Supprimer_joueur : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer_joueur(QWidget *parent = nullptr);
    ~Supprimer_joueur();
    void Afficher_supp_j();

private slots:
    void on_pushButton_clicked();

    void on_afficher_sup_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::Supprimer_joueur *ui;
};

#endif // SUPPRIMER_JOUEUR_H
