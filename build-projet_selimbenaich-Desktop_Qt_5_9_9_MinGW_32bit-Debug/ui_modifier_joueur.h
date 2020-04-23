/********************************************************************************
** Form generated from reading UI file 'modifier_joueur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_JOUEUR_H
#define UI_MODIFIER_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modifier_joueur
{
public:
    QLabel *label;
    QLabel *label_modif;
    QPushButton *b_image;
    QLabel *id_sup_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *in_id;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QDialog *Modifier_joueur)
    {
        if (Modifier_joueur->objectName().isEmpty())
            Modifier_joueur->setObjectName(QStringLiteral("Modifier_joueur"));
        Modifier_joueur->resize(762, 504);
        label = new QLabel(Modifier_joueur);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(80, 10, 411, 16));
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
        label->setFont(font);
        label_modif = new QLabel(Modifier_joueur);
        label_modif->setObjectName(QStringLiteral("label_modif"));
        label_modif->setGeometry(QRect(0, 0, 761, 501));
        b_image = new QPushButton(Modifier_joueur);
        b_image->setObjectName(QStringLiteral("b_image"));
        b_image->setGeometry(QRect(662, 380, 75, 23));
        id_sup_8 = new QLabel(Modifier_joueur);
        id_sup_8->setObjectName(QStringLiteral("id_sup_8"));
        id_sup_8->setGeometry(QRect(530, 70, 191, 271));
        horizontalLayoutWidget = new QWidget(Modifier_joueur);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 491, 311));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        in_id = new QLineEdit(Modifier_joueur);
        in_id->setObjectName(QStringLiteral("in_id"));
        in_id->setGeometry(QRect(10, 470, 113, 20));
        horizontalLayoutWidget_2 = new QWidget(Modifier_joueur);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(620, 410, 160, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_modif->raise();
        label->raise();
        b_image->raise();
        id_sup_8->raise();
        horizontalLayoutWidget->raise();
        in_id->raise();
        horizontalLayoutWidget_2->raise();

        retranslateUi(Modifier_joueur);

        QMetaObject::connectSlotsByName(Modifier_joueur);
    } // setupUi

    void retranslateUi(QDialog *Modifier_joueur)
    {
        Modifier_joueur->setWindowTitle(QApplication::translate("Modifier_joueur", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Modifier_joueur", "Veuillez selectionner l'id de joueur a modifier d'apes le tableau suivant:", Q_NULLPTR));
        label_modif->setText(QString());
        b_image->setText(QApplication::translate("Modifier_joueur", "Image", Q_NULLPTR));
        id_sup_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Modifier_joueur: public Ui_Modifier_joueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_JOUEUR_H
