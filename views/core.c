    int choice = 0;
    printf("Tapez 1 pour ajouter une bdd \nTapez 2 pour utiliser une bdd existante \nTapez 3 pour ajouter une table\nTapez 4 pour supprimer une table \nTapez 5 pour supprimer une bdd\n");
    scanf("%d", &choice);
    printf("Vous avez selectionnez : %d \n",choice);
    CleanBuffer();
    if(choice == 1){
        AddBDD();
    }
    if(choice == 2){
        OpenBDD();
    }
    if(choice == 3){
        AddTable();
    }
    if(choice == 4){
        DeleteTable();
    }
    if(choice == 5){
        DeleteBDD();
    }