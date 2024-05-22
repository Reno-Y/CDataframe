#include "Dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

/*
 * Cdataframe
 * Renaud YOGANATHAN & Arshdeep SINGH
 *
 * Le fichier Dataframe.c contient les fonctions pour manipuler les dataframes.
 */


CDATAFRAME* create_empty_dataframe()
{
    CDATAFRAME *dataframe = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (dataframe == NULL) {
        return NULL;
    }
    dataframe->column = NULL;
    dataframe->nbcol = 0;
    return dataframe;
    // Allocation de la mémoire pour le dataframe
    // Création d'un dataframe vide
}

void fill_dataframe_hardcode(CDATAFRAME *dataframe)
{
    COLUMN *column1 = create_column("Column 1"); // Création de colonnes
    COLUMN *column2 = create_column("Column 2");
    COLUMN *column3 = create_column("Column 3");

    insert_value(column1, 1); // Ajout de valeurs à la colonne
    insert_value(column1, 2);
    insert_value(column1, 3);

    insert_value(column2, 1);
    insert_value(column2, 2);
    insert_value(column2, 3);

    insert_value(column3, 1);
    insert_value(column3, 2);
    insert_value(column3, 3);


    dataframe->column = (COLUMN **)realloc(dataframe->column, (dataframe->nbcol + 3) * sizeof(COLUMN *));
    dataframe->column[dataframe->nbcol] = column1;  // Ajout de la colonne au dataframe
    dataframe->nbcol++;                             // Incrémentation du nombre de colonnes
    dataframe->column[dataframe->nbcol] = column2;
    dataframe->nbcol++;
    dataframe->column[dataframe->nbcol] = column3;
    dataframe->nbcol++;

    // Remplissage du dataframe avec des valeurs prédéfinies

}

int add_to_dataframe(CDATAFRAME *dataframe, COLUMN *column) {
    COLUMN **new_columns = realloc(dataframe->column, (dataframe->nbcol + 1) * sizeof(COLUMN *));
    if (new_columns == NULL) {
        return 1;
        // Retourne 1 si la réallocation de mémoire échoue
    }
    dataframe->column = new_columns; // Réallocation de la mémoire pour le tableau de colonnes
    dataframe->column[dataframe->nbcol] = column;
    dataframe->nbcol++;
    return 0;
    // Ajout d'une colonne au dataframe
}


void fill_dataframe(CDATAFRAME *dataframe) {
    int nbcol;

    printf("Veuillez saisir le nombre de colonnes que vous voulez ajouter : ");
    if (scanf("%d", &nbcol) != 1 || nbcol <= 0) {
        printf("Nombre de colonnes invalide.\n");
        return;
        // Vérification de la validité du nombre de colonnes
    }

    for (int i = 0; i < nbcol; i++)
    {
        int nbval;
        char title[BUFFER_SIZE];

        printf("Veuillez saisir le titre de la colonne %d : \n", i + 1);
        scanf("%s", title);
        // Utilisation de scanf pour les titres courts

        COLUMN *column = create_column(title);
        // Création d'une colonne avec le titre saisi

        printf("Veuillez saisir le nombre de valeurs que vous voulez ajouter a la colonne %d : \n", i + 1);
        if (scanf("%d", &nbval) != 1 || nbval < 0)
        {
            printf("Nombre de valeurs invalide.\n");
            delete_column(column);
            continue;
            // Vérification de la validité du nombre de valeurs
        }

        for (int j = 0; j < nbval; j++) {
            int value;
            printf("Veuillez saisir la valeur %d de la colonne %d : \n", j + 1, i + 1);
            if (scanf("%d", &value) != 1)
            {
                printf("Valeur invalide.\n");
                continue;
                // Vérification de la validité de la valeur
            }
            if (insert_value(column, value) != 0) {
                printf("Erreur lors de l'insertion de la valeur.\n");
                continue;
                // Insertion de la valeur dans la colonne
            }
        }

        if (add_to_dataframe(dataframe, column) != 0)
        {
            printf("Erreur lors de l'ajout de la colonne au dataframe.\n");
            delete_column(column);
            // libération de la mémoire si l'ajout de la colonne échoue
        }
    }
}

void print_all_dataframe(CDATAFRAME *dataframe) {
    if (dataframe->nbcol == 0) {
        printf("Toutes les colonnes sont vides\n");
        return;
        // Vérification si le dataframe est vide
    }


    for (int i = 0; i < dataframe->nbcol; i++)
    {
        printf("%-15s", dataframe->column[i]->title);
        // Afficher les titres des colonnes
    }
    printf("\n");


    int max_tlog = 0;
    for (int i = 0; i < dataframe->nbcol; i++) {
        if (dataframe->column[i]->tlog > max_tlog) {
            max_tlog = dataframe->column[i]->tlog;
        }
    }
    // Déterminer la longueur maximale de toutes les colonnes


    for (int i = 0; i < max_tlog; i++) {
        for (int j = 0; j < dataframe->nbcol; j++) {
            if (i < dataframe->column[j]->tlog) {
                printf("[%d] %-11d", i + 1, dataframe->column[j]->values[i]);
            } else {
                printf("               ");
            }
        }
        printf("\n");
    }
    // Afficher les valeurs des colonnes
}

void print_line_dataframe(CDATAFRAME *cdataframe, int line)
{
    if (line < 1)
    {
        printf("La ligne n'existe pas\n");
        return;
        // Vérification si la ligne existe
    }

    for (int i = 0; i < cdataframe->nbcol; i++) {
        printf("%-15s", cdataframe->column[i]->title);
        // Afficher les titres des colonnes
    }
    printf("\n");


    for (int i = 0; i < cdataframe->nbcol; i++)
    // Parcourir toutes les colonnes
    {
        if (line <= cdataframe->column[i]->tlog)
        // Vérifier si la ligne existe
        {
            printf("[%d]%d           ", line , cdataframe->column[i]->values[line - 1]);
            // Afficher les valeurs de la ligne
        }
        else
        {
            printf("              ");
            // Ajout d'espace s'il n'y a pas de valeurs à cette endroit
        }

    }
    printf("\n");
}

void print_column_dataframe(CDATAFRAME *cdataframe, int column)
{
    if (column < 1 || column > cdataframe->nbcol)
    // Vérification si la colonne existe
    {
        printf("La colonne n'existe pas\n");
        return;
        // Affichage d'un message d'erreur si la colonne n'existe pas
    }
    print_column(cdataframe->column[column - 1]);
    printf("\n");
    // Affichage de la colonne
}

void add_column_to_dataframe(CDATAFRAME *dataframe)
{
    char title[BUFFER_SIZE];
    printf("Veuillez saisir le titre de la colonne que vous voulez ajouter : \n");
    scanf("%s", title);
    // Utilisation de scanf pour les titres courts

    COLUMN *column = create_column(title);
    if (column == NULL)
    {
        printf("Erreur lors de la création de la colonne.\n");
        return;
        // Vérification de la création de la colonne
    }
    printf("Veuillez saisir le nombre de valeurs que vous voulez ajouter a la colonne : \n");
    int nbval;
    if (scanf("%d", &nbval) != 1 || nbval < 0)
    {
        printf("Nombre de valeurs invalide.\n");
        delete_column(column);
        return;
        // suppression de la colonne si le nombre de valeurs est invalide
    }
    for(int i = 0; i < nbval; i++)
    {
        int value;
        printf("Veuillez saisir la valeur %d de la colonne : \n", i + 1);
        if (scanf("%d", &value) != 1)
        {
            printf("Valeur invalide.\n");
            continue;
            // Vérification de la validité de la valeur
        }
        if (insert_value(column, value) != 0)
        {
            printf("Erreur lors de l'insertion de la valeur.\n");
            continue;
            //retourne 1 si l'insertion échoue
        }
    }
    if (add_to_dataframe(dataframe, column) != 0)
    {
        printf("Erreur lors de l'ajout de la colonne au dataframe.\n");
        // Vérification de l'ajout de la colonne
        delete_column(column);

    }
}

// 3.Opérations usuelles



void add_line_to_dataframe(CDATAFRAME *dataframe)
{
    // Ajout d'une ligne au dataframe

    for (int i = 0; i < dataframe->nbcol; i++) {
        int value;
        printf("Veuillez saisir la valeur de la colonne %d : \n", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Valeur invalide.\n");
            continue;
            // Vérification de la validité de la valeur
        }
        if (insert_value(dataframe->column[i], value) != 0) {
            printf("Erreur lors de l'insertion de la valeur.\n");
            // Vérification de l'insertion de la valeur
            continue;

        }
    }
}

void remove_line_from_dataframe(CDATAFRAME *dataframe)
{
    // Suppression d'une ligne du dataframe
    int line;
    printf("Veuillez saisir le numero de la ligne que vous voulez supprimer : \n");
    if (scanf("%d", &line) != 1 || line < 1)
    {
        printf("Numéro de ligne invalide.\n");
        return;
        // Vérification de la validité de la ligne
    }
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        if (line <= dataframe->column[i]->tlog)
        {
            // Vérification si la ligne existe
            for (int j = line; j < dataframe->column[i]->tlog; j++)
            // Parcourir toutes les valeurs de la colonne
            {
                dataframe->column[i]->values[j - 1] = dataframe->column[i]->values[j];
                // Décalage des valeurs
            }
            dataframe->column[i]->tlog--;
            // Décrémentation du nombre de valeurs
        }
    }
}

void remove_column_from_dataframe(CDATAFRAME *dataframe)
{
    // Suppression d'une colonne du dataframe

    int column;
    printf("Veuillez saisir le numero de la colonne que vous voulez supprimer : \n");
    if (scanf("%d", &column) != 1 || column < 1 || column > dataframe->nbcol)

    // Vérification de la validité de la colonne

    {
        printf("Numéro de colonne invalide.\n");
        return;
        // Affichage d'un message d'erreur si la colonne n'existe pas

    }
    delete_column(dataframe->column[column - 1]);
    // Suppression de la colonne
    for (int i = column; i < dataframe->nbcol; i++)
    // Parcourir toutes les colonnes
    {
        dataframe->column[i - 1] = dataframe->column[i];
        // Décalage des colonnes
    }
    dataframe->nbcol--;
    // Décrémentation du nombre de colonnes

    dataframe->column = realloc(dataframe->column, dataframe->nbcol * sizeof(COLUMN *));
    // Réallocation de la mémoire pour le tableau de colonnes
}

void rename_column(CDATAFRAME *dataframe)
{
    int column;
    printf("Veuillez saisir le numero de la colonne que vous voulez renommer : \n");
    if (scanf("%d", &column) != 1 || column < 1 || column > dataframe->nbcol)
    // Vérification de la validité de la colonne

    {
        printf("Numéro de colonne invalide.\n");
        return;
        // Affichage d'un message d'erreur si la colonne n'existe pas

    }
    char title[BUFFER_SIZE];
    printf("Veuillez saisir le nouveau titre de la colonne : \n");
    scanf("%s", title);
    dataframe->column[column-1]->title = (char*)malloc((strlen(title)+1)*sizeof(char));
    // Allocation de la mémoire pour le titre
    strcpy(dataframe->column[column-1]->title,title);
    // Copie du nouveau titre dans la colonne

}

void does_value_exist(CDATAFRAME *dataframe)
{
    // Vérification de l'existence d'une valeur dans le dataframe
    int value;
    printf("Veuillez saisir la valeur que vous voulez chercher : \n");
    if (scanf("%d", &value) != 1)
    {
        printf("Valeur invalide.\n");
        return;
        // Vérification de la validité de la valeur
    }
    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            if (dataframe->column[i]->values[j] == value)
            {
                count++;
                // Compte le nombre de fois que la valeur est trouvée

            }
        }
    }
    if (count !=0)
    {
        printf("La valeur %d a ete trouvee %d fois dans le dataframe.\n", value, count);
        // Affichage du nombre de fois que la valeur est trouvée
    }
    else
    {
        printf("La valeur %d n'a pas ete trouvee dans le dataframe.\n", value);
        // Affichage d'un message si la valeur n'est pas trouvée
    }


}

void replace_value(CDATAFRAME *dataframe, int line, int column)

// Remplacement de la valeur d'une cellule

{
    if (line < 1 || line > dataframe->column[column - 1]->tlog)
    // Vérification de la validité de la ligne
    {
        printf("La ligne n'existe pas\n");
        return;
        // Affichage d'un message d'erreur si la ligne n'existe pas
    }
    int value;
    printf("Veuillez saisir la nouvelle valeur de la cellule : \n");
    if (scanf("%d", &value) != 1)
    {
        printf("Valeur invalide.\n");
        return;
        // Vérification de la validité de la valeur
    }
    dataframe->column[column - 1]->values[line - 1] = value;
    // Remplacement de la valeur de la cellule
}

void print_columns_name(CDATAFRAME *dataframe)
{
    // Affichage des noms des colonnes

    printf("Le nom des colonnes sont : \n");
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        printf("%s\n", dataframe->column[i]->title);
    }
}

// 4.Analyse et statistiques

void print_nb_lines(CDATAFRAME *dataframe)
{
    // Affichage du nombre de lignes du dataframe
    int max = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        if (dataframe->column[i]->tlog > max)
        {
            max = dataframe->column[i]->tlog;
            // Détermination du nombre de lignes
        }
    }
    printf("Le nombre de lignes du dataframe est : %d\n", max);
}

void print_nb_columns(CDATAFRAME *dataframe)
{

// Affichage du nombre de colonnes du dataframe
    printf("Le nombre de colonnes du dataframe est : %d\n", dataframe->nbcol);
}

void nb_of_cells_equal_to(CDATAFRAME *dataframe,int value)
{

    // Compter le nombre de cellules contenant une valeur donnée

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    // Parcourir toutes les colonnes
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        // Parcourir toutes les valeurs de la colonne
        {
            if (dataframe->column[i]->values[j] == value)
            // Vérifier si la valeur est égale à la valeur donnée
            {
                count++;
                // Compter le nombre de cellules contenant la valeur donnée
            }
        }
    }
    if (count == 0)
    {
        printf("La valeur %d n'a pas ete trouvee dans le dataframe.\n", value);
        return;
        // Affichage d'un message si la valeur n'est pas trouvée
    }
    else
    {
        printf("Le nombre de cellules contenant la valeur %d est : %d\n", value, count);
        // Affichage du nombre de cellules contenant la valeur donnée
    }
}

void nb_of_cells_greater_than(CDATAFRAME *dataframe, int value)
{
    // Compter le nombre de cellules supérieures à une valeur donnée

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        // Parcourir toutes les colonnes
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        // Parcourir toutes les valeurs de la colonne
        {
            if (dataframe->column[i]->values[j] > value)
            {
                count++;
                // Compter le nombre de cellules supérieures à la valeur donnée
            }
        }
    }
    if (count == 0)
    {
        printf("Aucune cellule n'est superieure a la valeur %d.\n", value);
        return;
        // Affichage d'un message si aucune cellule n'est supérieure à la valeur donnée
    }
    else
    {
        printf("Le nombre de cellules superieures a la valeur %d est : %d\n", value, count);
        // Affichage du nombre de cellules supérieures à la valeur donnée
    }
}

void nb_of_cells_lower_than(CDATAFRAME *dataframe, int value)
{

    // Compter le nombre de cellules inférieures à une valeur donnée

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        // Parcourir toutes les colonnes
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            // Parcourir toutes les valeurs de la colonne
            if (dataframe->column[i]->values[j] < value)
            {
                count++;
                // Compter le nombre de cellules inférieures à la valeur donnée
            }
        }
    }
    if (count == 0)
    {
        printf("Aucune cellule n'est inferieure a la valeur %d.\n", value);
        return;
        // Affichage d'un message si aucune cellule n'est inférieure à la valeur donnée
    }
    else
    {
        printf("Le nombre de cellules inferieures a la valeur %d est : %d\n", value, count);
        // Affichage du nombre de cellules inférieures à la valeur donnée
    }
}