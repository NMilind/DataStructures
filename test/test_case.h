/**
 * @file test_case.h
 * @author Nikhil Milind
 *
 * Defines a basic test case that has a name,
 * a certain number of tests, and ability to execute.
 */

#include "../list/array_list.h"
#include <stdio.h>

#ifndef DATASTRUCTURES_TEST_CASE
#define DATASTRUCTURES_TEST_CASE

#define SEPARATOR "\x1B[33m" "+------------------------------------------------------------------------------\n" "\x1B[0m"
#define TEST_RESET "\x1B[0m"
#define TEST_OUT "\x1B[33m"
#define TEST_SUCCESS "\x1B[32m"
#define TEST_ERROR "\x1B[31m"

#define TEST_CASE_SUCCESS 0
#define TEST_CASE_FAILURE 1

#define TEST_ASSERT_TRUE(statement) if (!(statement)) { return TEST_CASE_FAILURE; }
#define TEST_ASSERT_FALSE(statement) if (statement) { return TEST_CASE_FAILURE; }
#define TEST_LOG(log) printf("\x1B[37m" "+ \tLog: " log "\n" "\x1B[0m");

#define TEST_SUITE(block) { TestSuite ts; TestSuiteConstruct(&ts); block; ts.run(&ts); for (unsigned int i = 0; i < ts.test_cases->size; i++) { TestCaseDestroy(ts.test_cases->get(ts.test_cases, i)); } TestSuiteDestroy(&ts); }
#define TEST_CASE(name,func) { TestCase tc; TestCaseConstruct(&tc, name, func); ts.test_cases->addLast(ts.test_cases, &tc); }

struct test_case
{
    char *name;
    int (*run) ();
};

typedef struct test_case TestCase;

extern void TestCaseConstruct(TestCase *test_case, char *name, int (*run)());

extern void TestCaseDestroy(TestCase *test_case);

struct test_suite
{
    ArrayList *test_cases;
    int (*run) (struct test_suite *suite);
};

typedef struct test_suite TestSuite;

extern void TestSuiteConstruct(TestSuite *suite);

extern void TestSuiteDestroy(TestSuite *suite);

#endif