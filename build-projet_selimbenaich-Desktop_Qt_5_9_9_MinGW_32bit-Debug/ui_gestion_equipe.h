/********************************************************************************
** Form generated from reading UI file 'gestion_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_EQUIPE_H
#define UI_GESTION_EQUIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gestion_equipe
{
public:
    QLabel *label;
    QPushButton *Afficher_equipe;
    QPushButton *Modifier_equipe;
    QPushButton *Afficher_equipe_2;
    QPushButton *Ajouter_equipe;
    QPushButton *Supprimer_equipe;
    QPushButton *Ajouter_equipe_2;

    void setupUi(QDialog *gestion_equipe)
    {
        if (gestion_equipe->objectName().isEmpty())
            gestion_equipe->setObjectName(QStringLiteral("gestion_equipe"));
        gestion_equipe->resize(664, 435);
        label = new QLabel(gestion_equipe);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 681, 441));
        label->setFocusPolicy(Qt::StrongFocus);
        Afficher_equipe = new QPushButton(gestion_equipe);
        Afficher_equipe->setObjectName(QStringLiteral("Afficher_equipe"));
        Afficher_equipe->setGeometry(QRect(20, 290, 181, 31));
        Modifier_equipe = new QPushButton(gestion_equipe);
        Modifier_equipe->setObjectName(QStringLiteral("Modifier_equipe"));
        Modifier_equipe->setGeometry(QRect(20, 150, 181, 31));
        Afficher_equipe_2 = new QPushButton(gestion_equipe);
        Afficher_equipe_2->setObjectName(QStringLiteral("Afficher_equipe_2"));
        Afficher_equipe_2->setGeometry(QRect(240, 150, 181, 31));
        Ajouter_equipe = new QPushButton(gestion_equipe);
        Ajouter_equipe->setObjectName(QStringLiteral("Ajouter_equipe"));
        Ajouter_equipe->setGeometry(QRect(20, 80, 181, 31));
        Ajouter_equipe->setFocusPolicy(Qt::StrongFocus);
        Ajouter_equipe->setContextMenuPolicy(Qt::DefaultContextMenu);
        Supprimer_equipe = new QPushButton(gestion_equipe);
        Supprimer_equipe->setObjectName(QStringLiteral("Supprimer_equipe"));
        Supprimer_equipe->setGeometry(QRect(20, 220, 181, 31));
        Ajouter_equipe_2 = new QPushButton(gestion_equipe);
        Ajouter_equipe_2->setObjectName(QStringLiteral("Ajouter_equipe_2"));
        Ajouter_equipe_2->setGeometry(QRect(240, 80, 311, 31));
        Ajouter_equipe_2->setFocusPolicy(Qt::StrongFocus);
        Ajouter_equipe_2->setContextMenuPolicy(Qt::DefaultContextMenu);

        retranslateUi(gestion_equipe);

        QMetaObject::connectSlotsByName(gestion_equipe);
    } // setupUi

    void retranslateUi(QDialog *gestion_equipe)
    {
        gestion_equipe->setWindowTitle(QApplication::translate("gestion_equipe", "Equipe", Q_NULLPTR));
        label->setText(QString());
        Afficher_equipe->setText(QApplication::translate("gestion_equipe", "Afficher une \303\251quipe", Q_NULLPTR));
        Modifier_equipe->setText(QApplication::translate("gestion_equipe", "Modifier une \303\251quipe", Q_NULLPTR));
        Afficher_equipe_2->setText(QApplication::translate("gestion_equipe", "Pr\303\251c\303\251dent", Q_NULLPTR));
        Ajouter_equipe->setText(QApplication::translate("gestion_equipe", "Ajouter une \303\251quipe", Q_NULLPTR));
        Supprimer_equipe->setText(QApplication::translate("gestion_equipe", "Supprimer une \303\251quipe", Q_NULLPTR));
        Ajouter_equipe_2->setText(QApplication::translate("gestion_equipe", "Ajouter toute joueur ne figurant pas sur la liste d'une \303\251quipe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_equipe: public Ui_gestion_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_EQUIPE_H
