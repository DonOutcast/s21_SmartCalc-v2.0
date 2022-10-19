#include "controller.h"

void s21::Controller::finally(std::string &str, double X, double &resultOutput) {
    std::cout << resultOutput << std::endl;
    this->model_.finally(str, X, resultOutput);
    std::cout << resultOutput << std::endl;
}


int main(void) {
    s21::Controller a;
    double res = 0;
    std::string s("25+(5*2-10+sin(3) /2 * 3)");
    a.finally(s, 0, res);
    std::cout << res << std::endl;
    return 0;
}

