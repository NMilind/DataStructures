#include <stdio.h>
#include <math.h>

#define MAX_FIBONACCI 4000000

long fib(long n, double sqrt5, double phi, double iphi)
{
    return (long)floor((pow(phi, n) - pow(iphi, n)) / sqrt5);
}

void run2()
{
    double sqrt5 = sqrt(5);
    double phi = (1.0 + sqrt5) / 2.0;
    double iphi = (1.0 - sqrt5) / 2.0;

    long n = 3;
    long fibonacci = fib(n, sqrt5, phi, iphi);
    long sum = 0;
    do {
        sum += fibonacci;
        n += 3;
        fibonacci = fib(n, sqrt5, phi, iphi);
    } while (fibonacci <= MAX_FIBONACCI);

    printf("Sum of Even Fibonnaci Numbers <= %d: %ld\n", MAX_FIBONACCI, sum);
}