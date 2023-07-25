#include "add.h"
#include "ui_add.h"
#include<QString>
#include<QMessageBox>
#include<QFile>

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_clicked()
{
    QString bookName=ui->lineEdit->text();
    QFile inputFile("E:/QT/LibraryManagementSystem/LibraryBooks.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        bool bookExists = false;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if (line == bookName)
            {
                bookExists = true;
                break;
            }
        }
        inputFile.close();
        if (bookExists)
        {
            QString msg = QString("'%1' book already exists!").arg(bookName);
            QMessageBox msgBox(QMessageBox::Warning, "Book Exists", msg);
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        }
        else
        {
            QFile outputFile("E:/QT/LibraryManagementSystem/LibraryBooks.txt");
            if (outputFile.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream out(&outputFile);
                out << bookName << "\n";
                outputFile.close();
                QString successMessage = QString("'%1' added successfully!").arg(bookName);
                QMessageBox msgBox(QMessageBox::Information, "Success", successMessage);
                msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
                msgBox.exec();
            }
            else
            {
                QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open LibraryBooks.txt for writing.");
                msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
                msgBox.exec();
            }
        }
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open LibraryBooks.txt for reading.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}
