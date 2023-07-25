#include "issue.h"
#include "ui_issue.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QTextStream>

issue::issue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::issue)
{
    ui->setupUi(this);
}

issue::~issue()
{
    delete ui;
}

void issue::issueBook(const QString& bookName) {
    QFile inputFile("E:/QT/LibraryManagementSystem/LibraryBooks.txt");
    QFile issuedFile("E:/QT/LibraryManagementSystem/LibraryIssualRegister.txt");
    QStringList availableBooks; // Store the available books

    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text) &&
        issuedFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream in(&inputFile);
        QTextStream out(&issuedFile);

        bool bookFound = false;
        while (!in.atEnd()) {
            QString book = in.readLine();
            if (book == bookName) {
                bookFound = true;
                out << bookName << "\n"; // Update "LIBRARY ISSUAL REGISTER.txt"
            } else {
                availableBooks.append(book); // Add to the available books list
            }
        }

        inputFile.close();
        issuedFile.close();

        if (bookFound) {
            // Update "LIBRARY BOOKS.txt" to exclude the issued book
            QFile updatedFile("E:/QT/LibraryManagementSystem/LibraryBooks.txt");
            if (updatedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&updatedFile);
                for (const QString& book : availableBooks) {
                    out << book << "\n";
                }
                updatedFile.close();

                QMessageBox msgBox(QMessageBox::Warning, "Success", "THANK YOU FOR LENDING THE BOOK. WE HOPE YOU'LL ENJOY IT. PLEASE MAKE SURE TO RETURN IT IN TIME.");
                msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
                msgBox.exec();
            } else {
                QMessageBox msgBox(QMessageBox::Warning, "Error", "Failed to open Library Books File");
                msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
                msgBox.exec();
            }
        } else {
            QMessageBox msgBox(QMessageBox::Warning, "Error", "OOPS! Please check the name of the book you entered is correct or not. NOTE:The book must be available in the library to issue");
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Failed to open files");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}

void issue::on_pushButton_clicked()
{
    QString bookName = ui->lineEdit->text();
    issueBook(bookName);
}
