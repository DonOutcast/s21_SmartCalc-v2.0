#include "s21_credit.h"
#include "ui_s21_credit.h"

s21_credit::s21_credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s21_credit)
{
    ui->setupUi(this);
    this->event_loop();
}

s21_credit::~s21_credit()
{
    delete ui;
}

void s21_credit::on_pushButton_clicked() {
    summary = ui->spin_amount->text().toDouble();
    stavka = ui->spin_rate->text().toDouble();
    time = ui->spin_term->text().toInt();
    if (ui->combo_years_months->currentText() == "years") {
        years = 1;
    }
    ui->spin_diff->hide();
    if (ui->radio_ann->isChecked()) {
        this->controller_.credit_ann(summary, time, stavka, overpayment , total_payment ,years);
    } else {
        ui->spin_diff->show();
        int number_month = 0;
        number_month = ui->spin_diff->text().toInt();
        this->controller_.credit_diff(summary, time, number_month,stavka, overpayment,total_payment);
    }
    ui->label_monthly->setText(QString::number(total_payment, 'g', 4));
    ui->label_over->setText(QString::number(overpayment, 'g', 4));
    ui->label_total->setText(QString::number(summary + overpayment, 'g', 4));
}

void s21_credit::event_loop() {
    this->on_pushButton_clicked();
}

