#include "column.h"

typedef struct {
    COLUMN **column;  // pointeurs vers des colonnes
    int nbcol;         // Nombre de colonnes
} CDATAFRAME;


CDATAFRAME *create_empty_dataframe();

void fill_dataframe(CDATAFRAME *dataframe);

void fill_dataframe_hardcode(CDATAFRAME *dataframe);

void print_all_dataframe(CDATAFRAME *dataframe);

void print_line_dataframe(CDATAFRAME *dataframe, int line);

void print_column_dataframe(CDATAFRAME *dataframe, int column);

void add_line_to_dataframe(CDATAFRAME *dataframe);
