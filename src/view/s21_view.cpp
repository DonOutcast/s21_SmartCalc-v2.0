#include "s21_view.h"
#include "ui_s21_view.h"
#include <QDebug>
s21_view::s21_view(QWidget *parent): QMainWindow(parent), ui(new Ui::s21_view) {
    ui->setupUi(this);
//    ui->pushButton->setText("Hello World!");
//    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(digits_numbers()));
//       connect(ui->button_0, SIGNAL(clicked()), this, SLOT(output_label()));
    this->buttons_digits_ = {
        ui->button_0, ui->button_1, ui->button_2, ui->button_3,
        ui->button_4, ui->button_5, ui->button_6, ui->button_7,
        ui->button_8, ui->button_9
    };

    this->buttons_lexems_ = {
        ui->button_plus, ui->button_minus, ui->button_mult,
        ui->button_div,  ui->button_point,
        ui->button_open, ui->button_close,

    };
    this->buttons_functions_ = {
        ui->button_sin, ui->button_cos, ui->button_tan,
        ui->button_asin, ui->button_acos, ui->button_atan,
        ui->button_ln, ui->button_log, ui->button_mod, ui->button_sqrt
    };
    this->connecting_buttons();
    this->connection_function();
//    this->s21_credit_ = new s21_credit;
}

s21_view::~s21_view() {
    delete ui;
}

void s21_view::connecting_buttons() {
    for (auto &iter : this->buttons_digits_) {
        connect(iter, SIGNAL(clicked()), this, SLOT(output_label()));
    }

    for (auto &iter_2 : this->buttons_lexems_) {
        connect(iter_2, SIGNAL(clicked()), this, SLOT(output_label()));
    }

    connect(ui->button_equal, SIGNAL(clicked()), this, SLOT(calculate_finally()));

}

void s21_view::connection_function() {
    for (auto &iter_3 : this->buttons_functions_) {
        connect(iter_3, SIGNAL(clicked()), this, SLOT(output_functions()));
    }
}

void s21_view::output_functions() {
    QPushButton *button = (QPushButton *)sender();
    this->clear_label();
    QString result = ui->console->text();
    if (ui->console->text() == "0") {
        ui->console->clear();
    }
    ui->console->setText(result + button->text() + "(");
}

void s21_view::clear_label() {
    QString result = ui->console->text();
    if (result == "ERROR INPUT!") {
        ui->console->setText("");
    }
}

void s21_view::output_label() {
    QPushButton *button = (QPushButton *)sender();
    this->clear_label();
    QString result = ui->console->text();
    if (ui->console->text() == "0") {
        ui->console->clear();
    }
    if (ui->console->hasFocus())
        ui->console->setText(result + button->text());
    else if (ui->console_x->hasFocus())
        ui->console_x->setText(button->text());
}

void s21_view::calculate_finally() {
    double result = 0;
    std::string str = ui->console->text().toStdString();
    int check_input = 0;
    double x_value = ui->console_x->text().toDouble();
    check_input = this->s21_calc_.finally(str, x_value, result);
    if (check_input) {
        ui->console->setText("ERROR INPUT!");
    } else {
        ui->console->setText(QString::number(result, 'g', 15));
    }
}

//void s21_view::on_pushButton_clicked() {
//   qDebug() << "Ckicked";
//}


//void  s21_view::digits_numbers() {
//   QPushButton *button = (QPushButton *) sender();
//    ui->console->setText(button->text());
//}



void s21_view::on_button_clear_clicked()
{
    ui->console->clear();
}


void s21_view::on_button_credit_clicked()
{

    QWidget *widget = nullptr;
    auto const &objName = sender()->objectName();
    if (objName == "button_credit")
        widget = new s21_credit();
////    else if (objName == "graphCalcBtn")
////        widget = new GraphCalcView(controller_);
////    else if (objName == "creditCalcBtn")
////        widget = new CreditCalcView(controller_);
////    else
////        widget = new DepositCalcView(controller_);
    hide();
    execWidget(widget);
//    this->s21_credit_->show();
//    this->s21_credit_.setWindowTitle("CREDIT");
}

void s21_view::execWidget(QWidget *widget) {
    if (widget != nullptr) {
        QList<QPushButton*> btnList = widget->findChildren<QPushButton*>("button_back");
        connect(btnList[0], &QPushButton::clicked, this, &s21_view::closeCalcHandler);
//        setWidgetToCenter(widget);
        widget->show();
    }
}

void s21_view::closeCalcHandler() {
    QWidget *widget = qobject_cast<QWidget*>(sender()->parent());
    if (widget != nullptr)
        delete widget;
//    setWidgetToCenter(this);
    show();
}
