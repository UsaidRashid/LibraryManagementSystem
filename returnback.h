#ifndef RETURNBACK_H
#define RETURNBACK_H

#include <QDialog>

namespace Ui {
class returnback;
}

class returnback : public QDialog
{
    Q_OBJECT

public:
    explicit returnback(QWidget *parent = nullptr);
    ~returnback();

private slots:
    void on_pushButton_clicked();
    void returnBook(const QString& bookName);

private:
    Ui::returnback *ui;
};

#endif // RETURNBACK_H
