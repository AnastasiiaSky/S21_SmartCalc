#include "graf.h"

#include <qmath.h>

#include <QVector>
#include <QtMath>
#include <iostream>

#include "qcustomplot.h"
#include "ui_graf.h"

graf::graf(QWidget *parent) : QMainWindow(parent), ui(new Ui::graf) {
  ui->setupUi(this);
}

void graf::build_grafic(QString str) {
  ui->widget->clearGraphs();
  int check_answer = 0;

  QVector<double> X, Y;

  QString q_step = ui->step->text();
  QString q_min_x = ui->X_min_option->text();  // min_x
  QString q_min_y = ui->Y_min_option->text();  // min_y
  QString q_max_x = ui->X_max_option->text();  // max_x
  QString q_max_y = ui->Y_min_option->text();  // max_y

  double x = 0, y = 0;

  double d_step = q_step.toDouble();
  double d_min_x = q_min_x.toDouble();
  double d_min_y = q_min_y.toDouble();
  double d_max_x = q_max_x.toDouble();
  double d_max_y = q_max_y.toDouble();

  ui->widget->xAxis->setRange(-20, 20);
  ui->widget->yAxis->setRange(-10, 10);

  for (x = d_min_x; x <= d_max_x; x += d_step) {
    double y_result = 0;

    char correct_string[255] = {0};
    std::string str_string = str.toStdString();

    if (strstr(str_string.c_str(), "x")) {
      std::string str_x = std::to_string(x);
      char c_x_string[30] = {0};
      strcpy(c_x_string, str_x.c_str());
      str_string.replace(str_string.find("x"), 1, c_x_string);
    }

    strcpy(correct_string, str_string.c_str());

    check_answer = working_proccess(correct_string, &y_result);
    if (check_answer == 5 || check_answer == 3) {
      d_min_x = 0;
      x = 0;
      y_result = INFINITY;
    }

    X.push_back(x);
    Y.push_back(y_result);

    //      delete[] correct_string;
  }

  ui->widget->addGraph();  // добавляем график на виджет
  ui->widget->graph(0)->addData(
      X, Y);  // передодим в аддДата х, у,// обращаемся к этому графику и
              // устfнавливаем ему значение
  ui->widget->replot();  // функцией реплот нарисуем график
  //    ui->domain_res->setText(result);      // выводим текст с главного поля
  //    ui->line_x->clear();                  // удоляем данные с полей
  //    ui->result->clear();
}

graf::~graf() { delete ui; }
