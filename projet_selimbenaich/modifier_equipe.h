#ifndef MODIFIER_EQUIPE_H
#define MODIFIER_EQUIPE_H

#include <QDialog>

namespace Ui {
class modifier_equipe;
}

class modifier_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_equipe(QWidget *parent = nullptr);
    ~modifier_equipe();
    QString filename;
    int total_joueur;
    QString save_nom_equipe;
    QString save_id_joueur;
    int verif_retirer=0;
    int verif_annuler=0;
    int calcul_erreur=0;
    int total_j=0;
    int save_total_j=0;
    int appl_equipe=0;
    int test_retire=0;
    void Afficher_modif_eq();
private slots:
    void on_b_image_clicked();

    void on_afficher_modif_activated(const QModelIndex &index);

    void on_afficher_modif_2_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_Appliquer_modification_clicked();

    void on_Annuler_clicked();

    void on_modifier_equipe_finished(int result);

private:
    Ui::modifier_equipe *ui;
};

#endif // MODIFIER_EQUIPE_H
