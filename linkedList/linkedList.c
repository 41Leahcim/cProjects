#include "linkedList.h"

Node* newNode(uint64_t value, Node *next){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->number = value;
    newNode->next = next;
    return newNode;
}

LinkedList* newLinkedList(){
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    LinkedList_init(list);
    return list;
}

void LinkedList_init(LinkedList *list){
    list->head = NULL;
    list->tail = NULL;
}

void LinkedList_pushBack(LinkedList *list, uint64_t value){
    Node *node = newNode(value, NULL);
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
}

void LinkedList_pushFront(LinkedList *list, uint64_t value){
    Node *node = newNode(value, list->head);
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
    }else{
        list->head = node;
    }
}

void LinkedList_removeFront(LinkedList *list){
    Node *oldHead = list->head;
    if(oldHead != NULL){
        list->head = oldHead->next;
        free(oldHead);
    }
    if(list->head == NULL){
        list->tail = NULL;
    }
}

void LinkedList_removeBack(LinkedList *list){
    Node *index = list->head;
    Node *newTail;
    if(index == NULL){
        return;
    }else if(index->next == NULL){
        free(index);
        list->head = NULL;
        list->tail = NULL;
    }else{
        while(index->next->next != NULL){
            index = index->next;
        }
        newTail = index->next;
        free(newTail->next);
        list->tail = newTail;
    }
}

void LinkedList_remove(LinkedList *list, uint64_t value){
    Node *index = list->head;
    Node *previous = NULL;
    while(index != NULL && index->number != value){
        previous = index;
        index = index->next;
    }
    if(index == NULL){
        return;
    }else if(index == list->head){
        list->head = index->next;
        free(index);
    }else{
        previous->next = index->next;
        free(index);
    }
    if(list->head == NULL){
        list->tail = NULL;
    }else if(list->tail == NULL){
        list->head = NULL;
    }
}

uint64_t LinkedList_get(LinkedList *list, size_t index){
    Node *node = list->head;
    while(index > 0 && node != NULL){
        index--;
        node = node->next;
    }
    if(node == NULL){
        return UINT64_MAX;
    }else{
        return node->number;
    }
}

void LinkedList_clear(LinkedList *list){
    Node *index = list->head;
    Node *next;
    while(index != NULL){
        next = index->next;
        free(index);
        index = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

void LinkedList_destroy(LinkedList *list){
    LinkedList_clear(list);
    free(list);
}
