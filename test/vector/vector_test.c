#include "vector_test.h"
#include "../../vector/vector.h"

static int test_initialization()
{
    Vector vector;
    VectorConstruct(&vector);

    TEST_ASSERT_TRUE(vector.size(&vector) == 0);

    VectorDestroy(&vector);

    return TEST_CASE_SUCCESS;
}

static int test_add()
{
    Vector vector;
    VectorConstruct(&vector);

    int x = 0;
    int y = 1;
    int z = 2;

    // Test addition at indices
    vector.add(&vector, 0, &x);
    vector.add(&vector, 1, &z);
    vector.add(&vector, 1, &y);

    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == x);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == y);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 2) == z);

    int a = 100;
    int b = 200;

    // Test addition at terminal ends
    vector.addFirst(&vector, &a);
    vector.addLast(&vector, &b);

    TEST_ASSERT_TRUE(*(int *) vector.first(&vector) == a);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == a);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == x);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 2) == y);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 3) == z);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 4) == b);
    TEST_ASSERT_TRUE(*(int *) vector.last(&vector) == b);

    VectorDestroy(&vector);

    return TEST_CASE_SUCCESS;
}

static int test_remove()
{
    Vector vector;
    VectorConstruct(&vector);

    int v = 0;
    int w = 1;
    int x = 2;
    int y = 3;
    int z = 4;

    vector.addLast(&vector, &v);
    vector.addLast(&vector, &w);
    vector.addLast(&vector, &x);
    vector.addLast(&vector, &y);
    vector.addLast(&vector, &z);

    // Remove in the middle
    int *x_rem = (int *) vector.rem(&vector, 2);
    TEST_ASSERT_TRUE(vector.size(&vector) == 4);
    TEST_ASSERT_TRUE(*x_rem == x);

    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == v);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == w);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 2) == y);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 3) == z);

    // Remove from front
    int *v_rem = (int *) vector.remFirst(&vector);
    TEST_ASSERT_TRUE(vector.size(&vector) == 3);
    TEST_ASSERT_TRUE(*v_rem == v);

    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == w);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == y);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 2) == z);

    // Remove from end
    int *z_rem = (int *) vector.remLast(&vector);
    TEST_ASSERT_TRUE(vector.size(&vector) == 2);
    TEST_ASSERT_TRUE(*z_rem == z);

    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == w);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == y);

    VectorDestroy(&vector);

    return TEST_CASE_SUCCESS;
}

static int test_set()
{
    Vector vector;
    VectorConstruct(&vector);

    int v = 0;
    int w = 1;
    int x = 2;
    int y = 3;
    int z = 4;

    int a = 1000;

    vector.addLast(&vector, &v);
    vector.addLast(&vector, &w);
    vector.addLast(&vector, &x);
    vector.addLast(&vector, &y);
    vector.addLast(&vector, &z);

    // Set a value
    int *x_rem = vector.set(&vector, 2, &a);
    TEST_ASSERT_TRUE(*x_rem == x);

    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 0) == v);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 1) == w);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 2) == a);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 3) == y);
    TEST_ASSERT_TRUE(*(int *) vector.get(&vector, 4) == z);

    VectorDestroy(&vector);

    return TEST_CASE_SUCCESS;
}

void vector_test_setup()
{
    TEST_SUITE({

        TEST_CASE("Vector Initialization", &test_initialization);
        TEST_CASE("Vector Add", &test_add);
        TEST_CASE("Vector Remove", &test_remove);
        TEST_CASE("Vector Set", &test_set);
    });
}