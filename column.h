typedef struct{
    char* title;
    int tphys;
    int tlog;
    int* values;
}COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN *column, int value);

void delete_column(COLUMN *column);

void print_column(COLUMN *columns);


int value_occurence(COLUMN *column, int value);

int value_position(COLUMN *column, int value);

int value_up_to(COLUMN *column, int value);

int value_down_to(COLUMN *column, int value);

int value_equal_to(COLUMN *column, int value);