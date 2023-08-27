#include "../s21_test.h"

START_TEST(test_atan1) {
  long double arr[] = {14.96, -25.1235, 0.23464, 0, 1, -1};
  for (int i = 0; i < 6; i++)
    ck_assert_double_eq_tol(s21_atan(arr[i]), atan(arr[i]), 0.000001);
}
END_TEST

START_TEST(test_atan2) {
  ck_assert_double_eq(s21_atan(INFINITY), atan(INFINITY));
}
END_TEST

START_TEST(test_atan3) {
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(test_atan4) {
  ck_assert_double_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

Suite *test_atan(void) {
  Suite *s = suite_create("\033[45m-=S21_ATAN=-\033[0m");
  TCase *tc = tcase_create("test_atan");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_atan1);
  tcase_add_test(tc, test_atan2);
  tcase_add_test(tc, test_atan3);
  tcase_add_test(tc, test_atan4);

  suite_add_tcase(s, tc);
  return s;
}
