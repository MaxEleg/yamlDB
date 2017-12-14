//
// Created by Loïc Colat on 14/12/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList *newElement(int type ,int stringSize) {
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->next = NULL;

    switch (type) {
        case CHAR :
            ll->data.intType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = NULL;
            ll->data.firstColumn = FALSE;
            ll->data.lastColumn = FALSE;
            break;
        case INT :
            ll->data.charType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = NULL;
            ll->data.firstColumn = FALSE;
            ll->data.lastColumn = FALSE;
            break;
        case FLOAT :
            ll->data.charType = 0;
            ll->data.intType = 0;
            ll->data.stringType = NULL;
            ll->data.firstColumn = FALSE;
            ll->data.lastColumn = FALSE;
            break;
        case STRING :
            ll->data.charType = 0;
            ll->data.intType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = malloc(sizeof(char) * (stringSize + 1));
            ll->data.firstColumn = FALSE;
            ll->data.lastColumn = FALSE;
            break;
    }
    return ll;
}
void addNewElement(LinkedList *ll, int type, int stringSize){
    while(ll->next != NULL){
        ll =  ll->next;
    }
    ll->next = newElement(type, stringSize);
}



void freeLinkedList(LinkedList *ll) {
    if(ll->next != NULL) {
        freeLinkedList(ll->next);
    }
    free(ll);
}

void printLinkedList(LinkedList *ll) {
    while(ll != NULL) {
        if( ll->data.charType != 0){
            printf("%c|", ll->data.charType);
        } else if( ll->data.intType != 0){
            printf("%d|", ll->data.intType);
        } else if( ll->data.floatType != 0){
            printf("%f|", ll->data.floatType);
        } else if( ll->data.stringType != NULL){
            printf("%s|", ll->data.stringType);
        }
        ll = ll->next;
    }
}