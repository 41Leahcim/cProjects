/*
 * Developer: Michael Scholten
 * Description: prints statistics of set of numbers entered by the user.
*/

#include <stdio.h>
#include <stdint.h>

int main(){
    int64_t average, minimum, maximum, length, number;
    length = 1;
    printf("Enter integers, end with 0: ");
    scanf("%ld", &number);
    average = number;
    minimum = number;
    maximum = number;
    while(number != 0){
        scanf("%ld", &number);
        if(number != 0){
            average += number;
            if(number < minimum){
                minimum = number;
            }else if(number > maximum){
                maximum = number;
            }
            length++;
        }
    }
    printf("Average: %lf\n", (double)average / length);
    printf("Minimum: %ld\n", minimum);
    printf("Maximum: %ld\n", maximum);
}
