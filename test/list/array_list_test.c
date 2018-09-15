#include "array_list_test.h"
#include "../../list/array_list.h"

static int test_initialization()
{
    ArrayList list;
    ArrayListConstruct(&list);

    TEST_ASSERT_TRUE(list.size == 0);

    ArrayListDestroy(&list);

    return TEST_CASE_SUCCESS;
}

static int test_add()
{
    ArrayList list;
    ArrayListConstruct(&list);

    // Test addition by index
    int x = 0;
    int y = 1;
    int z = 2;

    TEST_ASSERT_TRUE(list.size == 0);

    list.add(&list, 0, &x);
    list.add(&list, 1, &y);
    list.add(&list, 2, &z);

    TEST_ASSERT_TRUE(list.size == 3);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == 0);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == 1);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == 2);

    // Insert into middle
    int a = 100;

    list.add(&list, 1, &a);

    TEST_ASSERT_TRUE(list.size == 4);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == 0);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == 100);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == 1);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == 2);

    // Insert first and last
    int b = 1000;
    int c = 2000;

    list.addFirst(&list, &b);
    list.addLast(&list, &c);

    TEST_ASSERT_TRUE(list.size == 6);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == 1000);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == 0);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == 100);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == 1);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 4) == 2);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 5) == 2000);

    // Test growth past initial capacity
    list.addLast(&list, &a);
    list.addLast(&list, &b);
    list.addLast(&list, &c);
    list.addLast(&list, &x);
    list.addLast(&list, &y);
    list.addLast(&list, &z);

    TEST_ASSERT_TRUE(list.size == 12);
    TEST_ASSERT_TRUE(list.capacity = 20);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == 1000);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == 0);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == 100);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == 1);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 4) == 2);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 5) == 2000);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 6) == 100);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 7) == 1000);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 8) == 2000);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 9) == 0);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 10) == 1);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 11) == 2);

    ArrayListDestroy(&list);

    return TEST_CASE_SUCCESS;
}

static int test_remove()
{
    ArrayList list;
    ArrayListConstruct(&list);

    int a = 10;
    int b = 5;
    int c = 2;
    int d = 8;
    int e = -2;

    list.addLast(&list, &a);
    list.addLast(&list, &b);
    list.addLast(&list, &c);
    list.addLast(&list, &d);
    list.addLast(&list, &e);

    TEST_ASSERT_TRUE(list.size == 5);

    // Remove from the middle
    int *c_rem = (int *) list.remove(&list, 2);

    TEST_ASSERT_TRUE(list.size == 4);
    TEST_ASSERT_TRUE(*c_rem == c);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == a);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == b);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == d);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == e);

    // Remove from beginning
    int *a_rem = (int *) list.removeFirst(&list);

    TEST_ASSERT_TRUE(list.size == 3);
    TEST_ASSERT_TRUE(*a_rem == a);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == b);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == d);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == e);

    // Remove from end
    int *e_rem = (int *) list.removeLast(&list);

    TEST_ASSERT_TRUE(list.size == 2);
    TEST_ASSERT_TRUE(*e_rem == e);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == b);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == d);

    ArrayListDestroy(&list);

    return TEST_CASE_SUCCESS;
}

static int test_get_set()
{
    ArrayList list;
    ArrayListConstruct(&list);

    int a = 10;
    int b = 5;
    int c = 2;
    int d = 8;
    int e = -2;

    list.addLast(&list, &a);
    list.addLast(&list, &b);
    list.addLast(&list, &c);
    list.addLast(&list, &d);
    list.addLast(&list, &e);

    TEST_ASSERT_TRUE(list.size == 5);

    // Test get
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == a);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == b);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == c);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == d);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 4) == e);

    // Set first, middle, last elements
    int x = 100;
    int y = 200;
    int z = 300;

    list.set(&list, 0, &x);
    list.set(&list, 2, &y);
    list.set(&list, 4, &z);

    TEST_ASSERT_TRUE(*(int *) list.get(&list, 0) == x);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 1) == b);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 2) == y);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 3) == d);
    TEST_ASSERT_TRUE(*(int *) list.get(&list, 4) == z);

    ArrayListDestroy(&list);

    return TEST_CASE_SUCCESS;
}

void array_list_test_setup()
{
    TEST_SUITE({

        TEST_CASE("Array List Initialization", &test_initialization);
        TEST_CASE("Array List Add", &test_add);
        TEST_CASE("Array List Remove", &test_remove);
        TEST_CASE("Array List Get Set", &test_get_set);
    });
}