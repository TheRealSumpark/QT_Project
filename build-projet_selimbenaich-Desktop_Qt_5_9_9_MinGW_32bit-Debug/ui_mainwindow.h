/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *Gestion_joueur;
    QPushButton *Modifier_joueur;
    QPushButton *fichier_pdf;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(794, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, -23, 794, 611));
        label->setFocusPolicy(Qt::StrongFocus);
        Gestion_joueur = new QPushButton(centralwidget);
        Gestion_joueur->setObjectName(QStringLiteral("Gestion_joueur"));
        Gestion_joueur->setGeometry(QRect(30, 100, 181, 31));
        Gestion_joueur->setFocusPolicy(Qt::StrongFocus);
        Gestion_joueur->setContextMenuPolicy(Qt::DefaultContextMenu);
        Modifier_joueur = new QPushButton(centralwidget);
        Modifier_joueur->setObjectName(QStringLiteral("Modifier_joueur"));
        Modifier_joueur->setGeometry(QRect(30, 180, 181, 31));
        fichier_pdf = new QPushButton(centralwidget);
        fichier_pdf->setObjectName(QStringLiteral("fichier_pdf"));
        fichier_pdf->setGeometry(QRect(30, 260, 181, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 794, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("Menu", "Menu", Q_NULLPTR));
        label->setText(QString());
        Gestion_joueur->setText(QApplication::translate("MainWindow", "Joueur", Q_NULLPTR));
        Modifier_joueur->setText(QApplication::translate("MainWindow", "Equipe", Q_NULLPTR));
        fichier_pdf->setText(QApplication::translate("MainWindow", "Cr\303\251er un fichier PDF", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
