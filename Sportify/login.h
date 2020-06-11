#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QWidget>
#include "home.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
