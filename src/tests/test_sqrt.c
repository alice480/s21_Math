#include "../s21_test.h"

START_TEST(test_sqrt1) {
  ck_assert_double_nan(s21_sqrt(-0.01));
  ck_assert_double_nan(sqrt(-0.01));
}
END_TEST

START_TEST(test_sqrt2) {
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(test_sqrt3) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(test_sqrt4) {
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(test_sqrt5) {
  ck_assert_double_nan(s21_sqrt(-231.41));
  ck_assert_double_nan(sqrt(-231.41));
}
END_TEST

START_TEST(test_sqrt6) {
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     0.0001,
                       21345678, 7432,      0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), 0.000001);
  }
}

Suite *test_sqrt(void) {
  Suite *s = suite_create("\033[45m-=S21_SQRT=-\033[0m");
  TCase *tc = tcase_create("test_sqrt");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sqrt1);
  tcase_add_test(tc, test_sqrt2);
  tcase_add_test(tc, test_sqrt3);
  tcase_add_test(tc, test_sqrt4);
  tcase_add_test(tc, test_sqrt5);
  tcase_add_test(tc, test_sqrt6);

  suite_add_tcase(s, tc);
  return s;
}
