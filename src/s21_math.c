#include "s21_math.h"

long double s21_atan(double x) {
  long double atan_value;
  int sign = (x >= 0) ? 1 : -1;
  x = s21_fabs(x);
  if (x != 1) {
    if (x < 1) {
      atan_value = 0;
    } else {
      atan_value = S21_PI / 2;
      x = -1 / x;
    }
    int n = 1;
    long double member = x;
    while (member < S21_ACCURACY * -1 || S21_ACCURACY < member) {
      atan_value += member;
      n += 1;
      member = member * (-1) * (x * x) * (2 * n - 3) / (2 * n - 1);
    }
  } else {
    atan_value = S21_PI / 4;
  }
  return (x == x) ? atan_value * sign : x;
}

long double s21_ceil(double x) {
  long double res = 0;

  if (S21_ISNAN(x) || S21_ISINF(x)) {
    res = x;
  } else {
    int int_part = (int)x;

    if (int_part == x) {
      res = x;
    } else if (x > 0) {
      res += int_part + 1;
    } else {
      res = int_part;
    }
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;

  if (S21_ISNAN(x)) {
    res = x;
  } else if (S21_ISINF(x)) {
    res = x == -S21_INF ? 0 : S21_INF;
  } else {
    double num = x;
    double fact = 1;
    double step = 1;
    while (s21_fabs(step) > S21_EXP_EPS) {
      step *= num / fact;
      res += step;
      fact++;

      if (res > __DBL_MAX__) {
        res = S21_INF;
        break;
      }
    }
  }

  return res;
}

long double s21_fmod(double x, double y) {
  long double res;

  if (y == 0) {
    res = S21_NAN;
  } else if (S21_ISINF(y) && !S21_ISINF(x)) {
    res = x;
  } else {
    double tmp = x / y;

    res = x - (tmp < 0 ? s21_ceil(tmp) : s21_floor(tmp)) * y;
  }

  return res;
}

long double s21_sqrt(double x) {
  long double result;

  if (x == S21_MINUS_INF) {
    result = S21_NAN;
  } else {
    result = s21_pow(x, 0.5);
  }

  return result;
}

long double s21_log(double num) {
  int count = 0;
  long double res = 0.0;
  int i = 0;
  if (num == S21_INF) {
    res = S21_INF;
  } else if (num < 0) {
    res = S21_NAN;
  } else if (num == 0) {
    res = -S21_INF;
  } else {
    while (num >= S21_E) {
      num /= S21_E;
      count++;
    }
    while (i < 100) {
      double tmp = res;
      res = tmp + 2 * (num - s21_exp(tmp)) / (num + s21_exp(tmp));
      i++;
    }
  }
  return (res + count);
}

double period_limitation(double x) {
  int count = x / (2 * S21_PI);
  return x - 2 * S21_PI * count;
}

long double s21_sin(double x) {
  long double sin_value = S21_NAN;
  if (!S21_ISINF(x) && !S21_ISNAN(x)) {
    x = period_limitation(x);
    sin_value = 0;
    long double member = x;
    int n = 1;
    while (member < S21_ACCURACY * -1 || S21_ACCURACY < member) {
      sin_value += member;
      member = member * (-1) * (x * x) / (2 * n * (2 * n + 1));
      n += 1;
    }
  }
  return (x == x) ? sin_value : x;
}

long double s21_cos(double x) {
  long double cos_value = S21_NAN;
  if (!S21_ISINF(x) && !S21_ISNAN(x)) {
    x = period_limitation(x);
    cos_value = 0;
    long double member = 1;
    int n = 1;
    while (member < S21_ACCURACY * -1 || S21_ACCURACY < member) {
      cos_value += member;
      member = member * (-1) * (x * x) / (2 * n * (2 * n - 1));
      n += 1;
    }
  }
  return (x == x) ? cos_value : x;
}

long double s21_tan(double x) {
  long double tan_value;
  if (!S21_ISNAN(x) && !S21_ISINF(x)) {
    long double cos_value = s21_cos(x);
    if (cos_value - 0 < -S21_ACCURACY || S21_ACCURACY < cos_value - 0)
      tan_value = s21_sin(x) / cos_value;
    else {
      tan_value = 16331239353195370.;
      if (s21_sin(x) < 0) tan_value *= -1;
    }
  }
  if (x == S21_MINUS_INF) x = S21_NAN;
  return (x == x) ? tan_value : x;
}

long double s21_asin(double x) {
  long double asin_value;
  if (x < -1 || x > 1)
    asin_value = S21_NAN;
  else {
    if (x < -s21_sqrt(2) / 2)
      asin_value = -S21_PI / 2 - s21_atan(s21_sqrt(1 - x * x) / x);
    else if (x <= s21_sqrt(2) / 2)
      asin_value = s21_atan(x / s21_sqrt(1 - x * x));
    else
      asin_value = S21_PI / 2 - s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return asin_value;
}

long double s21_acos(double x) { return S21_PI / 2 - s21_asin(x); }

int s21_abs(int x) {
  if (x < 0 && x != S21_INF) x = -x;
  return (x);
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  if (S21_ISNAN(x)) x = -S21_NAN;
  return (x);
}

long double s21_floor(double x) {
  long double res = (long long int)x;

  if (x != x) res = x;
  if (x == S21_INF || x == S21_MINUS_INF) res = x;
  if (x < 0 && x != res) res -= 1;  // res = res - 1
  return (res);
}

double s21_int_pow(double base, unsigned int exp) {
  double res = 1.0;
  int i = 0;
  while (exp != 0) {
    if ((exp & 1) != 0) {
      res *= base;
    }
    base *= base;
    exp >>= 1;
    i++;
  }
  return (res);
}

int pow_special_case(double base, double exp, long double *result) {
  int cases = 0;
  if (base == 0.0 && exp > 0) {
    cases = 1;
    *result = 0;
  } else if (((base == S21_INF || base == -S21_INF) && exp > 0) ||
             (exp == S21_INF && s21_fabs(base) > 1) ||
             (exp == -S21_INF && s21_fabs(base) < 1) ||
             (base == 0 && exp < 0)) {
    cases = 1;
    *result = S21_INF;
  } else if ((base == S21_INF || base == -S21_INF) && exp < 0) {
    cases = 1;
    *result = 0;
  } else if (exp == 0) {
    cases = 1;
    *result = 1.0;
  } else if (base == 1 || (base == -1 && (exp == S21_INF || exp == -S21_INF))) {
    cases = 1;
    *result = 1;
  } else if (exp == -S21_INF && s21_fabs(base) > 1) {
    cases = 1;
    *result = 0.0;
  } else if (exp != exp || base != base) {
    cases = 1;
    *result = S21_NAN;
  } else if (base < 0 && ((int)exp) - exp != 0) {
    cases = 1;
    *result = S21_NAN;
  }
  return (cases);
}

long double s21_pow(double base, double exp) {
  long double res = base * exp;
  if (!S21_ISNAN(base) && !S21_ISNAN(exp)) {
    res = 0.0;
    int int_exp = (int)exp;
    int sign = 1;
    if (!pow_special_case(base, exp, &res)) {
      double exp0 = exp;
      if (exp0 < 0) exp0 = -exp0;
      if (base < 0 && int_exp - exp == 0) {
        if (int_exp == 1 || s21_abs(int_exp) % 2 == 1 || int_exp == -1)
          sign = -1;
        base = -base;
      }
      int_exp = (int)exp0;
      if (exp0 > 1) exp0 = exp0 - int_exp;
      res = s21_exp(s21_log(base) * exp0);
      res *= s21_int_pow(base, (unsigned int)int_exp);
      if (exp < 0) res = 1 / res;
      res *= sign;
    }
  }
  return (res);
}
