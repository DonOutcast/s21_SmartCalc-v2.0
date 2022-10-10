#include "s21_view.h"
#include "ui_s21_view.h"

s21_view::s21_view(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_view)
{
    ui->setupUi(this);
}

s21_view::~s21_view()
{
    delete ui;
}

