CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

OS = $(shell uname)
ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -lm -lsubunit -lpthread
else
	TEST_FLAGS = -lcheck -lm -lpthread
endif

.PHONY: all rebuild checks test gcov_report

all: checks s21_math.a test gcov_report

rebuild: clean all

checks:
	clang-format -style=google -n *.c *.h
	clang-format -style=google -n tests/*.c
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem .


s21_math.a: s21_math.c
	$(CC) $(CFLAGS) -c s21_math.c
	ar -rcs s21_math.a s21_math.o
	ranlib s21_math.a

test: s21_math.c
	$(CC) $(CFLAGS) --coverage -c s21_math.c -o s21_math_test.o
	ar -rcs s21_math_test.a s21_math_test.o
	ranlib s21_math_test.a
	$(CC) $(CFLAGS) -c tests/test_*.c
	$(CC) $(CFLAGS) -c s21_test.c
	$(CC) $(CFLAGS) --coverage test_*.o s21_test.o s21_math_test.a $(TEST_FLAGS) -o s21_test

gcov_report: test
	./s21_test
	lcov -t "coverage" -o unit_test.info -c -d .
	genhtml -o report unit_test.info
	open report/index.html

clean:
	rm -rf *.o *.a *.info *.gcda *.gch *.gcno report s21_test

test_valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all -s ./s21_test
