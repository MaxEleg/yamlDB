#include <stdio.h>
#include <stdlib.h>
#include "string.h";

char StringWithSpace(){
    char nom [1000] = {0};
    printf("indiquez le mot a tester : ");
    fgets(nom, sizeof(nom), stdin);
    printf("Vous avez ecris : %s \n",nom);
    int i = 0;
    int compt = 0;
    int err = 0;
    for(i ; i<= 100 ; i++){
        if((nom[i] <= 90 && nom[i] >= 65) || (nom[i] <= 122 && nom[i] >= 97) || nom[i] == 10 || nom[i] == 32){
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
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
        return 0;
    }
    return nom;
}

char StringWithoutSpace(){
    char nom [1000] = {0};
    printf("indiquez le mot a tester : ");
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
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
        return 0;
    }
    return nom;
}

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
        nom[compt-1] = '.';
        nom[compt] = 'y';
        nom[compt+1] = 'm';
        nom[compt+2] = 'l';
        FILE* fichier = NULL;
        if (fopen(nom,"r")!=NULL){
            printf("la bdd existe deja\n");
            fclose(fichier);
        }
        else{
            fichier = fopen(nom, "w");
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
        nom[compt-1] = '.';
        nom[compt] = 'y';
        nom[compt+1] = 'm';
        nom[compt+2] = 'l';
        FILE* fichier = NULL;
        if (fopen(nom,"r")!=NULL){
            printf("Vous avez ouvert la bdd %s\n", nom);
            fclose(fichier);
        }
        else{
            printf("la bdd indique n'existe pas\n", nom);
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
        nom[compt-1] = '.';
        nom[compt] = 'y';
        nom[compt+1] = 'm';
        nom[compt+2] = 'l';
        FILE* fichier = NULL;
        if ((fichier = fopen(nom,"r"))!=NULL){
            fclose(fichier);
            remove (nom);
            printf("Vous avez detruis la bdd %s\n", nom);
        }
        else{
            printf("la bdd indique n'existe pas\n", nom);
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
