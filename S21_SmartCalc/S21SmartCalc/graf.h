#ifndef GRAF_H
#define GRAF_H

#include <string.h>

#include <QMainWindow>
#include <QVector>

#include "qcustomplot.h"

extern "C" {
#include "../s21_calc.h"
}

namespace Ui {
class graf;
}

class graf : public QMainWindow {
  Q_OBJECT

 public:
  explicit graf(QWidget *parent = nullptr);
  ~graf();
  void build_grafic(QString str);

 private slots:

 private:
  Ui::graf *ui;
};

#endif  // GRAF_H
