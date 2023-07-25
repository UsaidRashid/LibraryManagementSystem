#ifndef DISPLAYBOOKS_H
#define DISPLAYBOOKS_H

#include <QDialog>

namespace Ui {
class displayBooks;
}

class displayBooks : public QDialog
{
    Q_OBJECT

public:
    explicit displayBooks(QWidget *parent = nullptr);
    void displayAvailableBooks();
    ~displayBooks();

private:
    Ui::displayBooks *ui;
};

#endif // DISPLAYBOOKS_H
