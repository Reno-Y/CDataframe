#include "column.h"
#define REALOC_SIZE 256



COLUMN *create_column(char* title);

int insert_value(COLUMN *column, int value);

void delete_column(COLUMN *column);

void print_column(COLUMN *column);