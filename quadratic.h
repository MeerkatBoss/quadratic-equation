#ifndef QUADRATIC_H
#define QUADRATIC_H

enum root_count
{
    NO_ROOTS,
    SINGLE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

int compare_double(double, double);
enum root_count solve_quadratic(double, double, double, double*, double*);

#endif
