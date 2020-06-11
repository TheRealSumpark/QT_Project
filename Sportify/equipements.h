#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H

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
class Equipements;
}

class Equipements : public QDialog
{
    Q_OBJECT

public:
    explicit Equipements(QWidget *parent = nullptr);
    ~Equipements();
     void Afficher_Liste_Equipements();

private slots:

    void Add_Values_To_Db(QString Nom,int  Quantite,QString Logo );

    void remove();
    void submit();
    void generate_Pdf();
    void onTableClicked(const QModelIndex &index);




    void on_Equipement_Ajout_Cancel_clicked();

    void on_Equipement_Ajout_Submit_clicked();

    void on_Equipement_Ajout_Image_clicked();

private:
    Ui::Equipements *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QPushButton *deleteButton;
    QPushButton *pdfButton;
    QString Logo="";

    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QTableView *view;
};

#endif // EQUIPEMENTS_H
