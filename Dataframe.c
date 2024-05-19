#include "Dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 256

CDATAFRAME* create_empty_dataframe()
{
    CDATAFRAME *dataframe = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (dataframe == NULL) {
        return NULL;
    }
    dataframe->column = NULL;
    dataframe->nbcol = 0;
    return dataframe;
}

void fill_dataframe_hardcode(CDATAFRAME *dataframe)
{
    COLUMN *column1 = create_column("Column 1");
    COLUMN *column2 = create_column("Column 2");
    COLUMN *column3 = create_column("Column 3");

    insert_value(column1, 1);
    insert_value(column1, 2);
    insert_value(column1, 3);

    insert_value(column2, 1);
    insert_value(column2, 2);
    insert_value(column2, 3);

    insert_value(column3, 1);
    insert_value(column3, 2);
    insert_value(column3, 3);

    dataframe->column = (COLUMN **)realloc(dataframe->column, (dataframe->nbcol + 3) * sizeof(COLUMN *));
    dataframe->column[dataframe->nbcol] = column1;
    dataframe->nbcol++;
    dataframe->column[dataframe->nbcol] = column2;
    dataframe->nbcol++;
    dataframe->column[dataframe->nbcol] = column3;
    dataframe->nbcol++;

}

int add_column_to_dataframe(CDATAFRAME *dataframe, COLUMN *column) {
    COLUMN **new_columns = realloc(dataframe->column, (dataframe->nbcol + 1) * sizeof(COLUMN *));
    if (new_columns == NULL) {
        return 1;
    }
    dataframe->column = new_columns;
    dataframe->column[dataframe->nbcol] = column;
    dataframe->nbcol++;
    return 0;
}


void fill_dataframe(CDATAFRAME *dataframe) {
    int nbcol;

    printf("Veuillez saisir le nombre de colonnes que vous voulez ajouter : ");
    if (scanf("%d", &nbcol) != 1 || nbcol <= 0) {
        printf("Nombre de colonnes invalide.\n");
        return;
    }

    for (int i = 0; i < nbcol; i++)
    {
        int nbval;
        char title[BUFFER_SIZE];

        printf("Veuillez saisir le titre de la colonne %d : \n", i + 1);
        scanf("%s", title); // Utilisation de scanf pour les titres courts

        COLUMN *column = create_column(title);

        printf("Veuillez saisir le nombre de valeurs que vous voulez ajouter a la colonne %d : \n", i + 1);
        if (scanf("%d", &nbval) != 1 || nbval < 0)
        {
            printf("Nombre de valeurs invalide.\n");
            delete_column(column);
            continue;
        }

        for (int j = 0; j < nbval; j++) {
            int value;
            printf("Veuillez saisir la valeur %d de la colonne %d : \n", j + 1, i + 1);
            if (scanf("%d", &value) != 1)
            {
                printf("Valeur invalide.\n");
                continue;
            }
            if (insert_value(column, value) != 0) {
                printf("Erreur lors de l'insertion de la valeur.\n");
                continue;
            }
        }

        if (add_column_to_dataframe(dataframe, column) != 0)
        {
            printf("Erreur lors de l'ajout de la colonne au dataframe.\n");
            delete_column(column);
        }
    }
}

void print_all_dataframe(CDATAFRAME *dataframe) {
    if (dataframe->nbcol == 0) {
        printf("Toutes les colonnes sont vides\n");
        return;
    }

    // Afficher les titres des colonnes
    for (int i = 0; i < dataframe->nbcol; i++) {
        printf("%-15s", dataframe->column[i]->title);
    }
    printf("\n");

    // Déterminer la longueur maximale de toutes les colonnes
    int max_tlog = 0;
    for (int i = 0; i < dataframe->nbcol; i++) {
        if (dataframe->column[i]->tlog > max_tlog) {
            max_tlog = dataframe->column[i]->tlog;
        }
    }

    // Afficher les valeurs des colonnes
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
}

void print_line_dataframe(CDATAFRAME *cdataframe, int line)
{
    if (line < 1)
    {
        printf("La ligne n'existe pas\n");
        return;
    }
    // Afficher les titres des colonnes
    for (int i = 0; i < cdataframe->nbcol; i++) {
        printf("%-15s", cdataframe->column[i]->title);
    }
    printf("\n");

    for (int i = 0; i < cdataframe->nbcol; i++)
    {
        if (line <= cdataframe->column[i]->tlog)
        {
            printf("[%d]%d           ", line , cdataframe->column[i]->values[line - 1]);
        }
        else
        {
            printf("[%d] \n", i + 1);
        }
    }
}

void print_column_dataframe(CDATAFRAME *cdataframe, int column)
{
    if (column < 1 || column > cdataframe->nbcol)
    {
        printf("La colonne n'existe pas\n");
        return;
    }
    print_column(cdataframe->column[column - 1]);
    printf("\n");
}

void add_line_to_dataframe(CDATAFRAME *cdataframe)
{


}