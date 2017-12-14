#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rwu.h"

int main() {

    LinkedList *head = newElement(CHAR, 0);
    head->data.charType = 'b';
    head->data.name = "test";
    head->next = newElement(INT, 0);
    head->next->data.intType = 23;
    head->next->data.name = "test2";
    head->next->data.lineEnd = TRUE;
    char **nomcolonne = NULL;
    char **typetable = NULL;

    nomcolonne = malloc(sizeof(char*) * 2);
    nomcolonne[0] = malloc(sizeof(char) * 6);
    nomcolonne[1] = malloc(sizeof(char) * 6);
    strcpy(nomcolonne[0], head->data.name);
    //nomcolonne[0][4] = '\0';
    nomcolonne[1] = head->next->data.name;
    typetable = malloc(sizeof(char*) * 2);
    typetable[0] = malloc(sizeof(char) * 6);
    typetable[1] = malloc(sizeof(char) * 6);
    typetable[0] = "!!char";
    typetable[1] = "!!int";
    writeTable("test", nomcolonne, typetable, 2, head);

    printLinkedList(head);
    freeLinkedList(head);

    //test writeTable
/*  char **nomcolonne = NULL;
    char **typetable = NULL;

    nomcolonne = malloc(sizeof(char*) * 2);
    nomcolonne[0] = malloc(sizeof(char) * 6);
    nomcolonne[1] = malloc(sizeof(char) * 6);
    strcpy(nomcolonne[0], "test");
    //nomcolonne[0][4] = '\0';
    nomcolonne[1] = "test2";
    typetable = malloc(sizeof(char*) * 2);
    typetable[0] = malloc(sizeof(char) * 6);
    typetable[1] = malloc(sizeof(char) * 6);
    typetable[0] = "!!str";
    typetable[1] = "!!str";

    writeTable("test", nomcolonne, typetable, 2);*/

    //printf("Hello, World! , %d\n", test.Int);
    return 0;
}