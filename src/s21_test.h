#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

Suite *test_log(void);
Suite *test_abs(void);
Suite *test_fabs(void);
Suite *test_atan(void);
Suite *test_ceil(void);
Suite *test_exp(void);
Suite *test_fmod(void);
Suite *test_sqrt(void);
Suite *test_s21_sin(void);
Suite *test_s21_cos(void);
Suite *test_s21_tan(void);
Suite *test_s21_asin(void);
Suite *test_s21_acos(void);
Suite *test_pow(void);
Suite *test_floor(void);

#endif  // SRC_S21_TEST_H
