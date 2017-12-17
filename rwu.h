//
// Created by Loïc Colat on 13/12/2017.
//

#ifndef PROJETC_RWU_H
#define PROJETC_RWU_H

#include "linkedList.h"


int writeTable(char *tableName, char **columnName,char **columnType, int columnAmount, LinkedList *ll);

int writeLine(FILE *yaml, LinkedList *ll);

LinkedList *readTableHeader(char *tableName);

int readTable();

int addLine(char *fileName, LinkedList *ll);

int removeLine();

#endif //PROJETC_RWU_H