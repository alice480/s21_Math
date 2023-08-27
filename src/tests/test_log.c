#include "../s21_test.h"

START_TEST(test_log_1) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(test_log_2) {
  ck_assert_ldouble_nan(s21_log(-S21_INF));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(test_log_3) {
  ck_assert_double_nan(s21_log(-1.0));
  ck_assert_double_nan(log(-1.0));
}
END_TEST

START_TEST(test_log_4) {
  ck_assert_float_eq_tol(s21_log(0.000001), log(0.000001), 1e-5);
}
END_TEST

START_TEST(test_log_5) { ck_assert_double_eq(s21_log(100), log(100)); }
END_TEST

START_TEST(test_log_6) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

START_TEST(test_log_7) {
  ck_assert_double_eq(s21_log(9.399999e20), log(9.399999e20));
}
END_TEST

START_TEST(test_log_8) {
  ck_assert_double_nan(s21_log(-0.000001));
  ck_assert_double_nan(log(-0.000001));
}
END_TEST

START_TEST(test_log_9) {
  ck_assert_ldouble_nan(s21_log(-S21_NAN));
  ck_assert_double_nan(log(-NAN));
}
END_TEST

START_TEST(test_log_10) {
  ck_assert_ldouble_eq_tol(log(987654321.0000123), s21_log(987654321.0000123),
                           1e-7);
}
END_TEST

Suite *test_log(void) {
  Suite *s = suite_create("\033[45m-=S21_LOG=-\033[0m");
  TCase *tc = tcase_create("test_log");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_log_1);
  tcase_add_test(tc, test_log_2);
  tcase_add_test(tc, test_log_3);
  tcase_add_test(tc, test_log_4);
  tcase_add_test(tc, test_log_5);
  tcase_add_test(tc, test_log_6);
  tcase_add_test(tc, test_log_7);
  tcase_add_test(tc, test_log_8);
  tcase_add_test(tc, test_log_9);
  tcase_add_test(tc, test_log_10);

  suite_add_tcase(s, tc);
  return s;
}
