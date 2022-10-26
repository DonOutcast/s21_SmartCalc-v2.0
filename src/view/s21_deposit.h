#ifndef S21_DEPOSIT_H
#define S21_DEPOSIT_H

#include <QWidget>
//#include "../controller/controller.h"

namespace Ui {
class s21_deposit;
}

class s21_deposit : public QWidget
{
    Q_OBJECT

public:
    explicit s21_deposit(QWidget *parent = nullptr);
    ~s21_deposit();

private slots:
    void on_button_calculate_clicked();

private:
//    s21::Controller s21_controller_d_;
    void dep_calc();
    void event_loop();
    void check_payments_give();
    void check_capital();
    void check_payments_add();
    void check_payments_sub();
    Ui::s21_deposit *ui;
    int viplata_day = 0, viplata_month = 0, viplata_kvartal = 0, viplata_end = 0;
    int kapitalization;
    int add_polyear = 0, add_month = 0, add_kvartal = 0, add_year = 0;
    int minus_polyear = 0, minus_month = 0, minus_kvartal = 0, minus_year = 0;
};

#endif // S21_DEPOSIT_H
