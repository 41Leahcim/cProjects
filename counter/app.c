#include <stdio.h>
#include <time.h>
#include <stdint.h>

const uint64_t max = 2900000000000;

int main(){
    clock_t start = clock();
    for(volatile uint64_t i = 0;i < max;i++){}
    printf("It took %lf seconds to count to %lu\n", (double)(clock() - start) / CLOCKS_PER_SEC, max);
}
