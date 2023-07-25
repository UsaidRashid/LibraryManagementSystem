#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include<QPixmap>
#include"pin.h"
#include"studentmainmenu.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}
LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_radioButton_2_clicked()
{
    pin *p=new pin(this);
    p->show();
}


void LoginWindow::on_radioButton_clicked()
{
    StudentMainMenu *s=new StudentMainMenu();
    s->show();
}
