#include <assert.h>
#include <stdio.h>

#include "../src/quadratic.h"
#include "testing.h"
#include "test_quadratic.h"

#define BUFF_SIZE 1000

void test_solve_linear(void)
{
    printf("Started testing of solve_linear\n");
    const char *file_path = TEST_SOURCE(solve_linear);
    TestFile *file = test_file(file_path);

    assert(file != NULL);

    char line[BUFF_SIZE] = "";
    int test_count = 0;
    int failed = 0;
    while (next_test_case(file, BUFF_SIZE, line) == 0)
    {
        double a = 0, b = 0, x = 0;
        int n_roots = NO_ROOTS;

        if (sscanf(line, " %lg %lg %d %lg ", &a, &b, &n_roots, &x) != 4)
        {
            printf("Corrupt test file %s. Error on line %d\n",
                file_path,
                get_case_number(file));
            continue;
        };

        double x_res = 0;
        int n_res = solve_linear(a, b, &x_res);

        if (n_res != n_roots || compare_double(x, x_res) != 0)
        {
            printf("Test for solve_linear FAILED (line %d)\n",
                get_case_number(file));
            printf("Expected result:\tn_roots\t= %d,\tx\t= %lg\n", n_roots, x);
            printf("Actual result:\tn_roots\t= %d,\tx\t= %lg\n\n", n_res, x_res);
            failed++;
        }
        test_count++;
    }
    printf("%d tests finished. Successful tests: %d, failed tests: %d\n",
        test_count, test_count - failed, failed);
    printf("-------------------------------\n");

    close_test_file(file);
}

void test_solve_quadratic(void)
{
    printf("Started testing of solve_linear\n");
    const char *file_path = TEST_SOURCE(solve_quadratic);
    TestFile *file = test_file(file_path);

    assert(file != NULL);

    char line[BUFF_SIZE] = "";
    int test_count = 0;
    int failed = 0;
    while (next_test_case(file, BUFF_SIZE, line) == 0)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int n_roots = NO_ROOTS;

        if (sscanf(line, " %lg %lg %lg %d %lg %lg ",
            &a, &b, &c, &n_roots, &x1, &x2) != 6)
        {
            printf("Corrupt test file %s. Error on line %d\n",
                file_path,
                get_case_number(file));
            continue;
        };

        double x_res1 = 0, x_res2 = 0;
        int n_res = solve_quadratic(a, b, c, &x_res1, &x_res2);

        if (n_res != n_roots ||
            compare_double(x1, x_res1) != 0 ||
            compare_double(x2, x_res2) != 0)
        {
            printf("Test for solve_linear FAILED (line %d)\n",
                get_case_number(file));
            printf("Expected result:\tn_roots\t= %d,\tx1\t= %lg\tx2\t=%lg\n",
                n_roots, x1, x2);
            printf("Actual result:\tn_roots\t= %d,\tx\t= %lg\tx2\t=%lg\n\n",
                n_res, x_res1, x_res2);
            failed++;
        }
        test_count++;
    }
    printf("%d tests finished. Successful tests: %d, failed tests: %d\n",
        test_count, test_count - failed, failed);
    printf("-------------------------------\n");

    close_test_file(file);
}