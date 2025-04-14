#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    struct timespec start_time, end_time;
    double time_taken_sec;
    long long time_taken_ns;
    double time_taken_ms;

    // Start high-resolution timer
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Run QEMU with your image (adjust path as needed)
    int ret = system("qemu-system-x86_64 -drive file=god_code_pulse_test.img,format=raw");


    if (ret == -1) {
        perror("QEMU execution failed");
        return 1;
    }

    // End high-resolution timer
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate time differences
    time_taken_ns = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL +
                    (end_time.tv_nsec - start_time.tv_nsec);
    time_taken_sec = time_taken_ns / 1e9;
    time_taken_ms = time_taken_ns / 1e6;

    // Estimate number of operations
    long double ops = 10.0L * powl(2.0L, 128.0L);

    // Calculate ops per second
    long double ops_per_sec = ops / time_taken_sec;

    // Display results
    printf("---- Runtime Report ----\n");
    printf("Time taken: %.6f seconds\n", time_taken_sec);
    printf("Time taken: %.3f milliseconds\n", time_taken_ms);
    printf("Time taken: %lld nanoseconds\n", time_taken_ns);
    printf("Estimated operations performed: %.7Le\n", ops);
    printf("Estimated operations per second: %.7Le\n", ops_per_sec);

    return 0;
}
