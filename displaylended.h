#ifndef DISPLAYLENDED_H
#define DISPLAYLENDED_H

#include <QDialog>

namespace Ui {
class displayLended;
}

class displayLended : public QDialog
{
    Q_OBJECT

public:
    explicit displayLended(QWidget *parent = nullptr);
    void displayLendedBooks();
    ~displayLended();

private:
    Ui::displayLended *ui;
};

#endif // DISPLAYLENDED_H
