#include "s21_deposit.h"
#include "ui_s21_deposit.h"
#include "../controller/controller.h"
s21_deposit::s21_deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s21_deposit)
{
    ui->setupUi(this);
}

s21_deposit::~s21_deposit()
{
    delete ui;
}


void s21_deposit::check_payments_give() {
    if (!ui->combo_payments_give->currentIndex()) {
        this->viplata_day = 1;
    } else if (ui->combo_payments_give->currentIndex() == 1) {
        this->viplata_month = 1;
    } else if (ui->combo_payments_give->currentIndex() == 2) {
        this->viplata_kvartal = 1;
    } else if (ui->combo_payments_give->currentIndex() == 3) {
        this->viplata_end = 1;
    }
}

void s21_deposit::check_capital() {
    if (ui->radio_capital->isChecked()) {
        this->kapitalization = 1;
    }
}

void s21_deposit::check_payments_add() {
    if (!ui->combo_add->currentIndex()) {
        this->add_month = 1;
    } else if (ui->combo_add->currentIndex() == 1) {
        this->add_kvartal = 1;
    } else if (ui->combo_add->currentIndex() == 2) {
        this->add_polyear = 1;
    } else if (ui->combo_add->currentIndex() == 3) {
        this->add_year = 1;
    }
}

void s21_deposit::check_payments_sub() {
    if (!ui->combo_sub->currentIndex()) {
        this->minus_month = 1;
    } else if (ui->combo_sub->currentIndex() == 1) {
        this->minus_kvartal = 1;
    } else if (ui->combo_sub->currentIndex() == 2) {
        this->minus_polyear = 1;
    } else if (ui->combo_sub->currentIndex() == 3) {
        this->minus_year = 1;
    }
}

void s21_deposit::event_loop() {
    this->check_payments_give();
    this->check_payments_add();
    this->check_capital();
    this->check_payments_sub();
    this->dep_calc();

}

void s21_deposit::on_button_calculate_clicked() {
//    double summary = 0;
//    int time = 0;
//    double rate = 0;
//    double nalog_rate = 0;
//    int choise_plus =  0;
//    double plus = 0;
//    int choise_minus = 0;
//    double minus = 0;
//    int choise_payments = 0;
//    int period_payments = 0;
//    int choise_kap  = 0;
//    double summ_end = 0;
//    double procent_end = 0;
//    int month = 0;

//    summary = ui->spin_amount->text().toDouble();
//    time = ui->spin_term->text().toInt();
//    rate = ui->spin_rate->text().toDouble();
//    nalog_rate = ui->spin_tax_rate->text().toDouble();
//    month = ui->spin_begin->text().toInt();

    this->event_loop();

}

void s21_deposit::dep_calc() {
  s21::Controller s21_controller_d_;
  int flag = 1;
  double sumnalend = 0;
  double procentEnd = 0;
  double depositEnd = 0;
  s21_controller_d_.deposit(
      ui->spin_amount->text().toDouble(), ui->spin_term->text().toInt(),
      ui->spin_rate->text().toDouble(), ui->spin_tax_rate->text().toDouble(),
      ui->combo_add->currentIndex() * 3, ui->spin_summary_add->text().toDouble(),
      ui->combo_sub->currentIndex() * 3, ui->spin_summary_sub->text().toDouble(),
      flag, ui->combo_payments_give->currentIndex(), ui->radio_capital->isChecked(), sumnalend,
      procentEnd, depositEnd, ui->spin_begin->text().toInt());
      ui->spin_tax_end->setValue(procentEnd);
      ui->spin_symmary_tax_end->setValue(sumnalend);
      ui->spin_sum_end->setValue(depositEnd);
//    ui->label_monthly->setText(QString::number(total_payment, 'g', 4));
//    ui->label_over->setText(QString::number(overpayment, 'g', 4));
//    ui->label_total->setText(QString::number(summary + overpayment, 'g', 4));
}


