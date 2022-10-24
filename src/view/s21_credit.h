#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QWidget>
#include "../controller/controller.h"
namespace Ui {
class s21_credit;
}

class s21_credit : public QWidget
{
    Q_OBJECT

public:
    explicit s21_credit(QWidget *parent = nullptr);
    ~s21_credit();

private slots:
    void on_pushButton_clicked();

private:
    s21::Controller controller_;
    Ui::s21_credit *ui;
    double summary = 0;
    double stavka = 0;
    int time = 0;
    int years = 0;
    double total_payment = 0;
    double overpayment = 0;
    void event_loop();
};

#endif // S21_CREDIT_H
