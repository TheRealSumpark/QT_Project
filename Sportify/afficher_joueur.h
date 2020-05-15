#ifndef AFFICHER_JOUEUR_H
#define AFFICHER_JOUEUR_H

#include <QDialog>
#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHeaderView>

#include "statclass.h"
#include <qcustomplot.h>

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
    StatClass statClass;
};

#endif // AFFICHER_JOUEUR_H
