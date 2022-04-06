#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_LENGTH 40000

typedef struct Array{
    uint64_t *numbers;
    size_t length;
} Array;

void sort(Array *array){
    size_t i = 1;
    while(i < array->length){
        if(array->numbers[i - 1] > array->numbers[i]){
            array->numbers[i] ^= array->numbers[i - 1];
            array->numbers[i - 1] ^= array->numbers[i];
            array->numbers[i] ^= array->numbers[i - 1];
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

void printArraySlice(Array arr, size_t begin, size_t end){
    if(begin < end){
        for(size_t i = begin;i < end;i++){
            printf("%lu ", arr.numbers[i]);
        }
    }else{
        for(size_t i = end;i > begin;i--){
            printf("%lu ", arr.numbers[i]);
        }
    }
    printf("\n");
}

int main(){
    Array numbers;
    clock_t start = clock();
    numbers.numbers = (uint64_t*)malloc(sizeof(uint64_t) * ARRAY_LENGTH);
    numbers.length = ARRAY_LENGTH;
    for(size_t i = 0;i < numbers.length;i++){
        numbers.numbers[i] = numbers.length - i;
    }
    printArraySlice(numbers, 0, 10);
    sort(&numbers);
    printArraySlice(numbers, 0, 10);
    free(numbers.numbers);
    printf("took: %lf seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
