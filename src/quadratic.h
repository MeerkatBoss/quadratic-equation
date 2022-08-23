#ifndef QUADRATIC_H
#define QUADRATIC_H

/**
 * @file quadratic.h
 * @author MeerkatBoss
 * @brief Contains definitions for equation solvers
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Enum representing number of roots
 * of an equation
 */
enum root_count
{
    NO_ROOTS    =  0, /*!< Equation has no roots */
    SINGLE_ROOT =  1, /*!< Equation has only one root */
    TWO_ROOTS   =  2, /*!< Equation has two distinct roots */
    INF_ROOTS   = -1  /*!< Any real number is a solution */
};

/**
 * @brief Compares two double-precision floating-point numbers
 * 
 * @param a [in] - first number
 * @param b [in] - second number
 * @return negative number if a < b; positive number if a > b;
 * 0 if a and b are close enough to be considered equal
 * 
 * @note Minimal difference between numbers considered not equal is 1e-9
 */
int compare_double(double a, double b);

/**
 * @brief Solves equations ax^2 + bx + c = 0
 * 
 * @param a [in] - first coefficient of an equaion
 * @param b [in] - second coefficient of an equation
 * @param c [in] - third coefficient of an equation
 * @param x1 [out] - pointer to the lesser of the roots
 * @param x2 [out] - pointer to the bigger of the roots
 * @return value, representing the number of roots
 * 
 * @note If there is only one solution to the equation, x2 is not changed.
 * If there are no roots or an infinite amount of roots,
 * both x1 and x2 are not changed.
 * If there are two roots, *x1 < *x2
 */
enum root_count solve_quadratic(double a, double b, double c,
                                double *x1, double *x2);

/**
 * @brief Solves equations ax + b = 0
 * 
 * @param a [in] - first coefficient of an equation
 * @param b [in] - second coefficient of an equation
 * @param x [out] - pointer to the root
 * @return value, representing the number of roots
 * 
 * @note If there are no roots or an infinite amount of roots, x is not changed
 */
enum root_count solve_linear(double a, double b, double* x);

#endif
