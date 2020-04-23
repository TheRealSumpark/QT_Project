/********************************************************************************
** Form generated from reading UI file 'modifier_equipe.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_EQUIPE_H
#define UI_MODIFIER_EQUIPE_H

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
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_modifier_equipe
{
public:
    QLabel *label;
    QTableView *afficher_modif;
    QTableView *afficher_modif_2;
    QLabel *label_3;
    QLineEdit *in_manager;
    QPushButton *b_image;
    QLabel *image_2;
    QLineEdit *in_categorie;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *in_number;
    QSpinBox *in_score;
    QLabel *label_7;
    QLineEdit *in_nom;
    QLabel *label_8;
    QLabel *image_1;
    QPushButton *Appliquer_modification;
    QPushButton *Annuler;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QLabel *label_modif;
    QLabel *label_6;
    QLineEdit *hide;

    void setupUi(QDialog *modifier_equipe)
    {
        if (modifier_equipe->objectName().isEmpty())
            modifier_equipe->setObjectName(QStringLiteral("modifier_equipe"));
        modifier_equipe->resize(1153, 639);
        label = new QLabel(modifier_equipe);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(10, 10, 451, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        afficher_modif = new QTableView(modifier_equipe);
        afficher_modif->setObjectName(QStringLiteral("afficher_modif"));
        afficher_modif->setGeometry(QRect(20, 45, 431, 241));
        afficher_modif_2 = new QTableView(modifier_equipe);
        afficher_modif_2->setObjectName(QStringLiteral("afficher_modif_2"));
        afficher_modif_2->setGeometry(QRect(590, 50, 531, 141));
        label_3 = new QLabel(modifier_equipe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 403, 47, 14));
        in_manager = new QLineEdit(modifier_equipe);
        in_manager->setObjectName(QStringLiteral("in_manager"));
        in_manager->setGeometry(QRect(90, 400, 113, 21));
        b_image = new QPushButton(modifier_equipe);
        b_image->setObjectName(QStringLiteral("b_image"));
        b_image->setGeometry(QRect(190, 595, 75, 23));
        image_2 = new QLabel(modifier_equipe);
        image_2->setObjectName(QStringLiteral("image_2"));
        image_2->setGeometry(QRect(290, 340, 201, 201));
        in_categorie = new QLineEdit(modifier_equipe);
        in_categorie->setObjectName(QStringLiteral("in_categorie"));
        in_categorie->setGeometry(QRect(90, 357, 113, 20));
        label_2 = new QLabel(modifier_equipe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 321, 47, 14));
        label_4 = new QLabel(modifier_equipe);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(36, 360, 51, 16));
        in_number = new QSpinBox(modifier_equipe);
        in_number->setObjectName(QStringLiteral("in_number"));
        in_number->setEnabled(false);
        in_number->setGeometry(QRect(110, 450, 71, 41));
        in_score = new QSpinBox(modifier_equipe);
        in_score->setObjectName(QStringLiteral("in_score"));
        in_score->setGeometry(QRect(90, 530, 71, 41));
        label_7 = new QLabel(modifier_equipe);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(36, 465, 71, 16));
        in_nom = new QLineEdit(modifier_equipe);
        in_nom->setObjectName(QStringLiteral("in_nom"));
        in_nom->setGeometry(QRect(90, 317, 113, 21));
        label_8 = new QLabel(modifier_equipe);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 545, 47, 14));
        image_1 = new QLabel(modifier_equipe);
        image_1->setObjectName(QStringLiteral("image_1"));
        image_1->setGeometry(QRect(777, 250, 191, 291));
        Appliquer_modification = new QPushButton(modifier_equipe);
        Appliquer_modification->setObjectName(QStringLiteral("Appliquer_modification"));
        Appliquer_modification->setGeometry(QRect(844, 590, 151, 23));
        Annuler = new QPushButton(modifier_equipe);
        Annuler->setObjectName(QStringLiteral("Annuler"));
        Annuler->setGeometry(QRect(1050, 590, 75, 23));
        label_5 = new QLabel(modifier_equipe);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 20, 671, 21));
        label_5->setFont(font);
        pushButton_3 = new QPushButton(modifier_equipe);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(700, 590, 75, 23));
        label_modif = new QLabel(modifier_equipe);
        label_modif->setObjectName(QStringLiteral("label_modif"));
        label_modif->setGeometry(QRect(-10, -200, 1171, 651));
        label_6 = new QLabel(modifier_equipe);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-10, 451, 1171, 191));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush4(QColor(0, 120, 215, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        label_6->setPalette(palette1);
        hide = new QLineEdit(modifier_equipe);
        hide->setObjectName(QStringLiteral("hide"));
        hide->setGeometry(QRect(10, 600, 113, 21));
        label_6->raise();
        label_modif->raise();
        label->raise();
        afficher_modif->raise();
        afficher_modif_2->raise();
        label_3->raise();
        in_manager->raise();
        b_image->raise();
        image_2->raise();
        in_categorie->raise();
        label_2->raise();
        label_4->raise();
        in_number->raise();
        in_score->raise();
        label_7->raise();
        in_nom->raise();
        label_8->raise();
        image_1->raise();
        Appliquer_modification->raise();
        Annuler->raise();
        label_5->raise();
        pushButton_3->raise();
        hide->raise();

        retranslateUi(modifier_equipe);

        QMetaObject::connectSlotsByName(modifier_equipe);
    } // setupUi

    void retranslateUi(QDialog *modifier_equipe)
    {
        modifier_equipe->setWindowTitle(QApplication::translate("modifier_equipe", "Modifier", Q_NULLPTR));
        label->setText(QApplication::translate("modifier_equipe", "Veuillez selectionner le nom d'\303\251quipe a modifier d'apes le tableau suivant:", Q_NULLPTR));
        label_3->setText(QApplication::translate("modifier_equipe", "Manager:", Q_NULLPTR));
        in_manager->setText(QString());
        b_image->setText(QApplication::translate("modifier_equipe", "image", Q_NULLPTR));
        image_2->setText(QString());
        in_categorie->setText(QString());
        label_2->setText(QApplication::translate("modifier_equipe", "Nom:", Q_NULLPTR));
        label_4->setText(QApplication::translate("modifier_equipe", "Categorie:", Q_NULLPTR));
        label_7->setText(QApplication::translate("modifier_equipe", "Total_joueur:", Q_NULLPTR));
        in_nom->setText(QString());
        label_8->setText(QApplication::translate("modifier_equipe", "Score:", Q_NULLPTR));
        image_1->setText(QString());
        Appliquer_modification->setText(QApplication::translate("modifier_equipe", "Appliquer la Modification", Q_NULLPTR));
        Annuler->setText(QApplication::translate("modifier_equipe", "Retour", Q_NULLPTR));
        label_5->setText(QApplication::translate("modifier_equipe", "Si vous ne souhaitez plus en faire partie. Vous pouvez supprimer des joueurs en cliquant sur l'id apr\303\251s retirer:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("modifier_equipe", "Retirer", Q_NULLPTR));
        label_modif->setText(QString());
        label_6->setText(QApplication::translate("modifier_equipe", "TextLabel", Q_NULLPTR));
        hide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modifier_equipe: public Ui_modifier_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_EQUIPE_H
