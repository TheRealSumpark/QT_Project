#ifndef SUPPRIMER_EQUIPE_H
#define SUPPRIMER_EQUIPE_H

#include <QDialog>

namespace Ui {
class supprimer_equipe;
}

class supprimer_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_equipe(QWidget *parent = nullptr);
    ~supprimer_equipe();
   QString save_nom_equipe;
void Afficher_supp_eq();
private slots:
    void on_annuler_la_suppression_clicked();

    void on_comboBox_equipe_currentIndexChanged(const QString &arg1);

    void on_listView_activated(const QModelIndex &index);

    void on_supprimer_equipe_2_clicked();

private:
    Ui::supprimer_equipe *ui;
};

#endif // SUPPRIMER_EQUIPE_H
