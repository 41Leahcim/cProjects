/*
 * Name: Michael Scholten
 * Description:
 * Reads a number from the screen and displays whether it's a narcissistic number.
 * An narcissistic number is a number of which the sum of its own digits each raised to the number of digits.
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

uint64_t power(uint8_t number, uint8_t exponent){
    uint64_t result = 1;
    while(exponent > 0){
        result *= number;
        exponent--;
    }
    return result;
}

uint8_t narcissistic(uint32_t number){
    uint64_t result = 0;
    uint32_t original = number;
    uint8_t length = getNumberOfDigits(number);
    do{
        result += power(number % 10, length);
        number /= 10;
    }while(number > 0);
    return result == original;
}

int main(){
    uint32_t number;
    for(number = 0;number < UINT32_MAX;number++){
        if(narcissistic(number)){
            printf("%u\n", number);
        }
    }
}
