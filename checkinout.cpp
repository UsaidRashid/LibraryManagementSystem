#include "checkinout.h"
#include "ui_checkinout.h"
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QDateTime>

checkinout::checkinout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkinout)
{
    ui->setupUi(this);
}

checkinout::~checkinout()
{
    delete ui;
}

bool isUserInside(const QString& name)
{
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryAttendanceRegister.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        bool checkedIn = false;
        bool checkedOut = false;

        while (!in.atEnd())
        {
            QString line = in.readLine();

            if (line.contains(name))
            {
                if (line.contains("CHECKED IN"))
                {
                    checkedIn = true;
                    checkedOut = false;
                }
                else if (line.contains("CHECKED OUT"))
                {
                    checkedOut = true;
                }
            }
        }

        file.close();

        if (checkedIn && !checkedOut)
        {
            return true;  // User is inside
        }
    }

    return false;
}

void checkinout::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();

    if (name.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information, "Check-In", "Please enter your name.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
        return;
    }

    if (isUserInside(name))
    {
        QMessageBox msgBox(QMessageBox::Information, "Check-In", "You are already inside.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
        return;
    }

    QDateTime currentTime = QDateTime::currentDateTime();
    QString checkInTime = currentTime.toString();

    // Save the check-in information to the attendance register file
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryAttendanceRegister.txt";

    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << name << " CHECKED IN AT : " << checkInTime << "\n";
        file.close();

        QMessageBox msgBox(QMessageBox::Information, "Check-In", "Check-in successful.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }

}



void checkinout::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_2->text();

    if (name.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information, "Check-Out", "Please enter your name.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
        return;
    }

    if (!isUserInside(name))
    {
        QMessageBox msgBox(QMessageBox::Information,"Check-Out","You never checked in.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
        return;
    }

    QDateTime currentTime = QDateTime::currentDateTime();
    QString checkOutTime = currentTime.toString();

    // Save the check-out information to the attendance register file
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryAttendanceRegister.txt";

    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << name << " CHECKED OUT AT : " << checkOutTime << "\n";
        file.close();

        QMessageBox msgBox(QMessageBox::Information, "Check-Out", "Check-out successful.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}

