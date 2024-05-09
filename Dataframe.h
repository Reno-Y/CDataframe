#include "column.h"


void add_line(COLUMN *column, int line, int value);

void delete_line(COLUMN *column, int line);

void add_column(COLUMN *column, char* title);

void rename_column(COLUMN *column, char* title);

int value_exist(COLUMN *column, int value);

int replace_value(COLUMN *column, int line, int value, int new_value);

void print_column_name(COLUMN *column);

int number_of_lines(COLUMN *column);

int number_of_columns(COLUMN *column);

COLUMN** CDdataframe(int nb_col);

void rempli_cd_dataframe(COLUMN ** CD_dataframe, int nb_col);

void aff_CD_dataframe(COLUMN ** CD_dataframe, int nb_col);

void aff_col_CD_dataframe(COLUMN ** CD_dataframe, int nb_col);

void ajt_ligne_valeurs_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, int * valeurs );

void supp_ligne_valeurs_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, int pos_ligne);

void ajt_une_col_CD_dataframe(COLUMN ** CD_dataframe, int nb_col, char * titre);