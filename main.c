#include <stdio.h>
#include <stdlib.h>
#include "./string.h";
#include "string.c";

int main()
{
    int choice;
    do{
    choice = 0;
    printf("Tapez 1 pour ajouter une bdd \nTapez 2 pour utiliser une bdd existante \nTapez 3 pour ajouter une table\nTapez 4 pour supprimer une table \nTapez 5 pour supprimer une bdd\nTapez 6 pour quitter\n");
    scanf("%d", &choice);
    printf("Vous avez selectionnez : %d \n",choice);
    CleanBuffer();
    if(choice == 1){
        AddBDD();
    }
    else if(choice == 2){
        OpenBDD();
    }
    else if(choice == 3){
        AddTable();
    }
    else if(choice == 4){
        DeleteTable();
    }
    else if(choice == 5){
        DeleteBDD();
    }
    else if(choice == 6 ){
        return 0;
    }
    else{
        printf("L'entree contient des caracteres interdits");
        choice = 1;
    }
    CleanBuffer();
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
