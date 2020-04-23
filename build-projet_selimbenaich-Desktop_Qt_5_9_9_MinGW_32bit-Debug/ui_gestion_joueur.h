/********************************************************************************
** Form generated from reading UI file 'gestion_joueur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_JOUEUR_H
#define UI_GESTION_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gestion_joueur
{
public:
    QPushButton *Modifier_joueur;
    QLabel *label;
    QPushButton *Supprimer_joueur;
    QPushButton *Afficher_joueur;
    QPushButton *Ajouter_joueur;
    QPushButton *Afficher_joueur_2;

    void setupUi(QDialog *gestion_joueur)
    {
        if (gestion_joueur->objectName().isEmpty())
            gestion_joueur->setObjectName(QStringLiteral("gestion_joueur"));
        gestion_joueur->resize(661, 459);
        Modifier_joueur = new QPushButton(gestion_joueur);
        Modifier_joueur->setObjectName(QStringLiteral("Modifier_joueur"));
        Modifier_joueur->setGeometry(QRect(30, 100, 181, 31));
        label = new QLabel(gestion_joueur);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 661, 461));
        label->setFocusPolicy(Qt::StrongFocus);
        Supprimer_joueur = new QPushButton(gestion_joueur);
        Supprimer_joueur->setObjectName(QStringLiteral("Supprimer_joueur"));
        Supprimer_joueur->setGeometry(QRect(30, 170, 181, 31));
        Afficher_joueur = new QPushButton(gestion_joueur);
        Afficher_joueur->setObjectName(QStringLiteral("Afficher_joueur"));
        Afficher_joueur->setGeometry(QRect(30, 240, 181, 31));
        Ajouter_joueur = new QPushButton(gestion_joueur);
        Ajouter_joueur->setObjectName(QStringLiteral("Ajouter_joueur"));
        Ajouter_joueur->setGeometry(QRect(30, 30, 181, 31));
        Ajouter_joueur->setFocusPolicy(Qt::StrongFocus);
        Ajouter_joueur->setContextMenuPolicy(Qt::DefaultContextMenu);
        Afficher_joueur_2 = new QPushButton(gestion_joueur);
        Afficher_joueur_2->setObjectName(QStringLiteral("Afficher_joueur_2"));
        Afficher_joueur_2->setGeometry(QRect(250, 30, 181, 31));
        label->raise();
        Modifier_joueur->raise();
        Supprimer_joueur->raise();
        Afficher_joueur->raise();
        Ajouter_joueur->raise();
        Afficher_joueur_2->raise();

        retranslateUi(gestion_joueur);

        QMetaObject::connectSlotsByName(gestion_joueur);
    } // setupUi

    void retranslateUi(QDialog *gestion_joueur)
    {
        gestion_joueur->setWindowTitle(QApplication::translate("gestion_joueur", "Joueur", Q_NULLPTR));
        Modifier_joueur->setText(QApplication::translate("gestion_joueur", "Modifier un joueur", Q_NULLPTR));
        label->setText(QString());
        Supprimer_joueur->setText(QApplication::translate("gestion_joueur", "Supprimer un joueur", Q_NULLPTR));
        Afficher_joueur->setText(QApplication::translate("gestion_joueur", "Statistiques", Q_NULLPTR));
        Ajouter_joueur->setText(QApplication::translate("gestion_joueur", "Ajouter un joueur", Q_NULLPTR));
        Afficher_joueur_2->setText(QApplication::translate("gestion_joueur", "Pr\303\251c\303\251dent", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_joueur: public Ui_gestion_joueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_JOUEUR_H
