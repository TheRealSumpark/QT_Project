/********************************************************************************
** Form generated from reading UI file 'ajouter_joueur_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTER_JOUEUR_EQUIPE_H
#define UI_AJOUTER_JOUEUR_EQUIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ajouter_joueur_equipe
{
public:
    QComboBox *comboBox_joueur;
    QLabel *label_9;
    QLineEdit *list_j_prenom;
    QLineEdit *list_j_id;
    QLineEdit *list_j_nom;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label;
    QPushButton *Ajouter_joueur_equipe;
    QPushButton *pushButton_2;
    QComboBox *comboBox_equipe;
    QLabel *label_10;
    QLineEdit *list_e_nom;
    QLabel *label_7;
    QLabel *label_3;
    QLineEdit *liste_e_manager;
    QLabel *image_2;
    QLabel *image_3;
    QLabel *label_ajout;

    void setupUi(QDialog *ajouter_joueur_equipe)
    {
        if (ajouter_joueur_equipe->objectName().isEmpty())
            ajouter_joueur_equipe->setObjectName(QStringLiteral("ajouter_joueur_equipe"));
        ajouter_joueur_equipe->resize(613, 544);
        comboBox_joueur = new QComboBox(ajouter_joueur_equipe);
        comboBox_joueur->setObjectName(QStringLiteral("comboBox_joueur"));
        comboBox_joueur->setGeometry(QRect(117, 50, 141, 31));
        label_9 = new QLabel(ajouter_joueur_equipe);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(13, 55, 101, 20));
        list_j_prenom = new QLineEdit(ajouter_joueur_equipe);
        list_j_prenom->setObjectName(QStringLiteral("list_j_prenom"));
        list_j_prenom->setEnabled(false);
        list_j_prenom->setGeometry(QRect(60, 190, 111, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        list_j_prenom->setFont(font);
        list_j_id = new QLineEdit(ajouter_joueur_equipe);
        list_j_id->setObjectName(QStringLiteral("list_j_id"));
        list_j_id->setEnabled(false);
        list_j_id->setGeometry(QRect(60, 110, 111, 20));
        list_j_id->setFont(font);
        list_j_nom = new QLineEdit(ajouter_joueur_equipe);
        list_j_nom->setObjectName(QStringLiteral("list_j_nom"));
        list_j_nom->setEnabled(false);
        list_j_nom->setGeometry(QRect(60, 150, 111, 20));
        list_j_nom->setFont(font);
        label_6 = new QLabel(ajouter_joueur_equipe);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 113, 47, 14));
        label_2 = new QLabel(ajouter_joueur_equipe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 193, 47, 14));
        label = new QLabel(ajouter_joueur_equipe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 153, 47, 14));
        Ajouter_joueur_equipe = new QPushButton(ajouter_joueur_equipe);
        Ajouter_joueur_equipe->setObjectName(QStringLiteral("Ajouter_joueur_equipe"));
        Ajouter_joueur_equipe->setGeometry(QRect(380, 500, 75, 23));
        pushButton_2 = new QPushButton(ajouter_joueur_equipe);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 500, 75, 23));
        comboBox_equipe = new QComboBox(ajouter_joueur_equipe);
        comboBox_equipe->setObjectName(QStringLiteral("comboBox_equipe"));
        comboBox_equipe->setGeometry(QRect(117, 342, 141, 31));
        label_10 = new QLabel(ajouter_joueur_equipe);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(13, 348, 101, 20));
        list_e_nom = new QLineEdit(ajouter_joueur_equipe);
        list_e_nom->setObjectName(QStringLiteral("list_e_nom"));
        list_e_nom->setEnabled(false);
        list_e_nom->setGeometry(QRect(100, 440, 111, 20));
        list_e_nom->setFont(font);
        label_7 = new QLabel(ajouter_joueur_equipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 442, 81, 20));
        label_3 = new QLabel(ajouter_joueur_equipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 402, 111, 20));
        liste_e_manager = new QLineEdit(ajouter_joueur_equipe);
        liste_e_manager->setObjectName(QStringLiteral("liste_e_manager"));
        liste_e_manager->setEnabled(false);
        liste_e_manager->setGeometry(QRect(130, 401, 111, 20));
        liste_e_manager->setFont(font);
        image_2 = new QLabel(ajouter_joueur_equipe);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(360, 30, 151, 211));
        image_3 = new QLabel(ajouter_joueur_equipe);
        image_3->setObjectName(QStringLiteral("image_3"));
        image_3->setGeometry(QRect(360, 280, 181, 191));
        label_ajout = new QLabel(ajouter_joueur_equipe);
        label_ajout->setObjectName(QStringLiteral("label_ajout"));
        label_ajout->setGeometry(QRect(0, 0, 621, 551));
        label_ajout->raise();
        comboBox_joueur->raise();
        label_9->raise();
        list_j_prenom->raise();
        list_j_id->raise();
        list_j_nom->raise();
        label_6->raise();
        label_2->raise();
        label->raise();
        Ajouter_joueur_equipe->raise();
        pushButton_2->raise();
        comboBox_equipe->raise();
        label_10->raise();
        list_e_nom->raise();
        label_7->raise();
        label_3->raise();
        liste_e_manager->raise();
        image_2->raise();
        image_3->raise();

        retranslateUi(ajouter_joueur_equipe);

        QMetaObject::connectSlotsByName(ajouter_joueur_equipe);
    } // setupUi

    void retranslateUi(QDialog *ajouter_joueur_equipe)
    {
        ajouter_joueur_equipe->setWindowTitle(QApplication::translate("ajouter_joueur_equipe", "Dialog", Q_NULLPTR));
        label_9->setText(QApplication::translate("ajouter_joueur_equipe", "Liste des joueurs:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ajouter_joueur_equipe", "Id:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ajouter_joueur_equipe", "Prenom:", Q_NULLPTR));
        label->setText(QApplication::translate("ajouter_joueur_equipe", "Nom:", Q_NULLPTR));
        Ajouter_joueur_equipe->setText(QApplication::translate("ajouter_joueur_equipe", "Appliquer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ajouter_joueur_equipe", "Retour", Q_NULLPTR));
        label_10->setText(QApplication::translate("ajouter_joueur_equipe", "Liste des d'\303\251quipes:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ajouter_joueur_equipe", "Nom d'\303\251quipe:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ajouter_joueur_equipe", "Manager de l'\303\251quipe:", Q_NULLPTR));
        image_2->setText(QString());
        image_3->setText(QString());
        label_ajout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ajouter_joueur_equipe: public Ui_ajouter_joueur_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTER_JOUEUR_EQUIPE_H
