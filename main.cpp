#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_double(double, double);
int solve_quadratic(double, double, double, double[]);
void show_help(void);

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;
    int root_count = 0;
    double roots[] = { 0, 0 };
    if (argc == 4)
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    }
    else if (argc == 1)
    {
        int read = 0;
        printf("This program solves equations ax^2 + bx + c = 0\n");
        printf("Please, enter coefficients a, b and c\n");
        read = scanf(" %lg %lg %lg", &a, &b, &c);
        if (read != 3)
        {
            printf("Please enter 3 (three) numbers\n");
            return 1;
        }
    }
    else
    {
        show_help();
        return 1;
    }
    root_count = solve_quadratic(a, b, c, roots);
    if (argc == 4)
    {
        if (root_count == 1)
            printf("%lg\n", roots[0]);
        else if (root_count == 2)
            printf("%lg %lg\n", roots[0], roots[1]);
        return 0;
    }
    if (root_count == 0)
        printf("No real roots\n");
    else if (root_count == 1)
        printf("Single root: %lg\n", roots[0]);
    else
        printf("Two roots: %lg and %lg\n", roots[0], roots[1]);
    return 0;
}

int compare_double(double a, double b)
{
    /* minimal significant difference between numbers */
    const double EPS = 1e-8;

    double diff = a - b;

    if (diff < -EPS)
        return -1;
    if (diff > EPS)
        return 1;
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

int solve_quadratic(double a, double b, double c, double roots[])
{
    double d = 0;
    int d_sign = 0;
    if (compare_double(a, 0) == 0) /* a = 0 => linear equation */
    {
        roots[0] = -c / b;
        return 1;
    }
    d = b * b - 4 * a * c;
    d_sign = compare_double(d, 0);
    if (d_sign < 0) /* d < 0 => no real roots */
        return 0;
    if (d_sign == 0) /* single root */
    {
        roots[0] = -b / (2 * a);
        return 1;
    }
    /* two roots */
    d = sqrt(d);
    roots[0] = (-b - d) / (2 * a);
    roots[1] = (-b + d) / (2 * a);
    return 2;
}

