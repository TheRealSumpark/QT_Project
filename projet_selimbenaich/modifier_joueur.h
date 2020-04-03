#ifndef MODIFIER_JOUEUR_H
#define MODIFIER_JOUEUR_H

#include <QDialog>

namespace Ui {
class Modifier_joueur;
}

class Modifier_joueur : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier_joueur(QWidget *parent = nullptr);
    ~Modifier_joueur();
    QString filename;
    QString save_id;
    void Afficher_modif_j();
private slots:
    void on_afficher_modif_activated(const QModelIndex &index);

    void on_b_image_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Modifier_joueur *ui;
};

#endif // MODIFIER_JOUEUR_H
