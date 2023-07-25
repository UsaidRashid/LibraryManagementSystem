#include "pin.h"
#include "ui_pin.h"
#include<QString>
#include<QMessageBox>
#include"authoritymainmenu.h"
#include<QDebug>

pin::pin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pin)
{
    ui->setupUi(this);
}

pin::~pin()
{
    delete ui;
}

void pin::on_pushButton_clicked()
{
    QString p=ui->lineEdit->text();
    if(p=="12345"){
        AuthorityMainMenu *a=new AuthorityMainMenu();
        a->show();
    }
    else{
        QMessageBox msgBox(QMessageBox::Warning, "Wrong Pin", "Sorry, but it seems like you entered the wrong pin.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}
