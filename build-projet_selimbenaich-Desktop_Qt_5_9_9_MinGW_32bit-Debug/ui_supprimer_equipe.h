/********************************************************************************
** Form generated from reading UI file 'supprimer_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_EQUIPE_H
#define UI_SUPPRIMER_EQUIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_supprimer_equipe
{
public:
    QLineEdit *list_e_nom;
    QComboBox *comboBox_equipe;
    QLabel *label_3;
    QLineEdit *liste_e_manager;
    QLabel *label_7;
    QLabel *label_10;
    QListView *listView;
    QLabel *image_2;
    QLabel *image_3;
    QPushButton *supprimer_equipe_2;
    QPushButton *annuler_la_suppression;
    QLabel *label_sup;

    void setupUi(QDialog *supprimer_equipe)
    {
        if (supprimer_equipe->objectName().isEmpty())
            supprimer_equipe->setObjectName(QStringLiteral("supprimer_equipe"));
        supprimer_equipe->resize(602, 566);
        list_e_nom = new QLineEdit(supprimer_equipe);
        list_e_nom->setObjectName(QStringLiteral("list_e_nom"));
        list_e_nom->setEnabled(false);
        list_e_nom->setGeometry(QRect(107, 142, 111, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        list_e_nom->setFont(font);
        comboBox_equipe = new QComboBox(supprimer_equipe);
        comboBox_equipe->setObjectName(QStringLiteral("comboBox_equipe"));
        comboBox_equipe->setGeometry(QRect(124, 44, 141, 31));
        label_3 = new QLabel(supprimer_equipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(17, 104, 111, 20));
        liste_e_manager = new QLineEdit(supprimer_equipe);
        liste_e_manager->setObjectName(QStringLiteral("liste_e_manager"));
        liste_e_manager->setEnabled(false);
        liste_e_manager->setGeometry(QRect(137, 103, 111, 20));
        liste_e_manager->setFont(font);
        label_7 = new QLabel(supprimer_equipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(17, 144, 81, 20));
        label_10 = new QLabel(supprimer_equipe);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 50, 101, 20));
        listView = new QListView(supprimer_equipe);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 270, 311, 231));
        image_2 = new QLabel(supprimer_equipe);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(370, 40, 201, 201));
        image_3 = new QLabel(supprimer_equipe);
        image_3->setObjectName(QStringLiteral("image_3"));
        image_3->setGeometry(QRect(400, 270, 171, 261));
        supprimer_equipe_2 = new QPushButton(supprimer_equipe);
        supprimer_equipe_2->setObjectName(QStringLiteral("supprimer_equipe_2"));
        supprimer_equipe_2->setGeometry(QRect(10, 530, 111, 23));
        annuler_la_suppression = new QPushButton(supprimer_equipe);
        annuler_la_suppression->setObjectName(QStringLiteral("annuler_la_suppression"));
        annuler_la_suppression->setGeometry(QRect(150, 530, 111, 23));
        label_sup = new QLabel(supprimer_equipe);
        label_sup->setObjectName(QStringLiteral("label_sup"));
        label_sup->setGeometry(QRect(0, 0, 601, 611));
        label_sup->raise();
        list_e_nom->raise();
        comboBox_equipe->raise();
        label_3->raise();
        liste_e_manager->raise();
        label_7->raise();
        label_10->raise();
        listView->raise();
        image_2->raise();
        image_3->raise();
        supprimer_equipe_2->raise();
        annuler_la_suppression->raise();

        retranslateUi(supprimer_equipe);

        QMetaObject::connectSlotsByName(supprimer_equipe);
    } // setupUi

    void retranslateUi(QDialog *supprimer_equipe)
    {
        supprimer_equipe->setWindowTitle(QApplication::translate("supprimer_equipe", "Supprimer", Q_NULLPTR));
        label_3->setText(QApplication::translate("supprimer_equipe", "Manager de l'\303\251quipe:", Q_NULLPTR));
        label_7->setText(QApplication::translate("supprimer_equipe", "Nom d'\303\251quipe:", Q_NULLPTR));
        label_10->setText(QApplication::translate("supprimer_equipe", "Liste des d'\303\251quipes:", Q_NULLPTR));
        image_2->setText(QString());
        image_3->setText(QString());
        supprimer_equipe_2->setText(QApplication::translate("supprimer_equipe", "Supprimer", Q_NULLPTR));
        annuler_la_suppression->setText(QApplication::translate("supprimer_equipe", "Retour", Q_NULLPTR));
        label_sup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class supprimer_equipe: public Ui_supprimer_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_EQUIPE_H
