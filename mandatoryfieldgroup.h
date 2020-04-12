#ifndef MANDATORYFIELDGROUP_H
#define MANDATORYFIELDGROUP_H

#include <QObject>
#include <QPushButton>
#include <QSqlQueryModel>

class MandatoryFieldGroup : public QObject
    {
        Q_OBJECT
    public:
        MandatoryFieldGroup(QObject *parent)
            : QObject(parent), okButton(0) {}

        void add(QWidget *widget);
        void remove(QWidget *widget);
        void setOkButton(QPushButton *button);

    private slots:
        void changed();

    private:
        QValueList<QWidget *> widgets;
        QPushButton *okButton;
    };


#endif // MANDATORYFIELDGROUP_H
