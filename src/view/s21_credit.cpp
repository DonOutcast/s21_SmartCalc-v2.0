#include "s21_credit.h"
#include "ui_s21_credit.h"

s21_credit::s21_credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s21_credit)
{
    ui->setupUi(this);
}

s21_credit::~s21_credit()
{
    delete ui;
}

void s21_credit::on_pushButton_clicked() {
    this->close();

}

