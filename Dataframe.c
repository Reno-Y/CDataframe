#include "Dataframe.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN** create_dataframe(int nb_columns)
{
    COLUMN **CD_dataframe = (COLUMN **)malloc(nb_columns * sizeof(COLUMN *));
    return CD_dataframe;
}
/*
void fill_cd_dataframe(COLUMN **CD_dataframe, int nb_col)
{
    for (int i = 0; i < nb_col; i++)
    {
        CD_dataframe[i] = create_column("colonne");
        for (int j = 0; j < 10; j++)
        {
            insert_value(CD_dataframe[i], j);
        }
    }
}
 */