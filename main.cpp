#include <stdio.h>
#include <stdlib.h>
#include "quadratic.h"

void show_help(void);

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;
    int root_count = 0;
    double x1 = 0, x2 = 0;

    /* input coefficients */
    if (argc == 4) /* non-interactive mode */
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    }
    else if (argc == 1) /* interactive mode */
    {
        int read = 0;
        printf("This program solves equations ax^2 + bx + c = 0\n");
        printf("Please, enter coefficients a, b and c\n");
        read = scanf(" %lg %lg %lg", &a, &b, &c);
        if (read != 3) /* TODO: repeat input until success */
        {
            printf("Please enter 3 (three) numbers\n");
            return 1;
        }
    }
    else /* incorrect usage */
    {
        show_help();
        return 1;
    }

    root_count = solve_quadratic(a, b, c, &x1, &x2);

    /* in non-interactive mode output roots with no additional info */
    if (argc == 4)
    {
        if (root_count == 1)
            printf("%lg\n", x1);
        else if (root_count == 2)
            printf("%lg %lg\n", x1, x2);
        else
            printf("\n");
        return 0;
    }
    /* in interactive mode provide root description */
    if (root_count == 0)
        printf("No real roots\n");
    else if (root_count == 1)
        printf("Single root: %lg\n", x1);
    else
        printf("Two roots: %lg and %lg\n", x1, x2);
    return 0;
}

void show_help(void)
{
    const char* MESSAGE =
        "Usage:\n"
        "\tquad - for interactive mode\n"
        "\tquad <a> <b> <c> - to get roots of equation ax^2 + bx + c = 0\n";
    printf("%s", MESSAGE);
}

