#include "controller.h"

int s21::Controller::finally(std::string &str, double X, double &resultOutput) {
    std::cout << "Hello man" << X << std::endl;
    return this->model_.finally(str, X, resultOutput);
}


 /* int main(void) { */
 /*     s21::Controller a; */
 /*     double res = 0; */
 /*     double x = 12; */
 /*     std::string s("2+x"); */
 /*     a.finally(s, x, res); */
     /* std::cout << res << std::endl; */
     /* return 0; */
 /* } */

