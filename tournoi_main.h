#ifndef TOURNOI_MAIN_H
#define TOURNOI_MAIN_H

#include <QDialog>
#include <QFileDialog>
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
#include <QPixmap>

namespace Ui {
class Tournoi_Main;
}

class Tournoi_Main : public QDialog
{
    Q_OBJECT

public:
    explicit Tournoi_Main(QWidget *parent = nullptr);
    ~Tournoi_Main();
    QString getFilename();
    void Db_Afficher_Liste_Tournois();
    void Db_Add_Values_To_Tournois_Table(QString Nom ,QString Categorie,QString Date_Lancement, int Nb_Participants);

private slots:

    void on_pushButton_clicked();
    void on_Tournoi_Main_Submit_clicked();
    void submit();
    void remove();
    void generate_Pdf();
    void choose_Filename();
    void generate_Json();
    void on_Filename_Cancel_clicked();

private:
    Ui::Tournoi_Main *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QPushButton *deleteButton;
    QPushButton *pdfButton;
    QPushButton *jsonButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QTableView *view;
};

#endif // TOURNOI_MAIN_H
