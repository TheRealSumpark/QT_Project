#include "mandatoryfieldgroup.h"

#include <QObject>
#include <QList>
#include <QCheckBox>
#include <QtCore>
#include <QLineEdit>
#include <QCheckBox>

void MandatoryFieldGroup::add(QWidget *widget)
   {
       if (!widgets.contains(widget)) {
           if (widget->inherits("QCheckBox")) {
               connect(widget, SIGNAL(clicked()),this, SLOT(changed()));
           } else if (widget->inherits("QComboBox")) {
               connect(widget, SIGNAL(highlighted(int)),this, SLOT(changed()));
           } else if (widget->inherits("QLineEdit")) {
               connect(widget,SIGNAL(textChanged(const QString &)),this, SLOT(changed()));
           } else {
               qWarning("%s unhandled", widget->className());
               return;
           }
           widget->setPaletteBackgroundColor(yellow);
           widgets.append(widget);
           changed();
       }
   }



void MandatoryFieldGroup::setOkButton(QPushButton *button)
   {
       if (okButton && okButton != button)
           okButton->setEnabled(true);
       okButton = button;
       changed();
   }



void MandatoryFieldGroup::changed()
    {
        if (!okButton)
            return;
        bool enable = true;
        QValueList<QWidget *>::const_iterator i;
        for (i = widgets.begin(); i != widgets.end(); ++i) {
            QWidget *widget = *i;
            if (widget->inherits("QCheckBox")) {
                if (((QCheckBox *)widget)->state() ==
                    QButton::NoChange) {
                    enable = false;
                    break;
                }
            } else if (widget->inherits("QComboBox")) {
                if (currentText().isEmpty()) {
                    enable = false;
                    break;
                }
            } else if (widget->inherits("QLineEdit")) {
                if (((QLineEdit *)widget)->text().isEmpty()) {
                    enable = false;
                    break;
                }
            }
        }
        okButton->setEnabled(enable);
    }
