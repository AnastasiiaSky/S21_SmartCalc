/**
 * @file s21_string_validation.c
 * @author qylenett (you@domain.com)
 * @brief This is a series of functions wich check input data
 * @version 0.1
 * @date 2023-02-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s21_calc.h"

/**
 * @brief This is a function which checks input-string for correct of data.
 *
 * @param input_string - it is a string which comes from mainwindow.cpp after
 * you press button "="
 * @param input_str_len - it is a nength of input string
 * @return validation_check - this int result can be 1 or 0. If validation_check
 * = 1 - the input string is incorrect, else string is correct.
 */

int check_input_data(char* input_string, int input_str_len) {
  int validation_check = 1;
  for (int i = 0; i < input_str_len; i++) {
    if (input_string[i] == 40 || input_string[i] == 41 ||
        input_string[i] == 42 || input_string[i] == 43 ||
        input_string[i] == 45 || input_string[i] == 46 ||
        input_string[i] == 47 || input_string[i] == 48 ||
        input_string[i] == 49 || input_string[i] == 50 ||
        input_string[i] == 51 || input_string[i] == 52 ||
        input_string[i] == 53 || input_string[i] == 54 ||
        input_string[i] == 55 || input_string[i] == 56 ||
        input_string[i] == 57 || input_string[i] == 94 ||
        input_string[i] == 97 || input_string[i] == 99 ||
        input_string[i] == 100 || input_string[i] == 103 ||
        input_string[i] == 105 || input_string[i] == 108 ||
        input_string[i] == 109 || input_string[i] == 110 ||
        input_string[i] == 111 || input_string[i] == 113 ||
        input_string[i] == 114 || input_string[i] == 115 ||
        input_string[i] == 116 || input_string[i] == 120) {
      validation_check = 0;
    }
    if (input_string[0] == ')' || input_string[0] == '.' ||
        input_string[0] == '/' || input_string[0] == '*' ||
        input_string[0] == '^') {
      validation_check = 1;
    }
  }
  return validation_check;
}

/**
 * @brief This function checks value of "x", it comes from mainwindow.cpp. This
 * is a value which user enters when use the application.
 *
 * @param x_value - it comes from mainwindow.cpp.
 * @return int result - shows, if "x" correct result = 0, else result =1;
 */
int check_x_value(char* x_value) {
  int result = 0;
  int i = 0;
  do {
    if ((x_value[i] == 48) || (x_value[i] == 49) || (x_value[i] == 5) ||
        (x_value[i] == 51) || (x_value[i] == 52) || (x_value[i] == 53) ||
        (x_value[i] == 54) || (x_value[i] == 55) || (x_value[i] == 56) ||
        (x_value[i] == 57) || (x_value[i] == 46) || (x_value[i] == 45)) {
      i++;
    } else {
      result = 1;
      break;
    }
  } while (x_value[i] != '\0');
  return result;
}

/**
 * @brief This function checks input data for correct;
 *
 * @param str - input string of data comes from mainwindow.cpp
 * @return int ret - returns error code.
 */

int Validator(char* str) {
  char sign_full[32] = {"+-*/^msctCSTqlL("};
  char sign_func[16] = {"sctCSTqlL"};
  char sign[16] = {"+-*/^m."};
  char sign_m[8] = {"*/^m)"};
  char sign_for_x[16] = {"+-*/^m.("};
  char num[16] = {"0123456789.)"};
  char num_1[16] = {"0123456789."};
  char symbol_for_back[24] = {"+-*/^+-*/^m("};
  int ret = 0;
  int len = strlen(str);
  int count_bracket = 0;

  // проверка на оператор в начале или в конце строки
  if (strchr(sign_full, str[len - 1]) != NULL) ret = 101;
  if (strchr(sign_m, str[0]) != NULL) ret = 102;

  for (int i = 0; i < len; i++) {
    // считаем скобки
    if (str[i] == '(') {
      count_bracket++;
    } else if (str[i] == ')') {
      count_bracket--;
    }
    if (count_bracket < 0) ret = 103;
    // проверка для 'x'
    if (i > 0 && str[i] == 'x' && strchr(sign_for_x, str[i - 1]) == NULL) {
      ret = 104;
    }

    if (i > 0 && str[i] == 'x' && str[i - 1] == '.') {
      ret = 105;
    }

    if (str[i] == 'x' && (int)(strlen(str) - 1) > i && str[i + 1] == '.') {
      ret = 106;
    }
    // ищем два оператора подряд '+-*/^'
    if (i > 0 && strchr(sign, str[i]) != NULL &&
        strchr(sign, str[i - 1]) != NULL) {
      ret = 107;
    }
    // проверяем на пустые скобки '()'
    if (i > 0 && str[i - 1] == '(' && str[i] == ')') {
      ret = 108;
    }
    // перед и после mod должно быть число
    if (str[i] == 'm' &&
        (strchr(sign, str[i - 1]) || strchr(sign, str[i + 3]))) {
      ret = 109;
    }
    // перед цифрой не может находиться ')'
    if (i > 0 && strchr(num_1, str[i]) != NULL && str[i - 1] == ')') {
      ret = 110;
    }
    // перед функцией не должно быть точки, числа
    // или ')'
    if (i > 0 && strchr(sign_func, str[i]) != NULL &&
        strchr(num, str[i - 1]) != NULL) {
      ret = 111;
    }
    // перед '(' не может находиться число или
    // точка
    if (i > 0 && str[i] == '(' && strchr(num, str[i - 1]) != NULL) {
      ret = 112;
    }

    // для backSpace перед вызовом функции не
    // может быть букв
    if (i > 0 && strchr(sign_func, str[i]) != NULL &&
        strchr(symbol_for_back, str[i - 1]) == NULL) {
      ret = 113;
    }
  }
  return ret;
}
