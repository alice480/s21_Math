#include "../s21_test.h"

START_TEST(acos_integer_values) {
  ck_assert_float_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_float_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_float_eq_tol(s21_acos(1), acos(1), 1e-6);
}
END_TEST

START_TEST(acos_float_values) {
  ck_assert_float_eq_tol(s21_acos(-0.9), acos(-0.9), 1e-6);
  ck_assert_float_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-6);
  ck_assert_float_eq_tol(s21_acos(0.5), acos(0.5), 1e-6);
  ck_assert_float_eq_tol(s21_acos(0.9), acos(0.9), 1e-6);
}
END_TEST

START_TEST(acos_outside_scope_definition_values) {
  ck_assert_double_nan(s21_acos(-1000));
  ck_assert_double_nan(s21_acos(-100));
  ck_assert_double_nan(s21_acos(-10));
  ck_assert_double_nan(s21_acos(10));
  ck_assert_double_nan(s21_acos(100));
  ck_assert_double_nan(s21_acos(1000));
}
END_TEST

Suite *test_s21_acos(void) {
  Suite *s = suite_create("\033[45m-=S21_ACOS=-\033[0m");
  TCase *tc = tcase_create("s21_acos_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, acos_integer_values);
  tcase_add_test(tc, acos_float_values);
  tcase_add_test(tc, acos_outside_scope_definition_values);
  return s;
}
