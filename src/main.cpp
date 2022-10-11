#include "consoleView.h"
// #include <iostream>

int main(void) {
    ExampleModel model;
    ExampleController controller(&model);
    ConsoleView view(&controller);
    view.startEventLoop();
    return 0;
}