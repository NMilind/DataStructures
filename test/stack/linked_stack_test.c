#include "linked_stack_test.h"
#include "../../stack/linked_stack.h"

static int test_initialization()
{
    LinkedStack stack;
    LinkedStackConstruct(&stack);

    TEST_ASSERT_TRUE(stack.size(&stack) == 0);

    LinkedStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

static int test_push_peek()
{
    LinkedStack stack;
    LinkedStackConstruct(&stack);

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

    LinkedStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

static int test_pop()
{
    LinkedStack stack;
    LinkedStackConstruct(&stack);

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

    LinkedStackDestroy(&stack);

    return TEST_CASE_SUCCESS;
}

void linked_stack_test_setup()
{
    TEST_SUITE({

        TEST_CASE("Linked Stack Initialization", &test_initialization);
        TEST_CASE("Linked Stack Push Peek", &test_push_peek);
        TEST_CASE("Linked Stack Pop", &test_pop);
    });
}