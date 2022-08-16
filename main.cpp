#include "quadratic.h"
#include "quadio.h"

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;
    enum root_count n_roots = NO_ROOTS;
    double x1 = 0, x2 = 0;

    /* input coefficients */
    if (argc == 4) /* non-interactive mode */
    {
        if (parse_args(argc, argv, &a, &b, &c) != 0)
        {
            show_help();
            return 1;
        }
    }
    else if (argc == 1) /* interactive mode */
    {
        if (interactive_input(&a, &b, &c) != 0)
            return 0;
    }
    else /* incorrect usage */
    {
        show_help();
        return 1;
    }

    n_roots = solve_quadratic(a, b, c, &x1, &x2);

    /* get rid of strange values '-0'*/
    if (compare_double(x1, 0) == 0)
        x1 = 0;
    if (compare_double(x2, 0) == 0)
        x2 = 0;

    return print_solutions(n_roots, x1, x2);
}

