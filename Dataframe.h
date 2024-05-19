#include "column.h"

typedef struct {
    COLUMN **column;  // pointeurs vers des colonnes
    int nbcol;         // Nombre de colonnes
} CDATAFRAME;


CDATAFRAME *create_empty_dataframe();

void fill_dataframe(CDATAFRAME *dataframe);

void print_dataframe(CDATAFRAME *dataframe);


void fill_dataframe_hardcode(CDATAFRAME *dataframe);