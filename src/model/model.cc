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
    
    int Model::validation_string(const str &string){
        int result = 0;
        for (int i = 0; i < string.length(); ++i) {
            if (this->check_numbers(&string[i]) && (this->check_after_lexem_numbers(&string[i + 1]) == 0)) {
            } else if (this->check_mod(&string[i])) {
                i += 2;
            } else if (this->check_sin(&string[i])) {
                i += 3;
            } else if (this->check_cos(&string[i])) {
                i += 3;
            } else if (this->check_tan(&string[i])) {
                i += 3;
            } else if (this->check_asin(&string[i])) {
                i += 4;
            } else if (this->check_acos(&string[i])) {
                i += 4;
            } else if (this->check_atan(&string[i])) {
                i += 4;
            } else if (this->check_sqrt(&string[i])) {
                i += 4;
            } else if (this->check_ln(&string[i])) {
                i += 2;
            } else if (this->check_log(&string[i])) {
                i += 3;
            } else if (this->check_x(&string[i])) {
            } else if (this->check_plus(&string[i])) {
            } else if (this->check_minus(&string[i])) {
            } else if (this->check_div(&string[i])) {
            } else if (this->check_mult(&string[i])) {
            } else if (this->check_pow(&string[i])) {
            } else if (this->check_point(&string[i])) {
            } else if (string[i] == this->lexems_["CLOSE_BRACE"] || this->lexems_["OPEN_BRACE"]) {
            } else {
                result = 1;
                break;
            }
        }
        return result;
    }

    int Model::finally(str &input, double X, double &resultOutput) {
        int exit = 0;
        exit = this->check_size_string(input);
        if(exit != -2) {
            exit = this->check_input_X(std::to_string(X)); 
            if (exit) {
                this->remove_space(input);
                exit = this->check_brace(input);
                if(exit) {
                   exit = this->validation_string(input);
                } else {
                    exit = 2;
                }
            }
        }
        return exit;
    }
    
    int Model::check_size_string(const str& string) {
        int result = 0;
        if (string.length() == 0 || string.length() > 255) {
            result = -2;
        }
        return result;
    }


    void Model::parsing_to_struct(const str &string, std::list<ListNode> node_)  {
        str number;
        const char first_symbol = string[0];
        std::cout << string << std::endl;
        for (int i = 0; i < string.length(); ++i) {
            if (this->check_numbers(&string[i]) || this->check_point(&string[i])) {
                number.push_back(string[i]);
                if ((string[i + 1] < '0' || string[i + 1] > '9' ) && !this->check_point(&string[i + 1])) {
                    node_.push_back(ListNode(std::stof(number), 0, this->type_t_["s21_number"]));
                    number.clear();
                }

            } else if (this->check_x(&string[i])) {
                node_.push_back(ListNode(0, 0, this->type_t_["s21_x"]));
            } else if (string[i] == this->lexems_["OPEN_BRACE"]) {
                node_.push_back(ListNode(0, 0, this->type_t_["s21_open_brace"]));
            } else if (string[i] == this->lexems_["CLOSE_BRACE"]) {
                node_.push_back(ListNode(0, 0, this->type_t_["s21_close_brace"]));
            } else if (string[i] == this->lexems_["LEXEM_PLUS"]) {
                if ((string[i] == first_symbol) || string[i - 1] == this->lexems_["CLOSE_BRACE"]) {
                    node_.push_back(ListNode(0, 1, this->type_t_["s21_un_plus"]));
                } else {
                      node_.push_back(ListNode(0, 1, this->type_t_["s21_plus"]));
                }
                    
            } else if (string[i] == this->lexems_["LEXEM_MINUS"]) {
                if (string[i] == first_symbol || string[i] == this->lexems_["CLOSE_BRACE"]) {
                    node_.push_back(ListNode(0, 1,  this->type_t_["s21_un_minus"]));
                } else  {
                    node_.push_back(ListNode(0, 1, this->type_t_["s21_minus"]));
                }
            } else if (string[i] == this->lexems_["LEXEM_MULT"]) {
                node_.push_back(ListNode(0, 2, this->type_t_["s21_mult"]));
            } else if (string[i] == this->lexems_["LEXEM_DIV"]) {
                node_.push_back(ListNode(0, 2, this->type_t_["s21_div"]));
            } else if (this->check_mod(&string[i])) {
                node_.push_back(ListNode(0, 2, this->type_t_["s21_mod"]));
            } else if (string[i] == this->lexems_["POW"]) {
                node_.push_back(ListNode(0, 3, this->type_t_["s21_pow"]));
            } else if (this->check_sin(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_sin"]));
                i +=2;
            }  else if (this->check_cos(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_cos"]));
                i +=2;
            } else if (this->check_tan(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_tan"]));
                i += 2;
            } else if (this->check_asin(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_asin"]));
                i += 3;
            } else if (this->check_acos(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_acos"]));
                i += 3;
            } else if (this->check_atan(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_atan"]));
                i +=3 ;
            } else if (this->check_ln(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_ln"]));
                i += 1;
            } else if (this->check_log(&string[i])) {
                node_.push_back(ListNode(0, 4, this->type_t_["s21_log"]));
                i += 2;
            }
        }
    }
    
    void Model::pols_notation(std::list<ListNode> &list_lexems) {}
    
    int Model::check_support(std::list<ListNode> &support_lexems, int priority) {
        int result = 0;
        std::list<ListNode>::iterator iter = support_lexems.begin();
        if ((*iter).get_type()) {
            if (priority > (*iter).get_priority()) {
                result = 1;
            }
        } else {
            result = 1;
        }
        return result;
    }
}  // namespace s21

int main(void) {
    s21::Model a;
    std::string j("2+2");
    double b = 0;
    std::list<s21::Model::ListNode> testing;
    a.parsing_to_struct(j, testing);
    for(auto i : testing)
        std::cout << (i).get_value() << std::endl;
    
    std::cout << a.finally(j, 2.2, b) << std::endl;
    /* for (int i = 0; i < j.length(); ++i) { */
    /*     if (!a.check_point(&j[i])) */
            /* std::cout << "You" << std::endl; */
        /* std::cout << a.check_point(&j[i]) << std::endl; */
    /* } */

    return 0; 
}
