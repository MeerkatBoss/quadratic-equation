#ifndef DOUBLE_UTILS_H
#define DOUBLE_UTILS_H

/**
 * @file double_utils.h
 * @author MeerkatBoss
 * @brief Contains helper functions to work with
 * double-precision floating-point numbers
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * @brief Compares two double-precision floating-point numbers
 * 
 * @param[in] a - first number
 * @param[in] b - second number
 * @return negative number if a < b; positive number if a > b;
 * 0 if a and b are close enough to be considered equal
 * 
 * @note Minimal difference between numbers considered not equal is 1e-8
 */
int compare_double(double a, double b);

/**
 * @brief If x is sufficiently close to zero, replace x with 0
 * 
 * @param[inout] x - Value to be tested and replaced
 */
void clamp_to_zero(double* x);


#endif