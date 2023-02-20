/**
 * @file s21_additional_fanctions.c
 * @author qylenett (you@domain.com)
 * @brief Additinal functions
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s21_calc.h"

// void print_tockens_arr(struct tockens tockens) {
//   for (int i = 0; i < tockens.index; i++)
//     printf("%f\t %s\t %d\t %d \n", tockens.tocken_arr[i].number,
//            tockens.tocken_arr[i].operation, tockens.tocken_arr[i].priority,
//            tockens.index);
// }

// void print_output_arr(output output_string) {
//   for (int i = 0; i < output_string.position; i++)
//     if (output_string.output_string[i].number) {
//       printf("%f\n", output_string.output_string[i].number);
//     } else {
//       printf("%s\n", output_string.output_string[i].operation);
//     }
// }

// void print_all_stack(struct stack *mystak) {
//   for (int i = 0; i < mystak->size; i++)
//     printf("priority:%d\toperation:%s\n", mystak->action_arr[i].priority,
//            mystak->action_arr[i].operation);
// }

// int check_stack_size(struct stack *mystack) {
//   int result = 0;
//   if (mystack->size != 0) {
//     result = mystack->size;
//   }
//   return result;
// }

/**
 * @brief Push operation to stack.
 *
 * @param mystack - stack.
 * @param action - operation
 * @param priority - priority of operation.
 */
void push(struct stack *mystack, char *action, int priority) {
  if (mystack->size >= STACK_MAX_SIZE) {
    exit(STACK_OVERFLOW);
  }
  mystack->size++;
  strcpy(mystack->action_arr[mystack->size].operation, action);
  mystack->action_arr[mystack->size].priority = priority;
}

/**
 * @brief Pop datafrom stack.
 *
 * @param mystack
 */
void pop(struct stack *mystack) {
  if (mystack->size == 0) {
    exit(STACK_UNDERFLOW);
  }
  mystack->size--;
}

/**
 * @brief Push number to stack.
 *
 * @param mystack
 * @param number
 */
void push_number(struct stack *mystack, double number) {
  if (mystack->size >= STACK_MAX_SIZE) {
    exit(STACK_OVERFLOW);
  }
  mystack->size++;
  mystack->action_arr[mystack->size].number = number;
}
