#include <stdlib.h>
#include <stdio.h>
#include <time.h>

extern void run2();

int main()
{
    clock_t start = clock();
    run2();
    clock_t end = clock();

    printf("Time Required for Execution: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}