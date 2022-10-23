#ifndef MODEL_H
#define MODEL_H #include <cmath>
#include <iostream>
#include <stdexcept>
#include <string> 
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <list>


namespace s21 {
    class Model {
        private:
            std::map<std::string, int> some_items_{
                {"OK", 1},
                {"NO", 0},
                {"SIZE", 1000}
            };
            std::map<std::string, char> lexems_{
                {"LEXEM_PLUS", '+'},
                {"LEXEM_MINUS", '-'},
                {"LEXEM_MULT", '*'},
                {"LEXEM_DIV", '/'},
                {"OPEN_BRACE", '('},
                {"CLOSE_BRACE", ')'},
                {"POINT", '.'},
                {"POW", '^'}
            };
            std::map<std::string, int> type_t_ {
                {"s21_number", 1},
                {"s21_x", 2},
                {"s21_open_brace", 3},
                {"s21_close_brace", 4},
                {"s21_sin", 5},
                {"s21_cos", 6},
                {"s21_tan", 7},
                {"s21_asin", 8},
                {"s21_acos", 9},
                {"s21_atan", 10},
                {"s21_sqrt", 11},
                {"s21_ln", 12},
                {"s21_log", 13},
                {"s21_un_plus", 14},
                {"s21_un_minus", 15},
                {"s21_mod", 16},
                {"s21_pow", 17},
                {"s21_plus", 18},
                {"s21_minus", 19},
                {"s21_mult", 20},
                {"s21_div", 21}
            };

            struct ListNode {
                private:
                    double value_;
                    int priority_;
                    int type_;
                    void bring_to_zero() {
                        this->value_ = 0;
                        this->priority_ = 0;
                        this->type_ = 0;
                    }
                public:
                    ListNode() {
                        this->value_ = 0;
                        this->priority_ = 0;
                        this->type_ = 0;
                    }
                    ListNode(double value, int priority, int type) : 
                        value_(value), priority_(priority), type_(type){}
                        ListNode(const ListNode& other) {
                        this->value_ = other.value_;
                        this->priority_ = other.priority_;
                        this->type_ = other.type_;
                    }
                ListNode(ListNode&& other) {
                    this->value_ = other.value_;
                    this->priority_ = other.priority_;
                    this->type_ = other.type_;
                }
                    ~ListNode(){;}
                    ListNode& operator=(const ListNode& other) {
                        if (this != &other) {
                            this->bring_to_zero();
                            this->value_ = other.value_;
                            this->priority_ = other.priority_;
                            this->type_ = other.type_;

                        }
                        return *this;
                    }
                    void set_value(double value) {
                        this->value_ = value;
                    }
                    void set_priority(int priority) {
                        this->priority_ = priority;
                    }
                    void set_type(int type) {
                        this->type_ = type;
                    }
                    double get_value() {
                        return this->value_;
                    }
                    int get_priority() {
                        return this->priority_;
                    }
                    int get_type() {
                        return this->type_;
                    }
            };
        public:
            using str = std::string;
            using iter = std::string::iterator;
            using type_list = std::list<ListNode>;
            using  double_list = std::list<double>;
            Model() {;}
            ~Model() {;}
            void say_hello() { 
            ;
            }
       
            void remove_space(str &string);
            int check_point(const char *point);
            int check_numbers(const char *numbers);
            int check_x(const char *x);
            int check_mod(const char *mod);
            int check_sin(const char *sin);
            int check_cos(const char *cos);
            int check_tan(const char *tan);
            int check_asin(const char *asin);
            int check_acos(const char *acos);
            int check_atan(const char *atan);
            int check_sqrt(const char *sqrt);
            int check_ln(const char *ln);
            int check_log(const char *log);
            int check_pow(const char *pow);

            int check_div(const char *div);
            int check_mult(const char *mult);
            int check_minus(const char *minus);
            int check_plus(const char *plus);
            int check_brace(const str &brace);
            int check_input_X(const str &x);

            int check_after_lexem(const char *after_lexem);
            int check_after_lexem_numbers(const char *after_lexem);
           

            void parsing_to_struct(const str &string, std::list<ListNode> &node_);
            std::list<ListNode> pols_notation(std::list<ListNode> &list_lexems);
            int check_support(std::list<ListNode> &support_lexems, int priority);
            void swap_x_n_number(std::list<ListNode> &after_posl, double &number_x);
            void calculate(std::list<ListNode> &after_pols);
            void calculate_lexems(std::list<ListNode> &after_pols, std::list<ListNode>::iterator &tmp1, std::list<ListNode>::iterator &tmp2, std::list<ListNode>::iterator &tmp3);
            void calculate_functions(type_list &after_pols, std::list<ListNode>::iterator &tmp2, std::list<ListNode>::iterator &tmp3);
            void calculate_functions_2(type_list &after_pols, std::list<ListNode>::iterator &tmp1, std::list<ListNode>::iterator &tmp2);
            double masud(type_list &after_pols);
            void plus(double_list &tmp);
            void minus(double_list &tmp);
            void mult(double_list &tmp);
            void div(double_list &tmp);
            void un_minus(double_list &tmp);
            void un_plus(double_list &tmp);
            void s21_sin(double_list &tmp);
            void s21_cos(double_list &tmp);
            void s21_tan(double_list &tmp);
            void s21_asin(double_list &tmp);
            void s21_acos(double_list &tmp);
            void s21_atan(double_list &tmp);
            void s21_log(double_list &tmp);
            void s21_ln(double_list &tmp);
            void s21_sqrt(double_list &tmp);
            void s21_pow(double_list &tmp);
            void s21_mod(double_list &tmp);

            int check_name_mod(const char *mod);
            int check_size_string(const str& string);
            int validation_string(const str &string);
            
        public:
            int finally(str &input, double X, double &resultOutput);
            void deposit(double sum, int time, double stavka, double nalog, int choice_plus,
                         double plus, int choice_minus, double minus, int choice_viploti, double perio_viplat, int choice_kap,
                         double *summaNend,  double *procentEnd, double *dipositEnd);
            void credit_A(const str sum, const str time , const str stavka, double &output_x, double &output_pereplata);
            void credit_D(double sum, int time , double stavka,  double *output_p1, double *output_pereplata);



    }; 



}  // namesapce s21


#endif  // MODEL_H 
