#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string.h>

#include <QVector>
#include <iostream>

#include "graf.h"
#include "s21_creditcalc.h"

extern "C" {
#include "../s21_calc.h"
}

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

  graf grafic;
  S21_CreditCalc credit_calc;

 private slots:
  void digits_numbers();
  void operations();
  void on_pushButton_clean_clicked();
  void on_pushButton_result_clicked();
  void math_operations();
  void on_pushButton_delite_simbol_clicked();
  void trigonometry_operations();
  void add_bracket();
  void other_operations();
  void on_pushButton_create_graf_clicked();
  void on_pushButton_credit_culc_clicked();
};
#endif  // MAINWINDOW_H
