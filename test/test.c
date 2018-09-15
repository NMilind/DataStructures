/**
 * @file main.c
 * @author Nikhil Milind
 *
 * All tests are deployed from here.
 */

#include <stdio.h>
#include <stdlib.h>

#include "test_case.h"
#include "list/array_list_test.h"
#include "list/singly_linked_list_test.h"
#include "list/doubly_linked_list_test.h"
#include "stack/array_stack_test.h"
#include "stack/linked_stack_test.h"

#define FORMAT(name,id) printf(SEPARATOR); printf(TEST_OUT "+ " name " Tests\n" TEST_RESET); id;  printf(TEST_OUT "+\n" TEST_RESET);

int main()
{
    printf(SEPARATOR);
    printf(TEST_OUT "+ Testing Data Structure\n" TEST_RESET);
    printf(TEST_OUT "+\n" TEST_RESET);

    FORMAT("Array List Tests", array_list_test_setup());

    FORMAT("Singly-Linked List Test", singly_linked_list_setup());

    FORMAT("Doubly-Linked List Tests", doubly_linked_list_test_setup());

    FORMAT("Array Stack Tests", array_stack_test_setup());

    FORMAT("Linked Stack Tests", linked_stack_test_setup());

    return EXIT_SUCCESS;
}