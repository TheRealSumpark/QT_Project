#ifndef MODIFIER_JOUEUR_H
#define MODIFIER_JOUEUR_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QSqlTableModel>
#include <QTableView>

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
    void Display();
private slots:

    void onTableClicked(const QModelIndex &index);

    void on_b_image_clicked();

    void Db_Afficher_Liste_Matchs();

    void submit();

private:
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QTableView *view;
    Ui::Modifier_joueur *ui;
};

#endif // MODIFIER_JOUEUR_H
