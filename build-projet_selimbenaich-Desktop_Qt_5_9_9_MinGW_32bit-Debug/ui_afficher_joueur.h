/********************************************************************************
** Form generated from reading UI file 'afficher_joueur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHER_JOUEUR_H
#define UI_AFFICHER_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Afficher_joueur
{
public:
    QTableView *tableView;
    QLabel *label_affich;
    QPushButton *pushButton;
    QLabel *image_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Afficher_joueur)
    {
        if (Afficher_joueur->objectName().isEmpty())
            Afficher_joueur->setObjectName(QStringLiteral("Afficher_joueur"));
        Afficher_joueur->resize(759, 590);
        tableView = new QTableView(Afficher_joueur);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 381, 281));
        label_affich = new QLabel(Afficher_joueur);
        label_affich->setObjectName(QStringLiteral("label_affich"));
        label_affich->setGeometry(QRect(0, -10, 771, 611));
        pushButton = new QPushButton(Afficher_joueur);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 540, 75, 31));
        image_2 = new QLabel(Afficher_joueur);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(490, 40, 151, 241));
        customPlot = new QCustomPlot(Afficher_joueur);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 320, 561, 251));
        label_affich->raise();
        image_2->raise();
        tableView->raise();
        pushButton->raise();
        customPlot->raise();

        retranslateUi(Afficher_joueur);

        QMetaObject::connectSlotsByName(Afficher_joueur);
    } // setupUi

    void retranslateUi(QDialog *Afficher_joueur)
    {
        Afficher_joueur->setWindowTitle(QApplication::translate("Afficher_joueur", "Dialog", Q_NULLPTR));
        label_affich->setText(QString());
        pushButton->setText(QApplication::translate("Afficher_joueur", "Retour", Q_NULLPTR));
        image_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Afficher_joueur: public Ui_Afficher_joueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHER_JOUEUR_H
