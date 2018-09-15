#include "test_case.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Test Case Constructor / Destructor
 */

/**
 * Constructs a new Test Case
 * @param test_case the test case to construct
 * @param name the name of the test case
 * @param run the function to run in the test case
 */
void TestCaseConstruct(TestCase *test_case, char *name, int (*run)())
{
    test_case->name = (char *) malloc(strlen(name));
    strcpy(test_case->name, name);

    test_case->run = run;
}

/**
 * Destroys an instance of a Test Case
 * @param test_case the test case to destroy
 */
void TestCaseDestroy(TestCase *test_case)
{
    free(test_case->name);
}

/*
 * Test Suite Instance Member Functions
 */

/**
 * Run the test cases in a test suite
 * @param suite the suite to run
 */
int run_test_cases(TestSuite *suite)
{
    int status = TEST_CASE_SUCCESS;
    for (unsigned int i = 0; i < suite->test_cases->size; i++) {
        TestCase *test_case = (TestCase *) suite->test_cases->get(suite->test_cases, i);
        printf(SEPARATOR);
        printf(TEST_OUT "+ \tRunning Test Case: %s\n" TEST_RESET, test_case->name);
        if (test_case->run() != TEST_CASE_SUCCESS) {
            status = TEST_CASE_FAILURE;
            printf(TEST_ERROR "+ \tTest Case Failed!\n" TEST_RESET);
        }
        else {
            printf(TEST_SUCCESS "+ \tTest Case Passed!\n" TEST_RESET);
        }
        printf(SEPARATOR);
    }
    return status;
}

/*
 * Test Suite Constructor / Destructor
 */

/**
 * Construct a new test suite
 * @param suite a pointer to the suite
 */
void TestSuiteConstruct(TestSuite *suite)
{
    suite->test_cases = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayListConstruct(suite->test_cases);

    suite->run = &run_test_cases;
}

/**
 * Destroy a test suite
 * @param suite the test suite to destroy
 */
void TestSuiteDestroy(TestSuite *suite)
{
    ArrayListDestroy(suite->test_cases);
}