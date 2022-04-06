#include <stdio.h>
#include <string.h>

char getCommand(char *command, const size_t commandLength, char c){
    size_t i = 0;
    while(c < 'A' || (c > 'Z' && c < 'a') || c > 'z'){
        c = getchar();
    }
    while(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && i < commandLength){
        command[i++] = c | 32;
        c = getchar();
    }
    command[i] = '\0';
    return c;
}

long long getValue(char *ch){
    char c = *ch;
    long long value = 0;
    unsigned char negative = 0;
    while((c < '0' || c > '9') && c != '-'){
        c = getchar();
    }
    if(c == '-'){
        negative = 1;
    }
    while(c >= '0' && c <= '9'){
        value = value * 10 + (c - '0');
        c = getchar();
    }
    if(negative){
        value = -value;
    }
    *ch = c;
    return value;
}

long long commandValue(char *command, const size_t commandLength){
    char c = getCommand(command, commandLength, getchar());
    long long value;
    if(strcmp(command, "push") == 0){
        value = getValue(&c);
    }else{
        value = 0;
    }
    while(c != '\n'){
        c = getchar();
    }
    return value;
}

size_t push(long long *numbers, const size_t i, const long long value){
    if(i < 2048){
        numbers[i] = value;
        return i + 1;
    }else{
        puts("ERROR: Stack full!\n");
        return i;
    }
}

long long pop(long long *numbers, size_t *i, unsigned char *success){
    if(*i > 0){
        *success = 1;
        return numbers[--(*i)];
    }else{
        puts("ERROR: Stack is empty!\n");
        *success = 0;
        return -1;
    }
}

void help(){
    puts("Possible commands: push, pop, size\n"
         "Possible number range: -9223372036854775808 - 9223372036854775807\n"
         "An instruction is a command + the number for push, or just the command for the other commands.\n");
}

int main(){
    long long numbers[4084];
    size_t i = 0;
    char command[10];
    long long number;
    unsigned char success;
    help();
    while(1){
        printf("Enter the instruction: ");
        number = commandValue(command, 10);
        if(strcmp(command, "push") == 0){
            i = push(numbers, i, number);
        }else if(strcmp(command, "pop") == 0){
            number = pop(numbers, &i, &success);
            if(success){
                printf("%lld\n", number);
            }
        }else if(strcmp(command, "size") == 0){
            printf("%lu\n", i);
        }else{
            printf("Invalid command: %s\n", command);
        }
    }
}
