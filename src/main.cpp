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

int main(int argc, char **argv)
{
    double a = 0, b = 0, c = 0;

    /* TODO: Extract user interaction to fuction */
    /* input coefficients */
    if (argc == 4) /* non-interactive mode */
    {
        if (extract_doubles(argc, argv, &a, &b, &c) != 0)
        {
            show_help();
            return RETURN_BAD_INPUT;
        }
    }
    else if (argc == 2)
    {
        show_help();
        if (strcmp(argv[1], "-h") == 0)
            return 0;
        return RETURN_BAD_INPUT;
    }
    else if (argc == 1) /* interactive mode */
    {
        if (interactive_input(&a, &b, &c) == EOF)
            return 0;
    }
    else /* incorrect usage */
    {
        show_help();
        return RETURN_BAD_INPUT;
    }

    EQUATION_RESULT(2) *result = 
        (EQUATION_RESULT(2)*) calloc(1, sizeof(EQUATION_RESULT(2)));

    solve_quadratic(a, b, c, result);

    print_roots(&result->base);

    free(result);

    return RETURN_SUCCESS;
}
