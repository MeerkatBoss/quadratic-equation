#ifndef QUADIO_H
#define QUADIO_H

#include <stdio.h>
#include "quadratic.h"

void show_help(void);
int flush_input(FILE *fd);
int parse_args(int, char**, ...);
int interactive_input(double*, double*, double*);
int print_solutions(enum root_count, double, double);

#endif
