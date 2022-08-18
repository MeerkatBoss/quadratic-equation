#ifndef QUADRATIC_H
#define QUADRATIC_H

enum root_count
{
    NO_ROOTS    =  0,
    SINGLE_ROOT =  1,
    TWO_ROOTS   =  2,
    INF_ROOTS   = -1
};

int compare_double(double, double);
enum root_count solve_quadratic(double, double, double, double*, double*);
enum root_count solve_linear(double, double, double*);

#endif
