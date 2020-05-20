#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{  QString username = ui ->lineEditUser->text();
    QString password = ui ->lineEditPass->text();



    QSqlQuery query;
    query.prepare("SELECT * from USERS WHERE USERNAME = ? AND PASSWORD =?");
    query.addBindValue(username);
    query.addBindValue(password);

   if (query.exec() && query.next()) {
        //successful
        //QMessageBox :: information(this,"login","Welcome");

    this->hide();
      MainWindow w;
      w.show();


   }
    else {
        // unsuccessful either no match or bad SQL
            QMessageBox::warning(this,"login","wrong password");
    }


}
