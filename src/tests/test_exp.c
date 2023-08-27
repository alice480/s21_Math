#include "../s21_test.h"

START_TEST(test_exp1) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST

START_TEST(test_exp2) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), 0.000001);
}
END_TEST

START_TEST(test_exp3) { ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY)); }
END_TEST

START_TEST(test_exp4) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(test_exp5) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(test_exp6) { ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001); }
END_TEST

START_TEST(test_exp7) { ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001); }
END_TEST

START_TEST(test_exp8) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);
}
END_TEST

Suite *test_exp(void) {
  Suite *s = suite_create("\033[45m-=S21_EXP=-\033[0m");
  TCase *tc = tcase_create("test_atan");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_exp1);
  tcase_add_test(tc, test_exp2);
  tcase_add_test(tc, test_exp3);
  tcase_add_test(tc, test_exp4);
  tcase_add_test(tc, test_exp5);
  tcase_add_test(tc, test_exp6);
  tcase_add_test(tc, test_exp7);
  tcase_add_test(tc, test_exp8);

  suite_add_tcase(s, tc);
  return s;
}
