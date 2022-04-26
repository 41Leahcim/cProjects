#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_LENGTH 20000LU

typedef struct Array{
    uint64_t *array;
    size_t length;
} Array;

size_t binarySearch(Array *array, uint64_t number){
    size_t a = 0, b = array->length, i;
    while(a < i && i < b){
        i = (a + b) / 2;
        if(array->array[i] > number){
            b = i;
        }else if(array->array[i] < number){
            a = i;
        }else{
            return i;
        }
    }
    return array->length;
}

void bubbleSort(Array *array){
    size_t i = 1;
    while(i < array->length){
        if(array->array[i - 1] > array->array[i]){
            array->array[i] ^= array->array[i - 1];
            array->array[i - 1] ^= array->array[i];
            array->array[i] ^= array->array[i - 1];
            if(i > 1){
                i--;
            }else{
                i++;
            }
        }else{
            i++;
        }
    }
}

int main(){
    clock_t start = clock(), took;
    Array array;
    array.array = (uint64_t*)malloc(ARRAY_LENGTH * sizeof(uint64_t));
    array.length = 0;
    uint64_t number;
    while(array.length < ARRAY_LENGTH){
        number = (uint64_t)rand() * rand();
        if(binarySearch(&array, number) == array.length){
            array.array[array.length++] = number;
            bubbleSort(&array);
        }
    }
    free(array.array);
    took = clock() - start;
    printf("Filling the array of size %lu, took %lf seconds.\n", ARRAY_LENGTH, (double)took / CLOCKS_PER_SEC);
}
