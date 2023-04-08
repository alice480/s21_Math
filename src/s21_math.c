#include "s21_math.h"

#include <math.h>

#define PI 3.1415926535897932
#define ACCURACY 1e-10

double period_limitation(double x) {
  int count = x / (2 * PI);
  return x - 2 * PI * count;
}

long double s21_sin(double x) {
  x = period_limitation(x);
  long double sin_value = 0;
  long double member = x;
  int n = 1;
  while (member < ACCURACY * -1 || ACCURACY < member) {
    sin_value += member;
    member = member * (-1) * (x * x) / (2 * n * (2 * n + 1));
    n += 1;
  }
  return sin_value;
}

long double s21_cos(double x) {
  x = period_limitation(x);
  long double cos_value = 0;
  long double member = 1;
  int n = 1;
  while (member < ACCURACY * -1 || ACCURACY < member) {
    cos_value += member;
    member = member * (-1) * (x * x) / (2 * n * (2 * n - 1));
    n += 1;
  }
  return cos_value;
}

long double s21_tan(double x) {
  long double cos_value = s21_cos(x);
  long double tan_value;
  if (cos_value - 0 < -ACCURACY || ACCURACY < cos_value - 0)
    tan_value = s21_sin(x) / cos_value;
  else {
    tan_value = 16331239353195370.;
    if (s21_sin(x) < 0) tan_value *= -1;
  }
  return tan_value;
}

// change sqrt to s21_sqrt
// change atan to s21_atan
long double s21_asin(double x) {
  long double asin_value;
  if (x < -1 || x > 1)
    asin_value = NAN;
  else {
    if (x < -sqrt(2) / 2)
      asin_value = -PI / 2 - atan(sqrt(1 - x * x) / x);
    else if (x <= sqrt(2) / 2)
      asin_value = atan(x / sqrt(1 - x * x));
    else
      asin_value = PI / 2 - atan(sqrt(1 - x * x) / x);
  }
  return asin_value;
}

long double s21_acos(double x) { return PI / 2 - s21_asin(x); }