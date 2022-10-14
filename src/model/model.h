#ifndef MODEL_H
#define MODEL_H #include <cmath>
#include <iostream>
#include <stdexcept>
#include <string> 
#include <cstring>
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
                {"POINT", '.'}
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
                    std::string type_;
                public:
                    ListNode() {
                        this->value_ = 0;
                        this->priority_ = 0;
                        this->type_ = "";
                    }
                    ListNode(double value, int priority, std::string type) : 
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
                    void set_value(double value) {
                        this->value_ = value;
                    }
                    void set_priority(int priority) {
                        this->priority_ = priority;
                    }
                    void set_type(std::string type) {
                        this->type_ = type;
                    }
                    double get_value() {
                        return this->value_;
                    }
                    int get_priority() {
                        return this->priority_;
                    }
                    std::string get_type() {
                        return this->type_;
                    }
            };
            ListNode node_;
        public:
            using str = std::string;
            using iter = std::string::iterator;
            Model() {;}
            ~Model() {;}
            void say_hello() { std::cout << "Hello World" << std::endl; }
       
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
            int check_after_lexem(const char *after_lexem);
            int check_after_lexem_numbers(const char *after_lexem);

        private:
            int check_name_mod(const char *mod);


    }; 



}  // namesapce s21


#endif  // MODEL_H 
