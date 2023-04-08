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
  Suite *s = suite_create("s21_sin");
  TCase *tc = tcase_create("s21_sin_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sin_integer_values);
  tcase_add_test(tc, sin_float_values);
  tcase_add_test(tc, sin_greater_period_values);
  return s;
}

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
  Suite *s = suite_create("s21_cos");
  TCase *tc = tcase_create("s21_cos_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, cos_integer_values);
  tcase_add_test(tc, cos_float_values);
  tcase_add_test(tc, cos_greater_period_values);
  return s;
}

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
  ck_assert_float_eq_tol(s21_tan(M_PI / 2), tan(M_PI / 2), 1e-6);
  ck_assert_float_eq_tol(s21_tan(-M_PI / 2), tan(-M_PI / 2), 1e-6);
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

Suite *test_s21_tan(void) {
  Suite *s = suite_create("s21_tan");
  TCase *tc = tcase_create("s21_tan_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, tan_integer_values);
  tcase_add_test(tc, tan_float_values);
  tcase_add_test(tc, tan_greater_period_values);
  return s;
}

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
  Suite *s = suite_create("s21_asin");
  TCase *tc = tcase_create("s21_asin_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, asin_integer_values);
  tcase_add_test(tc, asin_float_values);
  tcase_add_test(tc, asin_outside_scope_definition_values);
  return s;
}

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
  Suite *s = suite_create("s21_acos");
  TCase *tc = tcase_create("s21_acos_tests");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, acos_integer_values);
  tcase_add_test(tc, acos_float_values);
  tcase_add_test(tc, acos_outside_scope_definition_values);
  return s;
}
