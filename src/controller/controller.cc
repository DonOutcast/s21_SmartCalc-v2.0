#include "controller.h"

int s21::Controller::finally(std::string &str, double X, double &resultOutput) {
    std::cout << "Hello man" << X << std::endl;
    return this->model_.finally(str, X, resultOutput);
}

void s21::Controller::credit_A(const std::string sum, const std::string time , const std::string stavka, double &output_x, double &output_pereplata) {
    this->model_.credit_A(sum, time, stavka, output_x, output_pereplata);
}

void s21::Controller::credit_D(double sum, int time , double stavka,  double *output_p1, double *output_pereplata) {
    this->model_.credit_D(sum, time, stavka, output_p1, output_pereplata);
}

//
//  int main(void) {
//      s21::Controller a;
//      std::string i("100");
//      std::string j("20");
//      std::string time("10");
//      double k;
//      double l;
//      a.credit_A(i,j,time,k,l );
//      std::cout << "CREDIT " << k << std::endl;
//      std::cout << "Credit : " << l << std::endl;
//      double res = 0;
//      double x = 12;
//      std::string s("");
//      int i  = 0;
//      i  =a.finally(s, x, res);
//      std::cout << "IN main: " << i  << std::endl;
//      std::cout << "This is a finally result: " << res << std::endl;
//      return 0;
// }

