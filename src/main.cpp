#include <stdlib.h>
#include <assert.h>
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

    /* Read coefficients or display help message */
    switch (try_get_coefficients(argc, argv, &a, &b, &c))
    {
        case HELP_DISPLAYED:
            show_help();
            [[fallthrough]];
        case USER_QUIT:
            return RETURN_SUCCESS;
        case USER_BAD_INPUT:
            printf("Incorrect program usage.\n");
            show_help();
            return RETURN_BAD_INPUT;
        case ALL_READ:
            break;
        default:
            assert(0 && "Unknown enum value");
            return RETURN_RUNTIME_ERROR;
    }

    /* Solve equation */
    EQUATION_RESULT(2) result = {.nroots = NO_ROOTS, .roots = {0, 0}};
    solve_quadratic(a, b, c, &result);

    /* Output result */
    print_roots(&result.base);

    return RETURN_SUCCESS;
}
