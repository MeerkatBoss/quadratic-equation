#include <stdio.h>
#include <stdarg.h>
#include "quadio.h"

void show_help(void)
{
    const char* MESSAGE =
        "Usage:\n"
        "\tquad - to launch program in interactive mode\n"
        "\tquad <a> <b> <c> - to get roots of an equation ax^2 + bx + c = 0\n";
    printf("%s", MESSAGE);
}

int flush_input(void)
{
    while (1)
    {
        switch(getchar())
        {
            case EOF:
                return -1;
            case '\n':
                return 0;
            default:
                break;
        }
    }
}

int parse_args(int argc, char** argv, ...)
{
    va_list args;
    int i;

    va_start(args, argc - 1);

    for (i = 1; i < argc; i++)
    {
        double *arg = NULL;

        arg = va_arg(args, double*);
        if (sscanf(argv[i], " %lg", arg) != 1)
            return -1;
    }

    return 0;
}

int interactive_input(double *a, double *b, double *c)
{
    printf("This program solves equations ax^2 + bx + c = 0\n");
    printf("Please, enter coefficients a, b and c\n");
    while (scanf(" %lg %lg %lg", a, b, c) != 3)
    {
        if (flush_input() != 0)
            return -1;
        printf("Please enter 3 (three) numbers\n");
    }
    return 0;
}

int print_solutions(enum root_count n_roots, double x1, double x2)
{
    switch (n_roots) /* Determine output format */
    {
        case NO_ROOTS:
            printf("No real roots\n");
            break;
        case SINGLE_ROOT:
            printf("Single root: %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("Two roots: %lg and %lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Infinitely many roots (x can be any real number)\n");
            break;
        default:
            printf("Unknown error\n");
            return 2;
    }
    return 0;
}

