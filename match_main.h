#ifndef MATCH_MAIN_H
#define MATCH_MAIN_H

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


namespace Ui {
class Match_Main;
}

class Match_Main : public QDialog
{
    Q_OBJECT

public:
    explicit Match_Main(QWidget *parent = nullptr);
    ~Match_Main();
    void Db_Afficher_Liste_Matchs();
    void Db_Add_Values_To_Match_Table(QString Home_Team,QString Visitor_Team , QDate Play_Date, QString Location,QString Home_Team_Pic,QString Away_Team_Pic);
    QString getFilename();
    //void Db_Create_Table();




private slots:
    void on_Match_Cancel_clicked();

    void onTableClicked(const QModelIndex &index);
    void submit();
    void on_Match_Home_Pic_clicked();
    void remove();
    void on_Match_Away_Pic_clicked();
    void generate_Pdf();
    void on_Match_Submit_clicked();
    void choose_Filename();
    void on_Filename_Cancel_clicked();
    void generate_Json();


private:
    Ui::Match_Main *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QPushButton *deleteButton;
    QPushButton *pdfButton;
    QPushButton *jsonButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
    QTableView *view;
    QString Home_Team_Pic;
    QString Away_Team_Pic;

};





#endif // MATCH_MAIN_H
