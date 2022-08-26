#include <math.h>
#include <assert.h>
#include <errno.h>
#include "quadratic.h"
#include "double_utils.h"

static int solve_linear_unsafe(double a, double b, EQUATION_RESULT(1) *result);

EquationResultBase *generic_result(size_t root_count)
{
    return (EquationResultBase*) calloc(1,
        sizeof(EquationResultBase) + root_count*sizeof(double)
    );
}

int solve_quadratic(double a, double b, double c,
                                EQUATION_RESULT(2) *result)
{
    /* check for valid pointers */
    assert(result != NULL);

    /* check for valid coefficients */
    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
    {
        errno = EINVAL;
        return SOLVE_ERROR;
    }

    if (compare_double(a, 0) == 0) /* a = 0 => linear equation */
        return solve_linear_unsafe(b, c,
            (EQUATION_RESULT(1)*) result); /* EQUATION_RESULT(2)* can be safely cast
                                            to EQUATION_RESULT(1)* due to alignment
                                            rules */

    /* solve quadratic */
    double d = b * b - 4 * a * c;
    int d_sign = compare_double(d, 0);

    if (d_sign < 0) /* d < 0 => no real roots */
    {
        result->nroots = NO_ROOTS;
        return SOLVE_SUCCESS;
    }
    if (d_sign == 0) /* single root */
    {
        result->roots[0] = -b / (2 * a);
        result->base.nroots = SINGLE_ROOT;
        return SOLVE_SUCCESS;
    }
    /* two roots */
    double d_sqrt = sqrt(d);
    result->roots[0] = (-b - d_sqrt) / (2 * a);
    result->roots[1] = (-b + d_sqrt) / (2 * a);
    result->nroots = TWO_ROOTS;

    /* get rid of strange values '-0'*/
    clamp_to_zero(&result->roots[0]);
    clamp_to_zero(&result->roots[1]);

    return SOLVE_SUCCESS;
}

int solve_linear(double a, double b, EQUATION_RESULT(1) *result)
{
    /* check for valid pointer */
    assert(result != NULL);

    /* check for valid coefficients */
    if (!isfinite(a) || !isfinite(b))
    {
        errno = EINVAL;
        return SOLVE_ERROR;
    }

    return solve_linear_unsafe(a, b, result);
}

static int solve_linear_unsafe(double a, double b,
                                            EQUATION_RESULT(1) *result)
{
    if (compare_double(a, 0) == 0) /* no x in equation */
    {
        result->nroots = (compare_double(b, 0) == 0
            ? INF_ROOTS
            : NO_ROOTS);
        return SOLVE_SUCCESS;
    }

    result->roots[0] = -b / a;
    clamp_to_zero(&result->roots[0]);
    result->nroots = SINGLE_ROOT;
    return SOLVE_SUCCESS;
}

