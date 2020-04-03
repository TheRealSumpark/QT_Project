#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QFileDialog>
#include <QtWidgets>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString filename;
    int verif=0;
private slots:
 QString on_b_image_clicked();
void on_Ajouter_joueur_clicked();

void on_pushButton_2_clicked();

private:

    Ui::Dialog *ui;
};

#endif // DIALOG_H
