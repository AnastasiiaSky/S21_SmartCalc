/**
 * @file s21_calculation_proc.c
 * @author qylenett (you@domain.com)
 * @brief Calculation process after parcing and make Polish notation string.
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s21_calc.h"

/**
 * @brief Moving by output string, and looking for data to calculate. If it meet
 * foonctiong or operation, calculates priveous number, or to priveous 2
 * numbers.
 *
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param error_check - error status.
 * @return double result of calculation.
 */
double calculation_process(struct stack *mystack, output *output_string,
                           int *error_check) {
  double result = 0;
  if (mystack->size == 0) {
    for (int i = 0; i < output_string->position; i++) {
      if (strlen(output_string->output_string[i].operation) < 1) {
        push_number(mystack, output_string->output_string[i].number);
      } else if (strlen(output_string->output_string[i].operation) >= 1) {
        check_operation(mystack, output_string, &i, error_check);
      }
    }
  }
  result = mystack->action_arr[mystack->size].number;
  pop(mystack);
  return result;
}

/**
 * @brief Finds tipe of operating.
 *
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of output string.
 * @param error_check - error status.
 */

void check_operation(struct stack *mystack, output *output_string,
                     int *position, int *error_check) {
  if (strcmp(output_string->output_string[*position].operation, "+") == 0) {
    summer(mystack);
  } else if (strcmp(output_string->output_string[*position].operation, "-") ==
             0) {
    subtraction(mystack);
  } else if (strcmp(output_string->output_string[*position].operation, "*") ==
             0) {
    multiplication(mystack);
  } else if (strcmp(output_string->output_string[*position].operation, "/") ==
             0) {
    division(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "^") ==
             0) {
    power(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "mod") ==
             0) {
    div_reminder(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "sin") ==
             0) {
    sinus(mystack);
  } else if (strcmp(output_string->output_string[*position].operation, "cos") ==
             0) {
    cosinus(mystack);
  } else if (strcmp(output_string->output_string[*position].operation, "tan") ==
             0) {
    tangens(mystack);
  } else if (strcmp(output_string->output_string[*position].operation,
                    "acos") == 0) {
    arccosinus(mystack);
  } else if (strcmp(output_string->output_string[*position].operation,
                    "asin") == 0) {
    arcsinus(mystack);
  } else if (strcmp(output_string->output_string[*position].operation,
                    "atan") == 0) {
    arctangens(mystack);
  } else if (strcmp(output_string->output_string[*position].operation,
                    "sqrt") == 0) {
    root(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "ln") ==
             0) {
    logarithm(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "log") ==
             0) {
    ten_logarithm(mystack, error_check);
  } else if (strcmp(output_string->output_string[*position].operation, "(") ==
             0) {
    negative_number(mystack, output_string, position);
  }
}

/**
 * @brief Works with calculation of unar minus operation.
 *
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param error_check - error status.
 */
void negative_number(struct stack *mystack, output *output_string,
                     int *position) {
  double result = 0;
  result = 0 - output_string->output_string[*position + 3].number;
  push_number(mystack, result);
  *position += 4;
}

/**
 * @brief Calculates sum of two numbers and adds result to stack.
 *
 * @param mystack - struct array.
 */
void summer(struct stack *mystack) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  number_two = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = number_one + number_two;
  push_number(mystack, result);
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates sub of two numbers and adds result to stack
 *
 * @param mystack - struct array.
 */
void subtraction(struct stack *mystack) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  number_two = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = number_two - number_one;
  push_number(mystack, result);
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates multiplication of two numbers and adds result to stack
 *
 * @param mystack - struct array.
 */
void multiplication(struct stack *mystack) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  number_two = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = number_two * number_one;
  push_number(mystack, result);
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates division of two numbers and adds result to stack. If
 * divider = 0. returns error.
 *
 * @param mystack - struct array.
 * @param error_check - error status.
 */

void division(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_two = mystack->action_arr[mystack->size].number;
  if (number_two != 0) {
    pop(mystack);
    number_one = mystack->action_arr[mystack->size].number;
    pop(mystack);
    result = number_one / number_two;
    push_number(mystack, result);
  } else if (number_two == 0) {
    *error_check = 8;
  }
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates power of two numbers and adds result to stack.
 *
 * @param mystack - struct array.
 * @param error_check - error status.
 */
void power(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_two = mystack->action_arr[mystack->size].number;
  pop(mystack);
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  if ((number_one == 0) && (number_two < 0)) {
    *error_check = 7;
  } else if (number_one < 0 && !floor(number_two)) {
    *error_check = 7;
  } else {
    result = pow(number_one, number_two);
    push_number(mystack, result);
  }
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates remainder of the division of two numbers and adds result to
 * stack.
 *
 * @param mystack - struct array.
 * @param error_check - error status.
 */

void div_reminder(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double number_two = 0;
  double result = 0;
  number_two = mystack->action_arr[mystack->size].number;
  pop(mystack);
  if (number_two != 0) {
    number_one = mystack->action_arr[mystack->size].number;
    pop(mystack);
    result = fmod(number_one, number_two);
    push_number(mystack, result);
  } else if (number_two == 0) {
    *error_check = 8;
  }
  number_one = number_two = result = 0;
}

/**
 * @brief Calculates sinus of number and adds result to stack.
 *
 * @param mystack - struct array.
 */
void sinus(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = sin(number_one);
  if (number_one == 0) {
    result = 0;
  }
  push_number(mystack, result);
  number_one = result = 0;
}
/**
 * @brief Calculates cosinus of number and adds result to stack.
 *
 * @param mystack - struct array.
 */

void cosinus(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = cos(number_one);
  push_number(mystack, result);
  number_one = result = 0;
}

/**
 * @brief Calculates tangens of number and adds result to stack.
 *
 * @param mystack - struct array.
 */
void tangens(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = tan(number_one);
  push_number(mystack, result);
  number_one = result = 0;
}

/**
 * @brief Calculates arcsinus of number and adds result to stack.
 *
 * @param mystack - struct array.
 */
void arcsinus(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = asin(number_one);
  push_number(mystack, result);
  number_one = result = 0;
}

/**
 * @brief Calculates arccosinus of number and adds result to stack.
 *
 * @param mystack - struct array.
 */
void arccosinus(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = acos(number_one);
  push_number(mystack, result);
  number_one = result = 0;
}

/**
 * @brief Calculates arctangens of number and adds result to stack.
 *
 * @param mystack - struct array.
 */
void arctangens(struct stack *mystack) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  pop(mystack);
  result = atan(number_one);
  push_number(mystack, result);
  number_one = result = 0;
}

/**
 * @brief This function calculates the square root of a number.
 *
 * @param mystack - struct array.
 * @return int error statur
 */
void root(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  if (number_one >= 0) {
    pop(mystack);
    result = sqrt(number_one);
    push_number(mystack, result);
  } else {
    *error_check = 9;
  }
  number_one = result = 0;
}

/**
 * @brief This function calculates the logarithm of a number, and returns error
 * status.
 *
 * @param mystack - struct array.
 * @return int error statur
 */
void logarithm(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  if (number_one > 0) {
    result = log(number_one);
    push_number(mystack, result);
  } else if (number_one == 0) {
    *error_check = 4;
  } else if (number_one < 0) {
    *error_check = 3;
  }
  number_one = result = 0;
}

/**
 * @brief This function calculates the ten-logarithm of a number, and returns
 * error status.
 *
 * @param mystack - struct array.
 * @return int error statur
 */
void ten_logarithm(struct stack *mystack, int *error_check) {
  double number_one = 0;
  double result = 0;
  number_one = mystack->action_arr[mystack->size].number;
  if (number_one > 0) {
    result = log10(number_one);
    push_number(mystack, result);
  } else if (number_one == 0) {
    *error_check = 6;
  } else if (number_one < 0) {
    // result = INFINITY;
    *error_check = 5;
  }
  number_one = result = 0;
}
