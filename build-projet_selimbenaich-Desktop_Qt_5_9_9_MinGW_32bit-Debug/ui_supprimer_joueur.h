/********************************************************************************
** Form generated from reading UI file 'supprimer_joueur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_JOUEUR_H
#define UI_SUPPRIMER_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Supprimer_joueur
{
public:
    QTableView *afficher_sup;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *id_sup;
    QLabel *label_sup;
    QLabel *id_sup_8;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Supprimer_joueur)
    {
        if (Supprimer_joueur->objectName().isEmpty())
            Supprimer_joueur->setObjectName(QStringLiteral("Supprimer_joueur"));
        Supprimer_joueur->resize(761, 509);
        afficher_sup = new QTableView(Supprimer_joueur);
        afficher_sup->setObjectName(QStringLiteral("afficher_sup"));
        afficher_sup->setGeometry(QRect(20, 50, 461, 311));
        pushButton = new QPushButton(Supprimer_joueur);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(510, 470, 111, 23));
        label = new QLabel(Supprimer_joueur);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(70, 10, 411, 16));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label->setMouseTracking(true);
        label->setFocusPolicy(Qt::ClickFocus);
        id_sup = new QLineEdit(Supprimer_joueur);
        id_sup->setObjectName(QStringLiteral("id_sup"));
        id_sup->setEnabled(false);
        id_sup->setGeometry(QRect(10, 470, 111, 20));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        id_sup->setFont(font1);
        label_sup = new QLabel(Supprimer_joueur);
        label_sup->setObjectName(QStringLiteral("label_sup"));
        label_sup->setGeometry(QRect(0, 0, 761, 511));
        id_sup_8 = new QLabel(Supprimer_joueur);
        id_sup_8->setObjectName(QStringLiteral("id_sup_8"));
        id_sup_8->setGeometry(QRect(530, 60, 191, 291));
        pushButton_2 = new QPushButton(Supprimer_joueur);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 470, 111, 23));
        label_sup->raise();
        afficher_sup->raise();
        pushButton->raise();
        label->raise();
        id_sup->raise();
        id_sup_8->raise();
        pushButton_2->raise();
        QWidget::setTabOrder(pushButton, afficher_sup);
        QWidget::setTabOrder(afficher_sup, id_sup);

        retranslateUi(Supprimer_joueur);

        QMetaObject::connectSlotsByName(Supprimer_joueur);
    } // setupUi

    void retranslateUi(QDialog *Supprimer_joueur)
    {
        Supprimer_joueur->setWindowTitle(QApplication::translate("Supprimer_joueur", "Supprimer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Supprimer_joueur", "Supprimer", Q_NULLPTR));
        label->setText(QApplication::translate("Supprimer_joueur", "Veuillez selectionner l'id de joueur a supprimer d'apes le tableau suivant:", Q_NULLPTR));
        label_sup->setText(QString());
        id_sup_8->setText(QString());
        pushButton_2->setText(QApplication::translate("Supprimer_joueur", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Supprimer_joueur: public Ui_Supprimer_joueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_JOUEUR_H
