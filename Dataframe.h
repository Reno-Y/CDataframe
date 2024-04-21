#include "column.h"
#define REALOC_SIZE 256


void add_line(COLUMN *column, int line, int value);

void delete_line(COLUMN *column, int line , int value);

void add_column(COLUMN *column, char* title);

void rename_column(COLUMN *column, char* title);

int value_exist(COLUMN *column, int value);

int replace_value(COLUMN *column, int line, int value, int new_value);

void print_column_name(COLUMN *column);

int number_of_lines(COLUMN *column);

int number_of_columns(COLUMN *column);

