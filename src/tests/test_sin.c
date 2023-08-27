#include "../s21_test.h"

START_TEST(sin_integer_values) {
  ck_assert_float_eq_tol(s21_sin(-6), sin(-6), 1e-6);
  ck_assert_float_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_float_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_float_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_float_eq_tol(s21_sin(6), sin(6), 1e-6);
}
END_TEST

START_TEST(sin_float_values) {
  ck_assert_float_eq_tol(s21_sin(-6.14), sin(-6.14), 1e-6);
  ck_assert_float_eq_tol(s21_sin(-1.2563), sin(-1.2563), 1e-6);
  ck_assert_float_eq_tol(s21_sin(0.4), sin(0.4), 1e-6);
  ck_assert_float_eq_tol(s21_sin(1.3), sin(1.3), 1e-6);
  ck_assert_float_eq_tol(s21_sin(5.125), sin(5.125), 1e-6);
}
END_TEST

START_TEST(sin_greater_period_values) {
  ck_assert_float_eq_tol(s21_sin(-1000), sin(-1000), 1e-6);
  ck_assert_float_eq_tol(s21_sin(-100), sin(-100), 1e-6);
  ck_assert_float_eq_tol(s21_sin(-10), sin(-10), 1e-6);
  ck_assert_float_eq_tol(s21_sin(10), sin(10), 1e-6);
  ck_assert_float_eq_tol(s21_sin(100), sin(100), 1e-6);
  ck_assert_float_eq_tol(s21_sin(1000), sin(1000), 1e-6);
}
END_TEST

Suite *test_s21_sin(void) {
  Suite *s = suite_create("\033[45m-=S21_SIN=-\033[0m");
  TCase *tc = tcase_create("s21_sin_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sin_integer_values);
  tcase_add_test(tc, sin_float_values);
  tcase_add_test(tc, sin_greater_period_values);
  return s;
}