cmake_minimum_required(VERSION 3.12)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

set(EULER_FILES euler/main.c euler/project1.c euler/project2.c euler/project3.c)

set(LIST_FILES list/array_list.c list/doubly_linked_list.c list/singly_linked_list.c list/circularly_linked_list.c)
set(STACK_FILES stack/array_stack.c stack/linked_stack.c)
set(QUEUE_FILES queue/linked_queue.c)
set(VECTOR_FILES vector/vector.c)
set(SOURCE_FILES ${LIST_FILES} ${STACK_FILES} ${QUEUE_FILES} ${VECTOR_FILES})

set(TEST_FILES test/test_case.c)
set(TEST_FILES ${TEST_FILES}
        test/list/array_list_test.c
        test/list/singly_linked_list_test.c
        test/list/doubly_linked_list_test.c
        test/list/circularly_linked_list_test.c)
set(TEST_FILES ${TEST_FILES} test/stack/array_stack_test.c test/stack/linked_stack_test.c)
set(TEST_FILES ${TEST_FILES} test/vector/vector_test.c)

add_executable(DataStructures ${EULER_FILES} ${SOURCE_FILES})
add_executable(DataStructuresTest test/test.c ${TEST_FILES} ${SOURCE_FILES})
add_library(DataStructuresLib STATIC ${SOURCE_FILES})