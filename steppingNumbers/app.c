/*
 * Name: Michael Scholten
 * Description:
 * Reads a number from the screen and displays all stepping numbers with that amount of digits.
 * A stepping number is a number of which the adjacent digits have an absolute difference of 1.
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint8_t getNumberOfDigits(uint64_t number){
    uint8_t digits = 0;
    do{
        number /= 10;
        digits++;
    }while(digits > 0);
    return digits;
}

uint8_t steppingNumber(uint64_t number){
    uint8_t current, last;
    if(getNumberOfDigits(number) == 1){
        return 1;
    }
    last = number % 10;
    number /= 10;
    while(number > 0){
        current = number % 10;
        if((current >= last && current - last != 1) || (last > current && last - current != 1)){
            return 0;
        }
        last = current;
        number /= 10;
    }
    return 1;
}

int main(){
    uint64_t number;
    for(number = 0;number < UINT64_MAX;number++){
        if(steppingNumber(number)){
            printf("%lu\n", number);
        }
    }
}
