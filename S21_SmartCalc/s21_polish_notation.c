/**
 * @file s21_polish_notation.c
 * @author qylenett (you@domain.com)
 * @brief This is a file with functions which work with tockens array. And parse
 * it to output string and stack. And after add data from stack to output
 * string.
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s21_calc.h"

/**
 * @brief This is a main function of polish notation. If tockens_arr[i] = number
 * we send it to function wich add this number to output string, if
 * tockens_arr[i] = operation or function we add it to stack, after it we decide
 * to pop it to output string or not.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param result - result of calculation.
 * @param error_check - error status.
 */

void polish_notation(struct tockens *tockens, struct stack *mystack,
                     output *output_string, double *result, int *error_check) {
  mystack->size = 0;
  output_string->position = 0;
  *result = 0;
  int position = 0;
  while (position != tockens->index) {
    if (tockens->tocken_arr[position].priority == 0) {
      if_output_number(tockens, output_string, &position);
    } else if (tockens->tocken_arr[position].priority != 0) {
      if_output_not_number(tockens, mystack, output_string, &position,
                           error_check);
    }
  }
  empty_mystack(mystack, output_string);
  *result = calculation_process(mystack, output_string, error_check);
}

/**
 * @brief This function add number to output string.
 *
 * @param tockens - input string parced to struct array with data.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void if_output_number(struct tockens *tockens, output *output_string,
                      int *position) {
  output_string->output_string[output_string->position].number =
      tockens->tocken_arr[*position].number;
  output_string->output_string[output_string->position].priority = 0;
  output_string->position++;
  *position += 1;
}

/**
 * @brief If data are not number this function send data to different functions.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 * @param error_check - error status.
 */
void if_output_not_number(struct tockens *tockens, struct stack *mystack,
                          output *output_string, int *position,
                          int *error_check) {
  // printf("check\n");
  if (tockens->tocken_arr[*position].priority == 6 ||
      tockens->tocken_arr[*position].priority == 5) {
    *error_check = it_is_function(tockens, mystack, output_string, position);
  } else if (tockens->tocken_arr[*position].priority == 4 ||
             tockens->tocken_arr[*position].priority == 3) {
    it_is_operator(tockens, mystack, output_string, position);
  } else if (tockens->tocken_arr[*position].priority == 2 ||
             tockens->tocken_arr[*position].priority == 1) {
    brackets_add(tockens, mystack, output_string, position);
  }
}

/**
 * @brief This function send functions such as sin(x), asin(x), cos(x), acos(x),
 * tan(x), atan(x), sqrt(x), pow(x), mod(x), ln(x), log(x) to stack, and after
 * it add them to output string.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 * @return int - error_check - error status.
 */
int it_is_function(struct tockens *tockens, struct stack *mystack,
                   output *output_string, int *position) {
  int error_code = 0;
  if (tockens->tocken_arr[*position].priority == 6) {
    if (tockens->tocken_arr[*position + 1].priority != 2) {
      error_code = 9;
    } else {
      check_operations_in_oldstring(tockens, mystack, output_string, position);
      *position += 1;
    }
  } else if (tockens->tocken_arr[*position].priority == 5) {
    if (strcmp(tockens->tocken_arr[*position].operation, "^") == 0) {
      pow_processing(tockens, mystack, output_string, position);
    } else {
      check_operations_in_oldstring(tockens, mystack, output_string, position);
      *position += 1;
    }
  }
  return error_code;
}

/**
 * @brief This function decide wich way to make pow process. Polish notation
 * have right-associative pow, so this function dicides priority of pow.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void pow_processing(struct tockens *tockens, struct stack *mystack,
                    output *output_string, int *position) {
  double number_one = 0.0;
  double number_two = 0.0;

  if (tockens->tocken_arr[*position + 2].priority == 1) {
    check_operations_in_oldstring(tockens, mystack, output_string, position);
    *position += 1;
  } else if (tockens->tocken_arr[*position + 2].priority != 1) {
    if (strcmp(tockens->tocken_arr[*position + 2].operation, "^") == 0) {
      number_one = tockens->tocken_arr[*position + 1].number;
      number_two = tockens->tocken_arr[*position + 3].number;
      output_string->output_string[output_string->position].number =
          pow(number_one, number_two);
      output_string->output_string[output_string->position].priority = 0;
      output_string->position += 1;
      strcpy(output_string->output_string[output_string->position].operation,
             "^");
      output_string->output_string[output_string->position].priority = 5;
      output_string->position += 1;
      *position += 4;
    } else {
      check_operations_in_oldstring(tockens, mystack, output_string, position);
      *position += 1;
    }
  }
}

/**
 * @brief This function sends functions such as "/", "*", "-", "+" to stack, and
 * after it add them to output string. And if the oparator id "-", this function
 * checks, if it unar or not. If it unar function sends it to function wich
 * works with unar minus.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void it_is_operator(struct tockens *tockens, struct stack *mystack,
                    output *output_string, int *position) {
  if (tockens->tocken_arr[*position].priority == 4) {
    check_operations_in_oldstring(tockens, mystack, output_string, position);
    output_string->output_string[*position].priority =
        tockens->tocken_arr[*position].priority;
    *position += 1;
  } else if (tockens->tocken_arr[*position].priority == 3) {
    if (strcmp(tockens->tocken_arr[*position].operation, "-") == 0) {
      if ((strcmp(tockens->tocken_arr[0].operation, "-") == 0)) {
        check_unar_minus(tockens, output_string, position);
        check_operations_in_oldstring(tockens, mystack, output_string,
                                      position);
        output_string->output_string[*position].priority =
            tockens->tocken_arr[*position].priority;
        *position += 1;
      } else if (tockens->tocken_arr[*position - 1].priority != 0 &&
                 (tockens->tocken_arr[*position - 1].priority == 3 ||
                  tockens->tocken_arr[*position - 1].priority == 4 ||
                  tockens->tocken_arr[*position - 1].priority == 5 ||
                  tockens->tocken_arr[*position - 1].priority == 2)) {
        check_unar_minus(tockens, output_string, position);
        check_operations_in_oldstring(tockens, mystack, output_string,
                                      position);
        output_string->output_string[*position].priority =
            tockens->tocken_arr[*position].priority;
        *position += 1;
      } else if (tockens->tocken_arr[*position - 1].priority != 0 &&
                 (tockens->tocken_arr[*position - 1].priority == 1)) {
        check_operations_in_oldstring(tockens, mystack, output_string,
                                      position);
        output_string->output_string[*position].priority =
            tockens->tocken_arr[*position].priority;
        *position += 1;
      } else if (tockens->tocken_arr[*position - 1].priority == 0) {
        check_operations_in_oldstring(tockens, mystack, output_string,
                                      position);
        output_string->output_string[*position].priority =
            tockens->tocken_arr[*position].priority;
        *position += 1;
      }
    } else {
      check_operations_in_oldstring(tockens, mystack, output_string, position);
      output_string->output_string[*position].priority =
          tockens->tocken_arr[*position].priority;
      *position += 1;
    }
  }
}

/**
 * @brief This function works with brackets in  tockens array.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void brackets_add(struct tockens *tockens, struct stack *mystack,
                  output *output_string, int *position) {
  if (tockens->tocken_arr[*position].priority == 2) {
    push(mystack, tockens->tocken_arr[*position].operation,
         tockens->tocken_arr[*position].priority);
    *position += 1;
  } else if (tockens->tocken_arr[*position].priority == 1) {
    add_from_stack_to_output(mystack, output_string);
    *position += 1;
  }
}

/**
 * @brief This function works with unar minus, and adds brackes and 0 - number
 * to output string.
 *
 * @param tockens - input string parced to struct array with data.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void check_unar_minus(struct tockens *tockens, output *output_string,
                      int *position) {
  if ((strcmp(tockens->tocken_arr[*position].operation, "-") == 0)) {
    if ((tockens->tocken_arr[*position - 1].priority != 0 ||
         tockens->tocken_arr[*position - 1].priority != 1) &&
        ((tockens->tocken_arr[0].priority == 3 ||
          tockens->tocken_arr[*position - 1].priority == 2 ||
          tockens->tocken_arr[*position - 1].priority == 3 ||
          tockens->tocken_arr[*position - 1].priority == 4 ||
          tockens->tocken_arr[*position - 1].priority == 5))) {
      strcpy(output_string->output_string[output_string->position].operation,
             "(");
      output_string->output_string[output_string->position].priority = 2;
      output_string->position++;
      output_string->output_string[output_string->position].number =
          0.000000000000000000000000000000000000000000000000001;
      output_string->output_string[output_string->position].priority = 0;
      strcpy(output_string->output_string[output_string->position].operation,
             "");
      output_string->position++;
      strcpy(output_string->output_string[output_string->position].operation,
             "-");
      output_string->output_string[output_string->position].priority = 3;
      output_string->position++;
      output_string->output_string[output_string->position].number =
          tockens->tocken_arr[*position + 1].number;
      output_string->position++;
      strcpy(output_string->output_string[output_string->position].operation,
             ")");
      output_string->output_string[output_string->position].priority = 1;
      output_string->position++;
    } else if ((tockens->tocken_arr[*position].priority == 3) &&
               (strcmp(tockens->tocken_arr[*position].operation, "-") == 0) &&
               (tockens->tocken_arr[*position - 1].priority == 0 ||
                output_string->output_string[output_string->position - 1]
                        .priority == 1)) {
      position += 1;
    }
  }
  *position += 1;
}

/**
 * @brief This function works with data tockens array and add them to stack.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */

void check_operations_in_oldstring(struct tockens *tockens,
                                   struct stack *mystack, output *output_string,
                                   int *position) {
  if (tockens->tocken_arr[*position].priority == 4 ||
      tockens->tocken_arr[*position].priority == 3 ||
      tockens->tocken_arr[*position].priority == 5 ||
      tockens->tocken_arr[*position].priority == 6) {
    if (mystack->size == 0) {
      push(mystack, tockens->tocken_arr[*position].operation,
           tockens->tocken_arr[*position].priority);
    } else if (mystack->size > 0) {
      check_operation_in_mystack(tockens, mystack, output_string, position);
    }
  }
}

/**
 * @brief This function works with data in stack. Checks the priority of
 * previous element in stack. Makes pop if it is needed.
 *
 * @param tockens - input string parced to struct array with data.
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 * @param position - position of tockens array.
 */
void check_operation_in_mystack(struct tockens *tockens, struct stack *mystack,
                                output *output_string, int *position) {
  while ((tockens->tocken_arr[*position].priority == 3) &&
         (mystack->action_arr[mystack->size].priority == 3 ||
          mystack->action_arr[mystack->size].priority == 4 ||
          mystack->action_arr[mystack->size].priority == 5 ||
          mystack->action_arr[mystack->size].priority == 6)) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    output_string->position++;
    pop(mystack);
  }
  while ((tockens->tocken_arr[*position].priority == 4) &&
         (mystack->action_arr[mystack->size].priority == 4 ||
          mystack->action_arr[mystack->size].priority == 5 ||
          mystack->action_arr[mystack->size].priority == 6)) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    pop(mystack);
    output_string->position++;
  }
  while (tockens->tocken_arr[*position].priority == 5 &&
         (mystack->action_arr[mystack->size].priority == 5 ||
          mystack->action_arr[mystack->size].priority == 6)) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    pop(mystack);
    output_string->position++;
  }
  while ((tockens->tocken_arr[*position].priority == 6) &&
         (mystack->action_arr[mystack->size].priority == 6)) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    pop(mystack);
    output_string->position++;
  }
  push(mystack, tockens->tocken_arr[*position].operation,
       tockens->tocken_arr[*position].priority);
}

/**
 * @brief This function add data from stack to output if carrent ellement is
 * ")".
 *
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 */

void add_from_stack_to_output(struct stack *mystack, output *output_string) {
  while (mystack->action_arr[mystack->size].priority != 2) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    pop(mystack);
    output_string->position++;
  }
  if (mystack->action_arr[mystack->size].priority == 2) {
    pop(mystack);
  }
}

/**
 * @brief This function add data from stack to output.
 *
 * @param mystack - struct array.
 * @param output_string - struct array with data what need for polish notation
 * work.
 */
void empty_mystack(struct stack *mystack, output *output_string) {
  while (mystack->size > 0) {
    strcpy(output_string->output_string[output_string->position].operation,
           mystack->action_arr[mystack->size].operation);
    pop(mystack);
    output_string->position++;
  }
}
