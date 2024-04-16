#include "function.h"

int insert_value(COLUMN *column, int value) {
    if (column->Tlog == column->Tphys) {
        column->donnee *= 2;
        column->donnee = realloc(column->values, column->capacity * sizeof(int));
    }
    column->values[column->size++] = value;
    return 0;
}