#include "returnback.h"
#include "ui_returnback.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

returnback::returnback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnback)
{
    ui->setupUi(this);
}

returnback::~returnback()
{
    delete ui;
}

void returnback::returnBook(const QString& bookName){
    QStringList booksIssued; // Assuming this is the QStringList to store issued book names
    QStringList BOOKS;      // Assuming this is the QStringList to store all available book names

    QFile issuedFile("E:/QT/LibraryManagementSystem/LibraryIssualRegister.txt");
    QFile updatedFile("E:/QT/LibraryManagementSystem/LibraryBooks.txt");

    if (issuedFile.open(QIODevice::ReadOnly | QIODevice::Text) &&
        updatedFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream in(&issuedFile);
        while (!in.atEnd()) {
            QString book = in.readLine();
            booksIssued.append(book);
        }
        issuedFile.close();

        bool found = false;
        for (int i = 0; i < booksIssued.size(); ++i) {
            if (booksIssued.at(i) == bookName) {
                found = true;
                BOOKS.append(bookName);
                booksIssued.removeAt(i);
                break;
            }
        }

        if (found) {
            // Update "LIBRARY BOOKS.txt" to include the returned book
            QTextStream out(&updatedFile);
            out << bookName << "\n";
            updatedFile.close();

            // Update "LIBRARY ISSUAL REGISTER.txt" with remaining issued books
            if (issuedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&issuedFile);
                for (const QString& book : booksIssued) {
                    out << book << "\n";
                }
                issuedFile.close();
            } else {
                QMessageBox msgBox(QMessageBox::Warning, "Error", "Failed to open Issual Register File");
                msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
                msgBox.exec();
            }

            QMessageBox msgBox(QMessageBox::Information, "Success", "THANK YOU FOR RETURNING THE BOOK.\nWE HOPE TO SEE YOU AGAIN.");
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        } else {
            QMessageBox msgBox(QMessageBox::Warning, "Error", "The book named \"" + bookName + "\" was never lent or is misspelled.\nPlease check the name and try again.");
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Failed to open files");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}

void returnback::on_pushButton_clicked()
{
    QString bookName = ui->lineEdit->text();
    returnBook(bookName);
}
