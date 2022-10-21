#include "../model/model.h"

namespace s21 {
    class Controller {
    private:
        s21::Model model_;
    public:
        
        Controller() {;}
        ~Controller() {;}
        int finally(std::string &str, double X, double &resultOutput);
    };  // Controller


}  //  namespace s21 
