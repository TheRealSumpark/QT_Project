/********************************************************************************
** Form generated from reading UI file 'afficher_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHER_EQUIPE_H
#define UI_AFFICHER_EQUIPE_H

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
#include <QtWidgets/QUndoView>

QT_BEGIN_NAMESPACE

class Ui_afficher_equipe
{
public:
    QLineEdit *list_e_nom;
    QLabel *label_3;
    QComboBox *comboBox_equipe;
    QLabel *label_10;
    QLabel *image_2;
    QLabel *label_7;
    QLineEdit *liste_e_manager;
    QUndoView *undoView;
    QLabel *image_3;
    QPushButton *pushButton;
    QLabel *label_affich;

    void setupUi(QDialog *afficher_equipe)
    {
        if (afficher_equipe->objectName().isEmpty())
            afficher_equipe->setObjectName(QStringLiteral("afficher_equipe"));
        afficher_equipe->resize(603, 553);
        list_e_nom = new QLineEdit(afficher_equipe);
        list_e_nom->setObjectName(QStringLiteral("list_e_nom"));
        list_e_nom->setEnabled(false);
        list_e_nom->setGeometry(QRect(100, 150, 111, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        list_e_nom->setFont(font);
        label_3 = new QLabel(afficher_equipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 112, 111, 20));
        comboBox_equipe = new QComboBox(afficher_equipe);
        comboBox_equipe->setObjectName(QStringLiteral("comboBox_equipe"));
        comboBox_equipe->setGeometry(QRect(117, 31, 154, 31));
        label_10 = new QLabel(afficher_equipe);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(13, 37, 101, 20));
        image_2 = new QLabel(afficher_equipe);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(340, 27, 181, 201));
        label_7 = new QLabel(afficher_equipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 152, 81, 20));
        liste_e_manager = new QLineEdit(afficher_equipe);
        liste_e_manager->setObjectName(QStringLiteral("liste_e_manager"));
        liste_e_manager->setEnabled(false);
        liste_e_manager->setGeometry(QRect(130, 111, 111, 20));
        liste_e_manager->setFont(font);
        undoView = new QUndoView(afficher_equipe);
        undoView->setObjectName(QStringLiteral("undoView"));
        undoView->setGeometry(QRect(10, 280, 261, 192));
        image_3 = new QLabel(afficher_equipe);
        image_3->setObjectName(QStringLiteral("image_3"));
        image_3->setGeometry(QRect(370, 260, 151, 241));
        pushButton = new QPushButton(afficher_equipe);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 510, 75, 31));
        label_affich = new QLabel(afficher_equipe);
        label_affich->setObjectName(QStringLiteral("label_affich"));
        label_affich->setGeometry(QRect(0, 0, 611, 561));
        label_affich->raise();
        list_e_nom->raise();
        label_3->raise();
        comboBox_equipe->raise();
        label_10->raise();
        image_2->raise();
        label_7->raise();
        liste_e_manager->raise();
        undoView->raise();
        image_3->raise();
        pushButton->raise();

        retranslateUi(afficher_equipe);

        QMetaObject::connectSlotsByName(afficher_equipe);
    } // setupUi

    void retranslateUi(QDialog *afficher_equipe)
    {
        afficher_equipe->setWindowTitle(QApplication::translate("afficher_equipe", "liste des équipes", Q_NULLPTR));
        label_3->setText(QApplication::translate("afficher_equipe", "Manager de l'\303\251quipe:", Q_NULLPTR));
        label_10->setText(QApplication::translate("afficher_equipe", "Liste des d'\303\251quipes:", Q_NULLPTR));
        image_2->setText(QString());
        label_7->setText(QApplication::translate("afficher_equipe", "Nom d'\303\251quipe:", Q_NULLPTR));
        image_3->setText(QString());
        pushButton->setText(QApplication::translate("afficher_equipe", "Retour", Q_NULLPTR));
        label_affich->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class afficher_equipe: public Ui_afficher_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHER_EQUIPE_H
