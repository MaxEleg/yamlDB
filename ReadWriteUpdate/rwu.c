//
// Created by Loïc Colat on 13/12/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "rwu.h"



int writeTable(char *tableName, char **columnName,char **columnType, int columnAmount, LinkedList *ll){

    FILE *yaml =NULL;
    char *extension = ".yaml";
    char *fileName = NULL;
    fileName = malloc(sizeof(char) * (strlen(extension) + strlen(tableName) + 1) );
    strcpy(fileName, tableName);
    strcat(fileName, extension);

    yaml = fopen(fileName, "w");

    fprintf(yaml, "%s:\n  columns:\n",tableName);

    for(int i = 0; i < columnAmount; i++){
        fprintf(yaml, "    %s:\n      type: %s\n", columnName[i], columnType[i]);
    }
    fprintf(yaml, "\nData:\n");
    writeLine(yaml, ll);

    fclose(yaml);

    return EXIT_SUCCESS;
}

int writeLine(FILE *yaml, LinkedList *ll){
    while(ll != NULL) {
        if( ll->data.charType != 0){
            if( ll->firstColumn == TRUE){
                fprintf(yaml, "  Line:\n   %s: !!char %c\n", ll->name, ll->data.charType);
            } else if( ll->lastColumn != TRUE){
                fprintf(yaml, "   %s: !!char %c\n", ll->name, ll->data.charType);
            } else if( ll->next != NULL){
                fprintf(yaml, "   %s: !!char %c\n  Line:\n", ll->name, ll->data.charType);
            }else{
                fprintf(yaml, "   %s: !!char %c\n", ll->name, ll->data.charType);
            }
        } else if( ll->data.intType != 0){
            if( ll->lastColumn != TRUE){
                fprintf(yaml, "   %s: !!int %d\n", ll->name, ll->data.intType);
            } else if( ll->next != NULL){
                fprintf(yaml, "   %s: !!int %d\n  Line:\n", ll->name, ll->data.intType);
            }else{
                fprintf(yaml, "   %s: !!int %d\n", ll->name, ll->data.intType);
            }
        } else if( ll->data.floatType != 0){
            if( ll->lastColumn != TRUE){
                fprintf(yaml, "   %s: !!float %f\n", ll->name, ll->data.floatType);
            } else{
                fprintf(yaml, "   %s: !!float %f\n  Line:\n", ll->name, ll->data.floatType);
            }
        } else if( ll->data.stringType != NULL){
            if( ll->lastColumn != TRUE){
                fprintf(yaml, "   %s: !!str %s\n  Line:\n", ll->name, ll->data.stringType);
            } else{
                fprintf(yaml, "   %s: !!str %s\n", ll->name, ll->data.stringType);
            }
        }
        ll = ll->next;
    }

    return EXIT_SUCCESS;
}

LinkedList *readTableHeader(char *tableName){
    char buff[64];
    buff[63] = '\0';
    int a = 0;
    FILE *file = NULL;
    char *header = NULL;
    char *cursorBuffPosition1 = NULL;
    char *cursorBuffPosition2 = NULL;
    int cursorPosition1 = 0;
    int cursorPosition2 = 0;

    file = fopen(tableName, "r");

    while (cursorBuffPosition1 == NULL || cursorBuffPosition2 == NULL){
        for(int i = 0; i < 64; i++){
            buff[i] = (char)fgetc(file);
        }
        if(cursorBuffPosition1 == NULL){
            cursorBuffPosition1 = strstr(buff,"columns:");
            if(cursorBuffPosition1 != NULL){
                cursorPosition1 = (int)cursorBuffPosition1 - (int)buff + a + 13;//
            }else{
                a += 64;
            }
        }
        if(cursorBuffPosition2 == NULL){
            cursorBuffPosition2 = strstr(buff,"\n\nData:");
            if(cursorBuffPosition2 != NULL){
                cursorPosition2 = (int)cursorBuffPosition2 - (int)buff + a;
            }else{
                a += 64;
            }
        }
    }

    header = malloc(sizeof(char) * (cursorPosition2 + 1));
    if(header == NULL){
        fprintf(stderr, "\nERROR, can't create header");
        return NULL;
    }

    header[cursorPosition2] = '\0';
    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < cursorPosition2; i++){
        header[i] = (char)fgetc(file);
    }
    //printf("here");
    //LinkedList *ll;
    //printf("%s", header);
    //printf("\nC1 %d\nC2 %d", cursorPosition1, cursorPosition2);
    return NULL;
}

int addLine(char *fileName, LinkedList *ll){
    FILE *yaml = NULL;


    yaml = fopen(fileName, "a");

    writeLine(yaml,ll);

    fclose(yaml);

    return EXIT_SUCCESS;
}