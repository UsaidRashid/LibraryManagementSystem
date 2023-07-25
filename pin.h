#ifndef PIN_H
#define PIN_H

#include <QDialog>

namespace Ui {
class pin;
}

class pin : public QDialog
{
    Q_OBJECT

public:
    explicit pin(QWidget *parent = nullptr);
    ~pin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pin *ui;
};

#endif // PIN_H
