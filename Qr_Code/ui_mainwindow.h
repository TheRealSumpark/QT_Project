/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *qrcodepixmapLabel;
    QLineEdit *lineEdit;
    QPushButton *generateButton;
    QPushButton *saveFileButton;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 420);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(550, 420));
        MainWindow->setMaximumSize(QSize(550, 420));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 550, 420));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(550, 420));
        centralWidget->setMaximumSize(QSize(550, 420));
        qrcodepixmapLabel = new QLabel(centralWidget);
        qrcodepixmapLabel->setObjectName(QString::fromUtf8("qrcodepixmapLabel"));
        qrcodepixmapLabel->setGeometry(QRect(40, 80, 300, 300));
        qrcodepixmapLabel->setFrameShape(QFrame::StyledPanel);
        qrcodepixmapLabel->setFrameShadow(QFrame::Sunken);
        qrcodepixmapLabel->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 381, 26));
        QFont font;
        font.setPointSize(10);
        lineEdit->setFont(font);
        generateButton = new QPushButton(centralWidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(410, 20, 111, 26));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        generateButton->setFont(font1);
        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));
        saveFileButton->setGeometry(QRect(380, 300, 141, 51));
        saveFileButton->setFont(font1);
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 240, 51, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 240, 91, 21));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(MainWindow);

        generateButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QRCode Generator", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "7ot eli t7eb 3lih houni ", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "generate", nullptr));
        saveFileButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "PNG", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "JPG", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "BMP", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "PNG", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "type de img", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
