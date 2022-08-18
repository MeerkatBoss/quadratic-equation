#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <errno.h>
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
                return EOF;
            case '\n':
                return 0;
            default:
                break;
        }
    }
}

int parse_args(int argc, char** argv, ...)
{
    va_list args = {};

    va_start(args, argc - 1);

    for (int i = 1; i < argc; i++)
    {
        double *arg = NULL;

        arg = va_arg(args, double*);

        /* check for valid vararg */
        assert(arg != NULL);
        if (arg == NULL)
        {
            errno = EDESTADDRREQ;
            return -2;
        }

        /* check that argv is long enough */
        assert(argv[i] != NULL);
        if (argv[i] == NULL)
        {
            errno = EINVAL;
            return -2;
        }

        if (sscanf(argv[i], " %lg", arg) != 1)
            return -2;
    }

    return 0;
}

int interactive_input(double *a, double *b, double *c)
{
    /* check for valid pointers */
    assert(a != NULL && b != NULL && c != NULL);
    if (a == NULL || b == NULL || c == NULL)
    {
        errno = EDESTADDRREQ;
        return -2;
    }

    /* prompt */
    printf("This program solves equations ax^2 + bx + c = 0\n");
    printf("Please, enter coefficients a, b and c\n");

    /* repeat input until success */
    while (scanf(" %lg %lg %lg", a, b, c) != 3)
    {
        if (flush_input() == EOF) /* no further input */
            return EOF;
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
            return -2;
    }
    return 0;
}

