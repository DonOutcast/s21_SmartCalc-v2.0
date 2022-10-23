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
        } else if (*pow == this->lexems_["POW"] && *(pow - 1) == this->lexems_["CLOSE_BRACE"] && this->check_after_lexem(pow + 1)) {
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

void Model::credit_A(const str sum, const str time , const str stavka, double &output_x, double &output_pereplata) {
        std::string p_test;
        p_test = stavka + "/" + "100" + "/" + time;
        double p = 0;
        this->finally(p_test, 0,p);
        double x = 0;
        std::string x_test;
        x_test = sum + "*" + "(" + std::to_string(p) + "+("+ std::to_string(p) + "/" + "(((" + std::to_string(p) +"+"+ "1)^" + time + ")-1)))";
        this->finally(x_test, 0, x);
//    double p = stavka / 100 / time;
//    double x = sum * (p + (p / (pow(p + 1, time) - 1)));
    output_x = x;
    double pereplata ;
    std::string per_test;
    per_test = std::to_string(x) + "*" + time + "-" + sum;
//    double perplata = (x * time) - sum;
    this->finally(per_test, 0, pereplata);
    output_pereplata = pereplata;
}



void Model::credit_D(double sum, int time , double stavka,  double *output_p1, double *output_pereplata) {
    double b = sum / time;
    double  pereplata = 0;
    int days = 30;
    *output_p1 = b + sum * stavka / 100 * days/365;
    for (int i = 0; i < time; i++) {
       double  p = sum * stavka / 100 * days/365;
        sum -= (b);
        pereplata += p;
        if (days == 30)
            days = 31;
        else
            days = 30;
    }
    *output_pereplata = pereplata;
}

void Model::deposit(double sum, int time, double stavka, double nalog, int choice_plus,
double plus, int choice_minus, double minus, int choice_viploti, double perio_viplat, int choice_kap,
double *summaNend,  double *procentEnd, double *dipositEnd) {
    double doxod = 0;
    double sumnalog = 0;
    if (choice_plus == 1 && choice_minus == 1) {
        doxod =  ((((sum + plus - minus)* stavka * time)/ 365) / 100);
    } else if (choice_plus == 1 && choice_minus == 0) {
          doxod = ((((sum + plus)* stavka * time)/ 365) / 100);
    } else if (choice_plus == 0 && choice_minus == 1) {
          doxod = ((((sum - minus)* stavka * time)/ 365) / 100);
    } else if (choice_plus == 0 && choice_minus == 0) {
        doxod = (((sum  * stavka * time)/ 365) / 100);
    }
    if (choice_viploti == 1) {
        double vipl = doxod / perio_viplat;
        sumnalog = vipl * perio_viplat * nalog / 100;
    }
     double eyear_pro = stavka / 100;
    if (choice_kap == 1) {
        double tmp = 1 + (eyear_pro / 365);
        double kapday = sum * pow(tmp, time);
        *dipositEnd = kapday;
        *procentEnd = kapday - sum;
        *summaNend = *procentEnd * nalog / 100;
        *procentEnd -= *summaNend;

    } else if (choice_kap == 2) {
        double tmp1 = 1 + (eyear_pro / 12);
        int time_monht = time / 30;
         double kapmonth = sum * pow(tmp1, time_monht);
        *dipositEnd = kapmonth;
        *procentEnd = kapmonth - sum;
        *summaNend = *procentEnd * nalog / 100;
        *procentEnd -= *summaNend;
    } else if (choice_kap == 3) {
        double tmp2 = 1 + (eyear_pro / 4);
        int time_kvartal = time/ 90;
        double kapkvart = sum * pow(tmp2, time_kvartal);
        *dipositEnd = kapkvart;
        *procentEnd = kapkvart - sum;
        *summaNend = *procentEnd * nalog / 100;
        *procentEnd -= *summaNend;
    }
    if (choice_viploti == 0)
        sumnalog = doxod * nalog / 100;
    doxod -= sumnalog;
    sum += doxod + plus - minus;
    if (choice_kap == 0) {
            *summaNend = sumnalog;
        if (choice_viploti == 0)
            *dipositEnd = sum;
        else
            *dipositEnd = sum - doxod;
        *procentEnd = doxod;
    }
}



}  // namespace s21
