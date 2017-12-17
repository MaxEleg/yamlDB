#include "../header.h";

YamlContainer * loadYamlDb(char* dest){

	int size;
	int i;
	int j;
	int k;
    int n;

    n=0;
	char * content = readFile(dest);
	YamlContainer * yamlArray = newEmptyArrayYamlContainer();
	YamlObject * object = NULL;

	char ** objects = split(content, '#');

	for (i = 0; objects[i] != '\0'; i++) { //we split all objects

		if (my_strlen(objects[i]) > 3) {
			char** line = split(objects[i], '\n');

			object = (YamlObject*)malloc(sizeof(YamlObject));
			YamlKey * keys = (YamlKey*)malloc(sizeof(YamlKey) * 1000);

			for (j = 0; line[j] != '\0'; j++) {//we split all line
				char **  data = split(line[j], ':');
				char * name = data[0]; //we extract all data
				char * value = data[1];
				if(my_strlen(name)>1){ //if there is a value on the name
                    keys[n].name = name;
                    keys[n].value = value;
                    object->countKey = j;
                    n++;
				}
			}
			n=0;
			object->keys = keys;
			arrayAdd(yamlArray, object);
		}
	}
    return yamlArray;
}

void showYamlContainer(YamlContainer *yamlArray){
	int i;
	int size;

	printf("yamlContainerSize = %d\n", arraySize(yamlArray));
	int nbrObj = arraySize(yamlArray);
	for (i = 0; i < nbrObj; i++) {
		YamlKey * keys = yamlArray->tab[i].keys;
		size = yamlArray->tab[i].countKey;
		showKeys(keys, size);
		printf("_________________\n");
	}
}


YamlContainer* newEmptyArrayYamlContainer() {

	YamlContainer * yamlArray = (YamlContainer*)malloc(sizeof(YamlContainer));
	yamlArray->tab = (YamlObject*)malloc(sizeof(YamlObject) * 20);
	yamlArray->capacity = 20;
	yamlArray->size = 0;

	return yamlArray; // TODO
}

void freeArray(YamlContainer* array) {
	if (array != NULL) {
		free(array);
	}
}

int arraySize(YamlContainer* array) {
	if (array != NULL) {
		return array->size; // TODO
	}
	else {
		return -1;
	}
}

void arrayAdd(YamlContainer* array, YamlObject * value) {
	int capacity = array->capacity;
	int size = arraySize(array);
	int i = 0;

	if (size <= capacity) {
		array->tab[size] = *value;
		array->size++;
	}
	else {
		printf("new capacity required...\n");
		int newSize = size + 1;

		YamlObject * newTab = (YamlObject*)malloc(sizeof(YamlObject)*newSize);

		for (i = 0; i<size; i++) {
			newTab[i] = array->tab[i];
		}
		newTab[i] = *value;

		array->capacity++;
		array->size = newSize;
		array->tab = newTab;
	}
}

YamlObject * arrayGet(YamlContainer* yamlContainer, int index) {
	if (yamlContainer != NULL && index >= 0) {
		return & yamlContainer->tab[index]; // TODO
	}
	else {
		return NULL;
	}
}

void showKeys(YamlKey * keys,int size) {
	int i = 0;

	for (i = 0; i < size; i++) {
		printf("%s -> %s \n", keys[i].name, keys[i].value);
	}
}

int countCharacter(YamlContainer *yamlArray){
	int i;
	int nbrKey;
    int total;
    int j;
    char *name;
    char *value;

    j=0;
    total = 0;
	int nbrObj = arraySize(yamlArray);
	for (i = 0; i < nbrObj; i++) {
		YamlKey * keys = yamlArray->tab[i].keys;
		nbrKey = yamlArray->tab[i].countKey;

		for(j=0;j<nbrKey;j++){
            name = keys[j].name;
            value = keys[j].value;
		    if(name != NULL){
                total += my_strlen(name);
            }
		    if(value != NULL){
                total += my_strlen(value);
            }
		}
	}
	printf("\n%d\n",total);
	return total;
}

void writeYamlDb(YamlContainer * yamlArr,char ** dest){
    int nbrChar;
	int i;
	int j;
	int size;
    int nbrObj;
    char * content;

    nbrChar = countCharacter(yamlArr)*2;
	content = malloc(sizeof(char)*nbrChar);
	initTab(content,nbrChar);
	nbrObj = arraySize(yamlArr);

	for (i = 0; i < nbrObj; i++) {
		YamlKey * keys = yamlArr->tab[i].keys;
		size = yamlArr->tab[i].countKey;

        for (j = 0; j < size; j++) {
            if(j==0){
                printf("%s:\n", keys[j].name);

                strcat(content, keys[j].name);
                strcat(content, ":\n");
            }else{
                printf("\t%s:%s\n", keys[j].name, keys[j].value);
                strcat(content, "   ");
                strcat(content, keys[j].name);
                strcat(content, ":");
                strcat(content, keys[j].value);
                strcat(content, "\n");
            }
            if(j == size-1){
                strcat(content, "#\n");
            }
        }
	}
    writeFile(dest,content);
}

void deleteObjYaml(YamlContainer * yamlArr, int at){
    YamlContainer * newContainer = newEmptyArrayYamlContainer();

    int i = 0;

    for (i=0;i<yamlArr->size;i++){
        if(i != at){
            arrayAdd(newContainer, arrayGet(yamlArr,i));
        }
    }
}
