FLAGS_ER = -Wall -Wextra -Werror -std=c11
FSANIT = -fsanitize=address -pedantic
FLAGS_TEST = -lcheck -lgcov -coverage
FLAG_COV = -lcheck -lgcov -fprofile-arcs --coverage

.PHONY: all o_files gcov_report html clean fclean lint asan


all: s21_calc.a tests gcov_report

tests: s21_calc.a
	gcc s21_calc.a polish_tests.c $(FLAGS_TEST) -o test
	./test

gcov_report: tests
	gcc -o test s21_calc.a -lcheck *.c $(FLAG_COV)
	./test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info;
	open report/index.html

clean: fclean
	rm -rf s21_calc.a ./test

install: clean
	cd ./S21SmartCalc/ && cmake . && $(MAKE) all
	make copy
	make run

copy:
	cp -rf S21SmartCalc/S21SmartCalc.app $(HOME)/Desktop/S21SamartCalc.app 

run:
	open $(HOME)/Desktop/S21SamartCalc.app 

uninstall: clean
	rm -rf S21SmartCalc/S21SmartCalc.app
	rm -rf S21SmartCalc/CMakeFiles
	rm -rf S21SmartCalc/Makefile
	rm -rf S21SmartCalc/S21SmartCalc_autogen
	rm -rf S21SmartCalc/CMakeCache.txt
	rm -rf S21SmartCalc/cmake_install.cmake
	rm -rf $(HOME)/Desktop/S21SamartCalc

dist: install
	tar --totals -cvf S21SMARTCALC.tar S21SmartCalc/S21SmartCalc.app/Contents/MacOS/S21SmartCalc
dvi:
	doxygen . && open html/index.html


s21_calc.a: o_files
	ar rcs s21_calc.a *.o
	ranlib s21_calc.a

calc_t:
	gcc -g s21_string_parser.c s21_string_validation.c s21_polish_notation.c s21_additional_fanctions.c s21_calculation_proc.c -o calc

o_files: 
	gcc -c s21_string_parser.c s21_string_validation.c s21_polish_notation.c s21_additional_fanctions.c s21_calculation_proc.c s21_credit_calc.c

fclean:
	rm -rf *.o *.info *.gcda *.gcno s21_matrix/*.dSYM s21_matrix/*.gcda s21_matrix/*.gcno report _out.txt _valgrind-out.txt *.dSYM

clang:

	clang-format -i *.c
	clang-format -n *.c
	clang-format -i *.h
	clang-format -n *.h

# asan:
# 	gcc -fsanitize=address -g -c $(FLAGS_ER) *.c
# 	ar rcs s21_calc.a *.o
# 	ranlib s21_calc.a
# 	gcc -fsanitize=address -g $(FLAGS_ER) s21_calc.a polish_tests.c $(FLAGS_TEST) -o test



