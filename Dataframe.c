#include "Dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 256

CDataframe* create_empty_dataframe()
{
    CDataframe *dataframe = (CDataframe *)malloc(sizeof(CDataframe));
    if (dataframe == NULL) {
        return NULL;
    }
    dataframe->column = NULL;
    dataframe->nbcol = 0;
    return dataframe;
}


void print_cdataframe(CDataframe *dataframe)
{
    if (dataframe == NULL || dataframe->nbcol == 0)
    {
        printf("Le dataframe est vide \n");
        return;

    }
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        printf(" %-15s", dataframe->column[i]->title );
    }
    printf("\n");

    int tlog_max = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        if (dataframe->column[i]->tlog > tlog_max)
        {
            tlog_max = dataframe->column[i]->tlog;
        }
    }

    for (int i = 0; i < tlog_max; i++)
    {
        for (int j = 0; j < dataframe->nbcol; j++)
        {
            if(i < dataframe->column[j]->tlog)
            {
                printf(" %-15d", dataframe->column[j]->values[i]);

            }
            else
            {
                printf(" %-15s", " " );
            }

        }
        printf("\n");
    }

}