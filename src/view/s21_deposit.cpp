#include "s21_deposit.h"
#include "ui_s21_deposit.h"
#include "../controller/controller.h"
s21_deposit::s21_deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s21_deposit)
{
    ui->setupUi(this);
    this->setFixedSize(880, 660);
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
   this->setFixedSize(860, 880);
    this->event_loop();

}

void s21_deposit::dep_calc() {
  s21::Controller s21_controller_d_;
  int flag = 1;
  double sumnalend = 0;
  double procentEnd = 0;
  double depositEnd = 0;
  if (ui->spin_amount->text().toDouble() != 0 && ui->spin_rate->text().toDouble() != 0 && ui->spin_term->text().toInt() != 0)
  s21_controller_d_.deposit(
      ui->spin_amount->text().toDouble(), ui->spin_term->text().toInt(),
      ui->spin_rate->text().toDouble(), ui->spin_tax_rate->text().toDouble(),
      ui->combo_add->currentIndex() * 3, ui->spin_summary_add->text().toDouble(),
      ui->combo_sub->currentIndex() * 3, ui->spin_summary_sub->text().toDouble(),
      flag, ui->combo_payments_give->currentIndex(), ui->radio_capital->isChecked(), sumnalend,
      procentEnd, depositEnd, ui->spin_begin->text().toInt());
      ui->spin_tax_end->setValue(procentEnd);
      ui->spin_symmary_tax_end->setValue(sumnalend);
      ui->spin_sum_end->setValue(depositEnd + procentEnd);
}


