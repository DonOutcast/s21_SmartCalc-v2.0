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
        if ((*numbers) >= '0' && (*numbers) <= '9') {
            result = this->some_items_["OK"];
        }
        return result;
    }

    int Model::check_x(const char *x) {
        int result = this->some_items_["NO"];
        if (*x == 'x' || *x == 'X') {
            result = this->some_items_["OK"];
            if (*(x - 1) == this->lexems_["POINT"] || *(x - 1) == this->lexems_["CLOSE_BRACE"] ||
                    (*(x - 1) >= '0' && *(x - 1) <= '9')) {
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
        if (*(after_lexem) == '(') {
            result = this->some_items_["OK"];
        } else if (this->check_numbers(after_lexem)) {
            result = this->some_items_["OK"];
        } else if (*after_lexem == 'x'  || *after_lexem == 'X') {
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
//        } else if (*after_lexem == this->lexems_["OPEN_BRACE"]) {
//            std::cout << "I am in 12" << std::endl;
//            result = this->some_items_["OK"];
        } else {
            result = 0;
        }
        return result;
    }

    int Model::check_after_lexem_numbers(const char *after_lexem) {
        int result = this->some_items_["NO"];
        if (*(after_lexem) == this->lexems_["OPEN_BRACE"]) {
            result = this->some_items_["OK"];
        }
//        else if (this->check_numbers(after_lexem)) {
//            result = this->some_items_["OK"];
//        }
        else if (this->check_x(after_lexem)) {
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
//        } else if (*after_lexem == this->lexems_["OPEN_BRACE"]) {
//            result = this->some_items_["OK"];
        } else {
            result = 0;
        }

        return  result;
    }

    int Model::check_pow(const char *pow) {
        int result = this->some_items_["NO"];
        if (*pow == this->lexems_["POW"] && this->check_numbers(pow - 1) && this->check_numbers(pow + 1)) {
            result = this->some_items_["OK"];
        } else if (*pow == this->lexems_["POW"] && (*(pow - 1) == this->lexems_["CLOSE_BRACE"]  || this->check_numbers(pow - 1)) && this->check_after_lexem(pow + 1)) {
            result = this->some_items_["OK"];
        } else if (*pow == this->lexems_["POW"] && *(pow + 1) == this->lexems_["OPEN_BRACE"]) {
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
        } else if (*minus == this->lexems_["LEXEM_MINUS"] && *(minus - 1) == '(' && *(minus + 1) == ')') {
            result = this->some_items_["OK"];
        }
        return result;
    }

    int Model::check_brace(const str &brace) {
        int result = this->some_items_["OK"];
        int open_brace = 0;
        int close_brace = 0;
        for (size_t i = 0; i < brace.length(); ++i) {
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
        if (!result) {
            result = 2;
        }
        return result;
    }
    int Model::check_input_X(const str &x) {
    int result = -1;
    for (size_t i = 0; i < x.length(); i++) {
        if (this->check_numbers(&x[i])) {
            result = this->some_items_["OK"];
        } else if ((x[i] == this->lexems_["LEXEM_PLUS"]) && i == 0) {
            result = this->some_items_["OK"];
        } else if ((x[i] == this->lexems_["LEXEM_MINUS"]) && i == 0) {
            result = this->some_items_["OK"];
        } else if (x[i] == this->lexems_["POINT"] && this->check_numbers(&x[i - 1])) {
            result = this->some_items_["OK"];
        } else {
            result = -1;
            break;
        }
    } 
        return result;
    }
    
    int Model::validation_string(const str &string){
        int result = 0;
        for (size_t i = 0; i < string.length(); ++i) {
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
            } else if (string[i] == '('|| string[i] == ')') {
            } else {
                result = 1;
                return 1;
            }

        }
        return result;
    }

    int Model::finally(str &input, double X, double &resultOutput) {
        int exit = 0;
        resultOutput = 0;
        replace_symbol(input, "e+", "*10^");
        replace_symbol(input, "e-", "/10^");
        exit = this->check_size_string(input);
        if(exit != -2) {
            exit = this->check_input_X(std::to_string(X));
            if (exit) {
                this->remove_space(input);
                exit = this->check_brace(input);
                if(exit != 2) {
                   exit = this->validation_string(input);
                }
            }
        }
        if (!exit) {
            std::list<ListNode> list_lexems;
            this->parsing_to_struct(input, list_lexems);
            std::list<ListNode> test(this->pols_notation(list_lexems));
            this->swap_x_n_number(test, X);
            resultOutput = this->masud(test);
        }
        return exit;
    }
    
    int Model::check_size_string(const str& string) {
        int result = 0;
        if (string.length() == 0 || string.length() > 255 ) {
            result = -2;
        }
        return result;
    }


    void Model::parsing_to_struct(const str &string, std::list<ListNode> &node_)  {
        str number;
        const char first_symbol = string[0];
        for (size_t i = 0; i < string.length(); ++i) {
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
                if ((string[i] == first_symbol) || string[i - 1] == this->lexems_["OPEN_BRACE"]) {
                    node_.push_back(ListNode(0, 1, this->type_t_["s21_un_plus"]));
                } else {
                      node_.push_back(ListNode(0, 1, this->type_t_["s21_plus"]));
                }
                    
            } else if (string[i] == this->lexems_["LEXEM_MINUS"]) {
                if (string[i] == first_symbol || string[i - 1] == this->lexems_["OPEN_BRACE"]) {
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
    
    std::list<typename Model::ListNode> Model::pols_notation(std::list<ListNode> &list_lexems) {
        std::list<ListNode> support;
        std::list<ListNode> after_notation;
        std::list<ListNode>::iterator iter_list =  list_lexems.begin();
        while (iter_list != list_lexems.end()) {
            if ((*iter_list).get_type() != this->type_t_["s21_close_brace"]) {
                if ((*iter_list).get_type() == this->type_t_["s21_number"] || (*iter_list).get_type() == this->type_t_["s21_x"]) {
                    after_notation.push_front(*iter_list);
                } else {
                    while (true) {
                        if (this->check_support(support, (*iter_list).get_priority()) || (*iter_list).get_type() == this->type_t_["s21_open_brace"]) {
                            support.push_front(*iter_list);
                            break;
                        } else {
                            after_notation.push_front(support.front());
                                support.pop_front();
                        }
                    }  
                }
            } else {
                while (support.front().get_type() != this->type_t_["s21_open_brace"]) {
                   after_notation.push_front(support.front());
                        support.pop_front();
                }
                support.pop_front();
            }

            iter_list++;
        }
        while (!support.empty()) {
                    after_notation.push_front(support.front());
                    support.pop_front();
        }

        return after_notation;
    }




    int Model::check_support(std::list<ListNode> &support_lexems, int priority) {
        int result = 0;
        if (support_lexems.front().get_type()) {
            if (priority > support_lexems.front().get_priority()) {
                result = 1;
            }
        } else {
            result = 1;
        }
        return result;
    }

    void Model::swap_x_n_number(std::list<ListNode> &after_pols, double &number_x) {
        std::list<ListNode> tmp;
        while (!after_pols.empty()) {
            if ((after_pols.front()).get_type() == this->type_t_["s21_x"]) {
                (after_pols.front()).set_type(this->type_t_["s21_number"]);
                (after_pols.front()).set_value(number_x);
            }
            tmp.push_front(after_pols.front());
            after_pols.pop_front();
        }
        after_pols = tmp;
    }

    void Model::calculate(type_list &after_pols) {
        for (auto i : after_pols) {
        }
        while (!after_pols.empty()) {
            std::list<ListNode>::iterator tmp1 = after_pols.begin();
            std::list<ListNode>::iterator tmp2 = ++tmp1;
            --tmp1;
            std::list<ListNode>::iterator tmp3;
            if (++tmp2 != after_pols.end()) {
              tmp3 = tmp2;
             --tmp2;
            }
            if (((*tmp2).get_type() == this->type_t_["s21_number"])) {
                while ((*tmp3).get_priority() != 0) {
                    tmp1 = tmp2;
                    tmp2 = ++tmp1;
                    --tmp1;
                    tmp3 = ++tmp2;
                    --tmp2;
                }
                if ((*tmp3).get_type() >= 16 && (*tmp3).get_type() <= 21) {
                    this->calculate_lexems(after_pols, tmp1, tmp2, tmp3);
                } else {
                    this->calculate_functions(after_pols, tmp2, tmp3);
                }
            } else {
                this->calculate_functions_2(after_pols, tmp1, tmp2);
            }
        }
    }




  void Model::calculate_lexems(std::list<ListNode> &after_pols, std::list<ListNode>::iterator &tmp1, std::list<ListNode>::iterator &tmp2, std::list<ListNode>::iterator &tmp3) {
  double result = 0;
  double a = (*tmp1).get_value();
  double b = (*tmp2).get_value();
  if ((*tmp3).get_type() == this->type_t_["s21_plus"]) {
    result = a + b;
  } else if ((*tmp3).get_type() == this->type_t_["s21_minus"]) {
    result = a - b;
  } else if ((*tmp3).get_type() == this->type_t_["s21_mult"]) {
    result = a * b;
  } else if ((*tmp3).get_type() == this->type_t_["s21_div"]) {
    result = a / b;
  } else if ((*tmp3).get_type() == this->type_t_["s21_pow"]) {
    result = pow(a, b);
  } else if ((*tmp3).get_type() == this->type_t_["s21_mod"]) {
    result = fmod(a, b);
  }
  (*tmp1).set_priority(0);
  (*tmp1).set_type(this->type_t_["s21_number"]);
  (*tmp1).set_value(result);
  after_pols.erase(tmp3);
  after_pols.erase(tmp2);
}

  void Model::calculate_functions(type_list &after_pols, std::list<ListNode>::iterator &tmp2, std::list<ListNode>::iterator &tmp3) {
  double a = (*tmp2).get_value();
  double result = 0;
  if ((*tmp3).get_type() == this->type_t_["21_un_plus"]) {
    result = +a;
  } else if ((*tmp3).get_type() == this->type_t_["s21_un_minus"]) {
    result = -a;
  } else if ((*tmp3).get_type() == this->type_t_["s21_sin"]) {
    result = sin(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_cos"]) {
    result = cos(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_tan"]) {
    result = tan(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_asin"]) {
    result = asin(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_acos"]) {
    result = acos(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_atan"]) {
    result = atan(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_ln"]) {
    result = log(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_log"]) {
    result = log10(a);
  } else if ((*tmp3).get_type() == this->type_t_["s21_sqrt"]) {
    result = sqrt(a);
  }
  (*tmp2).set_priority(0);
  (*tmp2).set_type(this->type_t_["s21_number"]);
  (*tmp2).set_value(result);
  after_pols.erase(tmp3);
}


  void Model::calculate_functions_2(type_list &after_pols, std::list<ListNode>::iterator &tmp1, std::list<ListNode>::iterator &tmp2) {
  double a = 0;
  double result = (*tmp1).get_value();
  if ((*tmp2).get_type() == this->type_t_["s21_un_plus"]) {
    result = +a;
  } else if ((*tmp2).get_type() == this->type_t_["s21_un_minus"]) {
    result = -a;
  } else if ((*tmp2).get_type() == this->type_t_["s21_sin"]) {
    result = sin(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_cos"]) {
    result = cos(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_tan"]) {
    result = tan(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_asin"]) {
    result = asin(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_acos"]) {
    result = acos(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_atan"]) {
    result = atan(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_ln"]) {
    result = log(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_log"]) {
    result = log10(a);
  } else if ((*tmp2).get_type() == this->type_t_["s21_sqrt"]) {
    result = sqrt(a);
  }
  (*tmp1).set_priority(0);
  (*tmp1).set_type(this->type_t_["s21_number"]);
  (*tmp1).set_value(result);
  after_pols.erase(tmp2);
}

double Model::masud(type_list &after_pols) {
//    after_pols.reverse();
    std::list<double> tmp;
    for (auto &i : after_pols) {
        if (i.get_type() == this->type_t_["s21_number"]) {
            tmp.push_back(i.get_value());
        } else if (i.get_type() == this->type_t_["s21_plus"]) {
            this->plus(tmp);
        } else if (i.get_type() == this->type_t_["s21_minus"]) {
            this->minus(tmp);
        } else if (i.get_type() == this->type_t_["s21_mult"]) {
            this->mult(tmp); 
        } else if (i.get_type() == this->type_t_["s21_div"]) {
            this->div(tmp);
        } else if (i.get_type() == this->type_t_["s21_un_minus"]) {
            this->un_minus(tmp);
        } else if (i.get_type() == this->type_t_["s21_un_plus"]) {
            this->un_plus(tmp);
        } else if (i.get_type() == this->type_t_["s21_mod"]) {
            this->s21_mod(tmp);
        } else if (i.get_type() == this->type_t_["s21_pow"]) {
            this->s21_pow(tmp);
        } else if (i.get_type() == this->type_t_["s21_sin"]) {
            this->s21_sin(tmp);
        } else if (i.get_type() == this->type_t_["s21_cos"]) {
            this->s21_cos(tmp);
        } else if (i.get_type() == this->type_t_["s21_tan"]) {
            this->s21_tan(tmp);
        } else if (i.get_type() == this->type_t_["s21_asin"]) {
            this->s21_asin(tmp);
        } else if (i.get_type() == this->type_t_["s21_acos"]) {
            this->s21_acos(tmp);
        } else if (i.get_type() == this->type_t_["s21_atan"]) {
            this->s21_atan(tmp);
        } else if (i.get_type() == this->type_t_["s21_ln"]) {
            this->s21_ln(tmp);
        } else if (i.get_type() == this->type_t_["s21_log"]) {
            this->s21_log(tmp);
        } else if (i.get_type() == this->type_t_["s21_sqrt"]) {
            this->s21_sqrt(tmp);
        }
    }

    return tmp.back();
} 

void Model::un_minus(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = - b;
    tmp.push_back(result);
}

void Model::un_plus(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = +b;
    tmp.push_back(result);

}
void Model::minus(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = tmp.back() - b;
    tmp.pop_back();
    tmp.push_back(result);

}
void Model::plus(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = tmp.back() + b;
    tmp.pop_back();
    tmp.push_back(result);

}
void Model::mult(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = tmp.back() * b;
    tmp.pop_back();
    tmp.push_back(result);

}
void Model::div(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = tmp.back() / b;
    tmp.pop_back();
    tmp.push_back(result);

}

void Model::s21_pow(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = pow(tmp.back(), b);
    tmp.pop_back();
    tmp.push_back(result);

}

void Model::s21_mod(double_list &tmp) {
    double b = tmp.back();
    tmp.pop_back();
    double result = fmod(tmp.back(), b);
    tmp.pop_back();
    tmp.push_back(result);

}

void Model::s21_sin(double_list &tmp) {
    double res = sin(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_cos(double_list &tmp) {
    double res = cos(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_tan(double_list &tmp) {
    double res = tan(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_asin(double_list &tmp) {
    double res = asin(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_acos(double_list &tmp) {
    double res = acos(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_atan(double_list &tmp) {
    double res = atan(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_ln(double_list &tmp) {
    double res = log(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_log(double_list &tmp) {
    double res = log10(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}
void Model::s21_sqrt(double_list &tmp) {
    double res = sqrt(tmp.back());
    tmp.pop_back();
    tmp.push_back(res);
}


typename std::pair<std::vector<double>, std::vector<double>> Model::graph(const double min_x, const double max_x, str &output, int &flag) {
    std::pair<std::vector<double>, std::vector<double>> tmp;
    double N = 0;
    double h = 0.1;
    double X = 0;
    double result = 0;
    int check_input = 0;
    N = (max_x - min_x) / h + 2;
    for (X = min_x; X <= max_x; X += h) {
        tmp.first.push_back(X);
        check_input = this->finally(output, X, result);
        if (check_input) {
            flag = 1;
        }
        tmp.second.push_back(result);
    }
    return tmp;
}

    void  Model::credit_ann(double sum_credit, int time , double rate,
                    double &overpayment, double &total_payment, int years_months) {
        double stavka_monht = 0;
        double month_payment = 0;
        if (years_months)
            stavka_monht = rate / 100 / 12;
        else {
            stavka_monht = rate / 100 / 30;
        }
        double coefficient = stavka_monht * pow((1 + stavka_monht), time) / (pow((1 + stavka_monht), time) - 1);
        month_payment = coefficient * sum_credit;
        total_payment = (month_payment) * time;
        overpayment =total_payment - sum_credit;
    }

    void Model::credit_diff(double sum_credit, int time , int monht, double rate,
                     double &overpayment, double &total_payment) {
        double b = sum_credit / time;
        int days;
        double  month_payment = 0;
        count_days(monht, days);
        month_payment = b + sum_credit * rate / 100 * days/365;
        for (int i = 0; i < time; i++) {
            double p;
            count_days(monht, days);
            p = sum_credit * rate / 100 * days/365;
            sum_credit -= (b);
            overpayment += p;
            if (monht == 12) {
                monht = 0;
            }
            monht++;
        }
        total_payment = (overpayment + b * time);
    }

    void Model::count_days(int month, int &days) {
        if (month == 2) {
            days = 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days = 30;
        } else {
            days = 31;
        }
    }
    void Model::deposit(double sum, int time, double procent_rate,
                             double nalog_rate, int choise_plus, double plus,
                             int choise_minus, double minus, int choise_payments,
                             int perio_payments, int choise_kap, double &sumnalend,
                             double &procentEnd, double &depositEnd, int month) {
        if (month <= 0 || month > 12 || minus < 0 || plus < 0) {
//            throw std::invalid_argument("Incorrect input");
        }
        if (choise_kap) {
            choise_kap = perio_payments + 1;
            if (perio_payments == 3) choise_kap = 0;
        }
        if (perio_payments == 0) perio_payments = time;
        if (perio_payments == 1) {
            perio_payments = time / 30;
        }
        if (perio_payments == 2) {
            perio_payments = time / 90;
        }
        if (perio_payments == 3) {
            choise_payments = 0;
            perio_payments = 0;
        }
        if (choise_plus == 0) ++choise_plus;
        if (choise_minus == 0) ++choise_minus;
        double sumnalog = 0;
        int i = 0, flag = 1;
        int count = 0;
        double sum_kap = sum;
        double obprocent = 0;
        while (i < time) {
            int time_new, div;
            double doxod;
            if (month == 2) {
                div = 28;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                div = 30;
            } else {
                div = 31;
            }
            time_new = time - i;
            if (time_new < div) {
                div = time_new;
            }
            doxod = (((sum * procent_rate * div) / 365) / 100);
            if (choise_payments == 1) {
                double payments = doxod / perio_payments;
                sumnalog = payments * perio_payments * nalog_rate / 100;
            }
            int time_kap = 0;
            double eyear_pro = procent_rate / 100;
            double procent, nal;
            if (choise_kap == 1 && flag == 1) {
                double tmp = 1 + (eyear_pro / 365);
                time_kap = time - i;
                double kapday = sum_kap * pow(tmp, time_kap);
                procent = kapday - sum_kap;
                nal = procent * nalog_rate / 100;
                sumnalend += nal;
                obprocent += procent;
                procentEnd = obprocent - sumnalend;
                depositEnd = procentEnd + sum;
                flag = 0;
            } else if (choise_kap == 2 && flag == 1) {
                double tmp1 = 1 + (eyear_pro / 12);
                time_kap = time - i;
                double time_monht = time_kap / 30.41;
                double kapmonth = sum_kap * pow(tmp1, time_monht);
                procent = kapmonth - sum_kap;
                nal = procent * nalog_rate / 100;
                sumnalend += nal;
                obprocent += procent;
                procentEnd = obprocent - sumnalend;
                depositEnd = procentEnd + sum;
                flag = 0;
            } else if (choise_kap == 3 && flag == 1) {
                double tmp2 = 1 + (eyear_pro / 4);
                time_kap = time - i;
                double time_kvartal = time_kap / 91.;
                double kapkvart = sum_kap * pow(tmp2, time_kvartal);
                procent = kapkvart - sum_kap;
                nal = procent * nalog_rate / 100;
                sumnalend += nal;
                obprocent += procent;
                procentEnd = obprocent - sumnalend;
                depositEnd = procentEnd + sum;
                flag = 0;
            }
            if (choise_payments == 0) sumnalog = doxod * nalog_rate / 100;
            doxod -= sumnalog;
            if (choise_kap == 0) {
                sumnalend += sumnalog;
                procentEnd += doxod;
                if (choise_payments == 0)
                    depositEnd = sum + procentEnd;
                else
                    depositEnd = sum;
            }
            if (month == 12) {
                month = 0;
            }
            month++;
            count++;
            if (choise_plus) {
                if (fmod(count, choise_plus) == 0) {
                    sum += plus;
                    flag = 1;
                    sum_kap = plus;
                }
            }
            if (choise_minus) {
                if (fmod(count, choise_minus) == 0) {
                    sum -= minus;
                    flag = 1;
                    sum_kap = -minus;
                }
            }
            if (choise_plus && choise_minus) {
                if (fmod(count, choise_plus) == 0 && fmod(count, choise_minus) == 0) {
                    flag = 1;
                    sum_kap = plus - minus;
                }
            }
            i += div;
        }
        if (procentEnd <= 0 || depositEnd <= 0 || std::isnan(procentEnd) ||
            std::isnan(depositEnd)) {
//            throw std::invalid_argument("Incorrect input");
        }
    }
    
void Model::replace_symbol(str &input,const str sym_off,const str sym_on) {
    size_t position = 0;
    while ((position = input.find(sym_off)) != input.npos) {
        input.replace(position, sym_off.size(), sym_on);
    } 
}



}  // namespace s21
