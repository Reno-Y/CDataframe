#include "column.h"

typedef struct {
    COLUMN **column;  // pointeurs vers des colonnes
    int nbcol;         // Nombre de colonnes
} CDATAFRAME;

// 1. Alimentation

CDATAFRAME *create_empty_dataframe();

void fill_dataframe(CDATAFRAME *dataframe);

void fill_dataframe_hardcode(CDATAFRAME *dataframe);

// 2. Affichage

void print_all_dataframe(CDATAFRAME *dataframe);

void print_line_dataframe(CDATAFRAME *dataframe, int line);

void print_column_dataframe(CDATAFRAME *dataframe, int column);

// 3. Opérations usuelles

void add_column_to_dataframe(CDATAFRAME *dataframe);

void add_line_to_dataframe(CDATAFRAME *dataframe);

void remove_line_from_dataframe(CDATAFRAME *dataframe);

void remove_column_from_dataframe(CDATAFRAME *dataframe);

void rename_column(CDATAFRAME *dataframe);

void does_value_exist(CDATAFRAME *dataframe);

void replace_value(CDATAFRAME *dataframe, int line, int column);

void print_columns_name(CDATAFRAME *dataframe);

// 4. Analyse et statistiques

void print_nb_lines(CDATAFRAME *dataframe);

void print_nb_columns(CDATAFRAME *dataframe);

void nb_of_cells_equal_to(CDATAFRAME *dataframe, int value);

void nb_of_cells_greater_than(CDATAFRAME *dataframe, int value);

void nb_of_cells_lower_than(CDATAFRAME *dataframe, int value);