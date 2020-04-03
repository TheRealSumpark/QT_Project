#ifndef AJOUTER_JOUEUR_EQUIPE_H
#define AJOUTER_JOUEUR_EQUIPE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class ajouter_joueur_equipe;
}

class ajouter_joueur_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_joueur_equipe(QWidget *parent = nullptr);
    ~ajouter_joueur_equipe();
    int save_number=0;

private slots:
    void on_comboBox_joueur_currentIndexChanged(const QString &arg1);

    void on_comboBox_equipe_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_Ajouter_joueur_equipe_clicked();

private:
    Ui::ajouter_joueur_equipe *ui;
};

#endif // AJOUTER_JOUEUR_EQUIPE_H
