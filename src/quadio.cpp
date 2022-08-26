#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include "quadio.h"
#include "io_utils.h"

void show_help(void)
{
    const char* MESSAGE =
        "Usage:\n"
        "\tquad - to launch program in interactive mode\n"
        "\tquad <a> <b> <c> - to get roots of an equation ax^2 + bx + c = 0\n"
        "\tquad -h - to get this message\n";

    printf("%s", MESSAGE);
}


int extract_doubles(int argc, char** argv, ...)
{
    va_list args = {};

    va_start(args, argv);

    for (int i = 1; i < argc; i++)
    {
        double *arg = NULL;

        arg = va_arg(args, double*);

        /* check for valid vararg */
        assert(arg != NULL);

        /* check that argv is long enough */
        assert(argv[i] != NULL);

        if (sscanf(argv[i], " %lg", arg) != 1 || !isfinite(*arg))
            return -1;
    }
    
    va_end(args);

    return 0;
}

int interactive_input(double *a, double *b, double *c)
{
    /* check for valid pointers */
    assert(a != NULL && b != NULL && c != NULL);

    /* prompt */
    printf("This program solves equations ax^2 + bx + c = 0\n");
    printf("Please, enter coefficients a, b and c\n");

    /* repeat input until success */
    while (scanf(" %lg %lg %lg", a, b, c) != 3 ||
            ! isfinite(*a) ||
            ! isfinite(*b) ||
            ! isfinite(*c))
    {
        if (skip_line(stdin) == FILE_END) /* no further input */
            return EOF;
        printf("Please enter 3 (three) numbers\n");
    }
    return 0;
}

void print_roots(EquationResultBase* result)
{
    switch (result->nroots) /* Determine output format */
    {
        case NO_ROOTS:
            printf("No real roots\n");
            break;
        case SINGLE_ROOT:
            printf("Single root: %lg\n",
                result->roots[0]);
            break;
        case TWO_ROOTS:
            printf("Two roots: %lg and %lg\n",
                result->roots[0],
                result->roots[1]);
            break;
        case INF_ROOTS:
            printf("Infinitely many roots (x can be any real number)\n");
            break;
        default:
            assert(0 && "Unknown enum value.");
            break;
    }
}

