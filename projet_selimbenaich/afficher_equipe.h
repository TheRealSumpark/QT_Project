#ifndef AFFICHER_EQUIPE_H
#define AFFICHER_EQUIPE_H

#include <QDialog>

namespace Ui {
class afficher_equipe;
}

class afficher_equipe : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_equipe(QWidget *parent = nullptr);
    ~afficher_equipe();

private slots:
    void on_comboBox_equipe_currentIndexChanged(const QString &arg1);

    void on_undoView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::afficher_equipe *ui;
};

#endif // AFFICHER_EQUIPE_H
