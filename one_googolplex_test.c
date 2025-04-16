#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include </opt/homebrew/include/gmp.h>

// Function to print binary representation of an mpz_t number (limited to max_bits)
void print_binary_gmp(mpz_t number, int max_bits) {
    for (int i = max_bits - 1; i >= 0; i--) {
        printf("%d", mpz_tstbit(number, i));
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to calculate 10^1000 using GMP and measure time
void test_ten_to_the_1000() {
    mpz_t result;
    mpz_init(result);

    long total_time_ns = 0;
    int num_tests = 100;

    for (int test = 0; test < num_tests; test++) {
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Compute 10^1000
        mpz_ui_pow_ui(result, 10, 1000);

        clock_gettime(CLOCK_MONOTONIC, &end);

        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
        total_time_ns += elapsed_ns;
    }

    long average_time_ns = total_time_ns / num_tests;

    printf("Test - 10^1000 Operation:\n");
    printf("Result = 10^1000\n");
    printf("First 512 bits in binary: ");
    print_binary_gmp(result, 512);
    printf("Average time for %d iterations: %ld nanoseconds\n", num_tests, average_time_ns);

    mpz_clear(result);
}

int main() {
    test_ten_to_the_1000();
    return 0;
}
