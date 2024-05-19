#include <stdlib.h>
#include <stdio.h>
#include "Dataframe.h"

int
main() {

/*
   printf("Bienvenu dans le programme de test de la structure de donnée Dataframe\n");
   printf("Voici la liste des fonctionalités que vous pouvez tester\n");
    printf("1. Créer un Dataframe\n");
    printf("2. Remplir un Dataframe\n");
    printf("3. Afficher un Dataframe\n");
    printf("4. Ajouter une colonne à un Dataframe\n");
    printf("5. Ajouter une ligne à un Dataframe\n");
    printf("6. Supprimer une colonne d'un Dataframe\n");
    printf("7. Supprimer une ligne d'un Dataframe\n");
    printf("8. Remplacer une valeur d'un Dataframe\n");
    printf("9. Renommer une colonne d'un Dataframe\n");
    printf("10. Afficher le nombre de lignes d'un Dataframe\n");
    printf("11. Afficher le nombre de colonnes d'un Dataframe\n");
    printf("12. Afficher le nombre de cellules identiques à une valeur donnée dans un Dataframe\n");
    printf("13. Afficher le nombre de cellules supérieures à une valeur donnée dans un Dataframe\n");
    printf("14. Afficher le nombre de cellules inférieures à une valeur donnée dans un Dataframe\n");
    printf("15. Quitter le programme\n");

int choice;
    printf("Veuillez saisir le numéro de l'option que vous voulez tester\n");
    scanf("%d", &choice);

    switch (choice)
    {

    }


    COLUMN *mycol = create_column("Column 1");
    COLUMN *mycol2 = create_column("test2");

    insert_value(mycol, 1);
    insert_value(mycol, 3);
    insert_value(mycol, 3);



    insert_value(mycol2, 5);
    insert_value(mycol2, 4);
    insert_value(mycol2, 3);
    insert_value(mycol2, 2);
    insert_value(mycol2, 1);

    COLUMN columns[] = {*mycol, *mycol2};
    print_column(columns,2);
*/

    CDATAFRAME *dataframe = create_empty_dataframe();
    fill_dataframe(dataframe);
    print_dataframe(dataframe);


    return 0;


}
