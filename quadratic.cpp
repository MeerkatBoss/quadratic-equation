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

int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    double d = 0;
    int d_sign = 0;
    if (compare_double(a, 0) == 0) /* a = 0 => linear equation */
    {
        if (compare_double(b, 0) == 0)
        {
            return compare_double(c, 0) == 0
                ? TOO_MANY_ROOTS /* infinetely many roots */
                : 0; /* no roots */
        }
        *x1 = -c / b;
        return 1;
    }
    d = b * b - 4 * a * c;
    d_sign = compare_double(d, 0);
    if (d_sign < 0) /* d < 0 => no real roots */
        return 0;
    if (d_sign == 0) /* single root */
    {
        *x1 = -b / (2 * a);
        return 1;
    }
    /* two roots */
    d = sqrt(d);
    *x1 = (-b - d) / (2 * a);
    *x2 = (-b + d) / (2 * a);
    return 2;
}
