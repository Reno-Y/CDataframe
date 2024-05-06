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
    COLUMN ** tab_cd_dataframe = (COLUMN**) malloc(nb_col * sizeof (COLUMN*));

    if(tab_cd_dataframe == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < nb_col; i++)
    {
        tab_cd_dataframe[i] = create_column("column");

    }
    return tab_cd_dataframe;

}

void rempli_cd_dataframe(COLUMN ** CD_dataframe, int nb_col)
{
    if (CD_dataframe == NULL)
    {
        printf("Liste vide");
        return;
    }

    else
    {
        for (int i = 0; i < nb_col  ;i++)
        {
            int value = 0;
            printf("entrez les valeurs de la colonne %d : \n", i+1);

            do
            {
                printf("Valeur : (veuillez entrer 0 si vous souhaitez aereter la saisie.)");
                scanf(" %d", &value);
                if (value != 0)
                {
                    insert_value(CD_dataframe[i], value);

                }

            }while (value != 0);



        }
    }

    return;
}

// fonction qui permet de remplir en dure a faire
// à completer




 void aff_CD_dataframe(COLUMN ** CD_dataframe, int nb_col)
{
    printf("Voici le CD dataframe : ");
    for (int i = 0; i < nb_col ; i++)
    {
        print_column( CD_dataframe[i]);
        printf("\n");
        //à revoir car on utliser print colonne mais il faut tout print

    }
}


// une fct Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur A FAIRE.


void aff_col_CD_dataframe(COLUMN ** CD_dataframe, int nb_col)
{
    int deb, fin;

    do
    {
        printf("Saisir la fin de la colonne du CD dataframe à afficher.");
        scanf("%d", &fin);
    } while (fin > nb_col || fin < 0);

    do
    {
        printf("Saisir le debut de la colonne du CD dataframe à afficher.");
        scanf("%d", &deb);
    } while (deb > fin || deb < 0);


    printf("Voici le CD dataframe allant de la colonne %d à la colonne %d", deb, fin);
    for (int i = deb - 1 ; i < fin; i++)
    {
        print_column( CD_dataframe[i]);
        printf("\n");

    }
}


void ajt_ligne_valeurs_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, int * valeurs )
{
    if (CD_dataframe == NULL || nb_col <= 0 || valeurs == NULL )
    {
        printf("Il y a une erreur dans vos saisies, veuillez recommencez avec des valeurs valides !");
        return ;
    }

    for (int i = 0; i < nb_col; i++)
    {

        if (insert_value(CD_dataframe[i], valeurs[i]) != 0)
        {
            printf("La case n'est pas libre, impossible d'entrer une valeur !");
        }

    }
    printf("Les valeurs ont été ajoutées avec succès");
}

void supp_ligne_valeurs_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, int pos_ligne)
{
    if (CD_dataframe == NULL || nb_col <= 0 || pos_ligne <= 0 )
    {
        printf("Vos données saisies ne sont pas valide !");
        return;
    }

    for (int i = 0; i < nb_col; i++)
    {
        delete_line(CD_dataframe[i],  pos_ligne);

    }

}

void ajt_une_col_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, char * titre)
{
    if (CD_dataframe == NULL || nb_col <= 0 )
    {
        printf("Vos données saisies ne sont pas valide !");
        return;
    }

    for (int i = 0; i < nb_col; i++)
    {
        if (i == nb_col - 1)
        {
             add_column(CD_dataframe[i], titre);

        }
    }
}
