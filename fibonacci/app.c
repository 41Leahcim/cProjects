#include <stdio.h>

int main(){
    unsigned long long numbers[2] = {0, 1};
    printf("0\n");
    while(numbers[0] <= numbers[1]){
        printf("%llu\n", numbers[1]);
        numbers[1] += numbers[0];
        numbers[0] = numbers[1] - numbers[0];
    }
}
