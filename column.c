#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#define REALOC_SIZE 256

COLUMN *create_column(char* title)
{
    COLUMN *column = malloc(sizeof(COLUMN));
    if(column == NULL)
    {
        return NULL;
    }
    column->title = title;
    column->tphys = 0;
    column->tlog = 0;
    column->values = NULL;
    return column;
}
// la fonction permet de créer une collone avec un titre, un nombre de valeurs physique et logique à 0 et un tableau
// de valeurs vide.

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
    printf("Column %s: \n", column->title);
    for(int i = 0; i < column->tlog; i++)
    {
        printf( "[%d] %d \n", i, column->values[i]);
    }
    printf("\n");
}

// la fonction permet d'afficher la colonne, on affiche le titre de la colonne et les valeurs de la colonne.