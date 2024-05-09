#include <stdlib.h>
#include <stdio.h>
#include "Dataframe.h"

int main() {



    COLUMN **dataframe = create_empty_cd_dataframe(2);
    fill_cd_dataframe(dataframe, 2);
    print_cd_dataframe(dataframe, 2);



/*
    printf("Combiens de fois se trouve la valeur 10 dans la colonne mycolumn ?\n");
    printf("La valeur 10 se trouve %d fois dans la colonne mycolumn\n", value_occurence(mycolumn, 10));

    printf("A quelle position se trouve la valeur 20 dans la colonne mycolumn ?\n");
    printf("La valeur 20 se trouve à la position %d dans la colonne mycolumn\n", value_position(mycolumn, 20));

    printf("Combien de valeurs sont inférieures à 20 dans la colonne mycolumn ?\n");
    printf("Il y a %d valeurs inférieures à 20 dans la colonne mycolumn\n", value_up_to(mycolumn, 20));

    printf("Combien de valeurs sont supérieures à 20 dans la colonne mycolumn ?\n");
    printf("Il y a %d valeurs supérieures à 20 dans la colonne mycolumn\n", value_down_to(mycolumn, 20));

    printf("Combien de valeurs sont égales à 20 dans la colonne mycolumn ?\n");
    printf("Il y a %d valeurs égales à 20 dans la colonne mycolumn\n", value_equal_to(mycolumn, 20));

    printf("Ajoutons la valeur 35 à la ligne 2\n");
    add_line(mycolumn, 2, 35);


    printf("Ajoutons une colonne à la colonne mycolumn\n");
    add_column(mycolumn, "mycolumn2");

    printf("Renommons la colonne mycolumn2 en mycolumn3\n");
    rename_column(mycolumn, "mycolumn3");

    printf("La valeur 10 existe-t-elle dans la colonne mycolumn ?\n");
    printf("La valeur 10 %s dans la colonne mycolumn\n", value_exist(mycolumn, 10) ? "existe" : "n'existe pas");

    printf("Remplaçons la valeur 10 par 5 à la ligne 0\n");
    replace_value(mycolumn, 0, 10, 5);

    printf("Le nom de la colonne est : ");
    print_column_name(mycolumn);

    printf("Le nombre de lignes est : %d\n", number_of_lines(mycolumn));

    printf("Le nombre de colonnes est : %d\n", number_of_columns(mycolumn));

    COLUMN** mydataframe = CDdataframe(4);

    return 0;
*/

}
