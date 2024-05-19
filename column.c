#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include <string.h>
#define REALOC_SIZE 256


COLUMN *create_column(char* title) {
    COLUMN *column = malloc(sizeof(COLUMN));
    if (column == NULL) {
        return NULL;
    }

    column->title = (char*)malloc((strlen(title)+1)*sizeof(char)); // Allocation de la mémoire pour le titre
    strcpy(column->title,title);

    if (column->title == NULL) {
        free(column); // Libération de la mémoire allouée pour la colonne si la copie échoue
        return NULL;
    }
    column->tphys = 0;
    column->tlog = 0;
    column->values = NULL;
    return column;
}


int insert_value(COLUMN *column, int value)
{
    if(column->tlog + 1 > column->tphys)
    {
        if(column -> tphys == 0)
        {

            // Alocation de la mémoire pour le tableau de valeurs si la taille physique est null
            column->values = malloc(REALOC_SIZE * sizeof(int));

            if(column->values == NULL)
            {
                return 1; // Retourne 1 si l'allocation échoue
            }
            column->tphys = REALOC_SIZE;
        }
        else if(column->tphys >= REALOC_SIZE)
        {
            column-> values = realloc(column -> values, (column -> tphys + REALOC_SIZE) * sizeof(int));
            column->tphys += REALOC_SIZE;

            // Réallocation de la mémoire pour le tableau de valeurs si la taille physique est supérieure à REALOC_SIZE
        }

    }

    column->values[column->tlog] = value;
    column->tlog++;
    return 0; // Retourne 0 si l'insertion est réussie
}


void delete_column(COLUMN *column)
{
    // Libération de la mémoire allouée pour le tableau de valeurs et le titre de la colonne
    free(column->values);
    free(column->title);
    free(column);
}



void print_column(COLUMN *columns, int nb_col)
{

    /*
    int nb_real_column = sizeof columns / sizeof columns[0];

    if (nb_col > nb_real_column) {
        printf("Le nombre de colonnes a afficher est superieur au nombre de colonnes reelles\n");
        return;
    }
     //tentative de verification du nombre de colonnes a afficher
    */

    int all_empty = 1;
    for (int i = 0; i < nb_col; i++) {
        if (columns[i].tlog != 0) {
            all_empty = 0;
            break;
        }
    }
    // Vérifier si toutes les colonnes sont vides




    if (all_empty) {
        // Affiche un message si toutes les colonnes sont vides

        printf("Toutes les colonnes sont vides\n");
        return;
    }

    // Afficher les titres des colonnes
    for (int i = 0; i < nb_col; i++)
    {
        if (columns[i].tlog != 0)
        {
            printf("%-15s", columns[i].title);
        }
    }
    printf("\n");

    // Déterminer la longueur maximale de toutes les colonnes
    int max_tlog = 0;
    for (int i = 0; i < nb_col; i++) {
        if (columns[i].tlog > max_tlog) {
            max_tlog = columns[i].tlog;
        }
    }

    // Afficher les valeurs des colonnes
    for (int i = 0; i < max_tlog; i++) {
        for (int j = 0; j < nb_col; j++) {
            if (i < columns[j].tlog) {
                printf("[%d] %-11d", i + 1, columns[j].values[i]);
            } else {
                printf("               ");
                // Espace pour les colonnes avec moins de lignes
            }
        }
        printf("\n");
    }
}



int value_occurence(COLUMN *column, int value)
{
    int occurence = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] == value)
        {
            occurence++;
            // Compte le nombre d'occurence de la valeur dans la colonne
        }
    }
    return occurence;
}

int value_position(COLUMN *column, int value)
{
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] == value)
        {
            return i+1;
            // Retourne la position de la valeur dans la colonne
        }
    }
    printf("La valeur n'existe pas dans la colonne\n");
}

int value_down_to(COLUMN *column, int value)
{
    int occurence = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] < value)
        {
            occurence++;
            // Compte le nombre de valeurs inférieures à la valeur donnée
        }
    }
    return occurence;

}

int value_up_to(COLUMN *column, int value)
{
    int occurence = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] > value)
        {
            occurence++;
            // Compte le nombre de valeurs supérieures à la valeur donnée
        }
    }

    return occurence;
}

int value_equal_to(COLUMN *column, int value)
{
    int occurence = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] == value)
        {
            occurence++;
            // Compte le nombre de valeurs égales à la valeur donnée
        }
    }
    return occurence;
}