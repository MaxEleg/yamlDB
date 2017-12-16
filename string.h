#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int err;
int compt;
char nom;
char systemRM;
int c;
char *systemRm1;
char *systemRm2;

void OpenBDD();
void DeleteBDD();
void AddTable();
void DeleteTable();
void CleanBuffer();
char StringWithSpace();
char StringWithoutSpace();
void startApp();

typedef struct YamlKey YamlKey;
struct YamlKey {
	char * name;
	char * value;
	char * next;
	char * prev;
};

typedef struct YamlObject YamlObject;
struct YamlObject {
	YamlKey *keys;
	int countKey;
};

typedef struct YamlContainer YamlContainer;
struct YamlContainer {
	YamlObject* tab;
	int capacity;
	int size;
};

YamlContainer * loadYamlDb(char* fileLocation);

void showYamlContainer(YamlContainer *yamlArray);
YamlContainer* newEmptyArrayYamlContainer();

void freeArray(YamlContainer* array);
int arraySize(YamlContainer* array);
void arrayAdd(YamlContainer* array, YamlObject * value);

YamlObject * arrayGet(YamlContainer* yamlContainer, int index);
void showArr(YamlContainer * arr);
void showKeys(YamlKey * keys,int size);
char * readFile(char *dest);
char	**split(char *str, char separator);
int my_strlen(char*s);
void initTab(char * tab,int count);

#endif // STRING_H_INCLUDED
