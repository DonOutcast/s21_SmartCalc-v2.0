#include <gtest/gtest.h>
#include "../controller/controller.h"

namespace s21 {

TEST(Test,  calc_v2_0) {
    std::string tmp = ("4^acos(x/4)/tan(2*x)");
    double result = 0;
    s21::Controller test_;
    std::cout << tmp << std::endl;
    std::cout << "This is a return for function : " << test_.finally(tmp, 0, result) << std::endl;

   double real_result = -6.31492;
    EXPECT_DOUBLE_EQ(fabs(result), fabs(real_result));
}


}  // namespace s21
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



//START_TEST(calc_test) {
//  {
//    char arr[100] = "4^acos(x/4)/tan(2*x)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = -6.31492;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-1 failed");
//  }
//  {
//    double sum = 1000;
//    int time = 12;
//    double stavka = 20;
//    double ou = 0;
//    double per = 0;
//    credit_A(sum,  time , stavka, &ou, &per);
//    int newper = per;
//    ck_assert_msg(newper == 111, "test-Credit");
//  }
//  {
//    double sum = 1000;
//    int time = 12;
//    double stavka = 20;
//    double ou = 0;
//    double per = 0;
//    credit_D(sum,  time , stavka, &ou, &per);
//    int newper = per;
//    ck_assert_msg(newper == 108, "test-Credit2");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 3, &summaNend, &procnetEnd, &diositEnd);
//    int tax = summaNend;
//    ck_assert_msg(tax == 0, "test_Depozit");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 0, &summaNend, &procnetEnd, &diositEnd);
//    int tax = diositEnd;
//    ck_assert_msg(tax == 1100, "test_Depozit1");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 0, &summaNend, &procnetEnd, &diositEnd);
//    int tax = procnetEnd;
//    ck_assert_msg(tax == 100, "test_Depozit2");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 1, &summaNend, &procnetEnd, &diositEnd);
//    int tax = procnetEnd;
//    ck_assert_msg(tax == 105, "test_Depozit3");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 1, &summaNend, &procnetEnd, &diositEnd);
//    int tax = diositEnd;
//    ck_assert_msg(tax == 1105, "test_Depozit4");
//  }
//  {
//    int check = check_credit("q");
//    ck_assert_msg(check == -1, "test_check_credit");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 3, &summaNend, &procnetEnd, &diositEnd);
//    int tax = diositEnd;
//    ck_assert_msg(tax == 1103, "test_Depozit4");
//  }
//  {
//    double sum = 1000;
//    int time = 365;
//    double stavka = 10;
//    double nalog = 0;
//    double summaNend = 0;
//    double procnetEnd = 0;
//    double diositEnd = 0;
//    deposit(sum, time, stavka, nalog, 0,  0, 0, 0, 0, 0, 2, &summaNend, &procnetEnd, &diositEnd);
//    int tax = diositEnd;
//    ck_assert_msg(tax == 1104, "test_Depozit4");
//  }
//  {
//    char arr[100] = "tan(2)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = -2.18503986326152;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-tan(2)");
//  }
//  {
//    char arr[100] = "acos(3)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = NAN;
//    ck_assert_msg(r != real_result, "new-test failed");
//  }
//  {
//    char arr[100] = "ln(10) + log(2) * sqrt(4)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 2.90464508432201;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-sqrt");
//  }
//  {
//    char arr[100] = "+1 / 2 ^ 3";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 0.125;
//    ck_assert_msg(r == real_result, "test-unplus");
//  }
//  {
//    char src[100] = "(2+2)mod(3+3)";
//    double r = 0;
//    finaly(src, 0, &r);
//    double real_result = 4;
//    ck_assert_msg(r == real_result, "test-mod");
//  }
//  {
//  char arr[100] =
//      "sin(2+2) + cos(2+2) + tan(2+2) + asin(2+2) + acos(2+2) + atan(2+2)";
//  double r = 0;
//  finaly(arr, 0, &r);
//  double real_result = NAN;
//  ck_assert_msg(r != real_result, "test-crazy");
//  }
//  {
//    char arr[100] = "x+x";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 4;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-2 failed");
//  }
//  {
//    char arr[100] = "123+0.456";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 123.456;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-3 failed");
//  }
//  {
//    char arr[100] = "log(x)";
//    double x_text = -2;
//    double r = 0;
//    finaly(arr, x_text, &r);
//    double real_result = NAN;
//    ck_assert_msg(r != r && real_result != real_result,
//                  "test-4 failed");
//  }
//  {
//    char arr[100] = "-(-1)";
//    double r = 0;
//    int check = finaly(arr, 0, &r);
//    double real_result = 0;
//    ck_assert_msg(check == real_result, "test-5 failed");
//  }
//  {
//    char arr[100] = "cos(10mod2.2)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 0.362358;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-6 failed");
//  }
//  {
//    char arr[100] = "sqrt(ln(10))";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 1.517427;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-7 failed");
//  }
//  {
//    char arr[100] = "atan(10)+sin(10)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 1.644775;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-8 failed");
//  }
//  {
//    char arr[100] = "asin(1)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = 1.570796;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001, "test-9 failed");
//  }
//  {
//    char arr[100] = "10-20*(-10)";
//    double r = 0;
//    finaly(arr, 0, &r);
//    double real_result = -210;
//    ck_assert_msg(fabs(r) - fabs(real_result) <= 0.00001,
//                  "test-10 failed");
//  }
//  {
//    char arr[100] = "-(o(i(a(10.01)*n(2))/10m2))^q(5)";
//    double r = 0;
//    int check = finaly(arr, 0, &r);
//    ck_assert_msg(check, "test-10 failed");
//  }
//  {
//    char arr[100] = ")(s(x)";
//    double rez = 0;
//    int r = finaly(arr, 0, &rez);
//    ck_assert_msg(r, "test-10 failed");
//  }
//  {
//    char arr[100] = ".+m)";
//    double rez = 0;
//    int r = finaly(arr, 0, &rez);
//    ck_assert_msg(r, "test-10 failed");
//  }
//}
//END_TEST
//
//int main(void) {
//  Suite *s1 = suite_create("Core");
//  TCase *tc1_1 = tcase_create("Core");
//  SRunner *sr = srunner_create(s1);
//  suite_add_tcase(s1, tc1_1);
//
//  tcase_add_test(tc1_1, calc_test);
//
//  srunner_run_all(sr, CK_ENV);
//  int nf = srunner_ntests_failed(sr);
//  srunner_free(sr);
//
//  return nf == 0 ? 0 : 1;
//}
//
