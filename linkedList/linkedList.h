#include <stdint.h>
#include <stdlib.h>

typedef struct Node{
    uint64_t number;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node *head;
    Node *tail;
} LinkedList;

Node* newNode(uint64_t value, Node *next);

LinkedList* newLinkedList();

void LinkedList_init(LinkedList *list);

void LinkedList_pushBack(LinkedList *list, uint64_t value);

void LinkedList_pushFront(LinkedList *list, uint64_t value);

void LinkedList_removeFront(LinkedList *list);

void LinkedList_removeBack(LinkedList *list);

void LinkedList_remove(LinkedList *list, uint64_t value);

uint64_t LinkedList_get(LinkedList *list, size_t index);

void LinkedList_clear(LinkedList *list);

void LinkedList_destroy(LinkedList *list);