#include <gtest/gtest.h>
#include "../controller/controller.h"

namespace s21 {

    TEST(Test_1, calculation) {
        s21::Controller got;
        double result = 0;
        std::string tmp = ("15+25-(25*3)");
        got.finally(tmp, 0, result);
        double want = 15+25-(25*3);
        EXPECT_DOUBLE_EQ(result , want);
        tmp = "15^2/3 mod 2";
        got.finally(tmp, 0, result);
        want = fmod(pow(15, 2) / 3,  2);
        EXPECT_DOUBLE_EQ(result, want);
    }

    TEST(Test_2, math_operation) {
        s21::Controller got;
        double result = 0;
        std::string tmp = ("sin(x)");
        got.finally(tmp, 3, result);
        double want = sin(3);
        EXPECT_DOUBLE_EQ(result , want);
        tmp = "cos(x)";
        got.finally(tmp, 4, result);
        want = cos(4);
        EXPECT_DOUBLE_EQ(result, want);
        tmp = "tan(x)";
        got.finally(tmp, 5, result);
        want = tan(5);
        EXPECT_DOUBLE_EQ(result, want);
        tmp = "asin(x)";
        got.finally(tmp, 1, result);
        want = asin(1);
        EXPECT_DOUBLE_EQ(result, want);
        tmp = "acos(x)";
        got.finally(tmp, 1, result);
        want = acos(1);
        EXPECT_DOUBLE_EQ(result, want);
        tmp = "atan(x)";
        got.finally(tmp, 2, result);
        want = atan(2);
        EXPECT_DOUBLE_EQ(result , want);
        tmp = "ln(x)";
        got.finally(tmp, 2, result);
        want = log(2);
        EXPECT_DOUBLE_EQ(result , want);
        tmp = ("log(x)");
        got.finally(tmp, 2, result);
        want = log10(2);
        EXPECT_DOUBLE_EQ(result , want);
        tmp = ("sqrt(x)");
        got.finally(tmp, 9, result);
        want = sqrt(9);
        EXPECT_DOUBLE_EQ(result , want);
    }

    TEST(Test_3, ERRORS) {
        s21::Controller got;
        std::string tmp = "125++15";
        double result = 0;
        EXPECT_TRUE(got.finally(tmp, 0, result));
        tmp = "125+()";
        EXPECT_TRUE(got.finally(tmp, 0, result));
        tmp = "125..25-4";

        EXPECT_TRUE(got.finally(tmp, 0, result));
        tmp = "10//3)(";
        EXPECT_TRUE(got.finally(tmp, 0, result));
    }

    TEST(Test_4, long_values) {
        s21::Controller got;
        double result = 0;
        std::string tmp = "2+2345/3*4+sin(3)";
        got.finally(tmp, 0, result);
        double real_result = 2+2345./3.*4+sin(3);
        EXPECT_DOUBLE_EQ(result, real_result);
    }

    TEST(Test_5, long_values_1) {
        s21::Controller got;
        double result = 0;
        std::string tmp = "2^4+(sin(1) - tan(3)) * 4 / 5";
        got.finally(tmp, 0, result);
        double real_result = pow(2,4)+(sin(1) - tan(3)) * 4. / 5;
        EXPECT_DOUBLE_EQ(result, real_result);

    }

    TEST(Test_6, credit) {
        s21::Controller got;
        int flag = 1;
        double sum = 1000;
        int time = 12;
        double stavka = 20;
        double ou = 0;
        double per = 0;
        got.credit_ann(sum,  time , stavka, ou, per, flag);
        EXPECT_DOUBLE_EQ(per, 1111.6140707649638);
    }

    TEST(Test_6, credit_1) {
        s21::Controller got;
        int flag = 1;
        double sum = 1000;
        int time = 12;
        double stavka = 20;
        double ou = 0;
        double per = 0;
        got.credit_diff(sum,  time , flag, stavka, ou, per);
        int newper = per;
        EXPECT_EQ(newper , 1107);

    }


}  // namespace s21
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}