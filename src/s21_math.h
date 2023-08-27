#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PI 3.14159265358979323846264338327950288
#define S21_E 2.71828182845904523536028747
#define S21_EXP_EPS 1e-100
#define S21_ACCURACY 1e-10
#define S21_NAN (0.0 / 0.0)
#define S21_INF (1 / 0.0)
#define S21_MINUS_INF (-1.0 / 0.0)
#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))
#define S21_EXP_EPS 1e-100
#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))
#define S21_EPS 1e-16
#define S21_EPS_T 1e-6
#define MAX_INT 2147483647
#define MIN_INT -2147483646

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

double s21_int_pow(double base, unsigned int exp);
int pow_special_case(double base, double exp, long double *result);

#endif  // SRC_S21_MATH_H_
