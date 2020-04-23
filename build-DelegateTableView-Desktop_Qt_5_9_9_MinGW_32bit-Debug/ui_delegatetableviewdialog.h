/********************************************************************************
** Form generated from reading UI file 'delegatetableviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELEGATETABLEVIEWDIALOG_H
#define UI_DELEGATETABLEVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DelegateTableViewDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *DelegateTableViewDialog)
    {
        if (DelegateTableViewDialog->objectName().isEmpty())
            DelegateTableViewDialog->setObjectName(QStringLiteral("DelegateTableViewDialog"));
        DelegateTableViewDialog->resize(295, 222);
        horizontalLayout = new QHBoxLayout(DelegateTableViewDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(DelegateTableViewDialog);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(DelegateTableViewDialog);

        QMetaObject::connectSlotsByName(DelegateTableViewDialog);
    } // setupUi

    void retranslateUi(QDialog *DelegateTableViewDialog)
    {
        DelegateTableViewDialog->setWindowTitle(QApplication::translate("DelegateTableViewDialog", "DelegateTableViewDialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DelegateTableViewDialog: public Ui_DelegateTableViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELEGATETABLEVIEWDIALOG_H
