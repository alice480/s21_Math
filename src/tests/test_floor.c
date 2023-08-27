#include "../s21_test.h"

START_TEST(s21_floor_test) {
  ck_assert_ldouble_eq_tol(floor(1.0), s21_floor(1.0), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(0.0), s21_floor(0.0), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(1.8), s21_floor(1.8), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(0.8), s21_floor(0.8), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(-1.0), s21_floor(-1.0), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(-1.8), s21_floor(-1.8), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(-0.8), s21_floor(-0.8), S21_EPS_T);
  ck_assert_ldouble_eq_tol(floor(-21.21), s21_floor(-21.21), S21_EPS_T);
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

Suite *test_floor(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[45m-=S21_FLOOR=-\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_floor_test);
  suite_add_tcase(s, tc_core);
  return s;
}
