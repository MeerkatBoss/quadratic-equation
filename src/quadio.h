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

enum line_skip_status
{
    LINE_END = 0,
    FILE_END = -1
};

/**
 * @brief Reads and discards all symbols until '\\n'
 * from stream
 * 
 * @param[in] fd - file descriptor of a stream
 * @return 0 upon success; EOF upon encountering end-of-file
 */
enum line_skip_status skip_line(FILE *fd);

/**
 * @brief Reads double-precision floating-point numbers
 * from string
 * 
 * @param[in] n - amount of numbers to read
 * @param[in] str - string, containing numbers
 * @param[out] ... - pointers for storing numbers
 * @return 0 upon success; -2 upon failure
 */
int extract_doubles(int n, char** str, ...);

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
