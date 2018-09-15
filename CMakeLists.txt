cmake_minimum_required(VERSION 3.12)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

set(LIST_FILES list/array_list.c list/doubly_linked_list.c list/singly_linked_list.c)
set(STACK_FILES stack/array_stack.c stack/linked_stack.c)
set(VECTOR_FILES vector/vector.c)
set(SOURCE_FILES ${LIST_FILES} ${STACK_FILES} ${VECTOR_FILES})

set(TEST_FILES test/test_case.c)
set(TEST_FILES ${TEST_FILES} test/list/array_list_test.c test/list/singly_linked_list_test.c test/list/doubly_linked_list_test.c)
set(TEST_FILES ${TEST_FILES} test/stack/array_stack_test.c test/stack/linked_stack_test.c)

add_executable(DataStructures main.c ${SOURCE_FILES})
add_executable(DataStructuresTest test/test.c ${TEST_FILES} ${SOURCE_FILES})