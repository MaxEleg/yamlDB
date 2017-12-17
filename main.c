#include <stdio.h>
#include <stdlib.h>
#include "./header.h"

int main()
{
    int choice;
    do{
        choice = 0;
        printf("Tapez 1 pour ajouter une ligne dans une table\nTapez 2 pour modifier une ligne dans une table\nTapez 3 pour supprimer une ligne dans une table\nTapez 0 pour quitter\n");
        scanf("%d", &choice);
        printf("Vous avez selectionnez : %d \n",choice);
        CleanBuffer();
        if(choice == 1){
            addLine();
        }
        else if(choice == 2){
            //modifyLine();
        }
        else if(choice == 3){
            //deleteLine();
        }
        else if(choice == 0 ){
            return 0;
        }
        else{
            printf("L'entree contient des caracteres interdits");
            choice = 1;
        }
        CleanBuffer();
    }while(choice == 1 || choice == 2 || choice == 3);
}
