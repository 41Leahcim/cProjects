/*
 * Name: Michael Scholten
 * Description: Displays the digits of the number reversed.
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint64_t readUint64(){
    uint64_t number = 0;
    char c;
    printf("Enter a number between 0 and %lu: ", UINT64_MAX);
    c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        number = number * 10 + (c - '0');
        c = getchar();
    }
    while(c != '\n'){
        c = getchar();
    }
    return number;
}

void printReversed(uint64_t number){
    do{
        putchar('0' + number % 10);
        number /= 10;
    }while(number > 0);
}

int main(){
    uint64_t number;
    while(1){
        number = readUint64();
        printf("Number reversed: ");
        printReversed(number);
        putchar('\n');
    }
}
