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
    column->title = strdup(title); // Copie du titre dans une zone mémoire allouée dynamiquement
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
            column->values = malloc(REALOC_SIZE * sizeof(int));
            if(column->values == NULL)
            {
                return 1;
            }
            column->tphys = REALOC_SIZE;
        }
        else if(column->tphys >= REALOC_SIZE)
        {
            column-> values = realloc(column -> values, (column -> tphys + REALOC_SIZE) * sizeof(int));
            column->tphys += REALOC_SIZE;
        }
    }

    column->values[column->tlog] = value;
    column->tlog++;
    return 0;
}
// la fonction permet d'ajouter une valeur à la colonne, si le nombre de valeurs logiques est supérieur au nombre de
// valeurs alors on réalloue de la mémoire pour le tableau de valeurs.

void delete_column(COLUMN *column)
{
    free(column->values);
    free(column->title);
    free(column);
}
// la fonction permet de supprimer une colonne, on libère la mémoire allouée pour le tableau de valeurs, le titre et la
// colonne.

void print_column(COLUMN *column)
{

    printf("%s\n", column->title);
    for(int i = 0; i < column->tlog; i++)
    {
        printf( "[%d] %d \n", i+1, column->values[i]);
    }
    printf("\n");
}

// la fonction permet d'afficher la colonne, on affiche le titre de la colonne et les valeurs de la colonne.