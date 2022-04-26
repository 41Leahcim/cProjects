#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *array;
    size_t i;
    size_t maxSize = 1;
    while(1){
        array = (char*)malloc(maxSize);
        for(i = 0;i < maxSize;i++){
            array[i] = i;
        }
        printf("\r%lu", maxSize);
        maxSize = maxSize << 1;
        usleep(10000);
    }
}
