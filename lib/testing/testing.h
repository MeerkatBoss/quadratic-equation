#ifndef TESTING_H
#define TESTING_H

/**
 * @file testing.h
 * @author MeerkatBoss
 * @brief Contains macros for testing
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "text_styles.h"
#include <math.h>

void __testing_assert_true(int condition, const char* condition_str);
void __testing_init_test(const char* name);
void __testing_collect_test(const char* name);
void __testing_init_test_case(void);
void __testing_collect_test_case(void);
int __testing_check_test_case_running(void);
int __testing_add_test(void (*test)(void), const char* test_name);
void run_all_tests(void);

/**
 * @brief Gets name of file, containing tests for func
 * 
 * @param[in] func - tested function
 */
#define TEST_SOURCE(func) "test_cases/" #func "_test.txt"

#define __TEST_NAME(func) __test_##func

/**
 * @brief Defines testing function for provided function
 * 
 * @param[in] func - tested function
 */
#define TEST(func)\
    void __TEST_NAME(func)(void);\
    static int __init_##func = __testing_add_test(&__TEST_NAME(func), #func);\
    void __TEST_NAME(func)(void)

/**
 * @brief Defines testing case
 */
#define TEST_CASE                               \
    for (                                       \
        __testing_init_test_case();             \
        __testing_check_test_case_running();    \
        __testing_collect_test_case()           \
    )

/**
 * @brief Interrupts execution of current test case
 */
#define TEST_CASE_ABORT continue

/**
 * @brief If condition is false, prints Assertion failed message
 * 
 * @param[in] condition - tested condition
 */
#define ASSERT_TRUE(condition)\
    __testing_assert_true(condition, #condition);

/**
 * @brief If expected is not equal to actual, prints Assertion failed message
 * 
 * @param[in] expected - Expected value
 * @param[in] actual - Actual value
 * @param[in] format - Printf format for printing expected and actual
 */
#define ASSERT_EQUAL(expected, actual, format) do   \
{                                                   \
    ASSERT_TRUE(expected == actual);                \
    if (expected != actual)                         \
        printf("\tExpected result: " format         \
                ", actual result: " format "\n",    \
                expected, actual);                  \
} while (0)

/**
 * @brief If expected is not equal to actual, prints Assertion failed message
 * 
 * @param[in] expected - Expected double value
 * @param[in] actual - Actual double value
 * @param[in] format - Printf format for printing expected and actual
 */
#define ASSERT_DOUBLE_EQUAL(expected, actual, format) do\
{                                                       \
    ASSERT_TRUE(fabs(expected - actual) < 1e-8);        \
    if (fabs(expected - actual) >= 1e-8)                \
        printf("\tExpected result: " format             \
                ", actual result: " format "\n",        \
                expected, actual);                      \
} while (0)

#endif