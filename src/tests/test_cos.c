#include "../s21_test.h"

START_TEST(cos_integer_values) {
  ck_assert_float_eq_tol(s21_cos(-6), cos(-6), 1e-6);
  ck_assert_float_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_float_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_float_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_float_eq_tol(s21_cos(6), cos(6), 1e-6);
}
END_TEST

START_TEST(cos_float_values) {
  ck_assert_float_eq_tol(s21_cos(-6.14), cos(-6.14), 1e-6);
  ck_assert_float_eq_tol(s21_cos(-1.2563), cos(-1.2563), 1e-6);
  ck_assert_float_eq_tol(s21_cos(0.4), cos(0.4), 1e-6);
  ck_assert_float_eq_tol(s21_cos(1.3), cos(1.3), 1e-6);
  ck_assert_float_eq_tol(s21_cos(5.125), cos(5.125), 1e-6);
}
END_TEST

START_TEST(cos_greater_period_values) {
  ck_assert_float_eq_tol(s21_cos(-1000), cos(-1000), 1e-6);
  ck_assert_float_eq_tol(s21_cos(-100), cos(-100), 1e-6);
  ck_assert_float_eq_tol(s21_cos(-10), cos(-10), 1e-6);
  ck_assert_float_eq_tol(s21_cos(10), cos(10), 1e-6);
  ck_assert_float_eq_tol(s21_cos(100), cos(100), 1e-6);
  ck_assert_float_eq_tol(s21_cos(1000), cos(1000), 1e-6);
}
END_TEST

Suite *test_s21_cos(void) {
  Suite *s = suite_create("\033[45m-=S21_COS=-\033[0m");
  TCase *tc = tcase_create("s21_cos_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, cos_integer_values);
  tcase_add_test(tc, cos_float_values);
  tcase_add_test(tc, cos_greater_period_values);
  return s;
}