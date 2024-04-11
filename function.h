
#ifndef PROJET_C_FUNCTION_H
#define PROJET_C_FUNCTION_H
#endif //PROJET_C_FUNCTION_H

#define REALOC_SIZE 256

typedef struct
{
    char* title;
    int Tlog;
    int Tphys;
    int *donnee;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);