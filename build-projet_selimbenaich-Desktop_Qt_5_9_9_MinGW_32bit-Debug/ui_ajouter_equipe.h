/********************************************************************************
** Form generated from reading UI file 'ajouter_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTER_EQUIPE_H
#define UI_AJOUTER_EQUIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Ajouter_equipe
{
public:
    QPushButton *Ajouter_equipe_2;
    QLabel *label_2;
    QPushButton *b_image;
    QLineEdit *in_nom;
    QLineEdit *in_categorie;
    QLineEdit *in_manager;
    QLabel *label_ajout;
    QLabel *label;
    QLabel *image_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_7;
    QSpinBox *in_number;
    QLabel *label_8;
    QSpinBox *in_score;

    void setupUi(QDialog *Ajouter_equipe)
    {
        if (Ajouter_equipe->objectName().isEmpty())
            Ajouter_equipe->setObjectName(QStringLiteral("Ajouter_equipe"));
        Ajouter_equipe->resize(495, 383);
        Ajouter_equipe_2 = new QPushButton(Ajouter_equipe);
        Ajouter_equipe_2->setObjectName(QStringLiteral("Ajouter_equipe_2"));
        Ajouter_equipe_2->setGeometry(QRect(300, 330, 75, 23));
        label_2 = new QLabel(Ajouter_equipe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(6, 80, 51, 16));
        b_image = new QPushButton(Ajouter_equipe);
        b_image->setObjectName(QStringLiteral("b_image"));
        b_image->setGeometry(QRect(60, 330, 75, 23));
        in_nom = new QLineEdit(Ajouter_equipe);
        in_nom->setObjectName(QStringLiteral("in_nom"));
        in_nom->setGeometry(QRect(60, 37, 113, 21));
        in_categorie = new QLineEdit(Ajouter_equipe);
        in_categorie->setObjectName(QStringLiteral("in_categorie"));
        in_categorie->setGeometry(QRect(60, 77, 113, 20));
        in_manager = new QLineEdit(Ajouter_equipe);
        in_manager->setObjectName(QStringLiteral("in_manager"));
        in_manager->setGeometry(QRect(60, 120, 113, 21));
        label_ajout = new QLabel(Ajouter_equipe);
        label_ajout->setObjectName(QStringLiteral("label_ajout"));
        label_ajout->setGeometry(QRect(0, 0, 501, 391));
        label = new QLabel(Ajouter_equipe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 41, 47, 14));
        image_2 = new QLabel(Ajouter_equipe);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(260, 70, 201, 201));
        pushButton_2 = new QPushButton(Ajouter_equipe);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 330, 75, 23));
        label_3 = new QLabel(Ajouter_equipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 123, 47, 14));
        label_7 = new QLabel(Ajouter_equipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(6, 185, 71, 16));
        in_number = new QSpinBox(Ajouter_equipe);
        in_number->setObjectName(QStringLiteral("in_number"));
        in_number->setEnabled(false);
        in_number->setGeometry(QRect(80, 170, 71, 41));
        label_8 = new QLabel(Ajouter_equipe);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 265, 47, 14));
        in_score = new QSpinBox(Ajouter_equipe);
        in_score->setObjectName(QStringLiteral("in_score"));
        in_score->setGeometry(QRect(60, 250, 71, 41));
        label_ajout->raise();
        Ajouter_equipe_2->raise();
        label_2->raise();
        b_image->raise();
        in_nom->raise();
        in_categorie->raise();
        in_manager->raise();
        label->raise();
        image_2->raise();
        pushButton_2->raise();
        label_3->raise();
        label_7->raise();
        in_number->raise();
        label_8->raise();
        in_score->raise();

        retranslateUi(Ajouter_equipe);

        QMetaObject::connectSlotsByName(Ajouter_equipe);
    } // setupUi

    void retranslateUi(QDialog *Ajouter_equipe)
    {
        Ajouter_equipe->setWindowTitle(QApplication::translate("Ajouter_equipe", "Ajouter", Q_NULLPTR));
        Ajouter_equipe_2->setText(QApplication::translate("Ajouter_equipe", "Appliquer", Q_NULLPTR));
        label_2->setText(QApplication::translate("Ajouter_equipe", "Categorie:", Q_NULLPTR));
        b_image->setText(QApplication::translate("Ajouter_equipe", "image", Q_NULLPTR));
        in_nom->setText(QString());
        in_categorie->setText(QString());
        in_manager->setText(QString());
        label_ajout->setText(QString());
        label->setText(QApplication::translate("Ajouter_equipe", "Nom:", Q_NULLPTR));
        image_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Ajouter_equipe", "Retour", Q_NULLPTR));
        label_3->setText(QApplication::translate("Ajouter_equipe", "Manager:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Ajouter_equipe", "Total_joueur:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Ajouter_equipe", "Score:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ajouter_equipe: public Ui_Ajouter_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTER_EQUIPE_H
