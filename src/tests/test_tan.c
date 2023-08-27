#include "../s21_test.h"

START_TEST(tan_integer_values) {
  ck_assert_float_eq_tol(s21_tan(-6), tan(-6), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_float_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_float_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_float_eq_tol(s21_tan(6), tan(6), 1e-6);
}
END_TEST

START_TEST(tan_float_values) {
  ck_assert_float_eq_tol(s21_tan(-6.14), tan(-6.14), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-1.2563), tan(-1.2563), 1e-6);
  ck_assert_float_eq_tol(s21_tan(0.4), tan(0.4), 1e-6);
  ck_assert_float_eq_tol(s21_tan(1.3), tan(1.3), 1e-6);
  ck_assert_float_eq_tol(s21_tan(5.125), tan(5.125), 1e-6);
  ck_assert_float_eq_tol(s21_tan(S21_PI / 2), tan(S21_PI / 2), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-S21_PI / 2), tan(-S21_PI / 2), 1e-6);
}
END_TEST

START_TEST(tan_greater_period_values) {
  ck_assert_float_eq_tol(s21_tan(-1000), tan(-1000), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-100), tan(-100), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-10), tan(-10), 1e-6);
  ck_assert_float_eq_tol(s21_tan(10), tan(10), 1e-6);
  ck_assert_float_eq_tol(s21_tan(100), tan(100), 1e-6);
  ck_assert_float_eq_tol(s21_tan(1000), tan(1000), 1e-6);
}
END_TEST

START_TEST(tan_nan_value) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(s21_tan(-NAN));
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *s = suite_create("\033[45m-=S21_TAN=-\033[0ms");
  TCase *tc = tcase_create("s21_tan_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, tan_integer_values);
  tcase_add_test(tc, tan_float_values);
  tcase_add_test(tc, tan_greater_period_values);
  tcase_add_test(tc, tan_nan_value);
  return s;
}