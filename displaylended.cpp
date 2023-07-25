#include "displaylended.h"
#include "ui_displaylended.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

displayLended::displayLended(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayLended)
{
    ui->setupUi(this);
    displayLendedBooks();
}

displayLended::~displayLended()
{
    delete ui;
}

void displayLended::displayLendedBooks()
{
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryIssualRegister.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString lendedBooks;
        while (!in.atEnd()) {
            QString book = in.readLine();
            lendedBooks += book + "\n";
        }
        file.close();

        ui->textEdit->setPlainText(lendedBooks);
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the lended books file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}
