#include "controller.h"

int s21::Controller::finally(std::string &str, double X, double &resultOutput) {
    return this->model_.finally(str, X, resultOutput);
}


// int main(void) {
//     s21::Controller a;
//     double res = 0;
//     std::string s("+++");
//     a.finally(s, 0, res);
//     std::cout << res << std::endl;
//     return 0;
// }

