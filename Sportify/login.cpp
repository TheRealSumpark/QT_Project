#include "login.h"
#include "ui_login.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    Connection c;
      bool test=c.createconnect();
      this->setFixedSize(608,629);

}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{  QString username = ui ->lineEditUser->text();
    QString password = ui ->lineEditPass->text();



    QSqlQuery query;
    query.prepare("SELECT * from \"Sportify\".\"USERS\" WHERE USERNAME = ? AND PASSWORD =?");
    query.addBindValue(username);
    query.addBindValue(password);

   if (query.exec() && query.next()) {
        //successful
        //QMessageBox :: information(this,"login","Welcome");
        QMessageBox::information(nullptr, QObject::tr(""),
                   QObject::tr("Welcome ").append(username), QMessageBox::Cancel);
    this->hide();
      MainWindow *w= new MainWindow;
      w->show();


   }
    else {
        // unsuccessful either no match or bad SQL
       QMessageBox::warning(nullptr, QObject::tr(""),
                   QObject::tr("Wrong  Username or Password\n"), QMessageBox::Cancel);
    }


}
