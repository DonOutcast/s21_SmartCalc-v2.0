#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/model.h"
namespace s21 {
    class Controller {
    private:
        s21::Model model_;
    public:
        
        Controller() {;}
        ~Controller() {;}
        int finally(std::string &str, double X, double &resultOutput);
        std::pair<std::vector<double>, std::vector<double>> graph(const double min_x, const double max_x, std::string &output, int &flag);
        void  credit_ann(double sum_credit, int time , double rate,
                         double &overpayment, double &total_payment, int years_months);
        void credit_diff(double sum_credit, int time , int monht, double rate,
                          double &overpayment, double &total_payment);
        void deposit(double sum, int time, double procent_rate,
                     double nalog_rate, int choise_plus, double plus,
                     int choise_minus, double minus, int choise_payments,
                     int perio_payments, int choise_kap, double &sumnalend,
                     double &procentEnd, double &depositEnd, int month);
    };  // Controller


}  //  namespace s21 

#endif // CONTROLLER_H
