#include "s21_view.h"
#include "ui_s21_view.h"
#include <QDebug>
s21_view::s21_view(QWidget *parent): QMainWindow(parent), ui(new Ui::s21_view) {

    ui->setupUi(this);
   this->setFixedSize(750, 600);
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
    connect(ui->check_x, &QCheckBox::stateChanged, this, &s21_view::autoBtnClickHandler);
    connect(ui->check_y, &QCheckBox::stateChanged, this, &s21_view::autoBtnClickHandler);
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
    double x_value = ui->console_x->text().toDouble();
    qDebug() << x_value;
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
    bool is_graph_builded = false;
    double h = 0.1;
            ui->widget->clearGraphs();
            double  xBegin = 0;
            double xEnd = 0;
            double yBegin = 0;
            double yEnd = 0;
            double N = 0;
            xBegin = ui->spin_x_begin->text().toDouble();
            xEnd = ui->spin_x_end->text().toDouble();
            yBegin = ui->spin_y_begin->text().toDouble();
            yEnd = ui->spin_y_end->text().toDouble();
            ui->widget->xAxis->setRange(ui->spin_x_begin->text().toDouble(), ui->spin_x_end->text().toDouble());
            ui->widget->yAxis->setRange(ui->spin_y_begin->text().toDouble(), ui->spin_y_end->text().toDouble());
            std::string str = ui->console->text().toStdString();
            int check_input = 0;
            double x_value = ui->console_x->text().toDouble();
            double result = 0;
            double X = 0;
               N = (xEnd - xBegin)/h + 2;

               for(X = xBegin; X <= xEnd;X += h) {
                   x.push_back(X);
                   s21_calc_.finally(str, X, result);
                   y.push_back(result);
               }

                  ui->widget->addGraph();
                  ui->widget->graph(0)->addData(x, y);
                  ui->widget->replot();
                  x.clear();
                  y.clear();


//            x = x_min_begin;
//            x_vec_begin.clear();
//            y_vec_begin.clear();
//            x_vec_end.clear();
//            y_vec_end.clear();
//            int flag_x = 0;
//            std::string tmp = ui->console->text().toStdString();
//            const char *str = tmp.c_str();
//            for (size_t i = 0; i < strlen(str); i++) {
//                   if (str [i] == 'x') flag_x = 1;
//               }
//            if (flag_x) {
//                std::string tmp = ui->console->text().toStdString();
////                const char *str = tmp.c_str();

//                x_min = ui->lineEdit_x_min->text().toDouble();
//                x_max = ui->lineEdit_x_max->text().toDouble();

//                if (x_min == 0.0) x_min = -10;
//                if (x_max == 0.0) x_max = 10;

//                step = 0.1;
//                points = (fabs(x_min) + fabs(x_max)) / 0.1 + 2;
//                ui->widget_graph->xAxis->setRange(x_min, x_max);
//                ui->widget_graph->yAxis->setRange(-5, 5);

//                double result = 0.0;
//                int f = 1;
//                for (x = x_min; x <= x_max && f == 1; x += step) {
//                    if (!general_syntax_test(str)) {
//                        this->setFixedSize(1140,410);
//                        unar_sign((char *) str);
//                        parser_and_RPN((char *)str, &result, x);
//                        f = 1;
//                        x_vec.push_back(x);
//                        y_vec.push_back(result);
//                    } else {
//                        f = 0;
//                        ui->result_show->setText("Syntax error!");
//                        break;
//                    }
//                }
//                if (f == 1) {
//                    QPen pen;
//                    pen.setWidth(pen.width() + 1);
//    //                pen.setColor(QColor(255, 129, 0));
//                    pen.setColor(QColor(255, 0, 0));

//                    ui->widget_graph->addGraph()->setPen(pen);
//                    ui->widget_graph->graph(0)->addData(x_vec, y_vec);
//                    ui->widget_graph->replot();
//                }
//            }
//    }

}

