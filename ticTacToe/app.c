#include <stdio.h>
#include <stdint.h>

void init(char *field){
    for(uint8_t i = 0;i < 9;i++){
        field[i] = '0' + i;
    }
}

void printField(const char *field){
    for(uint8_t i = 0;i < 9;i++){
        if(i % 3 == 0){
            printf("\n %c ", field[i]);
        }else{
            printf("| %c ", field[i]);
        }
    }
    printf("\n\n");
}

uint8_t getPosition(const char *field, const char c){
    unsigned int position;
    printf("Enter the position for %c: ", c);
    scanf("%u", &position);
    while(position >= 9 && field[position] != 'X' && field[position] != 'O'){
        puts("Invalid input!\n");
        printf("Enter the position for %c: ", c);
        scanf("%u", &position);
    }
    return position;
}

char getWinner(const char *field){
    for(uint8_t i = 0;i < 3;i++){
        uint8_t pos = i * 3;
        if(field[pos] == field[pos + 1] && field[pos] == field[pos + 2]){
            return field[pos];
        }else if(field[i] == field[i + 3] && field[i] == field[i + 6]){
            return field[i];
        }
    }
    if(field[0] == field[4] && field[0] == field[8]){
        return field[0];
    }else if(field[2] == field[4] && field[2] == field[6]){
        return field[2];
    }
    return '\0';
}

void printWinner(char winner){
    if(winner == '\0'){
        printf("It was a tie.\n");
    }else{
        printf("%c won!\n", winner);
    }
}

int main(){
    char field[9];
    char player = 'X';
    uint8_t index;
    while(1){
        init(field);
        printField(field);
        while(!getWinner(field)){
            index = getPosition(field, player);
            field[index] = player;
            if(player == 'X'){
                player = 'O';
            }else{
                player = 'X';
            }
            printField(field);
        }
        printWinner(getWinner(field));
    }
}
