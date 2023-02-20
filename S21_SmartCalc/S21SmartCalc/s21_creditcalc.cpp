#include "s21_creditcalc.h"

#include "ui_s21_creditcalc.h"

S21_CreditCalc::S21_CreditCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::S21_CreditCalc) {
  ui->setupUi(this);

  int time = 0, credit_sum = 0, credit_type;
  double rate = 0;
}

void S21_CreditCalc::on_pushButton_calculate_clicked() {
  credit_calc_calculation();
}

void S21_CreditCalc::credit_calc_calculation() {
  int time = 0, credit_type = 0;
  double rate = 0, credit_sum = 0;

  QString Qsum = ui->credit_sum->text();
  credit_sum = Qsum.toDouble();

  QString Qtime = ui->time->text();
  time = Qtime.toInt();

  QString Qrate = ui->rate->text();
  rate = Qrate.toDouble();

  QString Qtype = ui->type->text();
  credit_type = Qtype.toInt();

  double first_pay = 0, last_pay = 0, overpay = 0, final_sum = 0;

  s21_credit_calc(credit_sum, time, rate, credit_type, &first_pay, &last_pay,
                  &overpay, &final_sum);

  std::string str_final_sum = std::to_string(final_sum);
  char *c_str_final_sum = new char[str_final_sum.length() + 1];
  strcpy(c_str_final_sum, str_final_sum.c_str());

  std::string str_overpay = std::to_string(overpay);
  char *c_str_overpay = new char[str_overpay.length() + 1];
  strcpy(c_str_overpay, str_overpay.c_str());

  std::string str_last_pay = std::to_string(last_pay);
  char *c_str_last_pay = new char[str_last_pay.length() + 1];
  strcpy(c_str_last_pay, str_last_pay.c_str());

  std::string str_first_pay = std::to_string(first_pay);
  char *c_str_first_pay = new char[str_first_pay.length() + 1];
  strcpy(c_str_first_pay, str_first_pay.c_str());

  ui->final_sum->setText(c_str_final_sum);
  ui->overpay->setText(c_str_overpay);
  ui->First_pay->setText(c_str_first_pay);
  ui->Last_pay->setText(c_str_last_pay);
}

void S21_CreditCalc::on_clean_clicked() {
  ui->final_sum->setText("0");
  ui->overpay->setText("0");
  ui->First_pay->setText("0");
  ui->Last_pay->setText("0");
}

S21_CreditCalc::~S21_CreditCalc() { delete ui; }
