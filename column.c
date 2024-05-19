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

void print_column(COLUMN *column)
{

    printf("%s\n", column->title);
    for(int i = 0; i < column->tlog; i++)
    {
        printf( "[%d] %d \n", i+1, column->values[i]);
    }
    printf("\n");
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