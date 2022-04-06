#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

const size_t BUFSIZE = 25000;

struct aiocb* async_read(FILE *fp, char *buffer, size_t bytes){
    struct aiocb *aio = malloc(sizeof(struct aiocb));
    if(aio == NULL){
        return NULL;
    }

    memset(aio, 0, sizeof(*aio));

    aio->aio_buf = buffer;
    aio->aio_fildes = fileno(fp);
    aio->aio_nbytes = bytes;
    aio->aio_offset = 0;

    int result = aio_read(aio);
    if(result < 0){
        free(aio);
        return NULL;
    }
    return aio;
}

int main(int argc, const char **args){
    FILE *fp;
    char buffer[BUFSIZE];
    unsigned long counter = 0;
    int ret;

    if(argc <= 1){
        printf("You have to enter a file name!\n");
        return EXIT_FAILURE;
    }
    
    fp = fopen(args[1], "r");
    if(fp == NULL){
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct aiocb *aio = async_read(fp, buffer, BUFSIZE);

    while(aio_error(aio) == EINPROGRESS) counter++;

    ret = aio_return(aio);

    fclose(fp);

    printf("While we were reading, we counted %lu times.\n", counter);

    if(ret > 0){
        printf("Read %d bytes\n", ret);
    }else{
        printf("READ FAILED!\n");
    }

    free(aio);
}
