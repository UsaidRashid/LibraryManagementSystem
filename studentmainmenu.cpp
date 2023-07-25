#include "studentmainmenu.h"
#include "ui_studentmainmenu.h"
#include"checkinout.h"
#include"displaybooks.h"
#include"issue.h"
#include"returnback.h"

StudentMainMenu::StudentMainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMainMenu)
{
    ui->setupUi(this);
}

StudentMainMenu::~StudentMainMenu()
{
    delete ui;
}

void StudentMainMenu::on_radioButton_clicked()
{
    checkinout *ch=new checkinout();
    ch->show();
}


void StudentMainMenu::on_radioButton_4_clicked()
{
    displayBooks *disp=new displayBooks();
    disp->show();
}


void StudentMainMenu::on_radioButton_2_clicked()
{
    issue *i=new issue();
    i->show();
}


void StudentMainMenu::on_radioButton_3_clicked()
{
    returnback *ret=new returnback();
    ret->show();
}
