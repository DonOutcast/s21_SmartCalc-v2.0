#include "s21_deposit.h"
#include "ui_s21_deposit.h"

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
