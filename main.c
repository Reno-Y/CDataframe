#include <stdlib.h>
#include <stdio.h>
#include "Dataframe.h"

int main() {

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
*/

    COLUMN *mycol = create_column("test");
    insert_value(mycol, 1);
    insert_value(mycol, 3);
    insert_value(mycol, 3);
    insert_value(mycol, 3);
    insert_value(mycol, 5);
    print_column(mycol);
    printf(" L'occuruence de la valeur 3 est %d\n", value_occurence(mycol, 3));
    printf(" La position de la valeur 3 est %d\n", value_position(mycol, 3));
    printf("--------------------------------------------\n");
    printf(" Le nombre de valeurs superieures a 3 est %d\n", value_up_to(mycol, 3));
    printf(" Le nombre de valeurs inferieures a 3 est %d\n", value_down_to(mycol, 1));
    printf(" Le nombre de valeurs egale a 3 est %d\n", value_equal_to(mycol, 3));







    return 0;


}
