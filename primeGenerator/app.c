#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

const size_t MAX_VALUE = 66000000000;

typedef struct Array{
    uint64_t *numbers;
    size_t length;
} Array;

void initializePrimes(Array *primes){
    for(size_t i = 0;i < primes->length;i++){
        primes->numbers[i] = -1;
    }
    primes->numbers[0] &= ~(uint64_t)3;
}

void filterPrimes(Array *primes, const size_t i){
    size_t j;
    for(j = i * i;j < MAX_VALUE;j += i){
        primes->numbers[j / 64] &= ~((uint64_t)1 << (j & 63));
    }
}

size_t findNextPrime(const Array *primes, size_t i){
    while(i < MAX_VALUE && (primes->numbers[i / 64] & ((uint64_t)1 << (i & 63))) == 0) i++;
    return i;
}

void checkPrintPrimes(Array *primes){
    size_t i;
    for(i = 2;i <= MAX_VALUE / i;i++){
        i = findNextPrime(primes, i);
        if(i <= MAX_VALUE / i){
            filterPrimes(primes, i);
        }
        printf("%lu\n", i);
    }
    while(i < MAX_VALUE){
        i = findNextPrime(primes, i);
        printf("%lu\n", i);
        i++;
    }
}

void displayDuration(clock_t took){
    double seconds = (double)took / CLOCKS_PER_SEC;
    uint64_t minutes = (uint64_t)(seconds / 60) % 60;
    uint64_t hours = seconds / 3600;
    seconds -= hours * 3600 + minutes * 60;
    printf("Generating and displaying all the primes took: ");
    if(hours > 0){
        printf("%lu:%lu:%lf\n", hours, minutes, seconds);
    }else if(minutes > 0){
        printf("%lu:%lf\n", minutes, seconds);
    }else{
        printf("%lf seconds\n", seconds);
    }
}

int main(){
    clock_t start = clock();
    Array primes;
    primes.length = (MAX_VALUE / 64) + 1;
    primes.numbers = (uint64_t*)malloc(sizeof(uint64_t) * primes.length);
    initializePrimes(&primes);
    checkPrintPrimes(&primes);
    free(primes.numbers);
    displayDuration(clock() - start);
}
