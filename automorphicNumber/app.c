/*
 * Name: Michael Scholten
 * Description:
 * Reads a number from the screen and displays whether it's an automorphic number.
 * An automorphic number is a number of which the square ends with that number.
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint8_t getNumberOfDigits(uint64_t number){
    uint8_t result = 0;
    do{
        number /= 10;
        result++;
    }while(number > 0);
    return result;
}

uint64_t power10(uint8_t exponent){
    uint64_t result = 1;
    while(exponent > 0){
        result *= 10;
        exponent--;
    }
    return result;
}

uint32_t readUint32(){
    uint32_t result = 0;
    char c;
    printf("Enter an integer between 0 and %u: ", UINT32_MAX);
    c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9' && result <= UINT32_MAX / 10 - (c - '0')){
        result = result * 10 + (c - '0');
        c = getchar();
    }
    while(c != '\n'){
        c = getchar();
    }
    return result;
}

int main(){
    uint64_t number, square;
    while(1){
        number = readUint32();
        square = number * number;
        if(square % power10(getNumberOfDigits(number)) == number){
            printf("Anamorphic: %lu * %lu = %lu\n\n", number, number, square);
        }else{
            printf("Not anamorphic: %lu * %lu = %lu\n\n", number, number, square);
        }
    }
}
