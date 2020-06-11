#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QDialog>
#include <QTableView>
#include <QMainWindow>
#include "event.h"
#include "guests.h"
#include "stati.h"
#include "ui_stati.h"

namespace Ui {
class Evenement;
}

class Evenement : public QDialog
{
    Q_OBJECT

public:
    explicit Evenement(QWidget *parent = nullptr);
    ~Evenement();

private slots:

//void submit();
    //  void on_return_button1_clicked();
       void on_pushButton_7_clicked();
       void on_events_button_clicked();
       void on_guests_button_clicked();
       void on_pushButton_8_clicked();

      void on_pushButton_19_clicked();

       void on_pushButton_20_clicked();

       void on_pushButton_10_clicked();

       void on_pushButton_9_clicked();

       void on_pushButton_21_clicked();

       /*void on_pushButton_5_clicked();*/

   //    void on_pushButton_6_clicked();


       void on_pushButton_clicked();

       void on_pushButton_24_clicked();

       void on_pushButton_22_clicked();

       void on_pushButton_25_clicked();

       void on_pushButton_26_clicked();

       void on_pushButton_3_clicked();

       void on_pushButton_4_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_11_clicked();

       void on_pushButton_2_clicked();

       void on_pushButton_28_clicked();

       void on_pushButton_29_clicked();

       void on_pushButton_23_clicked();

       void on_pushButton_12_clicked();

       void on_pushButton_13_clicked();

       void on_pushButton_14_clicked();

       void on_pushButton_15_clicked();

       void on_pushButton_16_clicked();

       void on_pushButton_17_clicked();

       void on_pushButton_18_clicked();
     //  void on_pushButton_30_clicked();
   //    void on_pushButton_31_clicked();
       void on_pushButton_27_clicked();

       //  void openstatWindow();

    //   void on_pushButton_32_clicked();

       void on_pushButton_30_clicked();

private:
    Ui::Evenement *ui;
    class event temp;
    class Guests tempr;

    int getIDFromTableView(QTableView * tv);
    stati *stat;
};

#endif // EVENEMENT_H


