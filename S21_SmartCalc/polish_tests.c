/**
 * @file polish_tests.c
 * @author qylenett (you@domain.com)
 * @brief File with tests for ranctins.
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <check.h>

#include "s21_calc.h"

START_TEST(calc_test_1) {
  double result = 0.0;
  char input_string[256] = "(5+5)*-2";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -20.000000, 6);
}

START_TEST(calc_test_2) {
  double result = 0.0;
  char input_string[256] = "(10+10*2)/-3";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, -10.000000);
}

START_TEST(calc_test_3) {
  double result = 0.0;
  char input_string[256] = "2.0 / ( 3.0 + 2.0 ) * 5.0";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 2.000000, 6);
}

START_TEST(calc_test_4) {
  double result = 0.0;
  char input_string[256] = "10.0 + 10.0 * 10.0";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 110.000000, 6);
}

START_TEST(calc_test_5) {
  double result = 0.0;
  char input_string[256] = "-5 + -4 * -2";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 3.000000, 6);
}

START_TEST(calc_test_6) {
  double result = 0.0;
  char input_string[256] = "-5.0 mod -3.0";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, -2.000000);
}

START_TEST(calc_test_7) {
  double result = 0.0;
  char input_string[256] = "1.0 / 2.0 * ( 2.0 - 1.0 )";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 0.500000);
}

START_TEST(calc_test_8) {
  double result = 0.0;
  char input_string[256] = "1.1 + 2.0 + ( 3.0 * 4.0 ) + ( 5.0 + 6.8 )";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 26.900000);
}

START_TEST(calc_test_9) {
  double result = 0.0;
  char input_string[256] = "1.1 + 2.0 + (3.0 - 5.5) * (1.5 - 6.5)";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 15.600000);
}

START_TEST(calc_test_10) {
  double result = 0.0;
  char input_string[256] = "6.6 - 1.1 - 2.2 - 3.3 - 4.4 - 5.5";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, -9.900000);
}

START_TEST(calc_test_11) {
  double result = 0.0;
  char input_string[256] = "1.1 - 2.2 - 3.3 - 4.4 - 5.5 + 6.6";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -7.7000000, 6);
}

START_TEST(calc_test_12) {
  double result = 0.0;
  char input_string[256] = "-1.1 * 5";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, -5.5);
}

START_TEST(calc_test_13) {
  double result = 0.0;
  char input_string[256] = "2^2";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 4.000000);
}

START_TEST(calc_test_14) {
  double result = 0.0;
  char input_string[256] = "5^3";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 125.000000);
}

START_TEST(calc_test_15) {
  double result = 0.0;
  char input_string[256] = "2^2^3";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 256.000000);
}

START_TEST(calc_test_16) {
  double result = 0.0;
  char input_string[256] = "(2^2)^3";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 64.000000);
}

START_TEST(calc_test_17) {
  double result = 0.0;
  char input_string[256] = "-5 + 3 * 2^2";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 7.000000);
}

START_TEST(calc_test_18) {
  double result = 0.0;
  char input_string[256] = "(2^2^3 - 200) / 2";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 28.000000);
}

START_TEST(calc_test_19) {
  double result = 0.0;
  char input_string[256] = "5 mod -1.5";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 0.500000);
}

START_TEST(calc_test_20) {
  double result = 0.0;
  char input_string[256] = "(5 mod -1.5 * 4) ^ 2";
  working_proccess(input_string, &result);
  ck_assert_double_eq(result, 4.000000);
}

START_TEST(calc_test_21) {
  double result = 0.0;
  char input_string[256] = "sin(30)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.988032, 6);
}

START_TEST(calc_test_22) {
  double result = 0.0;
  char input_string[256] = "sin(45)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.850904, 6);
}

START_TEST(calc_test_23) {
  double result = 0.0;
  char input_string[256] = "sin(60)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.304811, 6);
}

START_TEST(calc_test_24) {
  double result = 0.0;
  char input_string[256] = "sin(90)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.893997, 6);
}

START_TEST(calc_test_25) {
  double result = 0.0;
  char input_string[256] = "sin(120)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.580611, 6);
}

START_TEST(calc_test_26) {
  double result = 0.0;
  char input_string[256] = "sin(180)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.801153, 6);
}

START_TEST(calc_test_27) {
  double result = 0.0;
  char input_string[256] = "sin(270)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.176046, 6);
}

START_TEST(calc_test_28) {
  double result = 0.0;
  char input_string[256] = "sin(360)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.958916, 6);
}

START_TEST(calc_test_29) {
  double result = 0.0;
  char input_string[256] = "sin(0)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.000000, 6);
}

START_TEST(calc_test_30) {
  double result = 0.0;
  char input_string[256] = "cos(30)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.154251, 6);
}

START_TEST(calc_test_31) {
  double result = 0.0;
  char input_string[256] = "cos(45)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.525322, 6);
}

START_TEST(calc_test_32) {
  double result = 0.0;
  char input_string[256] = "cos(90)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.448074, 6);
}

START_TEST(calc_test_33) {
  double result = 0.0;
  char input_string[256] = "cos(120)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.814181, 6);
}

START_TEST(calc_test_34) {
  double result = 0.0;
  char input_string[256] = "cos(180)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.598460, 6);
}

START_TEST(calc_test_35) {
  double result = 0.0;
  char input_string[256] = "cos(270)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.984382, 6);
}

START_TEST(calc_test_36) {
  double result = 0.0;
  char input_string[256] = "cos(360)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -0.283691, 6);
}

START_TEST(calc_test_37) {
  double result = 0.0;
  char input_string[256] = "cos(0)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.000000, 6);
}

START_TEST(calc_test_38) {
  double result = 0.0;
  char input_string[256] = "tan(90)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -1.995200, 6);
}

START_TEST(calc_test_39) {
  double result = 0.0;
  char input_string[256] = "tan(90) * sin(30) + (cos(45)^2)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -1.695358, 6);
}

START_TEST(calc_test_40) {
  double result = 0.0;
  char input_string[256] = "(sin(45) + cos(30) + tan(45) + tan(90)) * 2";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.25946, 6);
}

START_TEST(calc_test_41) {
  double result = 0.0;
  char input_string[256] = "tan(180)^2";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.792091, 6);
}

START_TEST(calc_test_43) {
  double result = 0.0;
  char input_string[256] = "asin(0.5)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.25946, 6);
}

START_TEST(calc_test_44) {
  double result = 0.0;
  char input_string[256] = "acos(0.5)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.047198, 6);
}

START_TEST(calc_test_45) {
  double result = 0.0;
  char input_string[256] = "acos(1)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.000000, 6);
}

START_TEST(calc_test_46) {
  double result = 0.0;
  char input_string[256] = "atan(0)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.000000, 6);
}

START_TEST(calc_test_47) {
  double result = 0.0;
  char input_string[256] = "atan(1)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.785398, 6);
}

START_TEST(calc_test_48) {
  double result = 0.0;
  char input_string[256] = "sqrt(100) / sqrt(25) * sqrt(121)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 22.000000, 6);
}

START_TEST(calc_test_49) {
  double result = 0.0;
  char input_string[256] = "ln(5)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.609438, 6);
}

START_TEST(calc_test_50) {
  double result = 0.0;
  char input_string[256] = " -5.0 mod -3.0";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, -2.000000, 6);
}

START_TEST(calc_test_51) {
  double result = 0.0;
  char input_string[256] = "log(10)";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.000000, 6);
}

START_TEST(calc_test_52) {
  double result = 0.0;
  char input_string[256] = "1.0 / 2.0 * ( 2.0 - 1.0 )";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.500000, 6);
}

START_TEST(calc_test_53) {
  double result = 0.0;
  char input_string[256] = "1.1 + 2.0 + ( 3.0 * 4.0 ) + ( 5.0 + 6.8 )";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 26.880000, 6);
}

START_TEST(calc_test_54) {
  double result = 0.0;
  char input_string[256] = "10^10";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 10000000000.000000, 6);
}

START_TEST(calc_test_55) {
  double result = 0.0;
  char input_string[256] = "10000000000 - 10000000000";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.000000, 6);
}

START_TEST(calc_test_56) {
  double result = 0.0;
  char input_string[256] =
      "1+2+3+4+5+6+7+8+9+10+100-3-2-10-3*2+12+15+16+17+18/2";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 203.000000, 6);
}

START_TEST(calc_test_57) {
  double result = 0.0;
  char input_string[256] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 128.000000, 6);
}

START_TEST(calc_test_58) {
  double result = 0.0;
  char input_string[256] =
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1";
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 1.000000, 6);
}
START_TEST(calc_test_59) {
  char input_string[50] = "log(1)";
  double result = 0.0;
  working_proccess(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, 6);

  char input_string1[50] = "log(1.5)";
  result = 0.0;
  working_proccess(input_string1, &result);
  ck_assert_double_eq_tol(result, 0.17609125905, 6);
}

///

START_TEST(calc_test_60) {
  double total_sum = 100000;
  int time = 12;
  double percent = 10;
  int type = 0;

  double first_pay = 0;
  double last_pay = 0;
  double overpay = 0;
  double final_sum = 0;

  s21_credit_calc(total_sum, time, percent, type, &first_pay, &last_pay,
                  &overpay, &final_sum);

  ck_assert_double_eq_tol(first_pay, 9166.666633, 6);
  ck_assert_double_eq_tol(last_pay, 8333.333333, 6);
  ck_assert_double_eq_tol(overpay, 5416.666450, 6);
  ck_assert_double_eq_tol(final_sum, 105416.666450, 6);
}

START_TEST(calc_test_61) {
  double total_sum = 100000;
  int time = 12;
  double percent = 10;
  int type = 1;

  double first_pay = 0;
  double last_pay = 0;
  double overpay = 0;
  double final_sum = 0;

  s21_credit_calc(total_sum, time, percent, type, &first_pay, &last_pay,
                  &overpay, &final_sum);

  ck_assert_double_eq_tol(first_pay, 8791.588723, 6);
  ck_assert_double_eq_tol(last_pay, 8791.588723, 6);
  ck_assert_double_eq_tol(overpay, 5499.064676, 6);
  ck_assert_double_eq_tol(final_sum, 105499.064676, 6);
}

START_TEST(calc_test_62) {
  int result = 0;
  char input_string[8] = "*kaktus";
  result = check_input_data(input_string, 8);
  ck_assert_int_eq(result, 1);
}

START_TEST(calc_test_63) {
  int result = 0;
  char input_string[5] = ")2+2";
  result = check_input_data(input_string, 7);
  ck_assert_int_eq(result, 1);
}

START_TEST(calc_test_64) {
  int result = 0;
  char input_string[4] = "2+2";
  result = check_input_data(input_string, 7);
  ck_assert_int_eq(result, 0);
}

START_TEST(calc_test_65) {
  int result = 0;
  char input_string[4] = "*xta";
  result = check_x_value(input_string);
  ck_assert_int_eq(result, 1);
}

START_TEST(calc_test_66) {
  int result = 0;
  char input_string[4] = "325";
  result = check_x_value(input_string);
  ck_assert_int_eq(result, 1);
}

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  double result;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  tcase_add_test(tc1_1, calc_test_6);
  tcase_add_test(tc1_1, calc_test_7);
  tcase_add_test(tc1_1, calc_test_8);
  tcase_add_test(tc1_1, calc_test_9);
  tcase_add_test(tc1_1, calc_test_10);
  tcase_add_test(tc1_1, calc_test_11);
  tcase_add_test(tc1_1, calc_test_12);
  tcase_add_test(tc1_1, calc_test_13);
  tcase_add_test(tc1_1, calc_test_14);
  tcase_add_test(tc1_1, calc_test_15);
  tcase_add_test(tc1_1, calc_test_16);
  tcase_add_test(tc1_1, calc_test_17);
  tcase_add_test(tc1_1, calc_test_18);
  tcase_add_test(tc1_1, calc_test_19);
  tcase_add_test(tc1_1, calc_test_20);
  tcase_add_test(tc1_1, calc_test_21);
  tcase_add_test(tc1_1, calc_test_22);
  tcase_add_test(tc1_1, calc_test_23);
  tcase_add_test(tc1_1, calc_test_24);
  tcase_add_test(tc1_1, calc_test_25);
  tcase_add_test(tc1_1, calc_test_26);
  tcase_add_test(tc1_1, calc_test_27);
  tcase_add_test(tc1_1, calc_test_28);
  tcase_add_test(tc1_1, calc_test_29);
  tcase_add_test(tc1_1, calc_test_30);
  tcase_add_test(tc1_1, calc_test_31);
  tcase_add_test(tc1_1, calc_test_32);
  tcase_add_test(tc1_1, calc_test_33);
  tcase_add_test(tc1_1, calc_test_34);
  tcase_add_test(tc1_1, calc_test_35);
  tcase_add_test(tc1_1, calc_test_36);
  tcase_add_test(tc1_1, calc_test_37);
  tcase_add_test(tc1_1, calc_test_38);
  tcase_add_test(tc1_1, calc_test_39);
  tcase_add_test(tc1_1, calc_test_40);
  tcase_add_test(tc1_1, calc_test_41);
  tcase_add_test(tc1_1, calc_test_43);
  tcase_add_test(tc1_1, calc_test_44);
  tcase_add_test(tc1_1, calc_test_45);
  tcase_add_test(tc1_1, calc_test_46);
  tcase_add_test(tc1_1, calc_test_47);
  tcase_add_test(tc1_1, calc_test_48);
  tcase_add_test(tc1_1, calc_test_49);
  tcase_add_test(tc1_1, calc_test_50);
  tcase_add_test(tc1_1, calc_test_51);
  tcase_add_test(tc1_1, calc_test_52);
  tcase_add_test(tc1_1, calc_test_53);
  tcase_add_test(tc1_1, calc_test_54);
  tcase_add_test(tc1_1, calc_test_55);
  tcase_add_test(tc1_1, calc_test_56);
  tcase_add_test(tc1_1, calc_test_57);
  tcase_add_test(tc1_1, calc_test_58);
  tcase_add_test(tc1_1, calc_test_59);
  tcase_add_test(tc1_1, calc_test_60);
  tcase_add_test(tc1_1, calc_test_61);
  tcase_add_test(tc1_1, calc_test_62);
  tcase_add_test(tc1_1, calc_test_63);
  tcase_add_test(tc1_1, calc_test_64);
  tcase_add_test(tc1_1, calc_test_65);
  tcase_add_test(tc1_1, calc_test_66);
  // tcase_add_test(tc1_1, calc_test_67);
  // tcase_add_test(tc1_1, calc_test_68);
  // tcase_add_test(tc1_1, calc_test_69);
  // tcase_add_test(tc1_1, calc_test_70);

  // srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}
