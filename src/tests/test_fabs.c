#include "../s21_test.h"

START_TEST(test_fabs_1) { ck_assert_ldouble_eq(fabs(50.0), s21_fabs(50.0)); }
END_TEST

START_TEST(test_fabs_2) { ck_assert_ldouble_eq(fabs(-50.0), s21_fabs(-50.0)); }
END_TEST

START_TEST(test_fabs_3) {
  ck_assert_ldouble_eq(fabs(987654321987654321.123456),
                       s21_fabs(987654321987654321.123456));
}
END_TEST

START_TEST(test_fabs_4) {
  ck_assert_ldouble_eq(fabs(-987654321987654321.123456),
                       s21_fabs(-987654321987654321.123456));
}
END_TEST

START_TEST(test_fabs_5) { ck_assert_ldouble_eq(fabs(0.0), s21_fabs(0.0)); }
END_TEST

START_TEST(test_fabs_6) {
  ck_assert_ldouble_nan(fabs((double)NAN));
  ck_assert_ldouble_nan(s21_fabs((double)S21_NAN));
}
END_TEST

START_TEST(test_fabs_7) {
  ck_assert_ldouble_eq(fabs((double)INFINITY), s21_fabs((double)S21_INF));
}
END_TEST

START_TEST(test_fabs_8) {
  ck_assert_ldouble_eq(fabs((double)-INFINITY), s21_fabs((double)-S21_INF));
}
END_TEST

START_TEST(test_fabs_9) { ck_assert_ldouble_eq(fabs(+0.0), s21_fabs(+0.0)); }
END_TEST

START_TEST(test_fabs_10) { ck_assert_ldouble_eq(fabs(-0.0), s21_fabs(-0.0)); }
END_TEST

Suite *test_fabs(void) {
  Suite *s = suite_create("\033[45m-=S21_FABS=-\033[0m");
  TCase *tc = tcase_create("test_log");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_fabs_1);
  tcase_add_test(tc, test_fabs_1);
  tcase_add_test(tc, test_fabs_2);
  tcase_add_test(tc, test_fabs_3);
  tcase_add_test(tc, test_fabs_4);
  tcase_add_test(tc, test_fabs_5);
  tcase_add_test(tc, test_fabs_6);
  tcase_add_test(tc, test_fabs_7);
  tcase_add_test(tc, test_fabs_8);
  tcase_add_test(tc, test_fabs_9);
  tcase_add_test(tc, test_fabs_10);

  suite_add_tcase(s, tc);
  return s;
}
