#include "../model/model.h"

namespace s21 {
    class Controller {
    private:
        s21::Model model_;
    public:
        
        Controller() {;}
        ~Controller() {;}
        int finally(std::string &str, double X, double &resultOutput);
        void credit_A(const std::string sum, const std::string time , const std::string stavka, double &output_x, double &output_pereplata);
        void credit_D(double sum, int time , double stavka,  double *output_p1, double *output_pereplata);
        std::pair<std::vector<double>, std::vector<double>> graph(const double min_x, const double max_x, std::string &output, int &flag);
        void  credit_ann(double sum_credit, int time , double rate,
                         double &overpayment, double &total_payment, int years_months);
        void credit_diff(double sum_credit, int time , int monht, double rate,
                          double &overpayment, double &total_payment);
        void testing(std::string &number_one, std::string &number_two) {
            std::string res;
            res = number_one + "/" + number_two;
            double i = 2.2;
            int k = 5;
            res = std::to_string(k) + "/" +std::to_string(2);
            std::cout << res << std::endl;
        }
    };  // Controller


}  //  namespace s21 
