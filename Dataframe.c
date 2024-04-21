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
