#include "Dataframe.h"
#include <stdlib.h>
#include <stdio.h>

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

void delete_column(COLUMN *column)
{
    free(column->values);
    free(column->title);
    free(column);
}

void print_column(COLUMN *column)
{
    printf("Column %s: \n", column->title);
    for(int i = 0; i < column->tlog; i++)
    {
        printf( "[%d] %d \n", i, column->values[i]);
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
            return i;
        }
    }
    return -1;
}

int value_up_to(COLUMN *column, int value)
{
    int up_to = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] < value)
        {
            up_to++;
        }
    }
    return up_to;
}

int value_down_to(COLUMN *column, int value)
{
    int down_to = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] > value)
        {
            down_to++;
        }
    }
    return down_to;
}

int value_equal_to(COLUMN *column, int value)
{
    int equal_to = 0;
    for(int i = 0; i < column->tlog; i++)
    {
        if(column->values[i] == value)
        {
            equal_to++;
        }
    }
    return equal_to;
}


COLUMN ** CDdataframe(int nb_col)
{
    COLUMN ** tabcddataframe = malloc(nb_col * sizeof (COLUMN*));

    if(tabcddataframe == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < nb_col; i++)
    {
        tabcddataframe[i] = create_column("column");

    }
    return tabcddataframe;

}

