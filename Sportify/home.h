#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include <QtDebug>
#include <QtSql>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include <QWidget>
#include <QPushButton>

#include <QDialogButtonBox>

#include <QHBoxLayout>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextTableFormat>
#include <QFileDialog>
#include <QTextTableCell>
#include <QTableWidget>
#include <QModelIndex>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QPrinter>

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();



private slots:
    void on_pushButton_clicked();

    void on_terrain_clicked();

    void on_employes_clicked();

    void on_home_2_clicked();

    void on_home_3_clicked();






  //  void on_loadview_clicked();



    void on_add_clicked();


    void on_delete_2_clicked();

    void on_load_table_clicked();

    void sendMail();
   // void mailSent(QString);






 //   void on_tableView_2_activated(const QModelIndex &index);

    void on_pdf_clicked();

    void on_home_4_clicked();

    void on_report_clicked();

    void on_add_stade_clicked();

    void on_load_table_stade_clicked();

    void on_delete_stade_clicked();

    void on_pdf_2_clicked();

    void on_home_5_clicked();

private:
    Ui::home *ui;

QSqlTableModel *modal;


};

#endif // HOME_H
