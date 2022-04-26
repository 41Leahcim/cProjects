#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* openFile(const char *fileName, const char *mode){
    FILE *file = fopen(fileName, mode);
    if(file == NULL){
        perror("ERROR while opening file: ");
        exit(EXIT_FAILURE);
    }
    return file;
}

size_t getFileSize(const char *fileName){
    FILE *file = openFile(fileName, "r");
    size_t size = 0;
    while(fgetc(file) != EOF){
        size++;
    }
    fclose(file);
    return size;
}

void readFile(const char *fileName, char **result){
    size_t fileSize = getFileSize(fileName);
    FILE *file = openFile(fileName, "r");
    char c;
    size_t i = 0;
    *result = (char*)malloc(sizeof(char) * (fileSize + 1));
    while((c = fgetc(file)) != EOF){
        (*result)[i++] = c;
    }
    (*result)[i] = '\0';
    fclose(file);
}

void hash(const char *text, char *result, const char *outputName){
    FILE *file = openFile(outputName, "w+");
    size_t i;
    size_t j;
    size_t textLength = strlen(text);
    for(i = 0;i < 64;i++){
        result[i] = i;
    }
    for(i = 0;i < 64;i++){
        for(j = 0;j < textLength;j++){
            result[i] ^= text[(i + j) % textLength];
        }
        fputc(result[i], file);
    }
    result[i] = '\0';
    fclose(file);
}

void help(const char *appName){
    printf("Usage of this application:\n"
           "%s [target file name]\n\n"
           "This program xors every character of the file with each other character of the file.\n"
           "This results in an unreadable text and making it impossible to traceback the original text.\n\n", appName);
}

int main(int argc, const char **args){
    const char *fileName;
    char *text;
    char hashedText[65];
    char outputFile[] = "hash.txt";
    if(argc == 1){
        help(args[0]);
    }else if(argc >= 2){
        fileName = args[1];
        readFile(fileName, &text);
        hash(text, hashedText, outputFile);
        free(text);
    }
}
