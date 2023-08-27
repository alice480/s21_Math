#include "../s21_test.h"

START_TEST(test_abs_1) { ck_assert_int_eq(abs(50), s21_abs(50)); }
END_TEST

START_TEST(test_abs_2) { ck_assert_int_eq(abs(-50), s21_abs(-50)); }
END_TEST

START_TEST(test_abs_3) { ck_assert_int_eq(abs(987654321), s21_abs(987654321)); }
END_TEST

START_TEST(test_abs_4) {
  ck_assert_int_eq(abs(-987654321), s21_abs(-987654321));
}
END_TEST

START_TEST(test_abs_5) { ck_assert_int_eq(abs(0), s21_abs(0)); }
END_TEST

START_TEST(test_abs_6) {
  ck_assert_int_eq(abs((int)S21_NAN), s21_abs((int)S21_NAN));
}
END_TEST

START_TEST(test_abs_7) {
  ck_assert_int_eq(abs((int)INFINITY), s21_abs((int)INFINITY));
}
END_TEST

START_TEST(test_abs_8) {
  ck_assert_int_eq(abs((int)-INFINITY), s21_abs((int)-S21_INF));
}
END_TEST

START_TEST(test_abs_9) { ck_assert_int_eq(abs(+0), s21_abs(+0)); }
END_TEST

START_TEST(test_abs_10) { ck_assert_int_eq(abs(-0), s21_abs(-0)); }
END_TEST

Suite *test_abs(void) {
  Suite *s = suite_create("\033[45m-=S21_ABS=-\033[0m");
  TCase *tc = tcase_create("test_log");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_abs_1);
  tcase_add_test(tc, test_abs_2);
  tcase_add_test(tc, test_abs_3);
  tcase_add_test(tc, test_abs_4);
  tcase_add_test(tc, test_abs_5);
  tcase_add_test(tc, test_abs_6);
  tcase_add_test(tc, test_abs_7);
  tcase_add_test(tc, test_abs_8);
  tcase_add_test(tc, test_abs_9);
  tcase_add_test(tc, test_abs_10);
  suite_add_tcase(s, tc);
  return s;
}
