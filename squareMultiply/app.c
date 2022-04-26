#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint64_t squareMultiplyUint32ToUint64(uint32_t number, uint8_t exponent){
    uint64_t result = 1;
    uint64_t num = number;
    while(exponent > 0){
        if(exponent & 1){
            result *= num;
        }
        exponent >>= 1;
        if(exponent != 0 && (UINT64_MAX / result < num || UINT64_MAX / num < num)){
            printf("%lu / %lu = %lu\n", UINT64_MAX, result, UINT64_MAX / result);
            printf("%lu / %lu = %lu\n", UINT64_MAX, num, UINT64_MAX / num);
            return 0;
        }else if(exponent != 0){
            num *= num;
        }
    }
    return result;
}

int main(){
    while(1){
        uint32_t number, exponent;
        uint64_t result;
        printf("Enter the number (0 - %u): ", UINT32_MAX);
        scanf("%u", &number);
        printf("Enter the exponent (0 - 63): ");
        scanf("%u", &exponent);
        if(exponent > 63){
            printf("ERROR: Invalid input!\n");
        }else{
            result = squareMultiplyUint32ToUint64(number, exponent);
            if(result == 0){
                printf("ERROR: calculation failed, number and exponent are not compatible!\n");
            }else{
                printf("%u to the %uth is: %lu\n\n", number, exponent, squareMultiplyUint32ToUint64(number, exponent));
            }
        }
    }
}
