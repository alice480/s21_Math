#include "../s21_test.h"

START_TEST(asin_integer_values) {
  ck_assert_float_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_float_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_float_eq_tol(s21_asin(1), asin(1), 1e-6);
}
END_TEST

START_TEST(asin_float_values) {
  ck_assert_float_eq_tol(s21_asin(-0.9), asin(-0.9), 1e-6);
  ck_assert_float_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
  ck_assert_float_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_float_eq_tol(s21_asin(0.9), asin(0.9), 1e-6);
}
END_TEST

START_TEST(asin_outside_scope_definition_values) {
  ck_assert_double_nan(s21_asin(-1000));
  ck_assert_double_nan(s21_asin(-100));
  ck_assert_double_nan(s21_asin(-10));
  ck_assert_double_nan(s21_asin(10));
  ck_assert_double_nan(s21_asin(100));
  ck_assert_double_nan(s21_asin(1000));
}
END_TEST

Suite *test_s21_asin(void) {
  Suite *s = suite_create("\033[45m-=S21_ASIN=-\033[0m");
  TCase *tc = tcase_create("s21_asin_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, asin_integer_values);
  tcase_add_test(tc, asin_float_values);
  tcase_add_test(tc, asin_outside_scope_definition_values);
  return s;
}