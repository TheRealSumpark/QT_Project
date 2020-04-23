/********************************************************************************
** Form generated from reading UI file 'Ajouter_joueur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTER_JOUEUR_H
#define UI_AJOUTER_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *Ajouter_joueur;
    QPushButton *pushButton_2;
    QLineEdit *in_nom;
    QLineEdit *in_prenom;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *in_date;
    QLabel *label_3;
    QDoubleSpinBox *in_poids;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *in_taille;
    QLabel *image_2;
    QPushButton *b_image;
    QLabel *label_6;
    QLineEdit *in_id;
    QSpinBox *in_number;
    QLabel *label_7;
    QLabel *label_ajout;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(475, 452);
        Ajouter_joueur = new QPushButton(Dialog);
        Ajouter_joueur->setObjectName(QStringLiteral("Ajouter_joueur"));
        Ajouter_joueur->setGeometry(QRect(260, 400, 75, 23));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 400, 75, 23));
        in_nom = new QLineEdit(Dialog);
        in_nom->setObjectName(QStringLiteral("in_nom"));
        in_nom->setGeometry(QRect(60, 110, 113, 21));
        in_prenom = new QLineEdit(Dialog);
        in_prenom->setObjectName(QStringLiteral("in_prenom"));
        in_prenom->setGeometry(QRect(60, 150, 113, 20));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 114, 47, 14));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 153, 47, 14));
        in_date = new QDateEdit(Dialog);
        in_date->setObjectName(QStringLiteral("in_date"));
        in_date->setGeometry(QRect(120, 210, 121, 41));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 225, 91, 16));
        in_poids = new QDoubleSpinBox(Dialog);
        in_poids->setObjectName(QStringLiteral("in_poids"));
        in_poids->setGeometry(QRect(60, 309, 64, 22));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 313, 47, 14));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 360, 47, 14));
        in_taille = new QDoubleSpinBox(Dialog);
        in_taille->setObjectName(QStringLiteral("in_taille"));
        in_taille->setGeometry(QRect(60, 355, 64, 22));
        image_2 = new QLabel(Dialog);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(280, 100, 171, 261));
        b_image = new QPushButton(Dialog);
        b_image->setObjectName(QStringLiteral("b_image"));
        b_image->setGeometry(QRect(170, 340, 75, 23));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 73, 47, 14));
        in_id = new QLineEdit(Dialog);
        in_id->setObjectName(QStringLiteral("in_id"));
        in_id->setGeometry(QRect(60, 70, 113, 21));
        in_number = new QSpinBox(Dialog);
        in_number->setObjectName(QStringLiteral("in_number"));
        in_number->setGeometry(QRect(60, 400, 71, 41));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 415, 47, 14));
        label_ajout = new QLabel(Dialog);
        label_ajout->setObjectName(QStringLiteral("label_ajout"));
        label_ajout->setGeometry(QRect(0, 0, 481, 451));
        label_ajout->raise();
        Ajouter_joueur->raise();
        pushButton_2->raise();
        in_nom->raise();
        in_prenom->raise();
        label->raise();
        label_2->raise();
        in_date->raise();
        label_3->raise();
        in_poids->raise();
        label_4->raise();
        label_5->raise();
        in_taille->raise();
        image_2->raise();
        b_image->raise();
        label_6->raise();
        in_id->raise();
        in_number->raise();
        label_7->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        Ajouter_joueur->setText(QApplication::translate("Dialog", "Appliquer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "Retour", Q_NULLPTR));
        in_nom->setText(QString());
        in_prenom->setText(QString());
        label->setText(QApplication::translate("Dialog", "Nom:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Prenom:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Date de naissance:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "poids", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Taille", Q_NULLPTR));
        image_2->setText(QString());
        b_image->setText(QApplication::translate("Dialog", "image", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "Id:", Q_NULLPTR));
        in_id->setText(QString());
        label_7->setText(QApplication::translate("Dialog", "Numero:", Q_NULLPTR));
        label_ajout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTER_JOUEUR_H
