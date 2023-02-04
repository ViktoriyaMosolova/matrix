ifeq ($(shell uname -s), Linux)	
	LFLAG += -lpthread -lrt -lm -lsubunit
endif

all: s21_matrix.a

s21_matrix.a:
	gcc -Wall -Wextra -Werror -std=c11 -c s21_*.c
	ar rc s21_matrix.a s21_*.o
	ranlib s21_matrix.a

test: clean s21_matrix.a 
	gcc main.c -o main s21_matrix.a $(LFLAG)
	./main

gcov_report:	
	gcc s21_*.c TEST.c -lcheck -o gcov_report --coverage $(LFLAG)
	./gcov_report
	rm -rf *TEST*.gc*
	gcov *s21_*.c 
	lcov -d . -o gcov_report.info -c
	genhtml -o report gcov_report.info
	open report/index.html

check:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n *.c *.h

leak_style: test
	leaks -atExit -- ./test
	clang-format -n -style=Google *s21_*.c TEST.c

rebuild: clean all

clean:
	rm -f *.gcno *.gcda *.info *.gcov 
	rm -f *.o *.a
	rm -rf report
	rm -f *.out
	rm -f test
	rm -f gcov_report
	rm -f main


