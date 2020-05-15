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
        int verif=0;
private slots:
    void on_b_image_clicked();

    void on_pushButton_2_clicked();

    void on_Ajouter_equipe_2_clicked();

private:
    Ui::Ajouter_equipe *ui;
};

#endif // AJOUTER_EQUIPE_H
