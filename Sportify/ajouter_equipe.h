#ifndef AJOUTER_EQUIPE_H
#define AJOUTER_EQUIPE_H

#include <QDialog>

namespace Ui {
class Ajouter_equipe;
}

class Ajouter_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_equipe(QWidget *parent = nullptr);
    ~Ajouter_equipe();
    QString filename;
    int total_joueur;
        QPixmap PixTrueIcon;
        QPixmap PixFalseIcon;
        bool verifNom();
        bool verifImage();
        bool verifCategorie();
        bool verifManager();
        bool verifScore();
private slots:
    void on_b_image_clicked();

    void on_pushButton_2_clicked();

    void on_Ajouter_equipe_2_clicked();

    void on_in_nom_cursorPositionChanged(int arg1, int arg2);

    void on_in_categorie_cursorPositionChanged(int arg1, int arg2);

    void on_in_manager_cursorPositionChanged(int arg1, int arg2);

    void on_in_score_valueChanged(int arg1);

private:
    Ui::Ajouter_equipe *ui;
};

#endif // AJOUTER_EQUIPE_H
