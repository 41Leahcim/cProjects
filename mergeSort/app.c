#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 30000000

typedef struct Array{
    uint64_t *numbers;
    size_t length;
} Array;

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

void printArray(Array arr){
    for(size_t i = 0;i < arr.length;i++){
        printf("%lu ", arr.numbers[i]);
    }
    printf("\n");
}

void swap(uint64_t *number1, uint64_t *number2){
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

void sort(Array *arr, Array *array2, Array *array3){
    uint64_t i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while(i < array2->length && j < array3->length){
        if(array2->numbers[i] < array3->numbers[j]){
            arr->numbers[k++] = array2->numbers[i++];
        }else{
            arr->numbers[k++] = array3->numbers[j++];
        }
    }
    while(i < array2->length){
        arr->numbers[k++] = array2->numbers[i++];
    }
    while(j < array3->length){
        arr->numbers[k++] = array3->numbers[j++];
    }
}

void mergeSort(Array *arr){
    if(arr->length == 1){
        return;
    }else if(arr->length == 2){
        if(arr->numbers[0] > arr->numbers[1]){
            swap(arr->numbers, arr->numbers + 1);
        }
        return;
    }
    size_t i;
    Array copy = {(uint64_t*)malloc(sizeof(uint64_t) * arr->length), arr->length};
    for(i = 0;i < copy.length;i++){
        copy.numbers[i] = arr->numbers[i];
    }
    Array array2 = {copy.numbers, copy.length / 2};
    Array array3 = {copy.numbers + array2.length, copy.length - array2.length};
    mergeSort(&array2);
    mergeSort(&array3);
    sort(arr, &array2, &array3);
    free(copy.numbers);
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
    mergeSort(&numbers);
    printArraySlice(numbers, 0, 10);
    free(numbers.numbers);
    printf("took: %lf seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
