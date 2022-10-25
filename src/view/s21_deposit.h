#ifndef S21_DEPOSIT_H
#define S21_DEPOSIT_H

#include <QWidget>

namespace Ui {
class s21_deposit;
}

class s21_deposit : public QWidget
{
    Q_OBJECT

public:
    explicit s21_deposit(QWidget *parent = nullptr);
    ~s21_deposit();

private:
    Ui::s21_deposit *ui;
};

#endif // S21_DEPOSIT_H
