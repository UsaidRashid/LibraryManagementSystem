#include "attendance.h"
#include "ui_attendance.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

Attendance::Attendance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Attendance)
{
    ui->setupUi(this);
    displayAttendanceRegister(); // Call the function to display the attendance register
}

Attendance::~Attendance()
{
    delete ui;
}

void Attendance::displayAttendanceRegister()
{
    QString filePath = "E:/QT/LibraryManagementSystem/LibraryAttendanceRegister.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString attendanceText = in.readAll();
        file.close();

        ui->textEdit->setPlainText(attendanceText);
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Failed to open the attendance register file.");
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));; } QLabel { color: white; }");
        msgBox.exec();
    }
}
