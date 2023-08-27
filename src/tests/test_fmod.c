#include "../s21_test.h"

START_TEST(test_fmod1) {
  ck_assert_double_nan(s21_fmod(NAN, NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(test_fmod2) {
  ck_assert_double_nan(s21_fmod(-INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(test_fmod3) {
  ck_assert_double_nan(s21_fmod(-INFINITY, INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, INFINITY));
}
END_TEST

START_TEST(test_fmod4) {
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(test_fmod5) {
  ck_assert_double_nan(s21_fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(NAN, INFINITY));
}
END_TEST

START_TEST(test_fmod6) {
  ck_assert_double_nan(s21_fmod(-INFINITY, NAN));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(test_fmod7) {
  ck_assert_double_nan(s21_fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
}
END_TEST

START_TEST(test_fmod8) {
  ck_assert_double_nan(s21_fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(INFINITY, NAN));
}
END_TEST

START_TEST(test_fmod9) {
  ck_assert_double_nan(s21_fmod(INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(INFINITY, -INFINITY));
}
END_TEST

START_TEST(test_fmod10) {
  ck_assert_double_nan(s21_fmod(INFINITY, 3));
  ck_assert_double_nan(fmod(INFINITY, 3));
}
END_TEST

START_TEST(test_fmod11) {
  ck_assert_double_nan(s21_fmod(-INFINITY, 2));
  ck_assert_double_nan(fmod(-INFINITY, 2));
}
END_TEST

START_TEST(test_fmod12) {
  ck_assert_double_nan(s21_fmod(NAN, 1));
  ck_assert_double_nan(fmod(NAN, 1));
}
END_TEST

START_TEST(test_fmod13) {
  ck_assert_double_eq(s21_fmod(100, INFINITY), fmod(100, INFINITY));
}
END_TEST

START_TEST(test_fmod14) {
  ck_assert_double_eq(s21_fmod(100, -INFINITY), fmod(100, -INFINITY));
}
END_TEST

START_TEST(test_fmod15) {
  ck_assert_double_eq(s21_fmod(0, INFINITY), fmod(0, INFINITY));
}
END_TEST

START_TEST(test_fmod16) {
  ck_assert_double_eq(s21_fmod(0, -INFINITY), fmod(0, -INFINITY));
}
END_TEST

START_TEST(test_fmod17) {
  ck_assert_double_nan(s21_fmod(0, NAN));
  ck_assert_double_nan(fmod(0, NAN));
}
END_TEST

START_TEST(test_fmod18) {
  ck_assert_double_nan(s21_fmod(INFINITY, 0));
  ck_assert_double_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(test_fmod19) {
  ck_assert_double_nan(s21_fmod(-INFINITY, 0));
  ck_assert_double_nan(fmod(-INFINITY, 0));
}
END_TEST

START_TEST(test_fmod20) {
  ck_assert_double_nan(s21_fmod(NAN, 0));
  ck_assert_double_nan(fmod(NAN, 0));
}
END_TEST

START_TEST(test_fmod21) {
  long double f_value[] = {4234, 20,      234,    -756,   435,    24.342, 345,
                           645,  2.24234, 53.534, 6456,   1,      0,      -1,
                           34,   64,      9786,   534.53, 756.56, 754};
  long double s_value[] = {8898.07,  6881.63, 1537.52, 5783.31, 2675.7,
                           5560.06,  1240.69, 9348.66, 103.02,  4153.9,
                           250,      29.3,    96.456,  86,      29.5,
                           302.0234, 1,       1947.38, 953,     42};
  for (int i = 0; i < 20; i++) {
    ck_assert_double_eq_tol(s21_fmod(f_value[i], s_value[i]),
                            fmod(f_value[i], s_value[i]), 0.000001);
  }
}

Suite *test_fmod(void) {
  Suite *s = suite_create("\033[45m-=S21_FMOD=-\033[0m");
  TCase *tc = tcase_create("test_fmod");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_fmod1);
  tcase_add_test(tc, test_fmod2);
  tcase_add_test(tc, test_fmod3);
  tcase_add_test(tc, test_fmod4);
  tcase_add_test(tc, test_fmod5);
  tcase_add_test(tc, test_fmod6);
  tcase_add_test(tc, test_fmod7);
  tcase_add_test(tc, test_fmod8);
  tcase_add_test(tc, test_fmod9);
  tcase_add_test(tc, test_fmod10);
  tcase_add_test(tc, test_fmod11);
  tcase_add_test(tc, test_fmod12);
  tcase_add_test(tc, test_fmod13);
  tcase_add_test(tc, test_fmod14);
  tcase_add_test(tc, test_fmod15);
  tcase_add_test(tc, test_fmod16);
  tcase_add_test(tc, test_fmod17);
  tcase_add_test(tc, test_fmod18);
  tcase_add_test(tc, test_fmod19);
  tcase_add_test(tc, test_fmod20);
  tcase_add_test(tc, test_fmod21);

  suite_add_tcase(s, tc);
  return s;
}
