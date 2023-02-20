#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "graf.h"
#include "s21_creditcalc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_null, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_add_x, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  // operations()
  connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this,
          SLOT(operations()));
  // clean_clicked()
  connect(ui->pushButton_clean, SIGNAL(clicked()), this,
          SLOT(on_pushButton_clean_clicked()));
  // delite_simbol_clicked()
  connect(ui->pushButton_delite_simbol, SIGNAL(clicked()), this,
          SLOT(on_pushButton_delite_simbol_clicked()));
  // math_operations()
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations()));
  // add_bracket_clicked()
  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(add_bracket()));
  connect(ui->pushButton_clos_bracket, SIGNAL(clicked()), this,
          SLOT(add_bracket()));
  // trigonometry_operations()
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(trigonometry_operations()));
  // other_operations()
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(other_operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(other_operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(other_operations()));

  //
  connect(ui->pushButton_create_graf, SIGNAL(clicked()), this,
          SLOT(on_pushButton_create_graf_clicked()));

  //
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "0") {
    ui->label->setText(ui->label->text() + "0");
  } else if (button->text() == "1") {
    ui->label->setText(ui->label->text() + "1");
  } else if (button->text() == "2") {
    ui->label->setText(ui->label->text() + "2");
  } else if (button->text() == "3") {
    ui->label->setText(ui->label->text() + "3");
  } else if (button->text() == "4") {
    ui->label->setText(ui->label->text() + "4");
  } else if (button->text() == "5") {
    ui->label->setText(ui->label->text() + "5");
  } else if (button->text() == "6") {
    ui->label->setText(ui->label->text() + "6");
  } else if (button->text() == "7") {
    ui->label->setText(ui->label->text() + "7");
  } else if (button->text() == "8") {
    ui->label->setText(ui->label->text() + "8");
  } else if (button->text() == "9") {
    ui->label->setText(ui->label->text() + "9");
  } else if (button->text() == ".") {
    ui->label->setText(ui->label->text() + ".");
  } else if (button->text() == "x") {
    ui->label->setText(ui->label->text() + "x");
  }
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  double all_numbers;
  if (button->text() == "+/-") {
    ui->label->setText(ui->label->text() + "-");
  }
}

void MainWindow::math_operations() {
  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "+") {
    ui->label->setText(ui->label->text() + " + ");
  } else if (button->text() == "-") {
    ui->label->setText(ui->label->text() + " - ");
  } else if (button->text() == "/") {
    ui->label->setText(ui->label->text() + " / ");
  } else if (button->text() == "*") {
    ui->label->setText(ui->label->text() + " * ");
  }
}

void MainWindow::trigonometry_operations() {
  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "sin") {
    ui->label->setText(ui->label->text() + " sin(");
  } else if (button->text() == "arcsin") {
    ui->label->setText(ui->label->text() + " asin(");
  } else if (button->text() == "cos") {
    ui->label->setText(ui->label->text() + " cos(");
  } else if (button->text() == "arccos") {
    ui->label->setText(ui->label->text() + " acos(");
  } else if (button->text() == "tan") {
    ui->label->setText(ui->label->text() + " tan(");
  } else if (button->text() == "arctan") {
    ui->label->setText(ui->label->text() + " atan(");
  } else if (button->text() == "ln") {
    ui->label->setText(ui->label->text() + " ln(");
  } else if (button->text() == "log") {
    ui->label->setText(ui->label->text() + " log(");
  }
}

void MainWindow::on_pushButton_clean_clicked() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "AC") {
    ui->label->setText("");
    ui->line_x->setText("0");
  }
}

void MainWindow::on_pushButton_delite_simbol_clicked() {
  QString all_text = ui->label->text();
  size_t text_len = all_text.length();
  QString copy_all_str = all_text.left(text_len - 1);
  on_pushButton_clean_clicked();
  ui->label->setText(copy_all_str);
}

void MainWindow::add_bracket() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "(") {
    ui->label->setText(ui->label->text() + " (");
  } else if (button->text() == ")") {
    ui->label->setText(ui->label->text() + ") ");
  }
}

void MainWindow::other_operations() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "^") {
    ui->label->setText(ui->label->text() + "^");
  } else if (button->text() == "sqrt") {
    ui->label->setText(ui->label->text() + "sqrt(");
  } else if (button->text() == "mod") {
    ui->label->setText(ui->label->text() + "mod(");
  }
}

void MainWindow::on_pushButton_result_clicked() {
  int check_answer = 0;
  double result = 0;
  QString input_str = ui->label->text();
  std::string str_string = input_str.toStdString();
  char correct_string[2048];

  if (strstr(str_string.c_str(), "x")) {
    std::string str_x = ui->line_x->text().toStdString();
    char c_x_string[150];
    strcpy(c_x_string, str_x.c_str());
    if (check_x_value(c_x_string) == 1) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect x-value-input. Use numbers!");
    } else if (check_x_value(c_x_string) != 1) {
      str_string.replace(str_string.find("x"), 1,
                         ui->line_x->text().toStdString());
    }
  }

  strcpy(correct_string, str_string.c_str());
  check_answer = working_proccess(correct_string, &result);
  if (check_input_data(correct_string, str_string.size()) == 1) {
    QMessageBox::information(this, "ERROR", "Incorrect input-data!");
  } else {
    if (check_answer == 8) {
      QMessageBox::information(
          this, "ERROR", "Incorrect input-data! Division by zero impossible");
    } else if (check_answer == 7) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect input-data for power!");
    } else if (check_answer == 6) {
      QMessageBox::information(
          this, "ERROR",
          "Incorrect input-data for decimal logarithm calculation! If ypur "
          "input is ln(0) - your result will be infinity");
    } else if (check_answer == 5) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect input-data for decimal logarithm "
                               "calculation! Input can't be less then 1");
    } else if (check_answer == 4) {
      QMessageBox::information(
          this, "ERROR",
          "Incorrect input-data for logarithm calculation! Input can't be = 0");
    } else if (check_answer == 3) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect input-data for logarithm "
                               "calculation! Input can't be less then 1");
    } else if (check_answer == 9) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect input-data for sqrt "
                               "calculation! Input can't be less then 0");
    } else if (check_answer == 11) {
      QMessageBox::information(this, "ERROR",
                               "Incorrect input-data for number."
                               "Two points in one number");
    } else if (check_answer == 0) {
      //      working_proccess(correct_string, &result);
      QString valDouble = QString::number(result);
      ui->label->setText(valDouble);
    }
  }
}

void MainWindow::on_pushButton_create_graf_clicked() {
  QString input_str = ui->label->text();

  grafic.show();
  grafic.build_grafic(input_str);
}

void MainWindow::on_pushButton_credit_culc_clicked() { credit_calc.show(); }
