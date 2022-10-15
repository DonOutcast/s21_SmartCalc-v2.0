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

    int Model::check_pow(const char *pow) {
        int result = this->some_items_["NO"];
        if (*pow == this->lexems_["POW"] && this->check_numbers(pow - 1) && this->check_numbers(pow + 1)) {
            result = this->some_items_["OK"];
        } else if (*pow == this->lexems_["POW"] && *(pow - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(pow + 1)) {
            result = this->some_items_["OK"];
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
        int result = this->some_items_["OK"];
        if (std::strncmp(mod, "mod", 3)) {
            result = this->some_items_["NO"];
        }
        return result;
    }

    int Model::check_mult(const char *mult) {
        int result = this->some_items_["NO"];
        if(*mult == this->lexems_["LEXEM_MULT"] && (this->check_x(mult  - 1) || this->check_numbers(mult - 1)) && this->check_after_lexem(mult + 1)) {
            result = this->some_items_["OK"];
        } else if (*mult == this->lexems_["LEXEM_MULT"] && *(mult - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(mult + 1)) {
            result = this->some_items_["OK"];
        }
        return result;
    }
    
    int Model::check_div(const char *div) {
        int result = this->some_items_["NO"];
        if (*div == this->lexems_["LEXEM_DIV"] && (this->check_numbers(div - 1) || this->check_x(div - 1)) && this->check_after_lexem(div + 1)) {
            result = this->some_items_["OK"];
        } else if (*div == this->lexems_["LEXEM_DIV"] && *(div - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(div + 1)) {
            result = this->some_items_["OK"];
        }
            return result;
    }

    int Model::check_plus(const char *plus) {
        int result = this->some_items_["NO"];
        if (*plus ==  this->lexems_["LEXEM_PLUS"] && (this->check_numbers(plus - 1) || this->check_x(plus - 1)) && this->check_after_lexem(plus + 1)) {
            result = this->some_items_["OK"];
        } else if (*plus == this->lexems_["LEXEM_PLUS"] && *(plus - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(plus + 1)) {
            result = this->some_items_["OK"];
        } else if (plus[0] == this->lexems_["LEXEM_PLUS"] && this->check_after_lexem(plus + 1)) {
            result = this->some_items_["OK"];
        } 
        return result;
    }

    int Model::check_minus(const char *minus) {
        int result = this->some_items_["NO"];
        if (*minus ==  this->lexems_["LEXEM_MINUS"] && (this->check_numbers(minus - 1) || this->check_x(minus - 1)) && this->check_after_lexem(minus + 1)) {
            result = this->some_items_["OK"];
        } else if (*minus == this->lexems_["LEXEM_MINUS"] && *(minus - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(minus + 1)) {
            result = this->some_items_["OK"];
        } else if (minus[0] == this->lexems_["LEXEM_MINUS"] && this->check_after_lexem(minus + 1)) {
            result = this->some_items_["OK"];
        } 
        return result;
    }

    int Model::check_brace(const str &brace) {
        int result = this->some_items_["OK"];
        int open_brace = 0;
        int close_brace = 0;
        for (int i = 0; i < brace.length(); ++i) {
            if (brace[i] == this->lexems_["OPEN_BRACE"]) {
                open_brace += 1;
                if (brace[i + 1] == this->lexems_["CLOSE_BRACE"]) {
                    result = this->some_items_["NO"];
                }
            }
            if (brace[i] == this->lexems_["CLOSE_BRACE"]) {
                close_brace += 1;
                if (close_brace > open_brace) {
                    result = this->some_items_["NO"];
                }
            }
        }
        if (open_brace != close_brace) {
            result = this->some_items_["NO"];
        }
        return result;
    }
    int Model::check_input_X(const str &x) {
    int result = -1;
    for (int i = 0; i < x.length(); i++) {
        if (this->check_numbers(&x[i])) {
            result = this->some_items_["OK"];
        } else if ((x[i] == this->lexems_["LEXEM_PLUS"]) && i == 0) {
            result = this->some_items_["OK"];
        } else if ((x[i] == this->lexems_["LEXEM_MINUS"]) && i == 0) {
            result = this->some_items_["OK"];
        } else if (x[i] == this->lexems_["POINT"] && this->check_numbers(&x[i - 1])) {
            result = this->some_items_["OK"];
        } else {
            break;
        }
    } 
        return result;
    }

    int Model::finaly(str &input, double X, double &resultOutput) {
        int exit = 0;
        size_t size = input.length();
        str 
        return exit;
    }
  
    

}  // namespace s21

int main(void) {
    s21::Model a;
    std::string j("(-2*3");
    std::cout << a.check_brace(j) << std::endl;
    /* for (int i = 0; i < j.length(); ++i) { */
    /*     std::cout << a.check_minus(&j[i]) << std::endl; */
    /* } */

    return 0; 
}
