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
    printf("indiquez la BBD a ouvrir : ");
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
        char *systemRm1 = NULL;
        char *systemRm2 = NULL;

        systemRm1 = malloc(sizeof(char) * ( strlen(nom) + 3));
        systemRm2 = malloc(sizeof(char) * ( strlen(nom) + 3 + 6));

        strcpy(systemRm1, "rd ");
        strcat(systemRm1, nom);
        strcpy(systemRm2, " /S /Q");
        strcat(systemRm1, systemRm2);

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
    char nom [1000] = {0};
    printf("indiquez la BBD a ouvrir : ");
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
        nom[compt-1] = '_';
        nom[compt] = 'B';
        nom[compt+1] = 'D';
        nom[compt+2] = 'D';
        DIR* rep = NULL;
        rep = opendir(nom);
        if (rep == NULL){
            printf("la bdd indique n'existe pas\n", nom);
            return;
        }
        else{
            printf("Vous avez ouvert la bdd %s\n", nom);
            closedir(rep);
            nom[compt+3] = '\\';
            char nom2 [1000] = {0};
            printf("indiquez la table a creer : ");
            fgets(nom2, sizeof(nom), stdin);
            printf("Vous avez ecris : %s \n",nom);
            int i = 0;
            int compt = 0;
            int err = 0;
            for(i ; i<= 100 ; i++){
                if((nom2[i] <= 90 && nom2[i] >= 65) || (nom2[i] <= 122 && nom2[i] >= 97) || (nom2[i] == 10)){
                    compt ++;
                }
                else if(nom2[i] == 0){
                    break;
                }
                else {
                    compt = 0;
                    err = 1;
                    break;
                }
            }
            if(err == 0){
                nom2[compt-1] = '.';
                nom2[compt] = 'y';
                nom2[compt+1] = 'm';
                nom2[compt+2] = 'l';
                strcat(nom, nom2);
                FILE* fichier = NULL;
                if(fopen(nom, "r") != NULL){
                    fclose(fichier);
                    printf("la table %s existe deja\n", nom);
                    return;
                }
                fichier = fopen(nom, "w");
                if (fichier != NULL){
                    fclose(fichier);
                    WriteTable(nom);
                    printf("la table a ete creer\n", nom);
                    return;
                }
            }
            else{
                printf("Le mot contient des caracteres interdits \n");
            }
        }
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
    }
}

void DeleteTable(){
    char nom [1000] = {0};
    printf("indiquez la BBD a ouvrir : ");
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
        nom[compt-1] = '_';
        nom[compt] = 'B';
        nom[compt+1] = 'D';
        nom[compt+2] = 'D';
        DIR* rep = NULL;
        rep = opendir(nom);
        if (rep == NULL){
            printf("la bdd indique n'existe pas\n", nom);
            return;
        }
        else{
            printf("Vous avez ouvert la bdd %s\n", nom);
            closedir(rep);
            nom[compt+3] = '\\';
            char nom2 [1000] = {0};
            printf("indiquez la table a detruire : ");
            fgets(nom2, sizeof(nom), stdin);
            printf("Vous avez ecris : %s \n",nom);
            int i = 0;
            int compt = 0;
            int err = 0;
            for(i ; i<= 100 ; i++){
                if((nom2[i] <= 90 && nom2[i] >= 65) || (nom2[i] <= 122 && nom2[i] >= 97) || (nom2[i] == 10)){
                    compt ++;
                }
                else if(nom2[i] == 0){
                    break;
                }
                else {
                    compt = 0;
                    err = 1;
                    break;
                }
            }
            if(err == 0){
                nom2[compt-1] = '.';
                nom2[compt] = 'y';
                nom2[compt+1] = 'm';
                nom2[compt+2] = 'l';
                strcat(nom, nom2);
                FILE* fichier = NULL;
                fichier = fopen(nom, "r");
                if(fichier != NULL){
                    fclose(fichier);
                    char *systemRm1 = NULL;

                    systemRm1 = malloc(sizeof(char) * ( strlen(nom) + 50));

                    strcpy(systemRm1, "C:\\Users\\chris\\Desktop\\ProjetBDD\\");
                    strcat(systemRm1, nom);
                    remove(systemRm1);
                    printf("la table %s a ete detruite\n", systemRm1);
                    return;
                }
                else {
                    printf("la table n'existe pas\n", nom);
                }
            }
            else{
                printf("Le mot contient des caracteres interdits \n");
            }
        }
    }
    else{
        printf("Le mot contient des caracteres interdits \n");
    }
}

void WriteTable(char* nom){
    printf("%s  test\n", nom);
    FILE* fichier = NULL;
    fichier = fopen(nom, "r+");
    fputs("NomTable:\n  columns:\n", fichier);
    char colonne [100] = {0};
    int i = 0;
    int compt = 0;
    int err = 0;
    int choice = 0;
    do {
        for(i = 0; i<= 100; i++){
            colonne[i] = 0;
        }
        printf("indiquez le nom de la colonne a ajouter : ");
        fgets(colonne, sizeof(colonne), stdin);
        printf("Vous avez ecris : %s \n",colonne);
        i = 0;
        compt = 0;
        err = 0;
        if(err == 0){
            for(i ; i<= 100 ; i++){
                if((colonne[i] <= 90 && colonne[i] >= 65) || (colonne[i] <= 122 && colonne[i] >= 97) || (colonne[i] == 10)){
                    compt ++;
                }
                else if(colonne[i] == 0){
                    break;
                }
                else {
                    compt = 0;
                    err = 1;
                    break;
                }
            }
        }
        do{
        choice = 0;
        printf("Tapez 1 pour un entier \nTapez 2 pour un reel \nTapez 3 pour une caractere\nTapez 4 pour une chaine de caractere\n");
        scanf("%d", &choice);
        printf("Vous avez selectionnez : %d \n",choice);
        if(choice == 1){
            systemRm1 = malloc(sizeof(char) * (200));
            strcpy(systemRm1, "    NomColonne: ");
            strcat(systemRm1, colonne);
            strcat(systemRm1, "      type: !!int\n");
            fputs(systemRm1, fichier);
        }
        else if(choice == 2){
            systemRm1 = malloc(sizeof(char) * (200));
            strcpy(systemRm1, "    NomColonne: ");
            strcat(systemRm1, colonne);
            strcat(systemRm1, "      type: !!float\n");
            fputs(systemRm1, fichier);
        }
        else if(choice == 3){
            systemRm1 = malloc(sizeof(char) * (200));
            strcpy(systemRm1, "    NomColonne: ");
            strcat(systemRm1, colonne);
            strcat(systemRm1, "      type: !!char\n");
            fputs(systemRm1, fichier);
        }
        else if(choice == 4){
            systemRm1 = malloc(sizeof(char) * (200));
            strcpy(systemRm1, "    NomColonne: ");
            strcat(systemRm1, colonne);
            strcat(systemRm1, "      type: !!char*\n");
            fputs(systemRm1, fichier);
        }else{
             printf("Le mot contient des caracteres interdits \n");
        }
        CleanBuffer();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
        do{
        printf("Tapez 1 pour un rajouter une colonne \nTapez 2 pour arreter\n");
        scanf("%d", &choice);
        printf("Vous avez selectionnez : %d \n",choice);
        CleanBuffer();
        }while(choice != 1 && choice != 2);
    }while(choice != 2);
    fputs("Data:\n", fichier);
    fclose(fichier);
}
