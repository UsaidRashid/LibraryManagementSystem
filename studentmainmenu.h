#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H

#include <QDialog>

namespace Ui {
class StudentMainMenu;
}

class StudentMainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMainMenu(QWidget *parent = nullptr);
    ~StudentMainMenu();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::StudentMainMenu *ui;
};

#endif // STUDENTMAINMENU_H
