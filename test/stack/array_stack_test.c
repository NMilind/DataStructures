#include "array_stack_test.h"
#include "../../stack/array_stack.h"

static int test_initialization()
{
    ArrayStack stack;
    ArrayStackConstruct(&stack);

    TEST_ASSERT_TRUE(stack.size(&stack) == 0);

    ArrayStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

static int test_push_peek()
{
    ArrayStack stack;
    ArrayStackConstruct(&stack);

    // Test pushing onto the stack
    int x = 0;
    int y = 1;
    int z = 2;

    TEST_ASSERT_TRUE(stack.size(&stack) == 0);

    stack.push(&stack, &x);
    TEST_ASSERT_TRUE(stack.size(&stack) == 1);
    TEST_ASSERT_TRUE(*(int *) stack.peek(&stack) == x);

    stack.push(&stack, &y);
    TEST_ASSERT_TRUE(stack.size(&stack) == 2);
    TEST_ASSERT_TRUE(*(int *) stack.peek(&stack) == y);

    stack.push(&stack, &z);
    TEST_ASSERT_TRUE(stack.size(&stack) == 3);
    TEST_ASSERT_TRUE(*(int *) stack.peek(&stack) == z);

    ArrayStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

static int test_pop()
{
    ArrayStack stack;
    ArrayStackConstruct(&stack);

    int x = 0;
    int y = 1;
    int z = 2;

    stack.push(&stack, &x);
    stack.push(&stack, &y);
    stack.push(&stack, &z);

    // Test pop
    TEST_ASSERT_TRUE(*(int *) stack.pop(&stack) == z);
    TEST_ASSERT_TRUE(stack.size(&stack) == 2);

    TEST_ASSERT_TRUE(*(int *) stack.pop(&stack) == y);
    TEST_ASSERT_TRUE(stack.size(&stack) == 1);

    TEST_ASSERT_TRUE(*(int *) stack.pop(&stack) == x);
    TEST_ASSERT_TRUE(stack.size(&stack) == 0);

    ArrayStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

void array_stack_test_setup()
{
    TEST_SUITE({

        TEST_CASE("Array Stack Initialization", &test_initialization);
        TEST_CASE("Array Stack Push Peek", &test_push_peek);
        TEST_CASE("Array Stack Pop", &test_pop);
    });
}