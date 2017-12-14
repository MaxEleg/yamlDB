//
// Created by Loïc Colat on 14/12/2017.
//

#ifndef PROJETC_LINKEDLIST_H
#define PROJETC_LINKEDLIST_H
#define TRUE 0
#define FALSE 1

enum {CHAR, INT, FLOAT, STRING};

typedef struct Column {
    char *name;
    char charType;
    int intType;
    float floatType;
    char *stringType;
    int firstColumn;
    int lastColumn;
}Column;

typedef struct LinkedList {
    Column data;
    struct LinkedList *next;
}LinkedList;

LinkedList *newElement(int type, int stringSize);

void addNewElement(LinkedList *ll, int type, int stringSize);

void freeLinkedList(LinkedList *ll);

void printLinkedList(LinkedList *ll);



#endif //PROJETC_LINKEDLIST_H
