#include "controller.h"

int s21::Controller::finally(std::string &str, double X, double &resultOutput) {
    return this->model_.finally(str, X, resultOutput);
}

typename  std::pair<std::vector<double>, std::vector<double>> s21::Controller::graph(const double min_x, const double max_x, std::string &output, int &flag) {
    return  this->model_.graph(min_x, max_x , output, flag);
}
void s21::Controller::credit_ann(double sum_credit, int time , double rate,
                                               double &overpayment, double &total_payment, int years_months) {
    return this->model_.credit_ann(sum_credit,time, rate,  overpayment, total_payment, years_months);
}
void s21::Controller::credit_diff(double sum_credit, int time , int monht, double rate,
                  double &overpayment, double &total_payment) {
    return this->model_.credit_diff(sum_credit, time, monht, rate,  overpayment, total_payment);
}

void s21::Controller::deposit(double sum, int time, double procent_rate, double nalog_rate, int choise_plus,
             double plus, int choise_minus, double minus, int choise_payments,
             int perio_payments, int choise_kap,
             double &sumnalend,  double &procentEnd, double &depositEnd, int month) {
    return this->model_.deposit(sum, time, procent_rate, nalog_rate, choise_plus, plus,choise_minus, minus, choise_payments,  perio_payments,choise_kap, sumnalend, procentEnd, depositEnd, month);
}
