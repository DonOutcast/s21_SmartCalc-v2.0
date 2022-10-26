#include "s21_view.h"
#include "ui_s21_view.h"
#include <QDebug>
s21_view::s21_view(QWidget *parent): QMainWindow(parent), ui(new Ui::s21_view) {

    ui->setupUi(this);
    this->event_loop();
    QPixmap pix("/Users/lymondgl/Desktop/s21_SmartCalc-v2.0/src/images/sber.png");
    ui->label_6->setPixmap(pix);
}

s21_view::~s21_view() {
    delete ui;
}

void s21_view::event_loop() {
       this->setFixedSize(750, 600);
    this->buttons_digits_ = {
        ui->button_0, ui->button_1, ui->button_2, ui->button_3,
        ui->button_4, ui->button_5, ui->button_6, ui->button_7,
        ui->button_8, ui->button_9, ui->button_e,
    };

    this->buttons_lexems_ = {
        ui->button_plus, ui->button_minus, ui->button_mult,
        ui->button_div,  ui->button_point, ui->button_pow,
        ui->button_open, ui->button_close, ui->button_x,

    };
    this->buttons_functions_ = {
        ui->button_sin, ui->button_cos, ui->button_tan,
        ui->button_asin, ui->button_acos, ui->button_atan,
        ui->button_ln, ui->button_log, ui->button_mod, ui->button_sqrt
    };
        this->connection_function();
        this->connecting_buttons();
    connect(ui->check_x, &QCheckBox::stateChanged, this, &s21_view::autoBtnClickHandler);
    connect(ui->check_y, &QCheckBox::stateChanged, this, &s21_view::autoBtnClickHandler);
    connectSignals();

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
    QString result_x = ui->console->text();
    if (ui->console->text() == "0") {
        ui->console->clear();
    }
    if (ui->console->hasFocus())
        ui->console->setText(result + button->text());
    else if (ui->console_x->hasFocus())
        ui->console_x->setText(result_x + button->text());
}

void s21_view::calculate_finally() {
    double result = 0;
    std::string str = ui->console->text().toStdString();
    int check_input = 0;
    int check_x = 0;
    double x_value = 0;
    x_value = ui->console_x->text().toDouble();
    std::string  str_x = ui->console_x->text().toStdString();
    if (str_x != "")
    check_x = this->s21_calc_.finally(str_x, 0, x_value);
    check_input = this->s21_calc_.finally(str, x_value, result);
    if (check_input || check_x) {
        ui->console->setText("ERROR INPUT!");
    } else {
        ui->console->setText(QString::number(result, 'g', 15));
    }
}

void s21_view::on_button_clear_clicked() {
    ui->console->clear();
}



void s21_view::connectSignals() {
    QList<QPushButton*> openCalcButtons {
        ui->button_deposit, ui->button_credit,
    };
    for (QPushButton *btn : qAsConst(openCalcButtons))
        connect(btn, &QPushButton::clicked, this, &s21_view::openCalcHandler);
//    connect(ui->quitBtn, &QPushButton::clicked, this, &s21_view::close);
}

void s21_view::closeCalcHandler() {
    QWidget *widget = qobject_cast<QWidget*>(sender()->parent());
    if (widget != nullptr)
        delete widget;
//    setWidgetToCenter(this);
    show();
}


void s21_view::openCalcHandler()
{

    QWidget *widget = nullptr;
    auto const &objName = sender()->objectName();
    if (objName == "button_credit") {
        widget = new s21_credit();
       }
    else if (objName == "button_deposit") {
        widget = new s21_deposit();
    }
////    else if (objName == "creditCalcBtn")
////        widget = new CreditCalcView(controller_);
////    else
////        widget = new DepositCalcView(controller_);
    hide();
    execWidget(widget);
}

void s21_view::execWidget(QWidget *widget) {
    if (widget != nullptr) {
        QList<QPushButton*> btnList = widget->findChildren<QPushButton*>("button_back");
        connect(btnList[0], &QPushButton::clicked, this, &s21_view::closeCalcHandler);
        widget->show();
    }
}




void s21_view::autoBtnClickHandler(int state) {
    if (sender()->objectName() == "check_x") {
        changeRangeState(ui->spin_x_begin, state, -10);
        changeRangeState(ui->spin_x_end, state, 10);
    } else if (sender()->objectName() == "check_y"){
        changeRangeState(ui->spin_y_begin, state, -1);
        changeRangeState(ui->spin_y_end, state, 1);
    }
}

void s21_view::changeRangeState(QSpinBox *spin, int state, int startValue) {
    if (state == Qt::Unchecked) {
        spin->setEnabled(true);
    } else {
        spin->setValue(startValue);
        spin->setEnabled(false);
    }
}


void s21_view::on_button_graph_clicked() {
    this->setFixedSize(1500, 600);
    ui->spin_x_begin->setValue(-10);
    ui->spin_x_end->setValue(10);
    ui->spin_y_begin->setValue(-1);
    ui->spin_y_end->setValue(1);
    ui->widget->clearGraphs();
    double  xBegin = 0;
    double xEnd = 0;
    xBegin = ui->spin_x_begin->text().toDouble();
    xEnd = ui->spin_x_end->text().toDouble();
    ui->widget->xAxis->setRange(ui->spin_x_begin->text().toDouble(), ui->spin_x_end->text().toDouble());
    ui->widget->yAxis->setRange(ui->spin_y_begin->text().toDouble(), ui->spin_y_end->text().toDouble());
    std::string str = ui->console->text().toStdString();
    int flag = 0;
        auto ko = this->s21_calc_.graph(xBegin, xEnd, str, flag);
        QVector<double> x(ko.first.begin(), ko.first.end());
        QVector<double> y(ko.second.begin(), ko.second.end());
        if (flag) {
            ui->console->setText("ERROR INPUT!");
        }
          ui->widget->addGraph();
          ui->widget->graph(0)->addData(x, y);
          ui->widget->replot();
          x.clear();
          y.clear();
}


void s21_view::on_pushButton_clicked() {
       this->setFixedSize(750, 600);
}



