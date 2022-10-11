#include "controller.h"

void s21::Controller::say() {
    model_->say_hello();
}


int main(void) {
    s21::Controller a;
    a.say();
}

