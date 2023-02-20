/**
 * @file s21_string_parser.c
 * @author qylenett (you@domain.com)
 * @brief This is a file with functions which work with input string, and parce
 * char data for tockens.
 * @version 0.1
 * @date 2023-02-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_calc.h"

/**
 * @brief This is a main function which send input string to other functions and
 * returns error_check status. struct tockens tockens - struct arrey, created to
 * write lexems in it. It contains struct of tockens and index. Struct of
 * tockens contains dounle number - we use this to write a number which we have
 * found, char operatin - we use to write function(like sin, cos, tan etc) or
 * operation (+/-* etc.) and int priority - we use to write a priority of
 * operation or function. Here we create stack, and output string. They have the
 * same structure like tockens arrey.
 *
 * @param input_string - incoming string, which user have entered, from front
 * part.
 * @param result - it is a result of calculation.
 * @return int error_check - status of errors.
 */
int working_proccess(char* input_string, double* result) {
  int error_check = 0;
  *result = 0.0;
  error_check = Validator(input_string);
  struct tockens tockens = {{0.0, '\0', 0}, 0};
  struct stack mystack = {{0.0, '\0', 0}, 0};
  struct output output_string = {{0.0, '\0', 0}, 0};
  int input_str_len = strlen(input_string);

  find_patterns(input_string, &tockens, input_str_len);
  polish_notation(&tockens, &mystack, &output_string, result, &error_check);
  return error_check;
}

/**
 * @brief This function works with input string, and parce it to lexems.
 *
 * @param input_string - char array - input data.
 * @param tockens - it is an array of structs. Tockens contains [tockens_arr]
 * and [index]. Tockens_arr contains [double number], [char operation], [int
 * priority].
 * @param input_str_len - length of input string.
 */
void find_patterns(char* input_string, struct tockens* tockens,
                   int input_str_len) {
  double new_number = 0;
  char buffer_str[255] = {0};
  int index_str = 0;
  tockens->index = 0;
  int prio_num = 0;

  for (int i = 0; i < input_str_len; i++) {
    if (is_number(input_string[i]) == 0) {
      if (is_number(input_string[i + 1]) == 0) {
        buffer_str[index_str] = input_string[i];
        index_str++;
      } else if (is_number(input_string[i + 1]) != 0) {
        buffer_str[index_str] = input_string[i];
        buffer_str[index_str + 1] = '\0';
        new_number = atof(buffer_str);
        strcpy(buffer_str, "");
        index_str = 0;
        tockens->tocken_arr[tockens->index].number = new_number;
        tockens->tocken_arr[tockens->index].priority = 0;
        strcpy(tockens->tocken_arr[tockens->index].operation, "");
        tockens->index++;
      }
    } else if (is_function(input_string[i]) == 0) {
      if (is_function(input_string[i + 1]) == 0) {
        buffer_str[index_str] = input_string[i];
        index_str++;
      } else {
        buffer_str[index_str] = input_string[i];
        buffer_str[index_str + 1] = '\0';
        strcpy(tockens->tocken_arr[tockens->index].operation, buffer_str);
        prio_num = check_priority(buffer_str);
        tockens->tocken_arr[tockens->index].number = 0;
        tockens->tocken_arr[tockens->index].priority = prio_num;
        tockens->index++;
        index_str = 0;
        prio_num = 0;
        strcpy(buffer_str, "");
      }
    } else if (is_operation(input_string[i]) == 0) {
      buffer_str[index_str] = input_string[i];
      buffer_str[index_str + 1] = '\0';
      strcpy(tockens->tocken_arr[tockens->index].operation, buffer_str);
      prio_num = check_priority(buffer_str);
      tockens->tocken_arr[tockens->index].priority = prio_num;
      tockens->tocken_arr[tockens->index].number = 0;
      prio_num = 0;
      tockens->index++;
      strcpy(buffer_str, "");
    }
  }
}

/**
 * @brief It checks if simbol a number with the help of ascii tabal elements.
 *
 * @param simbol - from input string.
 * @return int - if simbol is number or point it returns 0, else returns 1;
 */

int is_number(char simbol) {
  int answer = 1;
  if (simbol == 48 || simbol == 49 || simbol == 50 || simbol == 51 ||
      simbol == 52 || simbol == 53 || simbol == 54 || simbol == 55 ||
      simbol == 56 || simbol == 57 || simbol == 46) {
    answer = 0;
  }
  return answer;
}

/**
 * @brief It checks if simbol an element of the name of function with the help
 * of ascii tabal elements. To check it we looking for letters like "s", "i",
 * "n", etc
 *
 * @param simbol - from input string.
 * @return int - if simbol is number or point it returns 0, else returns 1.
 */

int is_function(char simbol) {
  int answer = 1;
  if (simbol == 99 || simbol == 111 || simbol == 115 || simbol == 105 ||
      simbol == 110 || simbol == 116 || simbol == 97 || simbol == 113 ||
      simbol == 114 || simbol == 108 || simbol == 103 || simbol == 109 ||
      simbol == 100) {
    answer = 0;
  }
  return answer;
}

/**
 * @brief It checks if simbol a "+", "-", "*", "/", "(", ")" with the help of
 * ascii tabal elements.
 *
 * @param simbol - from input string.
 * @return int - if simbol is number or point it returns 0, else returns 1.
 */
int is_operation(char simbol) {
  int answer = 1;
  if (simbol == 40 || simbol == 41 || simbol == 43 || simbol == 45 ||
      simbol == 42 || simbol == 47 || simbol == 94) {
    answer = 0;
  }
  return answer;
}

/**
 * @brief This is function check a priority of operation. In this program we
 * have 7 priorities. If it is number we give 0 priority. If it is a function
 * (cos(x), acos(x), sin(x), asin(x), tan(x), atan(x), sqrt(x), ln(x), log(x))
 * we give 6 priority. If it operations like mod or pove we give 5 priority. If
 * it "*", "/" we give 4 priority. If it "+" or "-" we give 3 priority. if it
 * "(" - 2 priority. If it ")" - 1 priority. We write priority to
 * tockens_arr->priority for each ellement of struct array.
 *
 * @param buffer_str - it is a tmp_str.
 * @return int prio - returns result.
 */
int check_priority(char* buffer_str) {
  int prio = 0;
  int len = strlen(buffer_str);
  if (len >= 2 && strcmp(buffer_str, "mod") != 0) {
    prio = 6;
  } else if (len >= 2 && strcmp(buffer_str, "mod") == 0) {
    prio = 5;
  } else if (len < 2 && strcmp(buffer_str, "^") == 0) {
    prio = 5;
  } else if (len < 2 &&
             (strcmp(buffer_str, "*") == 0 || strcmp(buffer_str, "/") == 0)) {
    prio = 4;
  } else if (len < 2 &&
             (strcmp(buffer_str, "-") == 0 || strcmp(buffer_str, "+") == 0)) {
    prio = 3;
  } else if (len < 2 && (strcmp(buffer_str, "(") == 0)) {
    prio = 2;
  } else if (len < 2 && (strcmp(buffer_str, ")") == 0)) {
    prio = 1;
  }
  return prio;
}
