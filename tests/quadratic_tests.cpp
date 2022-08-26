#include <stdio.h>
#include "quadratic_tests.h"
#include "quadratic.h"
#include "io_utils.h"

#define BUFLEN 1000

TEST(solve_linear)
{
    FileReader *fr = open_file(TEST_SOURCE(solve_linear));
    char line[BUFLEN] = "";
    while (next_line(fr, BUFLEN, line) == 0)
        TEST_CASE
        {
            double a = 0, b = 0, x_expected = 0;
            int status_expected = 0, roots_expected = 0;
            int read = sscanf(line, " %lg %lg > %d | %d %lg \n",
                &a, &b, &status_expected, &roots_expected, &x_expected);
            if (read != 5)
            {
                ASSERT_TRUE(0 && "Corrupted test file.");
                abort();
            }
            
            EQUATION_RESULT(1) result = {.nroots = NO_ROOTS, .roots = {0}};
            int status_actual = solve_linear(a, b, &result);

            ASSERT_EQUAL(status_expected, status_actual, "%d");
            ASSERT_EQUAL(roots_expected, (int)result.nroots, "%d");
            ASSERT_DOUBLE_EQUAL(x_expected, result.roots[0], "%lg");
        }
    close_file(fr);
}

TEST(solve_quadratic)
{
    FileReader *fr = open_file(TEST_SOURCE(solve_quadratic));
    char line[BUFLEN];
    while(next_line(fr, BUFLEN, line) == 0)
        TEST_CASE
        {
            double a = 0, b = 0, c = 0,
                x1_expected = 0, x2_expected = 0;
            int status_expected = 0, roots_expected = 0;
            int read = sscanf(line, " %lg %lg %lg > %d | %d %lg %lg \n",
                &a, &b, &c, &status_expected, &roots_expected,
                &x1_expected, &x2_expected);
            if (read != 7)
            {
                ASSERT_TRUE(0 && "Corrupted test file");
                abort();
            }

            EQUATION_RESULT(2) result = {.nroots = NO_ROOTS, .roots = {0, 0}};
            int status_actual = solve_quadratic(a, b, c, &result);

            ASSERT_EQUAL(status_expected, status_actual, "%d");
            ASSERT_EQUAL(roots_expected, (int)result.nroots, "%d");
            ASSERT_DOUBLE_EQUAL(x1_expected, result.roots[0], "%lg");
            ASSERT_DOUBLE_EQUAL(x2_expected, result.roots[1], "%lg");
        }
    close_file(fr);
}