#include <stdio.h>
#include <stdlib.h>
#include "quadratic.h"

void show_help(void);
int flush_input(void);

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;
    int root_count = 0;
    double x1 = 0, x2 = 0;

    /* input coefficients */
    if (argc == 4) /* non-interactive mode */
    {
        if (sscanf(argv[1], " %lg", &a) != 1 ||
            sscanf(argv[2], " %lg", &b) != 1 ||
            sscanf(argv[3], " %lg", &c) != 1)
        {
            show_help();
            return 1;
        }
    }
    else if (argc == 1) /* interactive mode */
    {
        int read = 0;
        printf("This program solves equations ax^2 + bx + c = 0\n");
        printf("Please, enter coefficients a, b and c\n");
        read = scanf(" %lg %lg %lg", &a, &b, &c);
        while (read != 3)
        {
            if (flush_input() != 0)
                return 0;
            printf("Please enter 3 (three) numbers\n");
            read = scanf(" %lg %lg %lg", &a, &b, &c);
        }
    }
    else /* incorrect usage */
    {
        show_help();
        return 1;
    }

    root_count = solve_quadratic(a, b, c, &x1, &x2);

    /* get rid of strange values '-0'*/
    if (compare_double(x1, 0) == 0)
        x1 = 0;
    if (compare_double(x2, 0) == 0)
        x2 = 0;
    
    switch (root_count) /* Determine output format */
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
        default: /* Shouldn't be executed */
            printf("Unknown error\n");
            return 2;
    }
    return 0;
}

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
    int c = 0;
    do
    {
        c = getchar();
    } while(c != '\n' && c != EOF);
    return c == EOF
        ? -1 /* cannot read further */
        : 0; /* can continue input */
}

