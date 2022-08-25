#include <stdio.h>
#include "quadratic_tests.h"

int main()
{
    RUN_TEST(solve_linear);
    RUN_TEST(solve_quadratic);
    return 0;
}
