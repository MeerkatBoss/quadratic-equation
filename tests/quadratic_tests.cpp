#include <stdio.h>
#include "quadratic.h"
#include "testing.h"
#include "io_utils.h"

typedef struct
{
    double *coeffs;
    int status;
    EquationResultBase *result;
} EquationTestCase;

enum
{
    EQ_LINEAR    = 1u,
    EQ_QUADRATIC = 2u
};

static EquationTestCase *read_test_case(size_t n, const char *line);
static int test_solver(size_t n, EquationTestCase *test_case);
static void run_solver_tests(size_t n, const char* name);

TEST(solve_linear)
{
    run_solver_tests(EQ_LINEAR, TEST_SOURCE(solve_linear));
}


TEST(solve_quadratic)
{
    run_solver_tests(EQ_QUADRATIC, TEST_SOURCE(solve_quadratic));
}

static void run_solver_tests(size_t n, const char* name) {
    const LineFileReader *fr = read_file(name);

    for (size_t i = 0; i < fr->line_count; i++)
    {
        const char *line = fr->lines[i];
        TEST_CASE
        {
            EquationTestCase *test_case = read_test_case(n, line);
            if (test_case == NULL)
            {
                free(test_case);
                TEST_CASE_ABORT;
            }
            test_solver(n, test_case);
            free(test_case);
        }
    }
    close_reader(fr);
}

static EquationTestCase *read_test_case(size_t n, const char *line)
{
    int nread = 0;
    /* Read coefficients */
    double *coeffs = (double *) calloc(n + 1u, sizeof(double));
    for (size_t i = 0; i < n + 1; i++)
    {
        if (!sscanf(line, " %lg%n", &coeffs[i], &nread))
        {
            ASSERT_TRUE(0 && "Corrupted test file");
            free(coeffs);
            return NULL;
        }
        line += nread;
    }

    /* Read status */
    int status = 0;
    if (!sscanf(line, " >  %d | %n", &status, &nread))
    {
        ASSERT_TRUE(0 && "Corrupted test file");
        free(coeffs);
        return NULL;
    }
    line += nread;

    /* Read result */
    EquationResultBase *result = generic_result(n);
    int nroots = 0;
    if (!sscanf(line, " %d %n", &nroots, &nread))
    {
        ASSERT_TRUE(0 && "Corrupted test file");
        free(coeffs);
        free(result);
        return NULL;
    }
    result->nroots = (enum root_count)nroots;
    line += nread;
    for (size_t i = 0; i < n; i++)
    {
        if (!sscanf(line, " %lg%n", &result->roots[i], &nread))
        {
            ASSERT_TRUE(0 && "Corrupted test file");
            free(coeffs);
            free(result);
            return NULL;
        }
        line += nread;
    }

    EquationTestCase *test_case = (EquationTestCase*) calloc(1,
                                    sizeof(EquationTestCase));
    *test_case = {.coeffs = coeffs, .status = status, .result = result};
    return test_case;
}

static int test_solver(size_t n,EquationTestCase *test_case)
{
    EquationResultBase *actual_result = local_generic_result(n);
    actual_result->nroots = NO_ROOTS;
    for (size_t i = 0; i < n; i++)
        actual_result->roots[i] = 0;
    int actual_status = 0;
    switch(n)
    {
        case 1:
            actual_status = solve_linear(
                test_case->coeffs[0],
                test_case->coeffs[1],
                (EQUATION_RESULT(1)*)actual_result);
            break;
        case 2:
            actual_status = solve_quadratic(
                test_case->coeffs[0],
                test_case->coeffs[1],
                test_case->coeffs[2],
                (EQUATION_RESULT(2)*)actual_result
            );
            break;
        default:
            ASSERT_TRUE(0 && "Cannot solve equation");
            return -1;
    }
    ASSERT_EQUAL(test_case->status,
                     actual_status,
                     "%d");
    ASSERT_EQUAL((int)test_case->result->nroots,
                     (int)actual_result->nroots,
                     "%d");
    for (size_t i = 0; i < n; i++)
        ASSERT_DOUBLE_EQUAL(test_case->result->roots[i],
                                actual_result->roots[i],
                                "%lg");
    return 0;
}
