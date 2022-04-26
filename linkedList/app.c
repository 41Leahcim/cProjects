#include <stdio.h>
#include <time.h>

#include "linkedList.h"

#define LENGTH 100000

int main(){
    LinkedList *list = newLinkedList();
    size_t i;
    clock_t start;
    clock_t took[7];
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_pushFront(list, i);
    }
    took[0] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_removeBack(list);
    }
    took[1] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_pushBack(list, i);
    }
    took[2] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_removeFront(list);
    }
    took[3] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_pushFront(list, i);
    }
    took[4] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        printf("%lu\n", LinkedList_get(list, i));
    }
    took[5] = clock() - start;
    
    start = clock();
    for(i = 0;i < LENGTH;i++){
        LinkedList_remove(list, i);
    }
    took[6] = clock() - start;

    LinkedList_destroy(list);

    printf("Time to push to the front: %lf seconds\n", (double)took[0] / CLOCKS_PER_SEC);
    printf("Time to remove from the back: %lf seconds\n", (double)took[1] / CLOCKS_PER_SEC);
    printf("Time to push to the back: %lf seconds\n", (double)took[2] / CLOCKS_PER_SEC);
    printf("Time to remove from the front: %lf seconds\n", (double)took[3] / CLOCKS_PER_SEC);
    printf("Second time to push to the front: %lf seconds\n", (double)took[4] / CLOCKS_PER_SEC);
    printf("Time to display every value: %lf seconds\n", (double)took[5] / CLOCKS_PER_SEC);
    printf("Time to push to remove every node: %lf seconds\n", (double)took[6] / CLOCKS_PER_SEC);
}
