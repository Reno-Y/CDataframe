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
