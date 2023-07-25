#include "delete.h"
#include "ui_delete.h"
#include<QString>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_clicked()
{
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryBooks.txt";
    QString bookName=ui->lineEdit->text();

    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream in(&file);
        QStringList bookList;


        while (!in.atEnd())
        {
            QString line = in.readLine();
            bookList.append(line);
        }

        file.resize(0);

        bool bookDeleted = false;

        for (const QString& book : bookList)
        {
            if (book != bookName)
            {
                in << book << "\n";
            }
            else
            {
                bookDeleted = true;
            }
        }

        file.close();

        if (bookDeleted)
        {
            QString msg= QString("'%1' has been deleted successfully!").arg(bookName);
            QMessageBox msgBox(QMessageBox::Information, "Book Deleted", msg);
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        }
        else
        {
            QString msg= QString("'%1' does not exist!").arg(bookName);
            QMessageBox msgBox(QMessageBox::Warning, "Book Not Found", msg);
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}

