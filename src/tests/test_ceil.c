#include "../s21_test.h"

START_TEST(test_ceil1) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), 0.000001);
}
END_TEST

START_TEST(test_ceil2) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), 0.000001);
}
END_TEST

START_TEST(test_ceil3) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(test_ceil4) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(test_ceil5) {
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(test_ceil6) {
  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), 0.000001);
}
END_TEST

Suite *test_ceil(void) {
  Suite *s = suite_create("\033[45m-=S21_CEIL=-\033[0m");
  TCase *tc = tcase_create("test_ceil");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_ceil1);
  tcase_add_test(tc, test_ceil2);
  tcase_add_test(tc, test_ceil3);
  tcase_add_test(tc, test_ceil4);
  tcase_add_test(tc, test_ceil5);
  tcase_add_test(tc, test_ceil6);

  suite_add_tcase(s, tc);
  return s;
}
