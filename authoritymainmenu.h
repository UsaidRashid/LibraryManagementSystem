#ifndef AUTHORITYMAINMENU_H
#define AUTHORITYMAINMENU_H

#include <QDialog>

namespace Ui {
class AuthorityMainMenu;
}

class AuthorityMainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorityMainMenu(QWidget *parent = nullptr);
    ~AuthorityMainMenu();
    void AddBooks();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

private:
    Ui::AuthorityMainMenu *ui;
};

#endif // AUTHORITYMAINMENU_H
