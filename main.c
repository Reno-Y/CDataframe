#include <stdio.h>
#include "Dataframe.h"

/*
 * Cdataframe
 * Renaud YOGANATHAN & Arshdeep SINGH
 *
 * Le main.c permet l'exécution du programme de test de la structure de donnée Dataframe
 */

void welcome_message()
{
    printf("**********************************************************************\n");
    printf("Bienvenu dans le programme de test de la structure de donnee Dataframe\n");
    printf("**********************************************************************\n");
    printf("\n");
    printf("Pour afficher le menu\n");
    printf("Appuyez sur une entrer pour continuer\n");
    printf("\n");
    getchar();
}

void wait_for_user() {
    printf("Appuyez sur une touche pour continuer...\n");
    getchar(); // Consomme le '\n' laissé par scanf
    getchar(); // Attend une nouvelle entrée de l'utilisateur
}

int main()
{
    CDATAFRAME *dataframe = create_empty_dataframe(); // Crée un dataframe vide
    welcome_message(); // Affiche le message de bienvenue

    int choice = 0;
    do {
        // Affiche le menu principale
        printf("\n");
        printf("------------------------------------\n");
        printf("               Menu                 \n");
        printf("------------------------------------\n");
        printf("1. Alimentation\n");
        printf("2. Affichage\n");
        printf("3. Operation usuelles\n");
        printf("4. Analyse et Statistiques\n");
        printf("5. Quitter\n");
        printf("\n");






        switch  (choice)
        {
            // Switch case pour les choix du menu
            case 1:
                printf("----------------\n");
                printf("- Alimentation -\n");
                printf("----------------\n");
                printf("\n");
                printf("1. Remplir le dataframe par saisie utilisateur\n");
                printf("2. Remplir le dataframe avec des valeurs predefinies\n");
                printf("3. Retour\n");
                printf("\n");

                int choix_alimentation;

                while (choix_alimentation < 1 || choix_alimentation > 3)
                {
                    printf("Entrez votre choix : ");
                    scanf("%d", &choix_alimentation);
                    printf("\n");
                }

                switch(choix_alimentation)

                // Switch case pour les choix du menu
                {
                    case 1:
                        fill_dataframe(dataframe);
                        choice = 0;

                        break;

                    case 2:
                        fill_dataframe_hardcode(dataframe);
                        choice = 0;

                        break;

                    case 3:

                        choice = 0;
                        choix_alimentation = 0;

                        break;
                }
                wait_for_user();
                break;

            case 2:
                printf("----------------\n");
                printf("-  Affichage   -\n");
                printf("----------------\n");
                printf("\n");
                printf("1. Afficher tout le dataframe\n");
                printf("2. Afficher une ligne du dataframe\n");
                printf("3. Afficher une colonne du dataframe\n");
                printf("4. Retour\n");
                printf("\n");


                int choix_affichage = 0;
                while (choix_affichage < 1 || choix_affichage > 4)
                {
                    printf("Entrez votre choix : ");
                    scanf("%d", &choix_affichage);
                    printf("\n");
                }

                switch(choix_affichage)
                {
                    case 1:
                        print_all_dataframe(dataframe);
                        choice = 0;
                        choix_affichage = 0;
                        break;

                    case 2:
                        printf("Entrez le numero de la ligne a afficher : \n");
                        int line = 0;
                        scanf("%d", &line);
                        print_line_dataframe(dataframe, line);
                        choice = 0;
                        choix_affichage = 0;
                        break;

                    case 3:

                        printf("Entrez le numero de la colonne a afficher : \n");
                        int column = 0;
                        scanf("%d", &column);

                        print_column_dataframe(dataframe, column);
                        choice = 0;
                        choix_affichage = 0;
                        break;

                    case 4:
                        choice = 0;
                        choix_affichage = 0;
                        break;
                }
                wait_for_user();
                break;

            case 3:
                printf("----------------\n");
                printf("-  Operations  -\n");
                printf("----------------\n");
                printf("\n");
                printf("1. Ajouter une ligne de valeurs \n");
                printf("2. Supprimer une ligne de valeurs \n");
                printf("3. Ajouter une colonne \n");
                printf("4. Supprimer une colonne \n");
                printf("5. Renommer le titre d une colonne \n");
                printf("6. Verifier l existence d une valeur dans le dataframe\n");
                printf("7. Remplacer la valeur se trouvant dans une cellule du dataframe\n");
                printf("8. Afficher les noms des colonnes\n");
                printf("9. Retour\n");
                printf("\n");

                int choix_operations = 0;
                while (choix_operations < 1 || choix_operations > 9)
                {
                    printf("Entrez votre choix : ");
                    scanf("%d", &choix_operations);
                    printf("\n");
                }

                switch(choix_operations)
                {
                    case 1:
                        add_line_to_dataframe(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 2:
                        remove_line_from_dataframe(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 3:
                        add_column_to_dataframe(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 4:
                        remove_column_from_dataframe(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 5:
                        rename_column(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 6:
                        does_value_exist(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 7:

                        printf("Entrez la la ligne la valeur a remplacer\n");

                        int line;
                        int column;
                        scanf("%d", &line);
                        printf("Entrez la colonne la valeur a remplacer\n");
                        scanf("%d", &column);

                        replace_value(dataframe, line, column);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 8:
                        print_columns_name(dataframe);
                        choice = 0;
                        choix_operations = 0;
                        break;

                    case 9:
                        choice = 0;
                        choix_operations = 0;
                        break;


                }
                wait_for_user();
                break;
            case 4:
                printf("----------------\n");
                printf("-  Statistiques -\n");
                printf("----------------\n");
                printf("\n");
                printf("1. Afficher le nombre de colonnes\n");
                printf("2. Afficher le nombre de lignes\n");
                printf("3. Afficher le nombre de cellules egales a une valeur donnee\n");
                printf("4. Afficher le nombre de cellules inferieures a une valeur donnee\n");
                printf("5. Afficher le nombre de cellules superieures a une valeur donnee\n");
                printf("6. Retour\n");
                printf("\n");

                int choix_statistiques = 0;
                while (choix_statistiques < 1 || choix_statistiques > 6)
                {
                    printf("Entrez votre choix : ");
                    scanf("%d", &choix_statistiques);
                    printf("\n");
                }

                switch(choix_statistiques)
                {
                    case 1:
                        print_nb_columns(dataframe);
                        choice = 0;
                        choix_statistiques = 0;
                        break;

                    case 2:
                        print_nb_lines(dataframe);
                        choice = 0;
                        choix_statistiques = 0;
                        break;

                    case 3:
                        printf("Entrez la valeur a rechercher : ");
                        int value;
                        scanf("%d", &value);
                        nb_of_cells_equal_to(dataframe, value);
                        choice = 0;
                        choix_statistiques = 0;
                        break;

                    case 4:
                        printf("Entrez la valeur a rechercher : ");
                        int value1;
                        scanf("%d", &value1);
                        nb_of_cells_lower_than(dataframe, value1);
                        choice = 0;
                        choix_statistiques = 0;
                        break;

                    case 5:
                        printf("Entrez la valeur a rechercher : ");
                        int value2;
                        scanf("%d", &value2);
                        nb_of_cells_greater_than(dataframe, value2);
                        choice = 0;
                        choix_statistiques = 0;
                        break;

                    case 6:
                        choice = 0;
                        choix_statistiques = 0;
                        break;
                }
                wait_for_user();
                break;
        }

    }while(choice != 5);


    printf("Merci d'avoir utilise notre programme\n");
    printf("JE SAIS QUE NOUS NOUS REVERRONS UN JOUR OU L'AUTRE, SALUT MON POTE :( \n");

    return 0;


}