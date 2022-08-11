#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct linkedNode{
    char* word;
    struct linkedNode* next;
}linkedNode;

typedef struct{
    linkedNode* head;
    linkedNode* tail;   
}list1;

void initLL(list1 ** L);

void destroyLL(list1 ** L);

void insertNode(list1 ** L, char a);

void removeNode(list1 **L);

char* getString(list1 * L);

#endif // LINKEDLIST_H_INCLUDED