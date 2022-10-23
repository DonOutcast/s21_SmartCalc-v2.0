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
    std::string summary = "";
    std::string stavka = "";
    std::string time = "";
    double output_x;
    double output_pereplata;
   summary = ui->spin_amount->text().toStdString();
   stavka = ui->spin_rate->text().toStdString();
   time = ui->spin_term->text().toStdString();
   double s = 0;
   s = ui->spin_amount->text().toDouble();
   if (ui->radio_ann->isChecked()) {
    this->controller_.credit_A(summary, time , stavka, output_x, output_pereplata);
       ui->label_monthly->setText(QString::number(output_pereplata, 'g', 3));
       ui->label_over->setText(QString::number(output_x, 'g', 3));
       ui->label_total->setText(QString::number(s + output_pereplata, 'g', 3));   }

}

void s21_credit::event_loop() {

    this->on_pushButton_clicked();
}

