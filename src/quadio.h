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

/**
 * @brief Reads and discards all symbols until '\\n'
 * from stream
 * 
 * @param fd [in] - file descriptor of a stream
 * @return 0 upon success; EOF upon encountering end-of-file
 */
int flush_input(FILE *fd);

/**
 * @brief Reads double-precision floating-point numbers
 * from string
 * 
 * @param n [in] - amount of numbers to read
 * @param str [in] - string, containing numbers
 * @param ... [out] - pointers for storing numbers
 * @return 0 upon success; -2 upon failure
 */
int parse_args(int n, char** str, ...);

/**
 * @brief Reads three double-precision floating-point numbers
 * interactively
 * 
 * @param a [out] - pointer to first number
 * @param b [out] - pointer to second number
 * @param c [out] - pointer to third number
 * @return 0 upon success, EOF upon encountering end-of-file,
 * -2 upon failure 
 */
int interactive_input(double* a, double* b, double* c);

/**
 * @brief Produces formatted output of equation roots
 * 
 * @param n_roots [in] - value, representing number of roots
 * @param x1 [in] - first root
 * @param x2 [in] - second root
 * @return 0 upon success, -2 upon failure
 */
int print_solutions(enum root_count n_roots, double x1, double x2);

#endif
