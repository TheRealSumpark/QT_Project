#ifndef GESTION_EQUIPE_H
#define GESTION_EQUIPE_H

#include <QDialog>

namespace Ui {
class gestion_equipe;
}

class gestion_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_equipe(QWidget *parent = nullptr);
    ~gestion_equipe();

private slots:
    void on_Ajouter_equipe_clicked();

    void on_Afficher_equipe_clicked();

    void on_Supprimer_equipe_clicked();

    void on_Modifier_equipe_clicked();

    void on_Afficher_equipe_2_clicked();

    void on_Ajouter_equipe_2_clicked();

private:
    Ui::gestion_equipe *ui;
};

#endif // GESTION_EQUIPE_H
