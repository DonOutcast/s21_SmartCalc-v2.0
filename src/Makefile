.PHONY: clean, rebuild, check
CC = gcc 
CFLAGC =  -Wall -Werror -Wextra -lstdc++ -std=c++17
SOURCES = model/model.cc controller/controller.cc 
OBJECTS = model.o controller.o


all: build static

build:
	$(CC) $(CFLAGC) -c $(SOURCES)

static:
	ar rc s21_calc.a $(OBJECTS)
	ranlib s21_calc.a
tests:
	$(CC) $(CFLAGC) -lcheck  unit_test.c s21_calc.a -o test
	./test

gcov_report:
	gcc $(WWW) -lcheck --coverage *.c -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	open ./report/index.html

install:
	make clean
	mkdir build
	cd view/ && qmake && make && make clean && rm Makefile  && mv view.app ../build/
	

uninstall:
	@rm -rf build*

dvi:
	open dvi.tex

dist:
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	mv  ./build/view.app  Archive_SmartCalc_v2.0/src/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	rm -rf Archive_SmartCalc_v2.0/



clean:
	@rm -rf *.{a,o,dSYM,out}
	@rm -rf $(EXECUTABLE)
	@rm -rf gcov_report
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf Archive_SmartCalc_v2.0 
	@rm -rf *tgz
	@rm -rf build
	@clear
	

rebuild: clean all

