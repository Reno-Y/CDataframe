#include "Dataframe.h"
#include <stdlib.h>
#include <stdio.h>
#define REALOC_SIZE 256

COLUMN** create_empty_cd_dataframe(int nb_col)
{
    COLUMN **CD_dataframe = malloc(nb_col * sizeof(COLUMN*));

    if (CD_dataframe == NULL || nb_col <= 0)
    {
        printf("Erreur dans votre saisies, le nombre de colonnes est invalide !\n");
        return NULL;
    }

    for (int i = 0; i < nb_col; i++)
    {
        char titre[25];
        printf("Veuillez entrez le nom de la colonne %d : \n", i+1);

        CD_dataframe[i] = create_column("test");
    }
    return CD_dataframe;
}



void fill_cd_dataframe(COLUMN ** CD_dataframe, int nb_col) {
    if (CD_dataframe == NULL || nb_col <= 0) {
        printf("Le nombre de colonnes est invalide, veuillez recommencer avec un nombre valide !");
        return;
    }

    for (int i = 0; i < nb_col; i++) {
        int value = 0;
        printf("entrez les valeurs de la colonne %d : \n", i + 1);

        do {
            printf("Valeur : (veuillez entrer 0 si vous souhaitez areter la saisie.) \n");
            scanf(" %d", &value);
            if (value != 0) {
                insert_value(CD_dataframe[i], value);

            }

        } while (value != 0);
    }
}

void print_cd_dataframe(COLUMN ** CD_dataframe, int nb_col)
{
    for (int i = 0; i < nb_col; i++) {
        print_column(CD_dataframe[i]);

    }
}

void add_line(COLUMN *column, int line, int value)
{
    if (line < 0 || line > column->tlog)
    {
        printf("La ligne n'existe pas");
        return;
    }

    if(column->tlog + 1 > column->tphys)
    {
        if(column -> tphys == 0)
        {
            column->values = malloc(REALOC_SIZE * sizeof(int));
            if(column->values == NULL)
            {
                return;
            }
            column->tphys = REALOC_SIZE;
        }
        else if(column->tphys >= REALOC_SIZE)
        {
            column-> values = realloc(column -> values, (column -> tphys + REALOC_SIZE) * sizeof(int));
            column->tphys += REALOC_SIZE;
        }
    }

    for (int i = column->tlog; i > line; i--)
    {
        column->values[i] = column->values[i - 1];
    }

    column->values[line] = value;
    column->tlog++;

}



// la fonction permet de créer un tableau de colonnes, on crée un tableau de colonnes avec un titre "column".

void remplir_cd_dataframe(COLUMN ** CD_dataframe, int nb_col)
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
                printf("Valeur : (veuillez entrer 0 si vous souhaitez areter la saisie.)");
                scanf(" %d", &value);
                if (value != 0)
                {
                    insert_value(CD_dataframe[i], value);

                }

            }while (value != 0);



        }
    }
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

/**
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
*/