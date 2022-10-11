#include "../model/model.h"

namespace s21 {
    class Controller {
    private:
        s21::Model *model_;
    public:
        Controller() {;}
        ~Controller() {;}
        void say();
    };  // Controller


}  //  namespace s21 
