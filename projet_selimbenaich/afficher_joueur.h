#ifndef AFFICHER_JOUEUR_H
#define AFFICHER_JOUEUR_H

#include <QDialog>

namespace Ui {
class Afficher_joueur;
}

class Afficher_joueur : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher_joueur(QWidget *parent = nullptr);
    ~Afficher_joueur();

private slots:

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Afficher_joueur *ui;
};

#endif // AFFICHER_JOUEUR_H
