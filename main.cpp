#include "loginwindow.h"
#include<Qlabel>
#include<QPixmap>
#include <QApplication>
#include <bits/stdc++.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <cctype>
#include<QFile>
#include<QMessageBox>
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
