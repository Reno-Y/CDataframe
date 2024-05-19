#include "Dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int add_to_dataframe(CDATAFRAME *dataframe, COLUMN *column) {
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

        if (add_to_dataframe(dataframe, column) != 0)
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

void add_column_to_dataframe(CDATAFRAME *dataframe)
{
    char title[BUFFER_SIZE];
    printf("Veuillez saisir le titre de la colonne que vous voulez ajouter : \n");
    scanf("%s", title);

    COLUMN *column = create_column(title);
    if (column == NULL)
    {
        printf("Erreur lors de la création de la colonne.\n");
        return;
    }
    printf("Veuillez saisir le nombre de valeurs que vous voulez ajouter a la colonne : \n");
    int nbval;
    if (scanf("%d", &nbval) != 1 || nbval < 0)
    {
        printf("Nombre de valeurs invalide.\n");
        delete_column(column);
        return;
    }
    for(int i = 0; i < nbval; i++)
    {
        int value;
        printf("Veuillez saisir la valeur %d de la colonne : \n", i + 1);
        if (scanf("%d", &value) != 1)
        {
            printf("Valeur invalide.\n");
            continue;
        }
        if (insert_value(column, value) != 0)
        {
            printf("Erreur lors de l'insertion de la valeur.\n");
            continue;
        }
    }
    if (add_to_dataframe(dataframe, column) != 0)
    {
        printf("Erreur lors de l'ajout de la colonne au dataframe.\n");
        delete_column(column);
    }
}

// 3.Opérations usuelles

void add_line_to_dataframe(CDATAFRAME *dataframe) {
    int collumn = 0;
    for (int i = 0; i < dataframe->nbcol; i++) {
        collumn++;
    }
    for (int i = 0; i < collumn; i++) {
        int value;
        printf("Veuillez saisir la valeur de la colonne %d : \n", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Valeur invalide.\n");
            continue;
        }
        if (insert_value(dataframe->column[i], value) != 0) {
            printf("Erreur lors de l'insertion de la valeur.\n");
            continue;
        }
    }
}

void remove_column_from_dataframe(CDATAFRAME *dataframe)
{
    int column;
    printf("Veuillez saisir le numero de la colonne que vous voulez supprimer : \n");
    if (scanf("%d", &column) != 1 || column < 1 || column > dataframe->nbcol)
    {
        printf("Numéro de colonne invalide.\n");
        return;
    }
    delete_column(dataframe->column[column - 1]);
    for (int i = column; i < dataframe->nbcol; i++)
    {
        dataframe->column[i - 1] = dataframe->column[i];
    }
    dataframe->nbcol--;
    dataframe->column = realloc(dataframe->column, dataframe->nbcol * sizeof(COLUMN *));
}

void rename_column(CDATAFRAME *dataframe)
{
    int column;
    printf("Veuillez saisir le numero de la colonne que vous voulez renommer : \n");
    if (scanf("%d", &column) != 1 || column < 1 || column > dataframe->nbcol)
    {
        printf("Numéro de colonne invalide.\n");
        return;
    }
    char title[BUFFER_SIZE];
    printf("Veuillez saisir le nouveau titre de la colonne : \n");
    scanf("%s", title);
    dataframe->column[column-1]->title = (char*)malloc((strlen(title)+1)*sizeof(char)); // Allocation de la mémoire pour le titre
    strcpy(dataframe->column[column-1]->title,title);

}

void does_value_exist(CDATAFRAME *dataframe)
{
    int value;
    printf("Veuillez saisir la valeur que vous voulez chercher : \n");
    if (scanf("%d", &value) != 1)
    {
        printf("Valeur invalide.\n");
        return;
    }
    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            if (dataframe->column[i]->values[j] == value)
            {
                count++;

            }
        }
    }
    if (count !=0)
    {
        printf("La valeur %d a ete trouvee %d fois dans le dataframe.\n", value, count);
    }
    else
    {
        printf("La valeur %d n'a pas ete trouvee dans le dataframe.\n", value);
    }

}

void replace_value(CDATAFRAME *dataframe, int line, int column)
{
    if (line < 1 || line > dataframe->column[column - 1]->tlog)
    {
        printf("La ligne n'existe pas\n");
        return;
    }
    int value;
    printf("Veuillez saisir la nouvelle valeur de la cellule : \n");
    if (scanf("%d", &value) != 1)
    {
        printf("Valeur invalide.\n");
        return;
    }
    dataframe->column[column - 1]->values[line - 1] = value;
}

void print_columns_name(CDATAFRAME *dataframe)
{
    printf("Le nom des colonnes sont : \n");
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        printf("%s\n", dataframe->column[i]->title);
    }
}

// 4.Analyse et statistiques

void print_nb_lines(CDATAFRAME *dataframe)
{
    int max = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        if (dataframe->column[i]->tlog > max)
        {
            max = dataframe->column[i]->tlog;
        }
    }
    printf("Le nombre de lignes du dataframe est : %d\n", max);
}

void print_nb_columns(CDATAFRAME *dataframe)
{
    printf("Le nombre de colonnes du dataframe est : %d\n", dataframe->nbcol);
}

void nb_of_cells_equal_to(CDATAFRAME *dataframe,int value)
{

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            if (dataframe->column[i]->values[j] == value)
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("La valeur %d n'a pas ete trouvee dans le dataframe.\n", value);
        return;
    }
    else
    {
        printf("Le nombre de cellules contenant la valeur %d est : %d\n", value, count);
    }
}

void nb_of_cells_greater_than(CDATAFRAME *dataframe, int value)
{

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            if (dataframe->column[i]->values[j] > value)
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("Aucune cellule n'est superieure a la valeur %d.\n", value);
        return;
    }
    else
    {
        printf("Le nombre de cellules superieures a la valeur %d est : %d\n", value, count);
    }
}

void nb_of_cells_lower_than(CDATAFRAME *dataframe, int value)
{

    int count = 0;
    for (int i = 0; i < dataframe->nbcol; i++)
    {
        for (int j = 0; j < dataframe->column[i]->tlog; j++)
        {
            if (dataframe->column[i]->values[j] < value)
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("Aucune cellule n'est inferieure a la valeur %d.\n", value);
        return;
    }
    else
    {
        printf("Le nombre de cellules inferieures a la valeur %d est : %d\n", value, count);
    }
}