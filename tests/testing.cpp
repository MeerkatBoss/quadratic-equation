#include <stdio.h>
#include "testing.h"

enum test_state
{
    TEST_NONE    = 0,
    TEST_SUCCESS = 1,
    TEST_FAILURE = -1
};

static struct
{
    int tests_total;
    int tests_failed;
    enum test_state state;
} __current_testing_state 
    {.tests_total = 0, .tests_failed = 0, .state = TEST_NONE};

void __testing_assert_true(int condition, const char* condition_str)
{
    if (!(condition))
    {
        printf(TEXT_NOTE("ASSERTION FAILED: ") "\'%s\' in test case %d\n",
            condition_str, __current_testing_state.tests_total);
        __current_testing_state.state = TEST_FAILURE;
    }
}

void __testing_init_test(const char* name)
{
    printf(TEXT_INFO("== RUNNING TESTS FOR \'%s\' ==")"\n", name);
    __current_testing_state = {
        .tests_total = 0, .tests_failed = 0, .state = TEST_NONE};
}

void __testing_collect_test(const char* name)
{
    if (__current_testing_state.tests_failed)
        printf(TEXT_ERROR("## TESTS FOR \'%s\' FAILED ##")"\n"
                "\t" TEXT_NOTE("Tests total: ") "%d\n"
                "\t" TEXT_BAD("Tests failed: ") "%d\n"
                "\n",
                name,
                __current_testing_state.tests_total,
                __current_testing_state.tests_failed);
    else
        printf(TEXT_SUCCESS(">> All tests for \'%s\' passed <<")"\n"
                "\t" TEXT_NOTE("Tests total: ") "%d\n"
                "\n",
                name, __current_testing_state.tests_total);
}

void __testing_init_test_case(void)
{
    __current_testing_state.tests_total++;
    __current_testing_state.state = TEST_NONE;
}

void __testing_collect_test_case(void)
{
    if (__current_testing_state.state == TEST_FAILURE)
        __current_testing_state.tests_failed++;
    else
        __current_testing_state.state = TEST_SUCCESS;
}

int __testing_check_test_case_running(void)
{
    return __current_testing_state.state == TEST_NONE;
}
