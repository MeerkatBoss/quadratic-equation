#ifndef TESTING_H
#define TESTING_H

#include "text_styles.h"
#include <math.h>

void __testing_assert_true(int condition, const char* condition_str);
void __testing_init_test(const char* name);
void __testing_collect_test(const char* name);
void __testing_init_test_case(void);
void __testing_collect_test_case(void);
int __testing_check_test_case_running(void);

#define TEST_SOURCE(func) "./test_cases/" #func "_test.txt"

#define __COLLECT_TEST(func) do                                     \
{                                                                   \
} while(0)

#define __TEST_NAME(func) __test_##func

#define TEST(func) void __TEST_NAME(func)(void)

#define RUN_TEST(func) do           \
{                                   \
    __testing_init_test(#func);     \
    __TEST_NAME(func)();            \
    __testing_collect_test(#func);  \
} while (0)

#define TEST_CASE                               \
    for (                                       \
        __testing_init_test_case();             \
        __testing_check_test_case_running();    \
        __testing_collect_test_case()           \
    )

#define TEST_CASE_ABORT break

#define ASSERT_TRUE(condition)\
    __testing_assert_true(condition, #condition);

#define ASSERT_EQUAL(expected, actual, format) do   \
{                                                   \
    ASSERT_TRUE(expected == actual);                \
    if (expected != actual)                         \
        printf("\tExpected result: " format         \
                ", actual result: " format "\n",    \
                expected, actual);                  \
} while (0)

#define ASSERT_DOUBLE_EQUAL(expected, actual, format) do\
{                                                       \
    ASSERT_TRUE(fabs(expected - actual) < 1e-8);        \
    if (fabs(expected - actual) >= 1e-8)                \
        printf("\tExpected result: " format             \
                ", actual result: " format "\n",        \
                expected, actual);                      \
} while (0)

#endif