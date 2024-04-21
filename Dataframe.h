#define REALOC_SIZE 256

typedef struct{
    char* title;
    int tphys;
    int tlog;
    int* values;
}COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN *column, int value);

void delete_column(COLUMN *column);

void print_column(COLUMN *column);