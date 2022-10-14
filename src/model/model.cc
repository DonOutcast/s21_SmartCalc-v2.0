#include "model.h"
#include <algorithm>
namespace s21 {
    void Model::remove_space(str &string) {
       string.erase(remove_if(string.begin(), string.end(), isspace), string.end());
    }
    int Model::check_point(const char *point) {
        int result = this->some_items_["NO"]; 
        if (*point == this->lexems_["POINT"] && (this->check_numbers(point - 1) == 1) && this->check_numbers(point + 1) == 1) {
            result = this->some_items_["OK"];
        }
        return result;
    }
    int Model::check_numbers(const char *numbers) {
        int result = this->some_items_["NO"];
        if (*numbers >= '0' && *numbers <= '9') {
            result = this->some_items_["OK"];
        }
        return result;
    }

    int Model::check_x(const char *x) {
        int result = this->some_items_["NO"];
        if (*x == 'x' || *x == 'X') {
            result = this->some_items_["OK"];
            if (*(x - 1) == this->lexems_["POINT"] || *(x - 1) == this->lexems_["OPEN_BRACE"] ||
                    *(x - 1) >= '0' && *(x - 1) <= '9') {
                result = this->some_items_["NO"];
            }
        }
        /* if (this->check_after_lexem(x + 1)) { */
        /*     result = this->some_items_["NO"]; */
        /* } */
        return result;
    }

    int Model::check_sin(const char *sin) {
        int result = this->some_items_["OK"];
        if (std::strncmp(sin, "sin(", 4)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_cos(const char *cos) {
        int result = this->some_items_["OK"];
        if (std::strncmp(cos, "cos(", 4)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_mod(const char *mod) {
        int result = this->some_items_["NO"];
        if (this->check_name_mod(mod) && (this->check_numbers(mod - 1) && this->check_numbers(mod +3))) {
            result = this->some_items_["OK"];
        } else if (this->check_name_mod(mod) && *(mod + 3) == '(' && *(mod - 1) == ')') {
            result = this->some_items_["OK"];
        }
        return result;
    }

    int Model::check_name_mod(const char * mod) {
        int result = this->some_items_["NO"];
        if ((*mod) == 'm' && *(mod + 1) == 'o' && *(mod + 2) == 'd') {
            result = this->some_items_["OK"];
        }
        return result;
    }

  
    

}  // namespace s21

int main(void) {
    s21::Model a;
    std::string j("sin(1)");
    for (int i = 0; i < j.length(); ++i) {
        std::cout << a.check_sin(&j[i]) << std::endl;
    }

    return 0; 
}
