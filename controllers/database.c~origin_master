#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "string.h";

void AddBDD(){
    char nom [1000] = {0};
    printf("indiquez le nom de la BBD a ajouter : ");
    fgets(nom, sizeof(nom), stdin);
    printf("Vous avez ecris : %s \n",nom);
    int i = 0;
    int compt = 0;
    int err = 0;
    for(i ; i<= 100 ; i++){
        if((nom[i] <= 90 && nom[i] >= 65) || (nom[i] <= 122 && nom[i] >= 97) || (nom[i] == 10)){
            compt ++;
        }
        else if(nom[i] == 0){
            break;
        }
        else {
            compt = 0;
            err = 1;
            break;
        }
    }
    if(err == 0){
        printf("Le mot contient %d lettres \n", compt);
        nom[compt-1] = '_';
        nom[compt] = 'B';
        nom[compt+1] = 'D';
        nom[compt+2] = 'D';
        FILE* fichier = NULL;
        if (mkdir(nom)!=NULL){
            printf("la bdd existe deja\n");
            fclose(fichier);
        }
        else{
            mkdir(nom);
            fclose(fichier);
            printf("la bdd a bien ete creer\n", nom);
        }
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
    }
}

void OpenBDD(){
    char nom [1000] = {0};
    printf("indiquez la BBD a tester : ");
    fgets(nom, sizeof(nom), stdin);
    printf("Vous avez ecris : %s \n",nom);
    int i = 0;
    int compt = 0;
    int err = 0;
    for(i ; i<= 100 ; i++){
        if((nom[i] <= 90 && nom[i] >= 65) || (nom[i] <= 122 && nom[i] >= 97) || (nom[i] == 10)){
            compt ++;
        }
        else if(nom[i] == 0){
            break;
        }
        else {
            compt = 0;
            err = 1;
            break;
        }
    }
    if(err == 0){
        printf("Le mot contient %d lettres \n", compt);
        nom[compt-1] = '_';
        nom[compt] = 'B';
        nom[compt+1] = 'D';
        nom[compt+2] = 'D';
        DIR* rep = NULL;
        rep = opendir(nom);
        if (rep == NULL){
            printf("la bdd indique n'existe pas\n", nom);
        }
        else{
            printf("Vous avez ouvert la bdd %s\n", nom);
        }
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
    }
}

void DeleteBDD(){
    char nom [1000] = {0};
    printf("indiquez la BBD a detruire : ");
    fgets(nom, sizeof(nom), stdin);
    printf("Vous avez ecris : %s \n",nom);
    int i = 0;
    int compt = 0;
    int err = 0;
    for(i ; i<= 100 ; i++){
        if((nom[i] <= 90 && nom[i] >= 65) || (nom[i] <= 122 && nom[i] >= 97) || (nom[i] == 10)){
            compt ++;
        }
        else if(nom[i] == 0){
            break;
        }
        else {
            compt = 0;
            err = 1;
            break;
        }
    }
    if(err == 0){
        printf("Le mot contient %d lettres \n", compt);
        nom[compt-1] = '_';
        nom[compt] = 'B';
        nom[compt+1] = 'D';
        nom[compt+2] = 'D';
        DIR* rep = NULL;
        rep = opendir(nom);
        printf("test1\n");
        if (rep == NULL){
            printf("la bdd indique n'existe pas\n", nom);
        }
        else{
        char *systemRm1 = NULL;
        char *systemRm2 = NULL;

        systemRm1 = malloc(sizeof(char) * ( strlen(nom) + 3));
        systemRm2 = malloc(sizeof(char) * ( strlen(nom) + 3 + 6));

        strcpy(systemRm1, "rd ");
        strcat(systemRm1, nom);
        strcpy(systemRm2, " /S /Q");
        strcat(systemRm1, systemRm2);

        printf("test : %s", systemRm1);

        system(systemRm1);

        printf("Vous avez detruis la bdd %s\n", nom);
        }
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
    }
}

void CleanBuffer(){
  int c;
  while((c=getchar()) != EOF && c != '\n');
}

void AddTable(){
}

void DeleteTable(){
}
