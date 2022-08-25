#include "double_utils.h"

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

void clamp_to_zero(double* x)
{
    if (compare_double(*x, 0) == 0)
        *x = 0;
}
