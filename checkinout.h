#ifndef CHECKINOUT_H
#define CHECKINOUT_H

#include <QDialog>

namespace Ui {
class checkinout;
}

class checkinout : public QDialog
{
    Q_OBJECT

public:
    explicit checkinout(QWidget *parent = nullptr);
    ~checkinout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::checkinout *ui;
};

#endif // CHECKINOUT_H
