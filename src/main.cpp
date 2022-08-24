#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadratic.h"
#include "quadio.h"

enum status_code
{
    RETURN_SUCCESS          = 0,
    RETURN_BAD_INPUT        = 1,
    RETURN_RUNTIME_ERROR    = 2
};

void check_error(void);

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;

    /* input coefficients */
    if (argc == 4) /* non-interactive mode */
    {
        errno = 0;
        if (parse_args(argc, argv, &a, &b, &c) != 0)
        {
            check_error();
            show_help();
            return RETURN_BAD_INPUT;
        }
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-h") == 0)
        {
            show_help();
            return 0;
        }
        return RETURN_BAD_INPUT;
    }
    else if (argc == 1) /* interactive mode */
    {
        errno = 0;
        if (interactive_input(&a, &b, &c) == EOF)
            return 0;
        check_error();
    }
    else /* incorrect usage */
    {
        show_help();
        return RETURN_BAD_INPUT;
    }

    double x1 = 0, x2 = 0;

    errno = 0;
    enum root_count n_roots = solve_quadratic(a, b, c, &x1, &x2);
    if (errno == EINVAL) /* invalid coefficients */
        return RETURN_RUNTIME_ERROR;
    check_error();

    if (print_solutions(n_roots, x1, x2) != 0)
        return RETURN_RUNTIME_ERROR;

    return RETURN_SUCCESS;
}

void check_error(void)
{
    if (errno)
    {
        perror("Runtime error");
        exit(RETURN_RUNTIME_ERROR);
    }
}
