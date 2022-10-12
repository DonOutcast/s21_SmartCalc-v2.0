#include "model.h"
#include <algorithm>
namespace s21 {
    void Model::remove_space(str &string) {
       string.erase(remove_if(string.begin(), string.end(), isspace), string.end());
    }
}  // namespace s21

int main(void) {
    s21::Model a;

    return 0; 
}
