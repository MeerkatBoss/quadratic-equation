#ifndef QUADIO_H
#define QUADIO_H

/**
 * @file quadio.h
 * @author MeerkatBoss
 * @brief Contains definitions for IO functions
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "quadratic.h"

/**
 * @brief Displays help message to stdout
 */
void show_help(void);

enum read_coeff_status
{
    ALL_READ        = 0,
    USER_QUIT       = 1,
    USER_BAD_INPUT  = -1,
    HELP_DISPLAYED  = 3
};
/**
 * @brief Processes command-line argments and user input to get coefficients
 * 
 * @param[in] argc - length of argv
 * @param[in] argv - command-line argument vector
 * @param[out] a - pointer to first coefficient
 * @param[out] b - pointer to second coefficient
 * @param[out] c - pointer to third coefficient
 * @return Status of reading coefficients
 */
enum read_coeff_status try_get_coefficients(int argc, char** argv,
                                        double *a, double *b, double *c);

/**
 * @brief Reads double-precision floating-point numbers
 * from argv
 * 
 * @param[in] argc - length of argv
 * @param[in] argv - command-line argument vector
 * @param[out] ... - pointers for storing numbers
 * @return 0 upon success; -2 upon failure
 */
int extract_doubles(int argc, char** argv, ...);

/**
 * @brief Reads three double-precision floating-point numbers
 * interactively
 * 
 * @param[out] a - pointer to first number
 * @param[out] b - pointer to second number
 * @param[out] c - pointer to third number
 * @return 0 upon success, EOF upon encountering end-of-file,
 * -2 upon failure 
 */
int interactive_input(double* a, double* b, double* c);

/**
 * @brief Produces formatted output of equation roots
 * 
 * @param[in] n_roots - value, representing number of roots
 * @param[in] x1 - first root
 * @param[in] x2 - second root
 * @return 0 upon success, -2 upon failure
 */
void print_roots(EquationResultBase* result);

#endif
