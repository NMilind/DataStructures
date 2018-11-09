#include <stdio.h>

#define TARGET 1000

void run1()
{
    int sum = 0;

    for (int i = 0; i < TARGET; i += 3) {
        sum += i;
    }

    for (int i = 0; i < TARGET; i += 5) {
        sum += i;
    }

    for (int i = 0; i < TARGET; i += 15) {
        sum -= i;
    }

    printf("Sum of Multiples of 3 and 5 below %d: %d\n", TARGET, sum);
}