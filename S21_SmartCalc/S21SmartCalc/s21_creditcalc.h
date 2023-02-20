#ifndef S21_CREDITCALC_H
#define S21_CREDITCALC_H

#include <QMainWindow>

extern "C" {
#include "../s21_calc.h"
}

namespace Ui {
class S21_CreditCalc;
}

class S21_CreditCalc : public QMainWindow {
  Q_OBJECT

 public:
  explicit S21_CreditCalc(QWidget *parent = nullptr);
  ~S21_CreditCalc();
  void credit_calc_calculation();

 private slots:
  void on_pushButton_calculate_clicked();

  void on_clean_clicked();

 private:
  Ui::S21_CreditCalc *ui;
};

#endif  // S21_CREDITCALC_H
