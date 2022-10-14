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
        if (this->check_after_lexem(x + 1)) {
            result = this->some_items_["NO"];
        }
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
    
    int Model::check_tan(const char *tan) {
        int result = this->some_items_["OK"];
        if (std::strncmp(tan, "tan(", 4)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_asin(const char *asin) {
        int result = this->some_items_["OK"];
        if (std::strncmp(asin, "asin(", 5)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_acos(const char *acos) {
        int result = this->some_items_["OK"];
        if (std::strncmp(acos, "acos(", 5)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_atan(const char *atan) {
        int result = this->some_items_["OK"];
        if (std::strncmp(atan, "atan(", 5)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_ln(const char *ln) {
        int result = this->some_items_["OK"];
        if (std::strncmp(ln, "ln(", 3)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_log(const char *log) {
        int result = this->some_items_["OK"];
        if (std::strncmp(log, "log(", 3)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_sqrt(const char *sqrt) {
        int result = this->some_items_["OK"];
        if (std::strncmp(sqrt, "sqrt(", 5)) {
            result = this->some_items_["NO"];
        }
        return result;
    }
    
    int Model::check_after_lexem(const char *after_lexem) {
        int result = this->some_items_["NO"];
        if (*(after_lexem) == this->lexems_["OPEN_BRACE"]) {
            result = this->some_items_["OK"];
        } else if (this->check_numbers(after_lexem) == this->some_items_["OK"]) {
            result = this->some_items_["OK"];
        } else if (this->check_x(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_cos(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_sin(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_tan(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_asin(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_acos(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_atan(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_ln(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_log(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_sqrt(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (*after_lexem == this->lexems_["OPEN_BRACE"]) {
            result = this->some_items_["OK"];
        }

        return result;
    }

    int Model::check_after_lexem_numbers(const char *after_lexem) {
        int result = this->some_items_["NO"];
        if (*(after_lexem) == this->lexems_["OPEN_BRACE"]) {
            result = this->some_items_["OK"];
        } else if (this->check_numbers(after_lexem) == this->some_items_["OK"]) {
            result = this->some_items_["OK"];
        } else if (this->check_x(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_cos(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_sin(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_tan(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_asin(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_acos(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_atan(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_ln(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_log(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (this->check_sqrt(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (*after_lexem == this->lexems_["OPEN_BRACE"]) {
            result = this->some_items_["OK"];
        }

        return  result;
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
        int result = this->some_items_["OK"];
        if (std::strncmp(mod, "mod", 3)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

  
    

}  // namespace s21

int main(void) {
    s21::Model a;
    std::string j("2mod3");
    for (int i = 0; i < j.length(); ++i) {
        std::cout << a.check_mod(&j[i]) << std::endl;
    }

    return 0; 
}
