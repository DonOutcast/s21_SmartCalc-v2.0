#ifndef MODEL_H
#define MODEL_H
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <cstring>
#define OK 1
#define NO 0
#define LEXEM_PLUS '+'
#define LEXEM_MINUS '-'
#define LEXEM_MULT '*'
#define LEXEM_DIV '/'
#define OPEN_BRACE '('
#define CLOSE_BRACE ')'
#define POINT '.'


namespace s21 {
    class Model {
        public:
            Model() {;}
            ~Model() {;}
            void say_hello() { std::cout << "Hello World" << std::endl; }
    }; 



}  // namesapce s21


#endif  // MODEL_H 
