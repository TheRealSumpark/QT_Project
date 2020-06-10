#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QDialog>
#include <QtDebug>
#include <QtSql>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include <QWidget>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QTableView>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextTableFormat>
#include <QPrinter>
#include <QTextTableCell>
#include <QTableWidget>
#include <QModelIndex>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QFileDialog>


namespace Ui {
class Fournisseur;
}

class Fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit Fournisseur(QWidget *parent = nullptr);
    ~Fournisseur();
    void Afficher_Liste_Fournisseurs();


private slots:
    void on_Fournisseur_Ajout_Cancel_clicked();
    void Add_Values_To_Db(QString Nom,QString Adresse );
    void on_Fournisseur_Ajout_Submit_clicked();
    void remove();
    void submit();
    void generate_Pdf();
    void onTableClicked(const QModelIndex &index);

private:
    Ui::Fournisseur *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QPushButton *deleteButton;
    QPushButton *pdfButton;

    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QTableView *view;
};

#endif // FOURNISSEUR_H
