/**
 * @file s21_credit_calc.c
 * @author qylenett (you@domain.com)
 * @brief This file make credit-calculation.
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "s21_calc.h"

/**
 * @brief This function make credit-calculation.
 *
 * @param total_amount - total sum of credit.
 * @param time - time in months.
 * @param percent - percent.
 * @param type - 1 - annuity, 0 - differentiated
 * @param first_pay - sum of first pay.
 * @param last_pay - sum of last pay.
 * @param overpay - total overpay.
 * @param final_sum - total sum wich user get with overpay.
 */

void s21_credit_calc(double total_amount, int time, double percent, int type,
                     double *first_pay, double *last_pay, double *overpay,
                     double *final_sum) {
  double monthly_rate = 0;
  monthly_rate = percent / (100 * 12);

  if (type == 1) {
    *last_pay =
        total_amount * (monthly_rate / (1 - pow((1 + monthly_rate), -(time))));
    *first_pay = *last_pay;
    *final_sum = *last_pay * time;
    *overpay = *final_sum - total_amount;
  } else {
    double rate = 0;
    double sum_balance = total_amount;
    *overpay = 0;

    for (int i = 1; sum_balance > 0; i++) {
      rate = sum_balance * ((percent / 100) * 0.08333333);
      sum_balance = sum_balance - (total_amount / time);
      *overpay += rate;
      *last_pay = total_amount / time + rate;
      *final_sum = total_amount + *overpay;
      if (i == 1) {
        *first_pay = *last_pay;
      }
    }
  }
}
