/*
 * Name: Michael Scholten
 * Description:
 * Reads a number from the screen and displays whether it's a neon number.
 * A neon number is a number which is equal to the multiplication of its own digits 
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint8_t neon(uint32_t number){
    uint64_t result = 0;
    uint64_t original = number;
    number *= number;
    while(number > 0){
        result += number % 10;
        number /= 10;
    }
    return result == original;
}

int main(){
    uint32_t number = 0;
    for(number = 0;number < UINT32_MAX;number++){
        if(neon(number)){
            printf("%u\n", number);
        }
    }
}
