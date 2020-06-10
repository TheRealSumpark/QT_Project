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
    bool verifID();
    bool verifImage();
    bool verifPrenom();
    bool verifNom();
    bool verifdateNaissance();
    bool verifTaille();
    bool verifPoids();
    bool verifNumero();
    QPixmap PixTrueIcon;
    QPixmap PixFalseIcon;
private slots:
 QString on_b_image_clicked();
void on_Ajouter_joueur_clicked();

void on_pushButton_2_clicked();

void on_in_id_cursorPositionChanged(int arg1, int arg2);

void on_in_prenom_cursorPositionChanged(int arg1, int arg2);

void on_in_nom_cursorPositionChanged(int arg1, int arg2);

void on_in_date_userDateChanged(const QDate &date);

void on_in_poids_valueChanged(double arg1);

void on_in_taille_valueChanged(double arg1);

void on_in_number_valueChanged(int arg1);

private:

    Ui::Dialog *ui;
};

#endif // DIALOG_H
