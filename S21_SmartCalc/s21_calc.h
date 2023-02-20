#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define STACK_MAX_SIZE 1000

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101

typedef struct tocken {
  double number;
  char operation[5];
  int priority;
} tocken;

typedef struct tockens {
  struct tocken tocken_arr[255];
  int index;
} tockens;

typedef struct stack {
  struct tocken action_arr[STACK_MAX_SIZE];
  size_t size;
} stack;

typedef struct output {
  struct tocken output_string[255];
  int position;
} output;

// validation
int check_input_data(char *input_string, int input_str_len);
int check_x_value(char *x_value);
int Validator(char *str);

// parser
int working_proccess(char *input_string, double *result);
void find_patterns(char *input_string, struct tockens *tockens,
                   int input_str_len);
int is_number(char simbol);
int is_function(char simbol);
int is_operation(char simbol);
int check_priority(char *buffer_str);

// polish_notation
void polish_notation(struct tockens *tockens, struct stack *mystack,
                     output *output_string, double *result, int *error_check);
void if_output_number(struct tockens *tockens, output *output_string,
                      int *position);
void if_output_not_number(struct tockens *tockens, struct stack *mystack,
                          output *output_string, int *position,
                          int *error_check);
void check_unar_minus(struct tockens *tockens, output *output_string,
                      int *position);
int it_is_function(struct tockens *tockens, struct stack *mystack,
                   output *output_string, int *position);
void it_is_operator(struct tockens *tockens, struct stack *mystack,
                    output *output_string, int *position);
void brackets_add(struct tockens *tockens, struct stack *mystack,
                  output *output_string, int *position);
void pow_processing(struct tockens *tockens, struct stack *mystack,
                    output *output_string, int *position);

void check_operations_in_oldstring(struct tockens *tockens,
                                   struct stack *mystack, output *output_string,
                                   int *position);
void check_operation_in_mystack(struct tockens *tockens, struct stack *mystack,
                                output *output_string, int *position);
void add_from_stack_to_output(struct stack *mystack, output *output_string);
void empty_mystack(struct stack *mystack, output *output_string);

// calculation
double calculation_process(struct stack *mystack, output *output_string,
                           int *error_check);
void check_operation(struct stack *mystack, output *output_string,
                     int *position, int *error_check);
void negative_number(struct stack *mystack, output *output_string,
                     int *position);
void summer(struct stack *mystack);
void subtraction(struct stack *mystack);
void multiplication(struct stack *mystack);
void division(struct stack *mystack, int *error_check);
void power(struct stack *mystack, int *error_check);
void div_reminder(struct stack *mystack, int *error_check);
void sinus(struct stack *mystack);
void cosinus(struct stack *mystack);
void tangens(struct stack *mystack);
void arcsinus(struct stack *mystack);
void arccosinus(struct stack *mystack);
void arctangens(struct stack *mystack);
void root(struct stack *mystack, int *error_check);
void logarithm(struct stack *mystack, int *error_check);
void ten_logarithm(struct stack *mystack, int *error_check);

// additional_fank

// void print_tockens_arr(struct tockens tockens);
// void print_all_stack(struct stack *mystak);
// void print_output_arr(output output_string);
// int check_stack_size(struct stack *mystack);
// void copy_null_tockens(struct tockens* tockens);
void push(struct stack *mystack, char *action, int priority);
void pop(struct stack *mystac);
void push_number(struct stack *mystack, double number);

// credit_calc
void s21_credit_calc(double total_amount, int time, double percent, int type,
                     double *first_pay, double *last_pay, double *overpay,
                     double *final_sum);

#endif  // SRC_S21_CALC_H_

// операция            приоритет
// число                 0
// cos(x)                6
// sin(x)                6
// tan(x)                6
// acos(x)               6
// asin(x)               6
// atan(x)               6
// sqrt(x)               6
// ln(x)                 6
// log(x)                6
// mod                   5
// ^                     5
// *                     4
// /                     4
// +                     3
// -                     3
// (                     2
// )                     1
