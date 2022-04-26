#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_LENGTH 40000LU

typedef struct Array{
    uint64_t *array;
    size_t length;
} Array;

size_t linearSearch(Array *array, uint64_t number){
    size_t i;
    for(i = 0;i < array->length && array->array[i] != number;i++){}
    return i;
}

int main(){
    clock_t start = clock(), took;
    Array array;
    array.array = (uint64_t*)malloc(ARRAY_LENGTH * sizeof(uint64_t));
    array.length = 0;
    uint64_t number;
    while(array.length < ARRAY_LENGTH){
        number = (uint64_t)rand() * rand();
        if(linearSearch(&array, number) == array.length){
            array.array[array.length++] = number;
        }
    }
    free(array.array);
    took = clock() - start;
    printf("Filling the array of size %lu, took %lf seconds.\n", ARRAY_LENGTH, (double)took / CLOCKS_PER_SEC);
}
