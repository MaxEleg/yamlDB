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
    fprintf(yaml, "\nData:\n  Line:\n");
    writeLine(yaml, ll);

    fclose(yaml);

    return EXIT_SUCCESS;
}

int writeLine(FILE *yaml, LinkedList *ll){
    while(ll != NULL) {
        if( ll->data.charType != 0){
            if( ll->data.lineEnd != TRUE){
                fprintf(yaml, "   %s: !!char %c\n", ll->data.name, ll->data.charType);
            } else{
                fprintf(yaml, "   %s: !!char %c\n  Line:\n", ll->data.name, ll->data.charType);
            }
        } else if( ll->data.intType != 0){
            if( ll->data.lineEnd != TRUE){
                fprintf(yaml, "   %s: !!int %d\n", ll->data.name, ll->data.intType);
            } else {
                fprintf(yaml, "   %s: !!int %d\n  Line:\n", ll->data.name, ll->data.intType);
            }
        } else if( ll->data.floatType != 0){
            if( ll->data.lineEnd != TRUE){
                fprintf(yaml, "   %s: !!float %f\n", ll->data.name, ll->data.floatType);
            } else{
                fprintf(yaml, "   %s: !!float %f\n  Line:\n", ll->data.name, ll->data.floatType);
            }
        } else if( ll->data.stringType != NULL){
            if( ll->data.lineEnd != TRUE){
                fprintf(yaml, "   %s: !!str %s\n  Line:\n", ll->data.name, ll->data.stringType);
            } else{
                fprintf(yaml, "   %s: !!str %s\n", ll->data.name, ll->data.stringType);
            }
        }
        ll = ll->next;
    }

    return EXIT_SUCCESS;
}