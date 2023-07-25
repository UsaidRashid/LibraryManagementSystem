#include "authoritymainmenu.h"
#include "ui_authoritymainmenu.h"
#include"add.h"
#include"delete.h"
#include"attendance.h"
#include"displaybooks.h"
#include"displaylended.h"
#include"pin.h"

AuthorityMainMenu::AuthorityMainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorityMainMenu)
{
    ui->setupUi(this);

}

AuthorityMainMenu::~AuthorityMainMenu()
{
    delete ui;
}

void AuthorityMainMenu::on_radioButton_clicked()
{
    Add *a=new Add();
    a->show();
}

void AuthorityMainMenu::on_radioButton_2_clicked()
{
    Delete *d=new Delete();
    d->show();
}


void AuthorityMainMenu::on_radioButton_3_clicked()
{
    Attendance *at=new Attendance();
    at->show();
}

void AuthorityMainMenu::on_radioButton_4_clicked()
{
    displayBooks *disp=new displayBooks();
    disp->show();
}


void AuthorityMainMenu::on_radioButton_5_clicked()
{
    displayLended *len=new displayLended();
    len->show();
}

