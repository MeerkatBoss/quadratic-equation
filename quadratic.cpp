#include <math.h>
#include "quadratic.h"

int compare_double(double a, double b)
{
    /* minimal significant difference between numbers */
    const double EPS = 1e-8;

    double diff = a - b;

    if (diff < -EPS)
        return -1;
    if (diff > EPS)
        return 1;
    return 0;
}

enum root_count solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    double d = 0;
    int d_sign = 0;
    if (compare_double(a, 0) == 0) /* a = 0 => linear equation */
    {
        return solve_linear(b, c, x1);
    }
    d = b * b - 4 * a * c;
    d_sign = compare_double(d, 0);
    if (d_sign < 0) /* d < 0 => no real roots */
        return NO_ROOTS;
    if (d_sign == 0) /* single root */
    {
        *x1 = -b / (2 * a);
        return SINGLE_ROOT;
    }
    /* two roots */
    d = sqrt(d);
    *x1 = (-b - d) / (2 * a);
    *x2 = (-b + d) / (2 * a);
    return TWO_ROOTS;
}

enum root_count solve_linear(double a, double b, double *x)
{
    if (compare_double(a, 0) == 0) /* no x in equation */
        return compare_double(b, 0) == 0
            ? INF_ROOTS
            : NO_ROOTS;
    *x = -b / a;
    return SINGLE_ROOT;
}

