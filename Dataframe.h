#include "column.h"
#define REALOC_SIZE 256



COLUMN *create_column(char* title);

int insert_value(COLUMN *column, int value);

void delete_column(COLUMN *column);

void print_column(COLUMN *column);

int value_occurence(COLUMN *column, int value);

int value_position(COLUMN *column, int value);

int value_up_to(COLUMN *column, int value);

int value_down_to(COLUMN *column, int value);

int value_equal_to(COLUMN *column, int value);

void add_line(COLUMN *column, int line, int value);

void delete_line(COLUMN *column, int line , int value);

void add_column(COLUMN *column, char* title);

void rename_column(COLUMN *column, char* title);

int value_exist(COLUMN *column, int value);

int replace_value(COLUMN *column, int line, int value, int new_value);

void print_column_name(COLUMN *column);

int number_of_lines(COLUMN *column);

int number_of_columns(COLUMN *column);

