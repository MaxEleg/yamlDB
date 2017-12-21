//
// Created by Loïc Colat on 14/12/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList *newElement(int type , char *name,int stringSize) {
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->next = NULL;
    ll->name = NULL;
    ll->name = malloc(sizeof(char) * strlen(name) + 1);
    if(ll->name = NULL){
        sprintf(stderr, "ERROR, can't initialize LinkedList name");
    }
    strcpy(ll->name, name);
    switch (type) {
        case CHAR :
            ll->type = CHAR;
            ll->data.intType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = NULL;
            ll->firstColumn = FALSE;
            ll->lastColumn = FALSE;
            break;
        case INT :
            ll->type = INT;
            ll->data.charType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = NULL;
            ll->firstColumn = FALSE;
            ll->lastColumn = FALSE;
            break;
        case FLOAT :
            ll->type = FLOAT;
            ll->data.charType = 0;
            ll->data.intType = 0;
            ll->data.stringType = NULL;
            ll->firstColumn = FALSE;
            ll->lastColumn = FALSE;
            break;
        case STRING :
            ll->type = STRING;
            ll->data.charType = 0;
            ll->data.intType = 0;
            ll->data.floatType = 0;
            ll->data.stringType = malloc(sizeof(char) * (stringSize + 1));
            ll->firstColumn = FALSE;
            ll->lastColumn = FALSE;
            break;
    }
    return ll;
}
void addNewElement(LinkedList *ll, int type, char *name, int stringSize){
    while(ll->next != NULL){
        ll =  ll->next;
    }
    ll->next = newElement(type, name, stringSize);
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
        if(ll->lastColumn = TRUE){
            printf("\n");
        }
        ll = ll->next;
    }
}