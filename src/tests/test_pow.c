#include "../s21_test.h"

START_TEST(s21_pow_test) {
  double base = 4, exp = 0.5;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_T);
  base = 0.0;
  exp = 100.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_T);
  base = 0.0;
  exp = 0.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_T);
  base = -1;
  exp = 10.0;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS_T);
  base = -1;
  exp = 10.1;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  base = -1;
  exp = 10.2;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  base = -1;
  exp = 1;
  base = -16.161435;
  exp = 9.0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-2);
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-2);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 5));
  ck_assert_ldouble_nan(pow(S21_NAN, INFINITY));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, INFINITY));
  ck_assert_ldouble_nan(pow(S21_NAN, -INFINITY));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -INFINITY));
  ck_assert_ldouble_eq_tol(pow(1, INFINITY), s21_pow(1, INFINITY), S21_EPS_T);
  ck_assert_ldouble_eq_tol(pow(1, -INFINITY), s21_pow(1, -INFINITY), S21_EPS_T);
  ck_assert_ldouble_eq_tol(pow(4, -INFINITY), s21_pow(4, -INFINITY), S21_EPS_T);
  ck_assert_ldouble_eq_tol(pow(0.4, INFINITY), s21_pow(0.4, INFINITY),
                           S21_EPS_T);
  ck_assert_ldouble_eq_tol(pow(0.4, INFINITY), s21_pow(0.4, INFINITY),
                           S21_EPS_T);
  base = 1.5591951;
  exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  base = -S21_INF;
  exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  base = S21_INF;
  exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

Suite *test_pow(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[45m-=S21_POW=-\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_pow_test);
  suite_add_tcase(s, tc_core);
  return s;
}
