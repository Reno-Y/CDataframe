#include "column.h"

typedef struct {
    COLUMN **column;  // pointeurs vers des colonnes
    int nbcol;         // Nombre de colonnes
} CDataframe;


CDataframe *create_empty_dataframe();

void add_column_to_dataframe(CDataframe *dataframe, COLUMN *column);

void fill_cdataframe(CDataframe *dataframe);
