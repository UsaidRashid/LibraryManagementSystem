#include "displaybooks.h"
#include "ui_displaybooks.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>

displayBooks::displayBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayBooks)
{
    ui->setupUi(this);
    displayAvailableBooks();
}

displayBooks::~displayBooks()
{
    delete ui;
}

void displayBooks::displayAvailableBooks(){
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryBooks.txt";
    qDebug()<<"running";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString books = in.readAll();
        file.close();

        ui->textEdit->setPlainText(books);
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the attendance register file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}
